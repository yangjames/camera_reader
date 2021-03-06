#!/usr/bin/env python

import time
import serial

ser = serial.Serial(
    port='/dev/video0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
    )
counter = 0

while True:
    x = ser.readline()
    print(x)
