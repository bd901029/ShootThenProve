//
//  LTCodecsLoadInformationEventArgs.h
//  Leadtools.Codecs
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

#import "LTCodecsDefines.h"

typedef NS_ENUM(NSInteger, LTCodecsPhotoInterpolation) {
    LTCodecsPhotoInterpolationWhiteIsZero = 0,
    LTCodecsPhotoInterpolationBlackIsZero = 1,
    LTCodecsPhotoInterpolationNoColorMap  = 2,
    LTCodecsPhotoInterpolationCmyk        = 5,
    LTCodecsPhotoInterpolationYcbCr       = 6,
    LTCodecsPhotoInterpolationCieLab      = 8
};

NS_ASSUME_NONNULL_BEGIN

@interface LTCodecsLoadInformationEventArgs : NSObject

@property (nonatomic, assign)                     BOOL whiteOnBlack;
@property (nonatomic, assign)                     BOOL leastSignificantBitFirst;
@property (nonatomic, assign)                     BOOL reverse;
@property (nonatomic, assign)                     BOOL pad4;
@property (nonatomic, assign)                     BOOL motorolaOrder;
@property (nonatomic, assign)                     BOOL isSigned;

@property (nonatomic, assign)                     NSInteger width;
@property (nonatomic, assign)                     NSInteger height;
@property (nonatomic, assign)                     NSInteger bitsPerPixel;
@property (nonatomic, assign)                     NSInteger xResolution;
@property (nonatomic, assign)                     NSInteger yResolution;
@property (nonatomic, assign)                     NSUInteger stripSize;

@property (nonatomic, assign)                     long offset;

@property (nonatomic, assign)                     LTRasterImageFormat format;
@property (nonatomic, assign)                     LTCodecsPhotoInterpolation photoInterpolation;
@property (nonatomic, assign)                     LTCodecsPlanarConfiguration planarConfiguration;
@property (nonatomic, assign)                     LTRasterByteOrder order;
@property (nonatomic, assign)                     LTRasterViewPerspective viewPerspective;

@property (nonatomic, strong, readonly)           NSFileHandle *fileHandle;
@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *palette;
@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *colorMask;

@end

NS_ASSUME_NONNULL_END