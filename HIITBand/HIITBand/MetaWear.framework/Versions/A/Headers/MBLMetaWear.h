/**
 * MBLMetaWear.h
 * MetaWear
 *
 * Created by Stephen Schiffli on 7/29/14.
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
#import <MetaWear/MBLConstants.h>

@class MBLTemperature;
@class MBLAccelerometer;
@class MBLGyro;
@class MBLLED;
@class MBLMechanicalSwitch;
@class MBLGPIO;
@class MBLHapticBuzzer;
@class MBLiBeacon;
@class MBLNeopixel;
@class MBLEvent;
@class MBLANCS;
@class MBLI2C;
@class MBLTimer;
@class MBLGSR;
@class MBLBarometer;

/**
 BLE transmiter power
 */
typedef NS_ENUM(uint8_t, MBLTransmitPower) {
    MBLTransmitPower4dBm,
    MBLTransmitPower0dBm,
    MBLTransmitPowerMinus4dBm,
    MBLTransmitPowerMinus8dBm,
    MBLTransmitPowerMinus12dBm,
    MBLTransmitPowerMinus16dBm,
    MBLTransmitPowerMinus20dBm,
    MBLTransmitPowerMinus30dBm
};

@class MBLMetaWear;

/**
 An MBLRestorable object is used to persist state across resets and disconnects.
 You create an object that conforms to this protocol and then assing it to an
 MBLMetaWear object using the setConfiguration:handler: method
 */
@protocol MBLRestorable <NSObject, NSCoding>
/**
 Any API calls in this method will be persisted in non-volatile memory on the
 MetaWear, so upon power cycle it will setup the device with whatever you want automatically
 */
- (void)runOnDeviceBoot:(MBLMetaWear *)device;
@end


/**
 Each MBLMetaWear object corresponds a physical MetaWear board.  It contains all the logical
 methods you would expect for interacting with the device, such as, connecting, disconnecting,
 reading and writing state.
 
 Sensors and peripherals on the MetaWear are encapsulated within their own objects accessable 
 here via properties.  For example, all accelerometer functionality is contained in the 
 MBLAccelerometer class and is accessed using the accelerometer property
 */
@interface MBLMetaWear : NSObject <CBPeripheralDelegate, NSCoding>

///----------------------------------
/// @name Sensor and Peripheral Accessors
///----------------------------------

/**
 MBLMechanicalSwitch object contains all methods for interacting with the on-board button
 */
@property (nonatomic, strong, readonly) MBLMechanicalSwitch *mechanicalSwitch;
/**
 MBLLED object contains all methods for interacting with the on-board LED
 */
@property (nonatomic, strong, readonly) MBLLED *led;
/**
 MBLTemperature object contains all methods for interacting with the on-chip and external thermistor temperature sensors
 */
@property (nonatomic, strong, readonly) MBLTemperature *temperature;
/**
 MBLAccelerometer object contains all methods for interacting with the on-board accelerometer sensor
 */
@property (nonatomic, strong, readonly) MBLAccelerometer *accelerometer;
/**
 MBLGyro object contains all methods for interacting with the on-board gyroscope sensor
 */
@property (nonatomic, strong, readonly) MBLGyro *gyro;
/**
 MBLGPIO object contains all methods for interacting with the on-board pins
 */
@property (nonatomic, strong, readonly) MBLGPIO *gpio;
/**
 MBLHapticBuzzer object contains all methods for interacting with the external haptic or buzzer
 */
@property (nonatomic, strong, readonly) MBLHapticBuzzer *hapticBuzzer;
/**
 MBLiBeacon object contains all methods for programming the device to advertise as an iBeacon
 */
@property (nonatomic, strong, readonly) MBLiBeacon *iBeacon;
/**
 MBLNeopixel object contains all methods for interacting with an external NeoPixel chain
 */
@property (nonatomic, strong, readonly) MBLNeopixel *neopixel;
/**
 MBLANCS object contains all methods for interacting with ANCS notifications
 */
@property (nonatomic, strong, readonly) MBLANCS *ancs;
/**
 MBLTimer object contains all methods for programming timer based operations
 */
@property (nonatomic, strong, readonly) MBLTimer *timer;
/**
 MBLTimer object contains all methods for performing raw I2C read/writes
 */
@property (nonatomic, strong, readonly) MBLI2C *i2c;
/**
 MBLGSR object contains all methods for perfoming GSR reads
 */
@property (nonatomic, strong, readonly) MBLGSR *gsr;
/**
 MBLBarometer object contains all methods for interacting with the barometer sensor
 */
@property (nonatomic, strong, readonly) MBLBarometer *barometer;
/**
 MBLDeviceInfo object contains version information about the device
 */
@property (nonatomic, strong, readonly) MBLDeviceInfo *deviceInfo;


///----------------------------------
/// @name Persistent Configuration Settings
///----------------------------------

/**
 MBLRestorable object containing custom settings and events that are programmed to 
 the MetaWear and preserved even after reset or power failure.
 */
@property (nonatomic, strong, readonly) id<MBLRestorable> configuration;

