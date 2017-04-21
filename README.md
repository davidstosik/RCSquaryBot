# R.C. SquaryBot

*SquaryBot is not a Roundy, but it's remote-controlled.*

This is the Arduino code for the robot I'm building at [Tokyo HackerSpace
(THS)](http://tokyohackerspace.org).

# Operating

## Normal

Robot runs normally, accepts directions, accepts state changers.

Move:

- Up/Down: go front/rear
- Left/Right: rotate left/right
- Enter: immediate stop

Modes:

- Volume+: setup parallelism
- Volume-: setup 10cm timing
- Mute: setup 90º timing
- Senseye: setup proximity sensor

## Setup parallelism

Set the wheels parallelism in order to go straight in both front and rear
directions. To do so, it adjusts the angle instructions sent to the repurposed
servos (which is supposed to impact the servo's speed).

- Up/Down: go front/rear
- Enter: save setting and go back to normal mode
- *Power: cancel setting and go back to normal mode?* (to be defined)
- Volume+/-: increase/decrease angle value for left wheel going forward
- Resize/resolution: increase/decrease angle value for right wheel going forward
- Left/Menu: increase/decrease angle value for left wheel going backward
- Right/Exit: increase/decrease angle value for right wheel going backward

## Setup 10cm timing

Set up how long the servos need to rotate for the robot to progress 10cm.

- Up/Down: go front/rear
- Enter: save setting and go back to normal mode
- *Power: cancel setting and go back to normal mode?* (to be defined)
- Volume+/-: increase/decrease timing

## Setup 90º timing

Set up how long the servos need to rotate for the robot to rotate 90º.

- Left/Right: rotate left/right
- Enter: save setting and go back to normal mode
- *Power: cancel setting and go back to normal mode?* (to be defined)
- Volume+/-: increase/decrease timing

## Setup proximity sensor

Setup the safety distance at which the robot will stop from an object. This will
measure the current distance to object in front of the robot, and save it as
setting.

- Up/Down: go front/rear
- Enter: save setting and go back to normal mode
- *Power: cancel setting and go back to normal mode?* (to be defined)
