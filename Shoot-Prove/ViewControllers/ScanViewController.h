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
#import "EnumHelper.h"
#import "ImageHelper.h"

@protocol ScanViewControllerDelegate <NSObject>
- (void)didScanViewControllerCancel;
- (void)didScanViewControllerReturnRasterImage:(LTRasterImage *)image format:(SPFormat)format dpi:(int)dpi colorMode:(SPColorMode)colorMode flashOn:(BOOL)flashOn autoCapture:(BOOL)autoCapture;
@optional
- (void)willScanViewControllerReturnRasterImage;
@end
@interface ScanViewController : UIViewController
- (id)initWithFormat:(SPFormat)format dpi:(int)dpi colorMode:(SPColorMode)colorMode flashOn:(BOOL)flashOn autoCapture:(BOOL)autoCapture freeMode:(BOOL)freeMode delegate:(id<ScanViewControllerDelegate>)delegate;
@end
