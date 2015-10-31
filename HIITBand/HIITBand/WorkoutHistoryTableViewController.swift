//
//  WorkoutHistoryTableViewController.swift
//  HIITBand
//
//  Created by Aaron  Batchelder on 6/28/15.
//  Copyright (c) 2015 Social Mason LLC. All rights reserved.
//

import Foundation
import UIKit


class WorkoutHistoryTableViewController: UITableViewController {
    var tableData = [String]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let path = NSBundle.mainBundle().pathForResource("TableData", ofType: "plist")
        let dict = NSDictionary(contentsOfFile: path!)
        
        tableData = dict!.objectForKey("WorkoutHistory") as! [String]
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Table view data source
    
    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        // Return the number of sections.
        return 1
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // Return the number of rows in the section.
        return tableData.count
    }
    
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath) 
        
        // Configure the cell...
        cell.textLabel!.text = tableData[indexPath.row]
        
        return cell
    }
}


