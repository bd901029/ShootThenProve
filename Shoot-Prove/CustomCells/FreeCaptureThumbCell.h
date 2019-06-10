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
#import <QuartzCore/QuartzCore.h>

@class FreeCaptureImage;
@protocol FreeCaptureThumbCellDelegate <NSObject>
- (void)didFreeCaptureThumbCellRequestRotate:(UICollectionViewCell *)cell;
- (void)didFreeCaptureThumbCellRequestDelete:(UICollectionViewCell *)cell;
- (void)didFreeCaptureThumbCellRequestView:(UICollectionViewCell *)cell;
@end
@interface FreeCaptureThumbCell : UICollectionViewCell
- (void)setImage:(FreeCaptureImage *)freeCaptureImage delegate:(id<FreeCaptureThumbCellDelegate>)delegate;
- (void)startAnimation;
- (void)stopAnimation;
@end
