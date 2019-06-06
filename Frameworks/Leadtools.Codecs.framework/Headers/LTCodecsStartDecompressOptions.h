//
//  LTCodecsStartDecompressOptions.h
//  Leadtools.Codecs
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

#import "LTCodecsDefines.h"

typedef NS_ENUM(NSInteger, LTCodecsStartDecompressDataType) {
    LTCodecsStartDecompressDataTypeStrips,
    LTCodecsStartDecompressDataTypeTiles
};

typedef NS_OPTIONS(NSUInteger, LTCodecsDecompressDataFlags) {
    LTCodecsDecompressDataFlagsNone     = 0,
    LTCodecsDecompressDataFlagsStart    = 1,
    LTCodecsDecompressDataFlagsEnd      = 2,
    LTCodecsDecompressDataFlagsComplete = (LTCodecsDecompressDataFlagsStart | LTCodecsDecompressDataFlagsEnd)
};

NS_ASSUME_NONNULL_BEGIN

@interface LTCodecsStartDecompressOptions : NSObject

@property (nonatomic, assign)           BOOL leastSignificantBitFirst;
@property (nonatomic, assign)           BOOL pad4;
@property (nonatomic, assign)           BOOL usePalette;

@property (nonatomic, assign)           NSInteger width;
@property (nonatomic, assign)           NSInteger height;
@property (nonatomic, assign)           NSInteger bitsPerPixel;
@property (nonatomic, assign)           NSInteger xResolution;
@property (nonatomic, assign)           NSInteger yResolution;

@property (nonatomic, assign)           LTRasterImageFormat format;
@property (nonatomic, assign)           LTRasterViewPerspective viewPerspective;
@property (nonatomic, assign)           LTRasterByteOrder rawOrder;
@property (nonatomic, assign)           LTCodecsStartDecompressDataType dataType;
@property (nonatomic, assign)           LTCodecsLoadByteOrder loadOrder;
@property (nonatomic, assign)           LTCodecsTiffPhotometricInterpretation tiffPhotometricInterpretation;
@property (nonatomic, assign)           LTCodecsPlanarConfiguration planarConfiguration;

@property (nonatomic, strong, nullable) NSArray<LTRasterColor *> *palette;
@property (nonatomic, strong, nullable) NSArray<LTRasterColor *> *colorMask;

@end

NS_ASSUME_NONNULL_END