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

#import "DateTimePicker.h"
#import "ItemPicker.h"

@class UIStyle;
@interface IndexesView : UIView <UITextFieldDelegate, UITextViewDelegate, DateTimePickerDelegate, ItemPickerDelegate>
@property (nonatomic, readonly) CGFloat preferredHeight;
@property (nonatomic, readonly) BOOL hasValue;
@property (nonatomic, readonly) BOOL updated;
@property (nonatomic, readonly, strong) NSOrderedSet *indexes;
- (void)setIndexes:(NSOrderedSet *)indexes readOnly:(BOOL)readOnly style:(UIStyle *)style;
- (void)setFocus;
@end
