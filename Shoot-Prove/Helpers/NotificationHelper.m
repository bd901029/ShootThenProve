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

#import "NotificationHelper.h"

@implementation NotificationHelper
+ (SPNotificationIntend)notificationIntend:(NSDictionary *)notification {
	NSString *intend = [notification objectForKey:@"intend"];
	if([intend isEqualToString:@"task"]) {
		return SPNotificationIntendTask;
	} else if([intend isEqualToString:@"rem"]) {
		return SPNotificationIntendREM;
	} else if([intend isEqualToString:@"template"]) {
		return SPNotificationIntendTemplate;
	}
	return SPNotificationIntendNone;
}

+ (NSString *)notificationIdentifier:(NSDictionary *)notification {
	NSString *uuid = [NSString stringWithFormat:@"%@", [notification objectForKey:@"identifier"]];
	if([uuid isEqualToString:@"(null)"] || [uuid isEqualToString:@"null"])
		uuid = nil;
	return uuid;
}

+ (BOOL)isNotificationSilent:(NSDictionary *)notification {
	BOOL isSilent = ([[notification objectForKey:@"content-available"] integerValue] == 1);
	return isSilent;
}
@end