/**
 Program MetaWear with persistance settings.  This only needs to be called once, likely 
 after you confirm the device from a scanning screen or such.  Upon calling it will
 erase all non-volatile memory the device (which requires disconnect), then perform reset, 
 then once its comes back online we will connect and invoke the runOnDeviceBoot method.
 These settings will be persisted device side so after any future reset these settings
 will be applied automatically.
 @param configuration Pointer to object containing programming commands.  Writing nil
 will reset to factory settings.
 @param handler Callback once programming is complete
 */
- (void)setConfiguration:(id<MBLRestorable>)configuration handler:(MBLErrorHandler)handler;

///----------------------------------
/// @name State Accessors
///----------------------------------

/**
 Current connection state of this MetaWear
 */
@property (nonatomic, readonly) CBPeripheralState state;
/**
 iOS generated unique identifier for this MetaWear
 */
@property (nonatomic, strong, readonly) NSUUID *identifier;
/**
 Stored value of signal strength at discovery time
 */
@property (nonatomic, strong) NSNumber *discoveryTimeRSSI;
/**
 Advertised device name, max 8 characters
 */
@property (nonatomic, strong) NSString *name;
/**
 Advertising interval in ms
 */
@property (nonatomic) uint16_t advertisingInterval;
/**
 Bluetooth radio transmit power.  Setting a smaller (lower dBm) value will
 result in a smaller connection radius, default is MBLTransmitPower0dBm.
 */
@property (nonatomic) MBLTransmitPower transmitPower;
/**
 Set a raw value into the scan response BLE advertising packet
 */
@property (nonatomic, strong) NSData *scanResponse;

///----------------------------------
/// @name Pairing/Bonding
///----------------------------------

/**
 Start the pairing process which creates a persistent bond between the 
 MetaWear and iOS device
 */
- (void)initiatePairing;
/**
 Removes all bonding information stored on the MetaWear.  Note, to delete
 bonding information on the iOS device you must go to Settings -> Bluetooth
 choose the device you want to remove and select "Forget This Device"
 */
- (void)deleteAllBonds;

///----------------------------------
/// @name Connect/Disconnect
///----------------------------------

/**
 Connect/reconnect to the MetaWear board. Once connection is complete, the provided block
 will be invoked.  If the NSError provided to the block is null then the connection
 succeeded, otherwise failure (see provided error for details)
 @param handler Callback once connection is complete
 */
- (void)connectWithHandler:(MBLErrorHandler)handler;

/**
 Disconnect from the MetaWear board.
 @param handler Callback once disconnection is complete
 */
- (void)disconnectWithHandler:(MBLErrorHandler)handler;

///----------------------------------
/// @name Remember/Forget
///----------------------------------

/**
 Remember this MetaWear, it will be saved to disk and retrievable
 through [MBLMetaWearManager retrieveSavedMetaWears]
 */
- (void)rememberDevice;
/**
 Forget this MetaWear, it will no longer be retrievable
 through [MBLMetaWearManager retrieveSavedMetaWears]
 */
- (void)forgetDevice;

///----------------------------------
/// @name State Reading
///----------------------------------

/**
 Query the current RSSI
 @param handler Callback once RSSI reading is complete
 */
- (void)readRSSIWithHandler:(MBLNumberHandler)handler;
/**
 Query the percent remaining battery life, returns int between 0-100
 @param handler Callback once battery life reading is complete
 */
- (void)readBatteryLifeWithHandler:(MBLNumberHandler)handler;

///----------------------------------
/// @name Firmware Update and Reset
///----------------------------------

/**
 Perform a software reset of the device
 @warning This will cause the device to disconnect
 */
- (void)resetDevice;

/**
 See if this device is running the most up to date firmware
 @param handler Callback once current firmware version is checked against the latest
 */
- (void)checkForFirmwareUpdateWithHandler:(MBLBoolHandler)handler;

/**
 Updates the device to the latest firmware, or re-installs the latest firmware.
 
 Please make sure the device is charged at 50% or above to prevent errors.
 Executes the progressHandler periodically with the firmware image uploading
 progress (0.0 - 1.0), once it's called with 1.0, you can still expect another 5
 seconds while we wait for the device to install the firmware and reboot.  After
 the reboot, handler will be called and passed an NSError object if the update
 failed or nil if the update was successful.
 @param handler Callback once update is complete
 @param progressHandler Periodically called while firmware upload is in progress
 */
- (void)updateFirmwareWithHandler:(MBLErrorHandler)handler
                  progressHandler:(MBLFloatHandler)progressHandler;


///----------------------------------
/// @name Deprecated Methods
///----------------------------------

/**
 * @deprecated use setConfiguration:handler: instead
 */
- (MBLEvent *)retrieveEventWithIdentifier:(NSString *)identifier DEPRECATED_MSG_ATTRIBUTE("Use setConfiguration:handler: instead");

/**
 * @deprecated use deviceInfo property instead
 */
- (void)readDeviceInfoWithHandler:(MBLDeviceInfoHandler)handler DEPRECATED_MSG_ATTRIBUTE("Use deviceInfo property instead");

/**
 * @deprecated Use connectWithHandler: instead
 */
- (void)connecWithHandler:(MBLErrorHandler)handler DEPRECATED_MSG_ATTRIBUTE("Use connectWithHandler: instead");

@end
