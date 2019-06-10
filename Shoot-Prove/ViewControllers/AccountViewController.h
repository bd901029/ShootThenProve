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
#import <CoreData/CoreData.h>
#import "RegisterViewController.h"
#import "RegisterOAuthViewController.h"
#import "RegisterPhoneViewController.h"
#import "InAppPurchaseManager.h"
#import "Dialog.h"
#import "GravatarPicker.h"

@class User;
@class Ident;
@class Device;
@protocol AccountViewControllerDelegate <NSObject>
- (void)didAccountViewControllerRequestReset;
- (void)didAccountViewControllerUpdateUser:(User *)user;
@end
@interface AccountViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, NSFetchedResultsControllerDelegate, GravatarPickerDelegate, UITextFieldDelegate, DialogDelegate, InAppPurchaseManagerDelegate, RegisterViewControllerDelegate, RegisterOAuthViewControllerDelegate, RegisterPhoneViewControllerDelegate>
- (id)initWithUser:(User *)user delegate:(id<AccountViewControllerDelegate>)delegate;
@end
