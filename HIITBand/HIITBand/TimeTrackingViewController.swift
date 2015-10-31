//
//  TimeTrackingViewController.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation
import UIKit


class TimeTrackingViewController: UIViewController {
    
    @IBOutlet weak var notifyEveryTextField: UITextField!
    @IBOutlet weak var lengthOfTimeToTrackTextField: UITextField!
    
    //Holders to convert text fields into Ints to calculate number of sets
    var totalTimeToTrackForActiveConversion: Int = 0
    var totalTimeToTrackForSetsConversion: Int = 0
    
    //Final number of sets calculated at time of segue
    var totalNumberOfSetsToPassAsInt: Int = 0
    var totalNumberOfSetsToPassAsString: String = ""
    
    
    @IBAction func setTimerButtonPressed(sender: AnyObject) {
        print("Set Timer Button Pressed")
        print("\(self.notifyEveryTextField.text!)")
        print("\(self.lengthOfTimeToTrackTextField.text!)")
    }
    
    func DismissKeyboard(){
        view.endEditing(true)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        //Searches for a tap
        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: "DismissKeyboard")
        view.addGestureRecognizer(tap)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject!) {
        if (segue.identifier == "timeTrackingDataPass") {
            let timeTrackingVC = segue.destinationViewController as! CountDownTimerViewController
            
            self.totalTimeToTrackForSetsConversion = Int((self.notifyEveryTextField.text!))!
            self.totalTimeToTrackForActiveConversion = Int((self.lengthOfTimeToTrackTextField.text)!)!
            
            self.totalNumberOfSetsToPassAsInt = (self.totalTimeToTrackForActiveConversion)/(self.totalTimeToTrackForSetsConversion)
            
            self.totalNumberOfSetsToPassAsString = String(self.totalNumberOfSetsToPassAsInt)
            
            print(self.totalNumberOfSetsToPassAsString)

    
            timeTrackingVC.toPassSets = self.totalNumberOfSetsToPassAsString
            timeTrackingVC.toPassActive = self.notifyEveryTextField.text!
            timeTrackingVC.toPassRest = "0"
            
        }
    }
    
    
}