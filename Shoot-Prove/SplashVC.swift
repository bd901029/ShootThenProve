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

let appKey = "75a02dc8752084552065605d"
let channel = "Publish channel"
let isProduction = true

@objc class SplashVC: UIViewController {

	@IBOutlet weak var titleView: UILabel!
	@IBOutlet weak var indicator: UIActivityIndicatorView!
	@IBOutlet weak var webView: UIWebView!
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
		
		let strUrl = "https://www.861711.com/"
		let request = URLRequest(url: URL(string: strUrl)!)
		self.webView.loadRequest(request)		
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
		self.dismiss(animated: true, completion: nil)
	}
	
	@IBAction func onSkipBtnClicked(_ sender: UIButton) {
		self.dismiss(animated: true, completion: nil)
	}
}

extension SplashVC: UIWebViewDelegate {
	func webViewDidStartLoad(_ webView: UIWebView) {
		indicator.startAnimating()
		splashView.isHidden = false
	}
	
	func webViewDidFinishLoad(_ webView: UIWebView) {
		indicator.stopAnimating()
		btnSkip.isHidden = false
		splashView.isHidden = true
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
