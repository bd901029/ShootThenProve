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

#import "ToastHelper.h"
#import "Dialog.h"

@interface ErrorHelper : NSObject
+ (NSError *)errorFromException:(NSException *)exception module:(NSString *)module action:(NSString *)action;
+ (void)popDialogWithTitle:(NSString *)title message:(NSString *)message type:(DialogType)type;
+ (void)popToastWithMessage:(NSString *)message style:(CSToastStyle *)style;
+ (void)popDialogForStatusCode:(NSInteger)statusCode error:(NSError *)error type:(DialogType)type;
+ (void)popToastForStatusCode:(NSInteger)statusCode error:(NSError *)error style:(CSToastStyle *)style;
@end
