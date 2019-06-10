/*************************************************************************
 *
 * ShootThenProve CONFIDENTIAL
 * __________________
 *
 *  [2016]-[2018] ShootThenProve SA/NV
 *  www.shootandprove.com
 *  All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property
 * of ShootThenProve SA/NV. The intellectual and technical concepts contained
 * herein are proprietary to ShootThenProve SA/NV.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from ShootThenProve SA/NV.
 */

#import <UIKit/UIKit.h>
#import "SWRevealViewController.h"
#import "MenuViewController.h"
#import "FreeCaptureViewController.h"
#import "TaskViewController.h"
#import "TaskViewController_iPad.h"
#import "AccountViewController.h"
#import "SettingsViewController.h"
#import "ServicesViewController.h"
#import "QRCodeViewController.h"
#import "NotificationManager.h"
#import "StartManager.h"
#import "RequestManager.h"
#import "TaskManager.h"

@interface RootViewController : UIViewController <StartManagerDelegate, SWRevealViewControllerDelegate, MenuViewControllerDelegate, AccountViewControllerDelegate, ServicesViewControllerDelegate, TaskViewControllerDelegate, TaskViewControllerIpadDelegate, NotificationManagerDelegate, SettingsViewControllerDelegate, QRCodeViewControllerDelegate, FreeCaptureViewControllerDelegate, RequestManagerDelegate, TaskManagerDelegate>
@end
