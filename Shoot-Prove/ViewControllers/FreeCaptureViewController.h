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
#import "FreeCaptureThumbCell.h"
#import "CertificationClient.h"

@class User;
@protocol FreeCaptureViewControllerDelegate <NSObject>
- (void)didFreeTaskViewControllerRequestDisplayHistory;
- (void)didFreeTaskViewControllerRequestDisplaySettings;
@end
@interface FreeCaptureViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout, UIGestureRecognizerDelegate, UINavigationControllerDelegate, UIImagePickerControllerDelegate, ScanViewControllerDelegate, FreeCaptureThumbCellDelegate, CertificationClientDelegate, DialogDelegate>
- (id)initWithUser:(User *)user delegate:(id<FreeCaptureViewControllerDelegate>)delegate;
@end
