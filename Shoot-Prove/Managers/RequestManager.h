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

@class Task;

@protocol RequestManagerDelegate <NSObject>
- (void)didRequestManagerRequestStartTask:(Task *)task;
@end

@interface RequestManager : NSObject

#pragma - public instance
@property (nonatomic, weak) id<RequestManagerDelegate> delegate;
+ (instancetype)sharedManager;

#pragma - public methods
- (BOOL)hasPendingRequest;
- (void)registerRequest:(NSString *)base64request;
- (void)processPendingRequest;

@end
