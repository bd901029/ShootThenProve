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

@interface RestClientHelper : NSObject
#pragma - user attributes mapping for rest client
+ (RKEntityMapping *)fullUserEntityMapping;
//+ (RKEntityMapping *)simpleUserEntityMapping;
+ (RKObjectMapping *)simpleUserRequestMapping;
#pragma - device attributes mapping for rest client
+ (RKEntityMapping *)deviceEntityMapping;
+ (RKObjectMapping *)deviceRequestMapping;
#pragma - ident attributes mapping for rest client
+ (RKEntityMapping *)identEntityMapping;
#pragma - eula attributes mapping for rest client
+ (RKObjectMapping *)eulaEntityMapping;
#pragma - value transformers
+ (RKValueTransformer*)millisecondsSince1970ToDateValueTransformer;
@end
