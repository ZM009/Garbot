# Intended for controlling the robot using the keyboard input
# Temporary control file
import keyboard, serial
bluetooth=serial.Serial('com5',9600)  # detects the cable that is connected to the robot's arduino
# while loop allows for control of the robot using the keyboard until someone enters ctrl^C on the keyboard.
while True:
    if keyboard.is_pressed('w'):
        bluetooth.write(b'f')  # if w is pressed, write the forward char to the arduino
    elif keyboard.is_pressed('s'):
        bluetooth.write(b'b')  # if s is pressed, write the backward char command to the arduino
    elif keyboard.is_pressed('d'):
        bluetooth.write(b'r')  # if d is pressed, write the left char command to the arduino
    elif keyboard.is_pressed('a'):
        bluetooth.write(b'l')  # if a is pressed, write the left char command to the arduino
    else:
        bluetooth.write(b's')
