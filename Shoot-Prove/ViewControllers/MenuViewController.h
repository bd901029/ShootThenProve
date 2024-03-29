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

#import <UIKit/UIKit.h>

@class MenuItem;
@protocol MenuViewControllerDelegate <NSObject>
- (void)didClickMenuItem:(MenuItem *)menuItem;
@end
@interface MenuViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
@property (weak, nonatomic) id<MenuViewControllerDelegate> delegate;
@property (strong, nonatomic) MenuItem *freeCaptureMenuItem;
@property (strong, nonatomic) MenuItem *inboxMenuItem;
@property (strong, nonatomic) MenuItem *servicesMenuItem;
@property (strong, nonatomic) MenuItem *historyMenuItem;
@property (strong, nonatomic) MenuItem *trashMenuItem;
@property (strong, nonatomic) MenuItem *qrCodeReaderMenuItem;
@property (strong, nonatomic) MenuItem *settingsMenuItem;
@property (strong, nonatomic) MenuItem *accountMenuItem;
@end
