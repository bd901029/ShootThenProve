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
#import "TaskDetailViewController.h"
#import "SyncManager.h"
#import "Dialog.h"
#import "EnumHelper.h"
#import "TaskCell_iPad.h"

@class Task;
@class User;
@protocol TaskViewControllerIpadDelegate <NSObject>
- (void)didTaskViewControllerIpadRequestStartTask:(Task *)task;
- (void)didTaskViewControllerIpadRequestDisplayAccount;
@end
@interface TaskViewController_iPad : UIViewController <NSFetchedResultsControllerDelegate, UICollectionViewDelegateFlowLayout, UICollectionViewDataSource, UICollectionViewDelegate, TaskDetailsViewControllerDelegate, TaskCelliPadDelegate, DialogDelegate>
- (id)initWithUser:(User *)user displayMode:(SPTaskDisplayMode)displayMode delegate:(id <TaskViewControllerIpadDelegate>)delegate;
@end
