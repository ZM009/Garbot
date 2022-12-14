# Intended for controlling the robot using the keyboard input
# Temporary control file
import keyboard, serial
ser=serial.Serial('com4',4800)  # detects the cable that is connected to the robot's arduino
# while loop allows for control of the robot using the keyboard until someone enters ctrl^C on the keyboard.
while True:
    if keyboard.is_pressed('w') and keyboard.is_pressed('a'):
        ser.write(b'q')
        '''
        The three conditions are to turn the robot while driving: wd -> forward and right, etc.
        These amy be implemented if different wheels are used, otherwise, with the current fixed wheels, the button presses are not useful.
        '''
    elif keyboard.is_pressed('w') and keyboard.is_pressed('d'):
        ser.write(b'e')
    elif keyboard.is_pressed('s') and keyboard.is_pressed('a'):
        ser.write(b'z')
    elif keyboard.is_pressed('s') and keyboard.is_pressed('d'):
        ser.write(b'c')
    elif keyboard.is_pressed('w'):
        ser.write(b'f')  # if w is pressed, write the forward char to the arduino
    elif keyboard.is_pressed("s"):
        ser.write(b'b')  # if s is pressed, write the backward char command to the arduino
    elif keyboard.is_pressed("d"):
        ser.write(b'r')  # if d is pressed, write the left char command to the arduino
    elif keyboard.is_pressed("a"):
        ser.write(b'l')  # if a is pressed, write the left char command to the arduino
    #The folling are for opening and closing the hand    
    elif keyboard.is_pressed("o"):
        ser.write(b'o')  # if d is pressed, write the open char command to the arduino
    elif keyboard.is_pressed("k"):
        ser.write(b'k')  # if a is pressed, write the close char command to the arduino

        ''' Might be modified to control the arm whenever a specific key is pressed on the keyboard.
    elif keyboard.is_pressed(" "):
        ser.write(b'+')
    else:
        ser.write(b's')
        ser.write(b'-')
        '''