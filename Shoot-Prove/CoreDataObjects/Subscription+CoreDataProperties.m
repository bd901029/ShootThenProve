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

#import "Subscription+CoreDataProperties.h"

@implementation Subscription (CoreDataProperties)

+ (NSFetchRequest<Subscription *> *)fetchRequest {
	return [[NSFetchRequest alloc] initWithEntityName:@"Subscription"];
}

@dynamic expirationDate;
@dynamic type;
@dynamic uuid;
@dynamic owner;

@end
