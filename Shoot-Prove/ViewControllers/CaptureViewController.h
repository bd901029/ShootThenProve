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
#import "ScanViewController.h"
#import "Dialog.h"
#import "CaptureThumbCell.h"
#import "CertificationClient.h"

@class AbstractSubTaskCapture;
@protocol CaptureViewControllerDelegate <NSObject>
- (void)didCaptureViewControllerRequestBackOnSubTask:(AbstractSubTaskCapture *)subTaskCapture;
- (void)didCaptureViewControllerCancelSubTask:(AbstractSubTaskCapture *)subTaskCapture;
- (void)didCaptureViewControllerCompleteSubTask:(AbstractSubTaskCapture *)subTaskCapture;
@end
@interface CaptureViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout, UIGestureRecognizerDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate, ScanViewControllerDelegate, CaptureThumbCellDelegate, CertificationClientDelegate, DialogDelegate>
- (id)initWithSubTaskCapture:(AbstractSubTaskCapture *)subTaskCapture stepCount:(NSInteger)stepCount delegate:(id<CaptureViewControllerDelegate>)delegate;
@end
