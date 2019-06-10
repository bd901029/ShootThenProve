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
#import "AbstractService.h"

@class CaptureImage, Rendition, User, SubTaskForm, DeleteImageReference;

NS_ASSUME_NONNULL_BEGIN

@interface Task : AbstractService
- (CaptureImage *)firstCaptureImage;
- (BOOL)isSync;
- (BOOL)isCertified;
- (BOOL)isComplete;
- (NSString *)completionMessage;
- (NSString *)displayTitle;
- (NSDictionary *)dictionary;
- (Rendition *)createRendition;
- (SubTaskForm *)createFreeSubTaskForm;
@end

NS_ASSUME_NONNULL_END

#import "Task+CoreDataProperties.h"
