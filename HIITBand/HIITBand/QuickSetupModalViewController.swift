//
//  QuickSetupModalViewController.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation
import UIKit


class QuickSetupModalViewController: UITableViewController {
    
    @IBOutlet var tableViewOutlet: UITableView!
    
    var textArray: NSMutableArray = NSMutableArray()
    var tabataWorkout: String = "Tabata: 8 sets, 20s, 10s"
    var turbulenceWorkout: String = "Turbulence: 8 sets, 45s, 10s"
    var hiitWorkout: String = "HIIT: 12 sets, 60s, 20s"
    var returnedCellText: String = ""
    
    //Variablers to Pass Data
    var setsDataPass: String = ""
    var activeDataPass : String = ""
    var restDataPass: String = ""
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.textArray.addObject(tabataWorkout)
        self.textArray.addObject(turbulenceWorkout)
        self.textArray.addObject(hiitWorkout)
        
        self.tableViewOutlet.rowHeight = UITableViewAutomaticDimension
        self.tableViewOutlet.estimatedRowHeight = 44.0
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.textArray.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell: UITableViewCell = self.tableView.dequeueReusableCellWithIdentifier("cell") as UITableViewCell!
        cell.textLabel?.text = self.textArray.objectAtIndex(indexPath.row) as? String
        
        return cell
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        let indexPath = tableView.indexPathForSelectedRow
        let currentCell = tableView.cellForRowAtIndexPath(indexPath!) as UITableViewCell!
        
        print(currentCell.textLabel!.text!)
        returnedCellText = currentCell.textLabel!.text!
        
        //Calling func to set parameteres for the pass
        setParameters(returnedCellText)

        performSegueWithIdentifier("passDataFrom", sender: self)
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject!) {
        if (segue.identifier == "passDataFrom") {
            let modalPush = segue.destinationViewController as! IntervalWorkoutViewController

            modalPush.setsReceiving = self.setsDataPass
            modalPush.activeReceiving = self.activeDataPass
            modalPush.restReceiving = self.restDataPass
        }
    }
    
    //Evaluates the content of the cell being tapped and sets the parameters to be passed accordingly
    func setParameters(input: String) {
        
        switch returnedCellText
        {
        case "Tabata: 8 sets, 20s, 10s":
            print("this is the tabata parameter")
            setsDataPass = "8"
            activeDataPass = "20"
            restDataPass = "10"
        case "Turbulence: 8 sets, 45s, 10s":
            print("this is the turbulence paramters")
            setsDataPass = "8"
            activeDataPass = "45"
            restDataPass = "10"
        case "HIIT: 12 sets, 60, 20s":
            print("this is the HIIT parameter")
            setsDataPass = "12"
            activeDataPass = "60"
            restDataPass = "20"
        default:
            print("there are no paramters")
        }
    }
}





