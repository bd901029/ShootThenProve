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

#import "CertificationError.h"

NS_ASSUME_NONNULL_BEGIN

@interface CertificationError (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *code;
@property (nullable, nonatomic, retain) NSString *desc;
@property (nullable, nonatomic, retain) NSString *domain;
@property (nullable, nonatomic, retain) CaptureImage *image;

@end

NS_ASSUME_NONNULL_END
