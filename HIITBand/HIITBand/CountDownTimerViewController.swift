//
//  CountDownTimerViewController.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation
import UIKit

class CountDownTimerViewController: UIViewController {
    
    //Run App in the background
    var backgroundTaskIdentifier: UIBackgroundTaskIdentifier?
    
    //Class Properties for Device
    var deviceManager = MyDeviceManager()
    
    //Class Properties for Timer
    var timerManager : SetManager!
    var activeInterval: NSTimeInterval = 3
    var restInterval: NSTimeInterval = 5
    var sets : Int = 3

    
    //Parameters for passing data between view controllers
    var toPassSets:String!
    var toPassActive:String!
    var toPassRest:String!

    //Outlet Properties
    @IBOutlet weak var timerLabel: UILabel!
    
    //Methods for UI
    @IBAction func startButtonPressed(sender: AnyObject) {
        print("start button pressed")
        self.deviceManager.singleBuzz()
        self.deviceManager.greenLed()
        self.startWorkout()
    }
    
    @IBAction func playButtonPressed(sender: AnyObject) {
        //Stop the current count
        
    }
    
    @IBAction func pauseButtonPressed(sender:AnyObject) {
        //stop the current count
        
    }
    
    @IBAction func stopButtonPresssed(sender: AnyObject) {
        self.timerManager.stopTimer()
    }
    
    @IBAction func resetButtonPressed(sender: AnyObject) {
        //Stop timer
        //set the timer back to the original time
        resetTimer()
    }
    
    func startWorkout() {
        let numberOfSets = Int((toPassSets))!
        let toPassActiveDouble = NSString(string: toPassActive).doubleValue
        let toPassRestDouble = NSString(string: toPassRest).doubleValue
        
        self.timerManager = SetManager(numberOfSets: numberOfSets, exerciseDuration: toPassActiveDouble, restDuration: toPassRestDouble)
        self.timerManager.onTimerUpdate = self.updateTimerLabel
        self.timerManager.onDone = self.printCongrats
        
        self.timerManager.startTimer()
    }
    
    //Converting the time into a readable form
    func timeString(time:NSTimeInterval) -> String {
        let minutes = Int(time) / 60
        let seconds = Int(time) % 60
        let secondFraction = Int((time - Double(seconds)) * 10.0)
        return String(format: "%02i:%02i.%02i",minutes,seconds,secondFraction)
    }
    
    func resetTimer() {
      self.timerManager.stopTimer()
      self.timerManager.reset()
      timerLabel.text = toPassActive + ".0"
    }
    
    func updateTimerLabel(countdown:Double) {
        self.timerLabel.text = "\(countdown)"
        checkForNeedToBuzz()
    }
    
    func printCongrats() {
        print("CONGRATS ALL DONE!")
        deviceManager.multipleBuzz()
    }
    
    func checkForNeedToBuzz() {
        if timerLabel.text == "0.0" {
            deviceManager.singleBuzz()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //Runs the app in the background for 3 minutes
        backgroundTaskIdentifier = UIApplication.sharedApplication().beginBackgroundTaskWithExpirationHandler({
            UIApplication.sharedApplication().endBackgroundTask(self.backgroundTaskIdentifier!)
        })
        
        //Stops the screen from dimming or shutting off automatically
        UIApplication.sharedApplication().idleTimerDisabled = true
        
        self.deviceManager = MyDeviceManager()
        self.deviceManager.startup()
        self.deviceManager.connectToDevice()
        
        //Set text label to active time
        self.timerLabel.text = toPassActive + ".0"
        
        print(toPassSets)
    
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
}


