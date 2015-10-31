//
//  ProjectClasses.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation


//MARK: Device related classes
class MyDeviceManager {
    
    var rememberedDevice : MBLMetaWear?
    
    func singleBuzz() {
        print("buzz()!!")
        if let device = self.rememberedDevice {
            print("got a device \(device) \(device.hapticBuzzer)")
            if let hapticMotor = device.hapticBuzzer {
                print("trying to buzz")
                //                hapticMotor.startBuzzerWithPulseWidth(500, completion: nil)   //soft vibration
                hapticMotor.startHapticWithDutyCycle(255, pulseWidth: 500, completion: nil) //strong vibration
                
            }
        } else {
            print("There was no device!")
        }
    }
    
    func multipleBuzz() {
        print("multipleBuzz()!!")
        if let device = self.rememberedDevice {
            print("got a device \(device) \(device.timer)")
            if let hapticMotor = device.hapticBuzzer {
                print("trying to buzz multiple times")
                let periodicEvent : MBLEvent = device.timer.eventWithPeriod(1500, repeatCount: 3)
                periodicEvent.programCommandsToRunOnEvent({ () -> Void in
                    hapticMotor.startHapticWithDutyCycle(255, pulseWidth: 500, completion: nil)
                })
                
                
            }
        }
    }
    
    func redLed() {
        if let device = self.rememberedDevice {
            if let led = device.led {
                led.setLEDColor(UIColor.redColor(), withIntensity: 0.5)
                led.setLEDOn(false, withOptions: 1)
            }
        } else {
            print("There was no device!")
        }
    }
    
    func blueLed() {
        if let device = self.rememberedDevice {
            if let led = device.led {
                led.setLEDColor(UIColor.blueColor(), withIntensity: 0.5)
                led.setLEDOn(false, withOptions: 1)
            }
        } else {
            print("There was no device!")
        }
    }
    
    func greenLed() {
        if let device = self.rememberedDevice {
            if let led = device.led {
                led.setLEDColor(UIColor.greenColor(), withIntensity: 0.5)
                led.setLEDOn(false, withOptions: 1)
            }
        } else {
            print("There was no device!")
        }
    }
    
    //Checks to see if there is a device saved on disk, if there is then it will connect, if not then it will scan for devices
    //and then connect to the first device it finds
    func startup() {
        MBLMetaWearManager.sharedManager().retrieveSavedMetaWearsWithHandler { (savedDevices: [AnyObject]!) -> Void in
            if savedDevices.count > 0 {
                print("Found a device among \(savedDevices.count)!!!")
                let firstDeviceFound:MBLMetaWear =  savedDevices[0] as! MBLMetaWear
                self.rememberedDevice = firstDeviceFound
                
                self.rememberedDevice!.connectWithHandler({ (error: NSError!) -> Void in
                    if error == nil {
                        print("Connected to \(self.rememberedDevice)")
                        self.blueLed()
                        
                    } else {
                        print(error!.description)
                    }
                })
                
                
            } else {
                print("Connecting...")
                self.connectToDevice()
            }
        }
    }
    
    func connectToDevice() {
        let manager = MBLMetaWearManager.sharedManager()
        
        func completionHandler(devicesFound: [AnyObject]!){
            if let devicesFound = devicesFound {
                if devicesFound.count > 0  {
                    //At least 1 device was found
                    for device in devicesFound {
                        let deviceHardware = device as! MBLMetaWear
                        print("Found \(deviceHardware) board")
                        manager.stopScanForMetaWears()
                        
                        //Connect to MetaWear board, will print the statement below
                        deviceHardware.connectWithHandler({ (error: NSError!) -> Void in
                            if error == nil {
                                print("Connected to \(deviceHardware)")
                                
                                deviceHardware.rememberDevice()
                                
                                // Is this really necessary? Or use: MBLMetaWearManager.retrieveSavedMetaWears() ???
                                self.rememberedDevice = deviceHardware
                                
                            } else {
                                print(error!.description)
                            }
                        })
                    }
                } else {
                    print("No devices were found!")
                    //we did not find any devices
                    //show alert could not found device
                }
                //No devices are found so devicesFound is nil
            }
        }
        manager.startScanForMetaWearsAllowDuplicates(false, handler: completionHandler)
    }
}


