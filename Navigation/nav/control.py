# Intended for controlling the robot using the keyboard input
# Temporary control file
import keyboard, serial
ser=serial.Serial('/dev/tty.usbmodem1101',9600)  # detects the cable that is connected to the robot's arduino
# while loop allows for control of the robot using the keyboard until someone enters ctrl^C on the keyboard.
while True:
    '''
    if keyboard.is_pressed('w') and keyboard.is_pressed('a'):
        ser.write(b'q')
        The three conditions are to turn the robot while driving: wd -> forward and right, etc.
        These amy be implemented if different wheels are used, otherwise, with the current fixed wheels, the button presses are not useful.

    elif keyboard.is_pressed('w') and keyboard.is_pressed('d'):
        ser.write(b'e')
    elif keyboard.is_pressed('s') and keyboard.is_pressed('a'):
        ser.write(b'z')
    elif keyboard.is_pressed('s') and keyboard.is_pressed('d'):
        ser.write(b'c')
        '''
    if keyboard.is_pressed('w'):
        ser.write(b'f')  # if w is pressed, write the forward char to the arduino
    elif keyboard.is_pressed('s'):
        ser.write(b'b')  # if s is pressed, write the backward char command to the arduino
    elif keyboard.is_pressed('d'):
        ser.write(b'r')  # if d is pressed, write the left char command to the arduino
    elif keyboard.is_pressed('a'):
        ser.write(b'l')  # if a is pressed, write the left char command to the arduino
    elif not keyboard.is_pressed('w') and not keyboard.is_pressed('s') and not keyboard.is_pressed('a') and not keyboard.is_pressed('d'):
        ser.write(b's')
