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

#import "MenuItem.h"

@implementation MenuItem
@synthesize section, name, image, resultController, treeLevel;

- (id)initWithName:(NSString *)itemName image:(UIImage *)itemImage resultController:(NSFetchedResultsController *)itemResultsController section:(NSInteger)itemSection treeLevel:(NSInteger)itemTreeLevel {
	
	self = [super init];
	
	if(self) {
		
		self.name = itemName;
		self.image = itemImage;
		self.resultController = itemResultsController;
        self.section = itemSection;
        self.treeLevel = itemTreeLevel;
		
	}
	
	return self;
	
}
@end
