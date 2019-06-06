//
//  LTRasterCommand.h
//  Leadtools Framework
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

#import "LTLeadtoolsDefines.h"
#import "LTRasterImage.h"

typedef NS_ENUM(NSInteger, LTRasterColorChannel) {
    LTRasterColorChannelMaster   = 0,
    LTRasterColorChannelRed      = 1,
    LTRasterColorChannelGreen    = 2,
    LTRasterColorChannelBlue     = 3
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^LTRasterCommandProgress)(NSInteger percent, BOOL *cancel);

/**
 @brief The LTRasterCommand class is the base class for all LEADTOOLS image processing commands.
 */
@interface LTRasterCommand : NSObject

/** @brief The flags specifying how the LTRasterImage was changed. */
@property (nonatomic, assign, readonly) LTRasterImageChangedFlags imageChangedFlags;


/**
 @brief Runs the image processing command.
 
 @param image The image on which the image processing command should be performed.
 @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the image processing command completed successfully, otherwise NO.
 */
- (BOOL)run:(LTRasterImage *)image error:(NSError **)error;

/**
 @brief Runs the image processing command.
 
 @param image The image on which the image processing command should be performed.
 @param progressHandler An optional block that is used for progress updates.
 @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the image processing command completed successfully, otherwise NO.
 */
- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler error:(NSError **)error;

@end



@protocol LTRasterCommandProgressDelegate;

@interface LTRasterCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTRasterCommandProgressDelegate> progressDelegate LT_DEPRECATED_USENEW(19_0, "run:progress:error:");

@end

NS_ASSUME_NONNULL_END