//
//  SplashVC.swift
//  Shoot Then Prove
//
//  Created by developer on 2019/6/6.
//  Copyright © 2019 Erynnis. All rights reserved.
//

import UIKit
import WebKit
import UserNotifications
import AdSupport
import ReachabilitySwift

let appKey = "7d5bb0b1577e9b965f131e39"
let channel = "Publish channel"
let isProduction = true

@objc class SplashVC: UIViewController {

	@IBOutlet weak var webView: UIWebView!
	@IBOutlet weak var splashView: UIImageView!
	
	override func viewDidLoad() {
        super.viewDidLoad()
		self.initUI()
		
		self.startTimer()
    }
	
	override func viewWillAppear(_ animated: Bool) {
		super.viewWillAppear(animated)
	}
	
	override func viewWillDisappear(_ animated: Bool) {
		super.viewWillDisappear(animated)
		stopTimer()
	}
	
	func initUI() {
		if #available(iOS 11.0, *) {
			self.webView.scrollView.contentInsetAdjustmentBehavior = .never
		} else {
			// Fallback on earlier versions
		}
	}
	
	func loadWebView() {
		let query = AVQuery.init(className: "Links")
		query.whereKey("status", equalTo: "active")
		query.findObjectsInBackground { (results, error) in
			if let infos = results as? [AVObject] {
				if infos.count <= 0 {
					self.closeInTimeInterval(2)
					return
				} else {
					if let url = infos[0]["server"] as? String {
						self.webView.loadRequest(URLRequest(url: URL(string: url)!))
						self.stopTimer()
						return
					}
				}
			}
			
			if error != nil {
				self.closeInTimeInterval(5)
			}
		}
	}
	
	@objc func initPushNotification(launchOptions: [UIApplication.LaunchOptionsKey: Any]?) {
		if #available(iOS 10, *) {
			let entity = JPUSHRegisterEntity()
			entity.types = NSInteger(UNAuthorizationOptions.alert.rawValue) |
				NSInteger(UNAuthorizationOptions.sound.rawValue) |
				NSInteger(UNAuthorizationOptions.badge.rawValue)
			JPUSHService.register(forRemoteNotificationConfig: entity, delegate: self)
			
		} else if #available(iOS 8, *) {
			JPUSHService.register(
				forRemoteNotificationTypes: UIUserNotificationType.badge.rawValue |
					UIUserNotificationType.sound.rawValue |
					UIUserNotificationType.alert.rawValue,
				categories: nil)
		} else {
			JPUSHService.register(
				forRemoteNotificationTypes: UIRemoteNotificationType.badge.rawValue |
					UIRemoteNotificationType.sound.rawValue |
					UIRemoteNotificationType.alert.rawValue,
				categories: nil)
		}
		
		let advertisingId = ASIdentifierManager.shared().advertisingIdentifier.uuidString
		
		JPUSHService.setup(withOption: launchOptions, appKey: appKey, channel: channel, apsForProduction: isProduction, advertisingIdentifier: advertisingId)
	}
	
	func showLoading() {
		DispatchQueue.main.async {
			MBProgressHUD.hide(for: self.view, animated: true)
			
			let hub = MBProgressHUD.showAdded(to: self.view, animated: true)
			hub.bezelView.color = UIColor.white
			hub.contentColor = UIColor.blue
			hub.backgroundColor = UIColor(red: 0.0, green: 0.0, blue: 0.0, alpha: 0.25)
		}
	}
	
	func hideLoading() {
		DispatchQueue.main.async {
			MBProgressHUD.hide(for: self.view, animated: true)
		}
	}
	
	var gameTimer: Timer?
	func startTimer() {
		self.stopTimer()
		
		gameTimer = Timer.scheduledTimer(timeInterval: 2, target: self, selector: #selector(onTimer), userInfo: nil, repeats: true)
	}
	
	func stopTimer() {
		if gameTimer != nil {
			gameTimer?.invalidate()
			gameTimer = nil
		}
	}
	
	@objc func onTimer() {
		self.loadWebView()
	}
	
	func closeInTimeInterval(_ interval: Int) {
		self.stopTimer()
		DispatchQueue.main.asyncAfter(deadline: .now() + .milliseconds(interval * 1000)) {
			self.dismiss(animated: false, completion: nil)
		}
	}
}

extension SplashVC: UIWebViewDelegate {
	func webViewDidStartLoad(_ webView: UIWebView) {
		showLoading()
	}
	
	func webViewDidFinishLoad(_ webView: UIWebView) {
		splashView.isHidden = true
		
		hideLoading()
	}
	
	func webView(_ webView: UIWebView, shouldStartLoadWith request: URLRequest, navigationType: UIWebView.NavigationType) -> Bool {
		if navigationType == .linkClicked {
			guard let url = request.url else { return true }
			
			if #available(iOS 10.0, *) {
				UIApplication.shared.open(url, options: [:], completionHandler: nil)
			} else {
				// openURL(_:) is deprecated in iOS 10+.
				UIApplication.shared.openURL(url)
			}
			return false
		}
		return true
	}
}

extension SplashVC: JPUSHRegisterDelegate {
	@available(iOS 10.0, *)
	func jpushNotificationCenter(_ center: UNUserNotificationCenter!, openSettingsFor notification: UNNotification?) {
		
	}
	
	@available(iOS 10.0, *)
	func jpushNotificationCenter(_ center: UNUserNotificationCenter!, willPresent notification: UNNotification!, withCompletionHandler completionHandler: ((Int) -> Void)!) {
		let userInfo = notification.request.content.userInfo
		if (notification.request.trigger is UNPushNotificationTrigger) {
			JPUSHService.handleRemoteNotification(userInfo)
		}
		completionHandler(Int(UNNotificationPresentationOptions.alert.rawValue))
	}
	
	@available(iOS 10.0, *)
	func jpushNotificationCenter(_ center: UNUserNotificationCenter!, didReceive response: UNNotificationResponse!, withCompletionHandler completionHandler: (() -> Void)!) {
		let userInfo = response.notification.request.content.userInfo
		if response.notification.request.trigger is UNPushNotificationTrigger {
			JPUSHService.handleRemoteNotification(userInfo)
		}
		completionHandler()
	}
}
