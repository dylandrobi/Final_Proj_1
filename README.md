<img width="351" alt="WakeAndShakeLogo" src="https://github.com/dylandrobi/WakeAndShake/assets/124712580/98c10d20-e7e6-4064-931c-b74bd02136cf">

Team: "E.C. Going" Dylan Robichaud and Gabi Acosta

Course name: ECE-218: Embedded Microcontroller Projects

Course professor: Cherrice Traver

Textbook used: Arm - "A Beginner’s Guide to Designing Embedded System Applications on Arm Cortex-M Microcontrollers" by Ariel Lutenberg, Pablo Gomez, Eric Pernia.

Summary of behavior: The user is allowed to set the alarm date and current time using their PC keyboard and serial monitor. The current time and the alarm time are compared, if they are equal, the alarm is activated. When the alarm is activated, the buzzer, IR sensor, RGB LED and servo motor are all activated. When the alarm is activated, the servo motor is turned on to remove the blanket off the bed. The servo motor stays on for 8 seconds then it stops rotating. The buzzer and RGB LED stays on until the IR sensor detects motion for 20 straight seconds, then the alarm is deactivated. After the deactivation of the alarm, the LED stays on if there isn’t enough light being sensed in the room by the LDR or else the LED turns off.

Detailed Project Summary: [M3_ Results Summary - Dylan  Gabi  (1).pdf](https://github.com/dylandrobi/WakeAndShake1795/files/11735309/M3_.Results.Summary.-.Dylan.Gabi.1.pdf)

Project Video Summary: https://www.youtube.com/watch?v=7vTegn_WqNc

List of Modules: Alarm Clock System - This module calls the initial functions of the hardware components as well as the update functions. This module is the only system. This code was based on the textbook.

Alarm - This module initializes and activates the hardware components when the alarm time is set. The module also deactivates the alarm and the buzzer. This code was partially written from scratch and the textbook.

Date and Time - This is where the live date is being constantly updated every second. Also, it is where the live time is being displayed onto the LCD.It does this using the RTC peripheral. This code was influenced by the textbook, and we added our own public function and variable.

Display - This module programs the LCD display. It can clear the screen and set the cursor to the screen. This code was based on the textbook code.

IR Sensor - When the alarm is activated, the IR sensor is activated. To deactivate the alarm the IR sensor is programmed to detect 20 straight seconds of motion. If motion is not detected the IR sensor waits to detect motion. If motion is detected for less than 20 seconds then the accumulated time is restarted. This code was written from scratch.

LDR sensor - the voltage of the sensor is used to detect if there is enough light in the room after the alarm is deactivated. If the average of the past 10 sample voltages of the LDR reading is less than 0.2V, the LED remains on. This code is based on an exercise we did in Chapter 5.

PC Serial Com - This module controls the PC monitor. The monitor is programmed to, show and set the alarm time and the current date and time and available commands. The user is also able to set the current date and time and also the alarm time using the PC keyboard. This code was influenced by the textbook code.

RGB LED - The LED is turned on when the alarm is activated. Once the alarm is deactivated,it only turns off when there is enough light being detected in the room by the LDR sensor. That is if the LDR voltage is greater than 0.2V.

Servo motor - When the alarm is activated, the servo motor turns on and removes the blanket from the bed. After eight seconds the servo motor turns off. To turn the motor on the duty cycle is set to 0.015 and to stop the motor it is set to 0. This code was based from scratch as it is a continuous servo motor.

Siren - When the alarm is activated, the buzzer is sent a low signal. The buzzer begins ringing. The buzzer only stops ringing when the alarm is deactivated. This code was based on the textbook.

User Interface - The user interface activates the alarm if the current time is equal to the alarm time. It also shows the current time and if the alarm is set on the LCD display. There is also a welcome message that directs the user to the PC serial monitor. This code was influenced from online and written from scratch.

List of Hardware components connected to the Nucleo board and their pins Buzzer - PE10 Servo Motor - PF9
IR Sensor Receptor - PD14 (D10) RGB LED - redLED - PA7(D11) blueLED - PA6(D12) greenLED - PA5(D13) LDR Sensor - PC3 (A2) LCD Display: Pin 4 - PF9 Pin 6 - PF12 Pin 7 - PG9 (D0) Pin 8 - PG14 (D1) Pin 9 - PF15 (D2) Pin 10 - PE13 (D3) Pin 11 - PF14 (D4) Pin 12 - PE11 (D5) Pin 13 - PE9 (D6) Pin 14 - PF13 (D7)

A description of the tests you performed on the system, and the results. Once we created the system, we ran various tests to assure that it worked. One test we ran was making sure the time was constantly being displayed and updated on the LCD display. We tested this by entering in various times throughout the day and watching it be displayed and updated every second on the LCD display. We even entered at 23:59:00 and watched it go all the way to 00:00:00 to ensure a smooth transition between different days.

The most important test we ran was making sure the alarm went off when the live time reached the alarm time. In order to test this, we would set the live time to the current time, and then set the alarm time for 10 seconds afterward. After many trial and errors, we got the alarm functions to activate when the time on the LCD struck the alarm time.

The next test was determining if the major functions behaved properly once the alarm went off. To test this, we counted that the motor would turn for 8 seconds in the clockwise direction, observed the LED turning on and that the buzzer was working properly and loud enough.

We then tested the sensor by writing to the serial monitor every single second whether motion was detected or not. We made sure that the code was working by placing our hand in between the sensors, and making sure that the serial monitor read “Motion is being detected” and also that after three seconds of consecutively blocking it, it would read “Have a good day!”, stop writing out if there was detection, and the alarm would turn off. We also ran tests to ensure that the alarm would stay on if the user blocked the sensor for one second intervals three times in total.

Lastly, we had to make sure that the LDR sensor behaved correctly. The RGB LED would turn on and off based on the light in the room once the alarm was deactivated. To test this, we would turn on a bright light in the room. At this moment, the RGB LED would remain off. But once we covered our hand over the LED, it turned off. It was able to turn on and off at the same time we moved our hand on and off of it.

Other Details that can help the reader understand the code.

The variable alarmState and postAlarmState are both initialized as public boolean variables in alarm.cpp. The purpose of this is so that different modules, such as ir_sensor.cpp and RGB_led.cpp can know the state of these variables (ON/OFF) in order to know when to run their functions → turning on the LED based off LDR sensor readings and access the deactivation of alarm by means of the ir sensor.
