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

#import <Foundation/Foundation.h>

//#import "NetworkManager.h"

#import "RegisterViewController.h"
#import "RegisterOAuthViewController.h"
#import "RegisterPhoneViewController.h"
#import "RegisterTermsViewController.h"

@class User;

@protocol StartManagerDelegate <NSObject>
- (void)didStartManagerSetMaxSteps:(NSInteger)maxSteps;
- (void)didStartManagerSetStep:(NSInteger)step async:(BOOL)async;
- (void)didStartManagerRequestReset;
- (void)didStartManagerRequestDisplayInterfaceWithUser:(User *)user serverOnline:(BOOL)serverOnline;
@end

@interface StartManager : NSObject </*NetworkManagerDelegate, */RegisterViewControllerDelegate, RegisterOAuthViewControllerDelegate, RegisterPhoneViewControllerDelegate, RegisterTermsViewControllerDelegate>

#pragma - public instance
+ (instancetype)sharedManager;

#pragma - public properties
@property (nonatomic, weak) id<StartManagerDelegate>delegate;
@property (nonatomic, strong) UINavigationController *navigationController;

#pragma - public methods
- (void)start;
- (void)reset;
@end
