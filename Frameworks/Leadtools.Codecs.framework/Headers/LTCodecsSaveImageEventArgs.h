//
//  LTCodecsSaveImageEventArgs.h
//  Leadtools.Codecs
//
//  Copyright © 1991-2016 LEAD Technologies, Inc. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface LTCodecsSaveImageEventArgs : NSObject

@property (nonatomic, assign)                     BOOL cancel;

@property (nonatomic, assign, readonly)           NSInteger page;
@property (nonatomic, assign, readonly)           NSInteger firstPage;
@property (nonatomic, assign, readonly)           NSInteger lastPage;
@property (nonatomic, assign, readonly)           NSInteger imagePage;
@property (nonatomic, assign, readonly)           NSInteger pagePercent;
@property (nonatomic, assign, readonly)           NSInteger totalPercent;
@property (nonatomic, assign, readonly)           NSInteger row;
@property (nonatomic, assign, readonly)           NSInteger lines;

@property (nonatomic, strong, readonly, nullable) LTRasterImage *image;
@property (nonatomic, strong, readonly, nullable) LTLeadStream *stream;

@property (nonatomic, assign, nullable)           unsigned char *buffer;
@property (nonatomic, assign)                     NSUInteger bufferLength;

@end

NS_ASSUME_NONNULL_END