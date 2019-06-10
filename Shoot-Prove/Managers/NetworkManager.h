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

typedef void(^connection)(BOOL);

@protocol NetworkManagerDelegate <NSObject>
- (void) isInternetAvailable:(BOOL)internetAvailable andServerOnline:(BOOL)serverOnline;
@end

@interface NetworkManager : NSObject <NSURLSessionDelegate, NSURLSessionDataDelegate>

@property (nonatomic, weak) id<NetworkManagerDelegate> delegate;

@property (nonatomic, readonly) BOOL internetAvailable;
@property (nonatomic, readonly) BOOL serverAvailable;
@property (nonatomic, readonly) CGFloat bandWidth;

+ (instancetype)sharedManager;

- (void)startNetworkPooling:(double)interval;
- (void)stopNetworkPooling;

- (void)checkServer:(connection)block;
- (void)checkInternet:(connection)block;

@end
