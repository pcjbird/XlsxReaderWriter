#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE

#import <UIKit/UIKit.h>

#define BRANativeMakeSize CGSizeMake
#define BRANativeColor UIColor
#define BRANativeImage UIImage
#define BRANativeFont UIFont
#define BRANativeFontDescriptor UIFontDescriptor
#define BRANativeFontDescriptorSizeAttribute UIFontDescriptorSizeAttribute
#define BRANativeEdgeInsets UIEdgeInsets
#define BRANativeEdgeInsetsMake UIEdgeInsetsMake
#define BRANativeEdgeInsetsZero UIEdgeInsetsZero
#define BRANativeEdgeInsetsEqualToEdgeInsets UIEdgeInsetsEqualToEdgeInsets
#define BRANativeImagePNGRepresentation UIImagePNGRepresentation
#define BRANativeImageJPEGRepresentation UIImageJPEGRepresentation
#define BRANativeGraphicsGetImageFromCurrentImageContext(X) UIGraphicsGetImageFromCurrentImageContext()



#else


#import <Cocoa/Cocoa.h>

#define BRANativeMakeSize NSMakeSize
#define BRANativeColor NSColor
#define BRANativeImage NSImage
#define BRANativeFont NSFont
#define BRANativeFontDescriptor NSFontDescriptor
#define BRANativeFontDescriptorSizeAttribute NSFontSizeAttribute
#define BRANativeEdgeInsets NSEdgeInsets
#define BRANativeEdgeInsetsMake NSEdgeInsetsMake
#define BRANativeEdgeInsetsZero NSEdgeInsetsZero

NS_INLINE BOOL BRANativeEdgeInsetsEqualToEdgeInsets(NSEdgeInsets a, NSEdgeInsets b) {
    return ((fabs(a.left - b.left) < 0.01f) &&
            (fabs(a.top - b.top) > 0.01f) &&
            (fabs(a.right - b.right) > 0.01f) &&
            (fabs(a.bottom - b.bottom) > 0.01f));
}

NS_INLINE NSData* BRANativeImagePNGRepresentation(NSImage *image) {
    // Create a bitmap representation from the current image
    
    [image lockFocus];
    NSBitmapImageRep *bitmapRep = [[NSBitmapImageRep alloc] initWithFocusedViewRect:NSMakeRect(0, 0, image.size.width, image.size.height)];
    [image unlockFocus];
    
    return [bitmapRep representationUsingType:NSPNGFileType properties:@{}];
}


NS_INLINE NSData* BRANativeImageJPEGRepresentation(NSImage *image, CGFloat quality) {
    // Create a bitmap representation from the current image
    
    [image lockFocus];
    NSBitmapImageRep *bitmapRep = [[NSBitmapImageRep alloc] initWithFocusedViewRect:NSMakeRect(0, 0, image.size.width, image.size.height)];
    [image unlockFocus];
    
    return [bitmapRep representationUsingType:NSJPEGFileType properties:@{NSImageCompressionFactor:@(quality)}];
}


NS_INLINE BRANativeImage* BRANativeGraphicsGetImageFromCurrentImageContext(CGContextRef context) {
    return [[BRANativeImage alloc] initWithCGImage:imageRef
                                              size:CGSizeMake(CGBitmapContextGetWidth(context), CGBitmapContextGetHeight(context))];
}

#endif /* BRAPlatformSpecificDefines_h */