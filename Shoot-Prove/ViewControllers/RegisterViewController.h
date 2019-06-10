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
#import "Dialog.h"

@protocol RegisterViewControllerDelegate <NSObject>
@optional
- (void)didRegisterViewControllerRequestCancel;
- (void)didRegisterViewControllerRequestPhoneAuth;
@required
- (void)didRegisterViewControllerRequestOAuthAtURL:(NSURL *)url title:(NSString *)title fakeBrowser:(BOOL)fakeBrowser;
- (void)didRegisterViewControllerReturnEmailRegistrationSuccess;
@end
@interface RegisterViewController : UIViewController <UITextFieldDelegate, DialogDelegate>
- (id)initForRegistration:(BOOL)isRegistration delegate:(id<RegisterViewControllerDelegate>)delegate;
@end
