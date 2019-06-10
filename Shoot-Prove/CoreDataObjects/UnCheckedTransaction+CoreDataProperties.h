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

#import "UnCheckedTransaction.h"


NS_ASSUME_NONNULL_BEGIN

@interface UnCheckedTransaction (CoreDataProperties)

+ (NSFetchRequest<UnCheckedTransaction *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *identifier;
@property (nullable, nonatomic, copy) NSDate *date;
@property (nullable, nonatomic, copy) NSString *product_id;
@property (nullable, nonatomic, copy) NSString *product_name;
@property (nullable, nonatomic, copy) NSNumber *quantity;
@property (nullable, nonatomic, copy) NSNumber *errorDisplayed;

@end

NS_ASSUME_NONNULL_END
