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

#import "ToastHelper.h"
#import "UIColor+HexString.h"

@implementation ToastHelper
+ (CSToastStyle *)styleError {
	CSToastStyle *style = [[CSToastStyle alloc] initWithDefaultStyle];
	style.backgroundColor = [UIColor colorWithHexString:colorLightGrey andAlpha:1.0f];
	style.titleColor = [UIColor colorWithHexString:colorRed andAlpha:1.0f];
	style.titleFont = [UIFont fontWithName:boldFontName size:normalFontSize];
	style.messageColor = [UIColor colorWithHexString:colorWhite andAlpha:1.0f];
	style.messageFont = [UIFont fontWithName:normalFontName size:normalFontSize];
    style.displayShadow = YES;
	return style;
}

+ (UIImage *)imageError {
	return [UIImage imageNamed:@"error"];
}

+ (CSToastStyle *)styleWarning {
	CSToastStyle *style = [[CSToastStyle alloc] initWithDefaultStyle];
	style.backgroundColor = [UIColor colorWithHexString:colorLightGrey andAlpha:1.0f];
	style.titleColor = [UIColor colorWithHexString:colorOrange andAlpha:1.0f];
	style.titleFont = [UIFont fontWithName:boldFontName size:normalFontSize];
	style.messageColor = [UIColor colorWithHexString:colorWhite andAlpha:1.0f];
	style.messageFont = [UIFont fontWithName:normalFontName size:normalFontSize];
    style.displayShadow = YES;
	return style;
}

+ (UIImage *)imageWarning {
	return [UIImage imageNamed:@"warning"];
}

+ (CSToastStyle *)styleInfo {
	CSToastStyle *style = [[CSToastStyle alloc] initWithDefaultStyle];
	style.backgroundColor = [UIColor colorWithHexString:colorLightGrey andAlpha:1.0f];
	style.titleColor = [UIColor colorWithHexString:colorGreen andAlpha:1.0f];
	style.titleFont = [UIFont fontWithName:boldFontName size:normalFontSize];
	style.messageColor = [UIColor colorWithHexString:colorWhite andAlpha:1.0f];
	style.messageFont = [UIFont fontWithName:normalFontName size:normalFontSize];
    style.displayShadow = YES;
	return style;
}

+ (UIImage *)imageInfo {
	return [UIImage imageNamed:@"info"];
}
@end
