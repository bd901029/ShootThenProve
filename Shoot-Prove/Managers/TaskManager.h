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

#import "TaskNotificationDialog.h"
#import "CaptureViewController.h"
#import "FormTaskViewController.h"
#import "CertificationClient.h"

@class Task;

@protocol TaskManagerDelegate <NSObject>
- (void)didTaskManagerRequestDisplayInbox;
- (void)didTaskManagerRequestDisplayHistory;
- (void)didTaskManagerRequestPushViewController:(UIViewController *)controller;
- (void)didTaskManagerResquestPopViewController;
- (BOOL)didTaskManagerRequestPopViewControllersFromStep:(NSInteger)step;
@end

@interface TaskManager : NSObject <CaptureViewControllerDelegate, FormTaskViewControllerDelegate, TaskNotificationDialogDelegate, CertificationClientDelegate>

#pragma - public instance
+ (instancetype)sharedManager;

#pragma - public properties
@property (nonatomic) BOOL taskIsStarted;
@property (nonatomic, weak) id<TaskManagerDelegate> delegate;

#pragma - public methods
- (void)startTask:(Task *)task popConfirmation:(BOOL)popConfirmation;
- (void)finalizeTask:(Task *)task;
@end
