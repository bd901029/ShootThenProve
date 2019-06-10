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
#import <UIKit/UIKit.h>

typedef enum {
	DialogTypeError = 0,
	DialogTypeWarning = 1,
	DialogTypeInfo = 2
} DialogType;

@protocol DialogDelegate <NSObject>
- (void)didClickConfirmButtonWithTitle:(NSString *)confirmButtonTitle confirmTag:(NSString *)tag;
@optional
- (void)didClickCancelButton;
@end
@interface Dialog : UIView
- (id)initWithType:(DialogType)dialogType title:(NSString *)title message:(NSString *)message confirmButtonTitle:(NSString *)confirmButtonTitle confirmTag:(NSString *)confirmTag cancelButtonTitle:(NSString *)cancelButtonTitle target:(id<DialogDelegate>)target;
- (void)show;
- (void)hide;
@end

