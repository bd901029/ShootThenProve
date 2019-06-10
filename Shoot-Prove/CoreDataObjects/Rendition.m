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

#import "Rendition.h"
#import "Task.h"
#import "StoreManager.h"
#import "NSData+Hash.h"
#import "DateTimeHelper.h"

@implementation Rendition
- (NSString *)privatePath {
	return [StoreManager.sharedManager.privatePath stringByAppendingPathComponent:[self name]];
}

- (NSString *)publicPath {
	return [StoreManager.sharedManager.publicPath stringByAppendingPathComponent:[self name]];
}
@end
