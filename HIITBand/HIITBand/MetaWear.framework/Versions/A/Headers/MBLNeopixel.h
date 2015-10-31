/**
 * MBLNeopixel.h
 * MetaWear
 *
 * Created by Stephen Schiffli on 8/12/14.
 * Copyright 2014 MbientLab Inc. All rights reserved.
 *
 * IMPORTANT: Your use of this Software is limited to those specific rights
 * granted under the terms of a software license agreement between the user who
 * downloaded the software, his/her employer (which must be your employer) and
 * MbientLab Inc, (the "License").  You may not use this Software unless you
 * agree to abide by the terms of the License which can be found at
 * www.mbientlab.com/terms . The License limits your use, and you acknowledge,
 * that the  Software may not be modified, copied or distributed and can be used
 * solely and exclusively in conjunction with a MbientLab Inc, product.  Other
 * than for the foregoing purpose, you may not use, reproduce, copy, prepare
 * derivative works of, modify, distribute, perform, display or sell this
 * Software and/or its documentation for any purpose.
 *
 * YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 * PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 * NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 * MBIENTLAB OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE,
 * STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE
 * THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED
 * TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST
 * PROFITS OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
 * SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY
 * DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * Should you have any questions regarding your right to use this Software,
 * contact MbientLab Inc, at www.mbientlab.com.
 */

#import <MetaWear/MBLConstants.h>
#import <MetaWear/MBLModule.h>
#import <UIKit/UIKit.h>

@class MBLNeopixelStrand;

/**
 Coloring ordering of the NeoPixel strand (depends on the LED driver chip)
 */
typedef NS_ENUM(uint8_t, MBLColorOrdering) {
    MBLColorOrderingRGB = 0,
    MBLColorOrderingRBG = 1,
    MBLColorOrderingGRB = 2,
    MBLColorOrderingGBR = 3
};

/**
 Speed of the NeoPixel strand (depends on the LED driver chip)
 */
typedef NS_ENUM(uint8_t, MBLStrandSpeed) {
    MBLStrandSpeedSlow = 0,
    MBLStrandSpeedFast = 1
};

/**
 Direction the pixel colors shift during rotation
 */
typedef NS_ENUM(uint8_t, MBLRotationDirection) {
    MBLRotationDirectionTowardsBoard = 0,
    MBLRotationDirectionAwayFromBoard = 1
};

/**
 Interface to external NeoPixel stands
 */
@interface MBLNeopixel : MBLModule <NSCoding>

/**
 Initialize memory on the MetaWear board for a NeoPixel strand
 @param color Color ordering format
 @param speed Operating speed
 @param pin GPIO pin the strand is connected to
 @param length Number of pixels to initialize
 */
- (MBLNeopixelStrand *)strandWithColor:(MBLColorOrdering)color
                                 speed:(MBLStrandSpeed)speed
                                   pin:(uint8_t)pin
                                length:(uint8_t)length;


///----------------------------------
/// @name Deprecated Methods
///----------------------------------

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)initializeStrandAtIndex:(uint8_t)index color:(MBLColorOrdering)color speed:(MBLStrandSpeed)speed pin:(uint8_t)pin length:(uint8_t)length DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)holdStrandAtIndex:(uint8_t)index withEnable:(BOOL)enable DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)clearStrandAtIndex:(uint8_t)index startPixel:(uint8_t)start endPixel:(uint8_t)end DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)setPixelAtIndex:(uint8_t)index pixel:(uint8_t)pixel color:(UIColor *)color DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)rotateStrandAtIndex:(uint8_t)index direction:(MBLRotationDirection)direction repetitions:(uint8_t)repetitions period:(uint16_t)period DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)deinitializeStrandAtIndex:(uint8_t)index DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)initializeStrandAtIndex:(uint8_t)index withColor:(uint8_t)color pin:(uint8_t)pin andLength:(uint8_t)length DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)clearStrandwithStartIndex:(uint8_t)start endIndex:(uint8_t)end DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)setPixelAtIndex:(uint8_t)index withRed:(uint8_t)red Green:(uint8_t)green andBlue:(uint8_t)blue DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

/**
 * @deprecated use MBLNeopixelStrand instead
 * @see MBLNeopixelStrand
 */
- (void)rotateStrandAtIndex:(uint8_t)index withIncFlag:(uint8_t)flag rotateRepeat:(uint8_t)repeat andDelay:(uint16_t)delay DEPRECATED_MSG_ATTRIBUTE("use MBLNeopixelStrand instead");

@end
