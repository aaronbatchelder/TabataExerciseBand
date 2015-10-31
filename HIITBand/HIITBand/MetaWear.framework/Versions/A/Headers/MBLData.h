/**
 * MBLData.h
 * MetaWear
 *
 * Created by Stephen Schiffli on 1/23/15.
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
#import <MetaWear/MBLRegister.h>

@class MBLEvent;

/**
 This object represents synchronous data from sensors and peripherals on the MetaWear board.
 */
@interface MBLData : MBLRegister <NSCoding>

/**
 Perform read of the current value, without getting a callback.  Useful for
 programming a triggered read.
 */
- (void)read;

/**
 Perform a one time read of the current value
 @param handler Callback once read is complete
 */
- (void)readWithHandler:(MBLObjectHandler)handler;


/**
 Create a new event that will periodically read this data a fixed number of times.
 @param period Period time in mSec
 @param repeatCount Number of times event will be triggered, 0xFFFF will repeat forever
 @returns New event that will read this data periodically
 */
- (MBLEvent *)periodicReadWithPeriod:(uint32_t)period
                         repeatCount:(uint16_t)repeatCount;

/**
 Create a new event that will periodically read this data until canceled.
 @param period Period time in mSec
 @returns New event that will read this data periodically
 */
- (MBLEvent *)periodicReadWithPeriod:(uint32_t)period;


///----------------------------------
/// @name Deprecated Methods
///----------------------------------

/**
 * @deprecated create an id<MBLRestorable> object and use [MBLMetaWear setConfiguration:handler:] instead
 */
- (MBLEvent *)periodicReadWithPeriod:(uint32_t)period
                          identifier:(NSString *)identifier DEPRECATED_MSG_ATTRIBUTE("Create an id<MBLRestorable> object and use [MBLMetaWear setConfiguration:handler:] instead");

/**
 * @deprecated create an id<MBLRestorable> object and use [MBLMetaWear setConfiguration:handler:] instead
 */
- (MBLEvent *)periodicReadWithPeriod:(uint32_t)period
                         repeatCount:(uint16_t)repeatCount
                          identifier:(NSString *)identifier DEPRECATED_MSG_ATTRIBUTE("Create an id<MBLRestorable> object and use [MBLMetaWear setConfiguration:handler:] instead");

@end
