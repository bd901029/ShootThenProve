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

#import "SubTaskForm.h"

NS_ASSUME_NONNULL_BEGIN

@interface SubTaskForm (CoreDataProperties)

@property (nullable, nonatomic, retain) NSOrderedSet<AbstractIndex *> *indexes;

@end

@interface SubTaskForm (CoreDataGeneratedAccessors)

- (void)insertObject:(AbstractIndex *)value inIndexesAtIndex:(NSUInteger)idx;
- (void)removeObjectFromIndexesAtIndex:(NSUInteger)idx;
- (void)insertIndexes:(NSArray<AbstractIndex *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeIndexesAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInIndexesAtIndex:(NSUInteger)idx withObject:(AbstractIndex *)value;
- (void)replaceIndexesAtIndexes:(NSIndexSet *)indexes withIndexes:(NSArray<AbstractIndex *> *)values;
- (void)addIndexesObject:(AbstractIndex *)value;
- (void)removeIndexesObject:(AbstractIndex *)value;
- (void)addIndexes:(NSOrderedSet<AbstractIndex *> *)values;
- (void)removeIndexes:(NSOrderedSet<AbstractIndex *> *)values;

@end

NS_ASSUME_NONNULL_END
