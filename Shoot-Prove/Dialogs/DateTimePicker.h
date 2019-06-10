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

@class UIStyle;
@protocol DateTimePickerDelegate <NSObject>
- (void)didDateTimePickerReturnDate:(NSDate *)date tag:(NSInteger)tag;
@end
@interface DateTimePicker : UIView
- (id)initWithCurrentDate:(NSDate *)currentDate displayDate:(BOOL)displayDate displayTime:(BOOL)displayTime maxDate:(NSDate *)maxDate minDate:(NSDate *)minDate style:(UIStyle *)style delegate:(id<DateTimePickerDelegate>)delegate tag:(NSInteger)tag;
- (void)show;
@end
