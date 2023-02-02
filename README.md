# Object_Follower_bot
Object following robot using Arduino
# About this project
In this project I have made an object following robot based on Arduino that uses proximity sensors like ultrasonic and infrared sensors(IR) to identify and track objects like the human hand and follow it. Here we have used 2 IR sensors to detect an object in the left or right direction while the ultrasonic sensor will detect the object in front of it and measure the object distance from the bot. The distance calculated will also be used to maintain a safe distance at which the bot could follow the object without colliding with it.

# Structure of the bot
I have made a 4 wheeled robot with a regular metal chassis and 12 volt geared DC motors. To control the motors I have used L298N motor driver module

![Object foloowing robot](https://user-images.githubusercontent.com/93535446/216448418-0fb8ee61-2d87-4ea0-a25d-417bc885d070.jpg)

# Data flow diagram
Algorithm of how the robot works
![DFD_ObjFollower](https://user-images.githubusercontent.com/93535446/216451206-3d56571b-a975-45b0-8a71-d1732023714e.png)





