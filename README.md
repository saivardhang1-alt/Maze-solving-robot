# Maze-solving-robot
TO DESIGN AND IMPELEMNT A ROBOT THAT CAN AUTONOMOUSLY NAVIGATE AND SOLVE A MAZE.
# Maze Solving Robot

## Project Overview
An autonomous robot developed using Arduino UNO that navigates through a maze by detecting obstacles and selecting a direction based on available space.

## Hardware Components
- Arduino UNO
- 3 HC-SR04 Ultrasonic Sensors
- L298N Motor Driver
- 2 DC Motors
- Two-Wheel Robot Chassis
- Rechargeable Battery
- Breadboard and Jumper Wires

## Technologies Used
- Arduino UNO
- Embedded C/C++
- Arduino IDE
- Ultrasonic Distance Measurement
- Motor Control

## Working Principle
1. Ultrasonic sensors measure distances in front, left and right directions.
2. Arduino UNO processes the sensor readings.
3. The robot moves forward when the front path is clear.
4. When an obstacle is detected, it compares left and right distances.
5. The robot turns toward the side with more available space.

## Motor and Sensor Connections

| Component | Arduino Pins |
|---|---|
| Front sensor TRIG | 9 |
| Front sensor ECHO | 8 |
| Right sensor TRIG | 3 |
| Right sensor ECHO | 2 |
| Left sensor TRIG | 5 |
| Left sensor ECHO | 6 |
| Motor 1 | 10, 11 |
| Motor 2 | 12, 13 |
| ENA | 7 |
| ENB | 4 |

## Source Code
See `code/maze_solver.ino`.

## Project Status
Arduino program uploaded. Hardware testing and calibration required.
