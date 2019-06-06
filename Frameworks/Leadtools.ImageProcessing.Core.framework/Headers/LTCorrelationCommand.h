//
//  LTCorrelationCommand.h
//  Leadtools.ImageProcessing.Core
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface LTCorrelationCommand : LTRasterCommand

@property (nonatomic, strong, nullable) LTRasterImage *correlationImage;
@property (nonatomic, strong, nullable) NSArray<NSValue *> *points; //LeadPoint
@property (nonatomic, assign, readonly) NSUInteger numberOfPoints;
@property (nonatomic, assign)           NSUInteger xStep;
@property (nonatomic, assign)           NSUInteger yStep;
@property (nonatomic, assign)           NSUInteger threshold;

- (instancetype)initWithCorrelationImage:(nullable LTRasterImage *)correlationImage points:(nullable NSArray<NSValue *> *)points xStep:(NSUInteger)xStep yStep:(NSUInteger)yStep threshold:(NSUInteger)threshold NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END