//MARK: Timer Related Classes
class SetManager : NSObject {
    // External event handlers.
    var onTimerUpdate : ((Double) -> Void)?
    var onDone : (() -> Void)?
    
    // Internal state.
    var sets : [Set] = []
    var timer : NSTimer?
    
    var countdown : Double = 0
    var currentSetIndex: Int = 0
    
    var currentSet : Set? {
        if sets.count == 0 {
            return nil
        } else {
            return self.sets[currentSetIndex]
        }
    }
    var currentInterval : Interval?
    
    
    var exerciseDuration : Double
    var restDuration : Double
    var numberOfSets: Int
    
    init(numberOfSets: Int, exerciseDuration: Double, restDuration: Double) {
        self.exerciseDuration = exerciseDuration
        self.restDuration = restDuration
        self.numberOfSets = numberOfSets
        
        super.init()
        
        self.setUpSets()
        self.reset()
    }
    
    func reset() {
        self.currentSetIndex = 0
        self.currentInterval = self.currentSet!.intervals[0]
        self.countdown = self.currentInterval!.duration
    }
    
    
    func setUpSets() {
        // Create a bunch of Sets.
        
        let set = Set()
        
        set.addNextInterval(Active(duration: exerciseDuration))
        set.addNextInterval(Rest(duration: restDuration))
        set.addNextInterval(EndOfSet())
        
        
        for i in 0..<self.numberOfSets {
            self.sets.append(set)
        }
    }
    
    
    func startTimer() {
        if let _updater = self.onTimerUpdate {
            _updater(self.countdown)
        }
        
        self.timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: "updateTimer" , userInfo: nil, repeats: true)
    }
    
    
    func stopTimer() {
        self.timer?.invalidate()
        
        if let _onDone = self.onDone {
            _onDone()
        }
    }
    
    
    func updateTimer() {
        if self.countdown == 0.0 {
            print("Getting the next interval")
            self.currentInterval = self.currentInterval!.next
            
            let setIsDone = self.currentInterval?.type == .EndOfSet
            if setIsDone {
                // DONE with this set! Get the next Set
                self.currentSetIndex += 1
                
                let atTheLastSet = self.currentSetIndex == self.sets.count
                if atTheLastSet {
                    self.stopTimer()
                    return
                    
                } else {
                    // Get the "next" interval, which is the first interval of the next set.
                    print("Starting the next set: \(self.currentSetIndex)")
                    self.currentInterval = self.currentSet!.intervals[0]
                }
            }
            
            self.countdown += self.currentInterval!.duration + 1.0
        }
        
        self.countdown -= 1.0
        
        if let _updater = self.onTimerUpdate {
            _updater(self.countdown)
        }
    }
}

class Set {
    var intervals : [Interval] = []
    
    init() {
        
    }
    
    var duration : Double {
        var total : Double = 0
        for activity in self.intervals {
            total += activity.duration
        }
        return total
    }
    
    func addNextInterval(interval:Interval) {
        if self.intervals.count > 0 {
            self.intervals.last!.next = interval
        }
        
        self.intervals.append(interval)
    }
}

enum IntervalType {
    case Exercise
    case Rest
    case EndOfSet
    case Generic
}

class Interval {
    var duration : Double
    var next : Interval?
    
    init(duration:Double) {
        self.duration = duration
    }
    
    var type : IntervalType {
        return .Generic
    }
}

class Active : Interval {
    override var type : IntervalType {
        return .Exercise
    }
}

class Rest : Interval {
    override var type : IntervalType {
        return .Rest
    }
}

class EndOfSet : Interval {
    init() {
        super.init(duration:0.0)
    }
    
    override var type : IntervalType {
        return .EndOfSet
    }
}











