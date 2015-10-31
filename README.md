# TabataExerciseBand-MetaWear

#Synopsis

This iOS app is a basic interface for using an mbientlab MetaWear board (more info at https://mbientlab.com) as an interval training band. It's purpose is to act as a customizable interval trainer and also use standard intervals such as tabata, etc..  


#Motivation

I had this idea prior to taking a Swift course, and ended up using it as a final project. I exercise fairly frequently and because I'm often short on time I do tabata workouts (20 seconds of work, 10 seconds rest, 8 rounds). That said headphone wires get in the way, and loud beeping timers at the gym are annoying for everyone which is why I wanted to create this band. mbientLab has an amazing little microcontroller with everything you'd want along with a silicon band so you can wear it on your wrist.

Other applications can be a hands-off time tracker when cycling or running to let you keep a general idea of pace (e.g., vibrations every 5 minutes).


#Installation

This has "out-of-the-box" functionality and should connect directly to your metawear board and allow you to set custom intervals as long as the software updates for the board haven't deprecated the code.'

It's worth noting that the bridging-header.h file may give you some issues. In that case you'll have to manually input the folder path location of the file on your build under "Build Settings".


#API Reference

Reference to the Metawear board SDK can be found at https://mbientlab.com/iosdocs/#intro.


#Contributors

I'd be happy to have contributors to project. There are some pretty glaring errors with the timer display and some basis timer functionality in general that I haven't had time to fix. Code refactoring is another area in need of improvement - I acknowledge this is a fairly messy project overall, though just don't have the time to improve it.'I can be reached at @aaronbatcheldr if you're interested.'

Additionally some features that would make this more of a useful app would be:
    -Basic persistence for the workout history tableView so you can easily grab and track past workouts
    -Tutorial improvements
    -Ability to customize certain exercises for each interval with the app prompting the user to do it


#License

General License: Anything for personal use.

Metawear License: https://github.com/mbientlab/Metawear-SampleiOSApp/blob/master/LICENSE