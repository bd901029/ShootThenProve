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

#import "DateTimeHelper.h"

@implementation DateTimeHelper
+ (NSString *)gmtDateTime:(NSDate *)date {
	NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
	dateFormatter.dateStyle = NSDateFormatterShortStyle;
	dateFormatter.timeStyle = NSDateFormatterShortStyle;
	NSTimeZone *timezone = [NSTimeZone localTimeZone];
	NSString *timeZoneStr = @"";
	NSInteger hourDelta = [timezone secondsFromGMT] / 36;
	if(hourDelta >= 0) {
		timeZoneStr = [NSString stringWithFormat:@"GMT+%.2ld", (long)hourDelta/100];
	} else {
		timeZoneStr = [NSString stringWithFormat:@"GMT%.2ld", (long)hourDelta/100];
	}
	dateFormatter.timeZone = timezone;
	return [NSString stringWithFormat:@"%@ %@", [dateFormatter stringFromDate:date], timeZoneStr];
}

+ (NSDate *)dateFromJson:(NSString *)jsonDate {
	if(!jsonDate)
		return nil;
	NSDateFormatter *df = [[NSDateFormatter alloc] init];
	[df setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
	[df setDateFormat:jsonDateFormat];
	NSDate *date = [df dateFromString:jsonDate];
	if(!date) {
		[df setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss"];
		date = [df dateFromString:jsonDate];
		if(!date) {
			[df setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS'Z'"];
			date = [df dateFromString:jsonDate];
			if(!date) {
				[df setDateStyle:NSDateFormatterShortStyle];
				[df setTimeStyle:NSDateFormatterNoStyle];
				date = [df dateFromString:jsonDate];
				if(!date)
					NSLog(@"unhandled date format for date: %@", jsonDate);
			}
		}
	}
	return date;
}

+ (NSString *)jsonFromDate:(NSDate *)date {
	if(!date)
		return @"";
	NSDateFormatter *df = [[NSDateFormatter alloc] init];
	[df setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
	[df setDateFormat:jsonDateFormat];
	return [df stringFromDate:date];
}
@end
