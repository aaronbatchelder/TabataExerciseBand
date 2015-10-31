/**
 * MBLMechanicalSwitch.h
 * MetaWear
 *
 * Created by Stephen Schiffli on 8/1/14.
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
#import <MetaWear/MBLEvent.h>
#import <MetaWear/MBLModule.h>

/**
 Interface to on-board switch (pushbutton)
 */
@interface MBLMechanicalSwitch : MBLModule <NSCoding>

/**
 Data representing the current state of the switch.
 Event callbacks will be provided an MBLNumericData object, where a bool value of
 YES means pressed, and NO means released.
 */
@property (nonatomic, strong, readonly) MBLData *switchValue;

/**
 Event representing a change in the push button state (pressed/depressed).
 Event callbacks will be provided an MBLNumericData object, where a bool value of
 YES means pressed, and NO means released.
 */
@property (nonatomic, strong, readonly) MBLEvent *switchUpdateEvent;


///----------------------------------
/// @name Deprecated Methods
///----------------------------------

/**
 * @deprecated use [switchValue readWithHandler:] instead
 * @see [switchValue readWithHandler:]
 */
- (void)readSwitchStateWithHandler:(MBLSwitchStateHandler)handler DEPRECATED_MSG_ATTRIBUTE("Use [switchValue readWithHandler:] instead");

/**
 * @deprecated use [switchUpdateEvent startNotificationsWithHandler] instead
 * @see [switchUpdateEvent startNotificationsWithHandler]
 */
- (void)startSwitchUpdatesWithHandler:(MBLSwitchStateHandler)handler DEPRECATED_MSG_ATTRIBUTE("Use [switchUpdateEvent startNotificationsWithHandler] instead");
/**
 * @deprecated use [switchUpdateEvent stopNotifications] instead
 * @see [switchUpdateEvent stopNotifications]
 */
- (void)stopSwitchUpdates DEPRECATED_MSG_ATTRIBUTE("Use [switchUpdateEvent stopNotifications] instead");
@end
