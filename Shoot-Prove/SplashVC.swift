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

let appKey = "7d5bb0b1577e9b965f131e39"
let channel = "Publish channel"
let isProduction = true

@objc class SplashVC: UIViewController {

	@IBOutlet weak var titleView: UILabel!
	@IBOutlet weak var webView: UIWebView!
	@IBOutlet weak var btnLarge: UIButton!
	@IBOutlet weak var btnSkip: UIButton!
	@IBOutlet weak var splashView: UIImageView!
	
	public static func instance() -> SplashVC {
		return SplashVC(nibName: "SplashVC", bundle: nil)
	}
	
	override func viewDidLoad() {
        super.viewDidLoad()
		self.initUI()
    }
	
	func initUI() {
		if #available(iOS 11.0, *) {
			self.webView.scrollView.contentInsetAdjustmentBehavior = .never
		} else {
			// Fallback on earlier versions
		}
		
		loadWebView()
	}
	
	func loadWebView() {
		if Reachability.isConnectedToNetwork() {
			AVOSCloud.setApplicationId("30nvuakCgU24uQO57N0vL1I1-gzGzoHsz", clientKey: "bKQV3jWTNT7OWhXVFDAjIT33")
			let query = AVQuery.init(className: "Links")
			query.whereKey("status", equalTo: "active")
			guard let obj = query.getFirstObject() else {
				self.webView.isHidden = true
				self.btnSkip.isHidden = false
				return
			}
			
			if let url = obj["server"] as? String {
				self.webView.loadRequest(URLRequest(url: URL(string: url)!))
			}
		} else {
			self.webView.isHidden = true
			self.btnSkip.isHidden = false
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
	
	@IBAction func onBigBtnTapped(_ sender: UIButton) {
		UIApplication.shared.openURL(URL(string: "https://itunes.apple.com/cn/app/id1187717749")!)
	}
	
	@IBAction func onSkipBtnClicked(_ sender: UIButton) {
		self.dismiss(animated: true, completion: nil)
	}
	
	func showLoading() {
		let hub = MBProgressHUD.showAdded(to: self.view, animated: true)
		hub.bezelView.color = UIColor.white
		hub.contentColor = UIColor.blue
		hub.backgroundColor = UIColor(red: 0.0, green: 0.0, blue: 0.0, alpha: 0.25)
	}
	
	func hideLoading() {
		DispatchQueue.main.async {
			MBProgressHUD.hide(for: self.view, animated: true)
		}
	}
}

extension SplashVC: UIWebViewDelegate {
	func webViewDidStartLoad(_ webView: UIWebView) {
		showLoading()
		splashView.isHidden = false
	}
	
	func webViewDidFinishLoad(_ webView: UIWebView) {
		btnSkip.isHidden = false
		btnLarge.isHidden = false
		splashView.isHidden = true
		
		hideLoading()
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
