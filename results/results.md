# PID Controller Project
## Self-Driving Car Engineer Nanodegree Program

### Tom Chmielenski
#### March 2018

----


In this project, I successfully implemented a PID Controller in C++ to manever the vehicle around the Term 2 simulator track.

---
To tune the Steering PID Controller, I manual tuned it by varying one parameter each run.  I mainly followed the steps indentified in the Forums - https://discussions.udacity.com/t/car-veering-off/312738/11

1.  Set Ki, Kd to zero, and find a Kp value that works.
2.  With Kp fixed, change Kd and slowly increasing Kd.
3.  Tune both Kp and Kd, to minimize oscillations.
4.  Tune Ki
5.  Once the steering controller is tuned, add in a second pid to control the throttle.

---

Here are the steps I took to manually tune this controller:

### Steering PID

|  Kp | Ki   | Kd  | Throttle  |Comments| Status |
|---|---|---|---|---|---|
| 1.00| 0.00  | 0  |  30 |   | | Unsuccessful |
| -0.50 | 0.00  | -0.50   | 30  | Starting point from Project Review video  | Unsuccessful
| -0.25 | 0.00  | -0.75  | 30  |   | Unsuccessful | 
|  -0.20 | 0.00  | -5.00  | 30  | First time successful  | Success
|  -0.20 | 0.00  | -5.00  | 50  | Increased speed to 50  | Successful lap, but oscillates back and forth across the lane. |
|  -0.20 | 0.00  | -10.00  | 50  | No significant difference to kd=-5.00  | Success
|  -0.20 | 0.0002  | -5.00  | 50  |Slightly better, osciallate at the end of the first lap | Success|
|  -0.20 | 0.00002  | -5.00  | 50  |Lost control need end of first lap | Unsuccessful|
|  -0.10 | 0.0002  | -5.00  | 50  | | Successful|
|  -0.15 | 0.0002  | -5.00  | 50  | | Successful|
|  -0.15 | 0.00002  | -5.00  | 50  | | Successful|
|  -0.15 | 0.00002  | -5.00  | 60  | Barely, touches edge of lane | Successful|
|  -0.15 | 0.0003  | -5.00  | 55  | Slightly Better, still close to edge of lane | Successful|
|  -0.15 | 0.00003  | -5.00  | 60  | not much difference | Successful|
|  -0.15 | 0.00003  | -5.00  | 30  | Successful at 30 as well | Successful|

I settled on the following parameters for my steering PID controller:

    Kp = -0.15
    Ki = 0.0003
    Kd = -5.00

One I had tuned the Steering PID controller, I chose to implement a simple Throttle
P controller as well.

    Kp = -0.10
    Ki =  0.00
    Kd =  0.00

After implementing both controllers, the vehicle navigated the course correctly at least 3 laps with a target speed up to 65 mph.  Here is a video showing the final results, with a constant speed of 59 mph.

---

[![PID Controller](PIDController.png)](https://www.youtube.com/watch?v=Dy2lb78cYIA")
