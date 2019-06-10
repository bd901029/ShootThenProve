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
#import <StoreKit/StoreKit.h>
#import "NetworkManager.h"

@interface SyncManager : NSObject <NetworkManagerDelegate>

#pragma - public instance
+ (instancetype)sharedManager;

#pragma - public methods
- (void)addSyncTaskRequest;
- (void)addSyncServiceRequest;

- (void)syncTasks:(BOOL)syncTasks andServices:(BOOL)syncServices;
@end
