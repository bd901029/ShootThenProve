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

#import "MapPin.h"

@interface MapPin()
{
	UIImage *_image;
}
@end

@implementation MapPin
- (id)initWithImage:(UIImage *)image title:(NSString *)title coordinate:(CLLocationCoordinate2D)coordinate {
	self = [super init];
	if(self) {
		_title = title;
		_coordinate = coordinate;
		_image = image;
	}
	return self;
}

- (MKAnnotationView *)annotationView {
	MKAnnotationView *annotationView = [[MKAnnotationView alloc] initWithAnnotation:self reuseIdentifier:@"MapPin"];
	annotationView.enabled = (_title != nil ? YES:NO);
	annotationView.canShowCallout = (_title != nil ? YES:NO);
	annotationView.image = _image;
	return annotationView;
}
@end
