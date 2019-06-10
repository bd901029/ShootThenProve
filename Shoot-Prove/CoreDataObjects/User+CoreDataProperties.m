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

#import "User+CoreDataProperties.h"

@implementation User (CoreDataProperties)

+ (NSFetchRequest<User *> *)fetchRequest {
	return [[NSFetchRequest alloc] initWithEntityName:@"User"];
}

@dynamic avatar;
@dynamic avatar_email;
@dynamic avatar_data;
@dynamic betaUser;
@dynamic creationDate;
@dynamic credits;
@dynamic devUser;
@dynamic displayName;
@dynamic eulaAcceptDate;
@dynamic eulaAcceptVersion;
@dynamic firstName;
@dynamic lastName;
@dynamic lastUsageDate;
@dynamic locale;
@dynamic timeZone;
@dynamic uuid;
@dynamic devices;
@dynamic idents;
@dynamic remoteServices;
@dynamic remoteTasks;
@dynamic activeSubscription;

@end
