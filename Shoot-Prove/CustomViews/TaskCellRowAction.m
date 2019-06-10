//
//  TaskCellRowAction.m
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

#import "TaskCellRowAction.h"

@implementation TaskCellRowAction
+ (instancetype)rowActionWithStyle:(UITableViewRowActionStyle)style title:(NSString *)title icon:(UIImage*)icon handler:(void (^)(UITableViewRowAction *action, NSIndexPath *indexPath))handler {
	TaskCellRowAction *action = [super rowActionWithStyle:style title:title handler:handler];
	action.icon = icon;
	return action;
}

- (void)_setButton:(UIButton*)button {
	if (self.font) button.titleLabel.font = self.font;
	if (self.icon) {
		[button setImage:[self.icon imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate] forState:UIControlStateNormal];
		button.tintColor = button.titleLabel.textColor;
		CGSize titleSize = [button.titleLabel.text sizeWithAttributes:@{NSFontAttributeName:button.titleLabel.font}];
		button.imageEdgeInsets = UIEdgeInsetsMake(-(titleSize.height/2), 0, 0, -titleSize.width);
	}
}
@end
