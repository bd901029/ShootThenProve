//
//  LTConvertSignedToUnsignedCommand.h
//  Leadtools.ImageProcessing.Core
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

typedef NS_ENUM(NSInteger, LTConvertSignedToUnsignedCommandType) {
    LTConvertSignedToUnsignedCommandTypeShiftZeroToCenter         = 0x0000,
    LTConvertSignedToUnsignedCommandTypeShiftMinimumToZero        = 0x0001,
    LTConvertSignedToUnsignedCommandTypeShiftNegativeToZero       = 0x0002,
    LTConvertSignedToUnsignedCommandTypeShiftRangeOnly            = 0x0003,
    LTConvertSignedToUnsignedCommandTypeShiftRangeProcessOutSide  = 0x0004
};

NS_ASSUME_NONNULL_BEGIN

@interface LTConvertSignedToUnsignedCommand : LTRasterCommand

@property (nonatomic, assign) LTConvertSignedToUnsignedCommandType type;

- (instancetype)initWithType:(LTConvertSignedToUnsignedCommandType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END