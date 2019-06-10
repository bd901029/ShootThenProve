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

#import "ShadowButton.h"
#import "UIColor+HexString.h"
#import <QuartzCore/QuartzCore.h>

@implementation ShadowButton
- (void)setupView {
	self.layer.shadowColor = [[UIColor colorWithHexString:colorDarkGrey andAlpha:1.0f] CGColor];
	self.layer.shadowOpacity = 0.5;
	self.layer.shadowRadius = 4;
	self.layer.shadowOffset = CGSizeMake(4.0f, 4.0f);
	self.layer.masksToBounds = NO;
}

- (id)initWithFrame:(CGRect)frame {
	if((self = [super initWithFrame:frame])) {
		[self setupView];
	}
	return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder {
	if((self = [super initWithCoder:aDecoder])) {
		[self setupView];
	}
	return self;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	self.contentEdgeInsets = UIEdgeInsetsMake(0.0,0.0,-2.0,-2.0);
	self.layer.shadowOffset = CGSizeMake(1.0f, 1.0f);
	self.layer.shadowOpacity = 0.9;
	[super touchesBegan:touches withEvent:event];
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	self.contentEdgeInsets = UIEdgeInsetsMake(0.0,0.0,0.0,0.0);
	self.layer.shadowOffset = CGSizeMake(4.0f, 4.0f);
	self.layer.shadowOpacity = 0.5;
	[super touchesEnded:touches withEvent:event];
}
@end
