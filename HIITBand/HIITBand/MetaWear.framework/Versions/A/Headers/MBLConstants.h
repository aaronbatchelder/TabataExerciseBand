/**
 * MBLConstants.h
 * MetaWear
 *
 * Created by Stephen Schiffli on 7/30/14.
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

#import <CoreBluetooth/CoreBluetooth.h>
@class MBLAccelerometerData;
@class MBLDeviceInfo;

#pragma mark - Block Typedefs

typedef void (^MBLVoidHandler)();
typedef void (^MBLErrorHandler)(NSError *error);
typedef void (^MBLDataHandler)(NSData *data, NSError *error);
typedef void (^MBLObjectHandler)(id obj, NSError *error);
typedef void (^MBLArrayHandler)(NSArray *array);
typedef void (^MBLArrayErrorHandler)(NSArray *array, NSError *error);
typedef void (^MBLCentralManagerStateHandler)(CBCentralManagerState state);
typedef void (^MBLPeripheralStateHandler)(CBPeripheralState state);
typedef void (^MBLAccelerometerHandler)(MBLAccelerometerData *acceleration, NSError *error);
typedef void (^MBLDeviceInfoHandler)(MBLDeviceInfo *deviceInfo, NSError *error);
typedef void (^MBLDecimalNumberHandler)(NSDecimalNumber *number, NSError *error);
typedef void (^MBLThresholdHandler)(NSDecimalNumber *number, BOOL isRising, NSError *error);
typedef void (^MBLNumberHandler)(NSNumber *number, NSError *error);
typedef void (^MBLSwitchStateHandler)(BOOL isPressed, NSError *error);
typedef void (^MBLBoolHandler)(BOOL isTrue, NSError *error);
typedef void (^MBLFloatHandler)(float number, NSError *error);
typedef void (^MBLStringHandler)(NSString *string);
typedef void (^MBLUrlHandler)(NSURL *url, NSError *error);

#pragma mark - Errors

extern NSString *const kMBLErrorDomain;

/*! @abstract 100: Unexpected number of bluetooth services */
extern NSInteger const kMBLErrorUnexpectedServices;

/*! @abstract 101: Unexpected number of bluetooth characteristics */
extern NSInteger const kMBLErrorUnexpectedCharacteristics;

/*! @abstract 102: Couldn't connect to firmware updater */
extern NSInteger const kMBLErrorNoFirmwareUpdater;

/*! @abstract 103: MetaWear object not recognized by MetaWearManager */
extern NSInteger const kMBLErrorInvalidMetaWearObject;

/*! @abstract 104: MetaWear not charged enough for firmware update */
extern NSInteger const kMBLErrorInsufficientCharge;

/*! @abstract 105: MetaWear firmware version too old */
extern NSInteger const kMBLErrorOutdatedFirmware;

/*! @abstract 106: Unexpected disconnect during a connection */
extern NSInteger const kMBLErrorUnexpectedDisconnect;
