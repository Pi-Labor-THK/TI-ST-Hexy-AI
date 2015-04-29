#!/usr/bin/python3
'''
Created on 16.02.2015
@author: lukasdavidphillipminas
'''

import time
from SerialWrapper import SerialWrapper
from Speed import Speed
from Servo import Servo

SW = SerialWrapper("/dev/ttyACM0")
SW.StandUp()


i=300
zaehler = 0

while i > 0:
    cm = SW.GetDistance(90)
    print(cm)
    SW.BeginMove(90,Speed.Fast)
    
    if cm <= 17 and cm != 0:
       	SW.EndMove() 
        SW.Turn(90)
        zaehler += 1
        if zaehler ==2:
            SW.turn(175)
            zaehler = 0

    SW.BeginMove(90,Speed.Fast)


SW.CloseSerial()

