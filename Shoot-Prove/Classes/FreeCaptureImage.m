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

#import "FreeCaptureImage.h"
#import "StoreManager.h"

@implementation FreeCaptureImage
@synthesize uuid, name, path, mimetype, format, resolution, colorMode, size, md5, accuracy, certified, creationDate, errorLevel, latitude, longitude, sha1, timestamp, errors;

- (instancetype)initWithMimeType:(NSString *)mimeType {
	
	self = [super init];
	
	if(self) {
		
		self.uuid = [[NSUUID UUID] UUIDString];
		self.name = [NSString stringWithFormat:@"temp_image_%@.%@", self.uuid, [[StoreManager sharedManager] extentionFromMime:mimeType]];
		self.path = [[[StoreManager sharedManager] privatePath] stringByAppendingPathComponent:self.name];
		self.mimetype = mimeType;
		self.format = SPFormatPicture;
		self.resolution = [EnumHelper resolutionFromValue:0];
		self.colorMode = SPColorModeColor;
		self.size = SPsize1200x900;
		self.md5 = nil;
		self.accuracy = nil;
		self.certified = NO;
		self.creationDate = [NSDate date];
		self.errorLevel = [NSNumber numberWithInt:SPErrorLevelNone];
		self.latitude = @0;
		self.longitude = @0;
		self.sha1 = nil;
		self.timestamp = nil;
		self.errors = [[NSMutableArray alloc] init];
        
	}
	
	return self;
	
}

@end
