//
//  TotalTimeViewController.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation
import UIKit

class TotalTimeViewController: UIViewController {
    
    @IBOutlet weak var totalTimeTextField: UITextField!
    
    @IBAction func setTimerButtonPressed(sender: AnyObject) {
        print("Set Timer Button Pressed")
        print("\(self.totalTimeTextField.text)")
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
        if (segue.identifier == "totalTimeDataPass") {
            let totalTimeVC = segue.destinationViewController as! CountDownTimerViewController;
            
            totalTimeVC.toPassSets = "1"
            totalTimeVC.toPassActive = self.totalTimeTextField.text
            totalTimeVC.toPassRest = "0"
            
        }
    }
    
    
}



