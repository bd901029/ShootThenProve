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
#import <SPCertificationSDK/SPCertificationItem.h>
#import <SPCertificationSDK/SPCertificationQueue.h>
#import <SPCertificationSDK/SPCertificationInfo.h>
#import "Dialog.h"

@protocol CertificationClientDelegate <NSObject>
- (void)didCertificationClientFinishWithCaptureImageObject:(id)imageObject indexPath:(NSIndexPath *)indexPath;
@end
@interface CertificationClient : NSObject <SPCertificationDelegate, DialogDelegate>
+ (instancetype)sharedManager;
- (void)queueCaptureImageObject:(id)imageObject indexPath:(NSIndexPath *)indexPath;
@property (weak, nonatomic) id<CertificationClientDelegate> delegate;
@end
