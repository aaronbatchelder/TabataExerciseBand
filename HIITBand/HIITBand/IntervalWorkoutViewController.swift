//
//  IntervalWorkoutViewController.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation
import UIKit

class IntervalWorkoutViewController: UIViewController {
    
    @IBOutlet weak var setsTextField: UITextField!
    @IBOutlet weak var activeIntervalTextField: UITextField!
    @IBOutlet weak var restIntervalTextField: UITextField!
    
    //Property for passing workout history
    var intervalHistoryToPass: String = "This string is blank"
    
    var setsReceiving: String = ""
    var activeReceiving: String = ""
    var restReceiving: String = ""
    
    
    //Triggers the segue override below
    @IBAction func setTimerButtonPressed(sender: UIButton) {
        print("Set Timer Button Pressed")
        print("\(self.setsTextField.text), \(self.activeIntervalTextField.text), \(self.restIntervalTextField.text)")
        
        intervalHistoryToPass = "\(self.setsTextField.text) sets, \(self.activeIntervalTextField.text)s, \(self.restIntervalTextField.text)s"
        
        print(intervalHistoryToPass)
        
//        writeToPlist()
    }
    
    func DismissKeyboard(){
        view.endEditing(true)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //Check to see if there are parameters being passed in from the Quick Select VC
        if self.setsReceiving.characters.count > 0 {
            self.setsTextField.text = self.setsReceiving
            self.activeIntervalTextField.text = self.activeReceiving
            self.restIntervalTextField.text = self.restReceiving
        } else {
            self.setsTextField.text = self.setsTextField.text
            self.activeIntervalTextField.text = self.activeIntervalTextField.text
            self.restIntervalTextField.text = self.restIntervalTextField.text
        }
        
        //Searches for a tap
        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: "DismissKeyboard")
        view.addGestureRecognizer(tap)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject!) {
        if (segue.identifier == "intervalSeguePass") {
            let svc = segue.destinationViewController as! CountDownTimerViewController;
            
            svc.toPassSets = self.setsTextField.text
            svc.toPassActive = self.activeIntervalTextField.text
            svc.toPassRest = self.restIntervalTextField.text
        }
    }
}
//    
//    func writeToPlist() {
//        
//        println("what up")
//        var paths = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! String
//        var path = paths.stringByAppendingPathComponent("TableData.plist")
//        var data : NSMutableDictionary = NSMutableDictionary(contentsOfFile: path)!
//        let save = NSDictionary(contentsOfFile: path)a
//        
//        data.writeToFile(path, atomically: true)
//
//        var fileManager = NSFileManager.defaultManager()
//        
//        if (!(fileManager.fileExistsAtPath(path)))
//            {
//                var bundle : NSString = NSBundle.mainBundle().pathForResource("TableData", ofType: "plist")!
//                fileManager.copyItemAtPath(bundle as String, toPath: path, error:nil)
//            }
//        }
//}




