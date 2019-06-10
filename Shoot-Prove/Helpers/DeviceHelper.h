//
//  DeviceHelper.h
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
#import <AVFoundation/AVFoundation.h>

@interface DeviceProperties : NSObject
@property (nonatomic, strong) NSString *buildNumber;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *uid;
@property (nonatomic, strong) NSString *preferredLanguage;
@end
@class User;
@class Device;
@interface DeviceHelper : NSObject
+ (DeviceProperties *)getDeviceProperties;
+ (Device *)getCurrentDevice;
+ (void)checkCameraGranted:(void (^)(BOOL granted))block;
+ (void)openDeviceSettings;
+ (NSString *)totalDiskSpace;
+ (NSString *)freeDiskSpace;
+ (NSString *)usedDiskSpace;
+ (CGFloat)totalDiskSpaceInBytes;
+ (CGFloat)freeDiskSpaceInBytes;
+ (CGFloat)usedDiskSpaceInBytes;
@end
