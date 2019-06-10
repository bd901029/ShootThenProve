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

@class AbstractService;
@class Service;
@class Task;
@interface TaskHelper : NSObject
#pragma - service helpers
+ (NSString *)serviceIdFromDictionary:(NSDictionary *)dictionary;
+ (Service *)createServiceFromDictionary:(NSDictionary *)dictionary error:(NSError **)error;
+ (void)updateService:(Service *)service withDictionary:(NSDictionary *)dictionary error:(NSError **)error;
#pragma - task helpers
+ (Task *)createTaskFromDictionary:(NSDictionary *)dictionary visible:(BOOL)visible error:(NSError **)error;
+ (void)updateTask:(Task *)task withDictionary:(NSDictionary *)dictionary error:(NSError **)error;
@end
