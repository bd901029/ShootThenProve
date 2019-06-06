//
//  LTChangeContrastCommand.h
//  Leadtools.ImageProcessing.Color
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface LTChangeContrastCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger contrast;

- (instancetype)initWithContrast:(NSInteger)contrast NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END