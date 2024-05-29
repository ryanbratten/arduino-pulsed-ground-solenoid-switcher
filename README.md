# Arduino Stepper

## Explanation:

### Power Supply:

The positive terminal of the 12V power supply is connected to the positive terminals of both solenoids.
The negative terminal of the 12V power supply is connected to the ground.

### Pins Setup:

inputPin is set to pin 2.
outputPinA and outputPinB are set to pins 3 and 4 respectively.

### Interval Calculation:

The interval for switching solenoids is calculated as 1000 / 60, which gives approximately 16.67 milliseconds (60 Hz
frequency).

T=1/60
T≈0.0167 seconds

In milliseconds:

Period(in milliseconds) = 0.0167 × 1000
Period(in milliseconds) ≈ 16.67 milliseconds

So, for a signal with a frequency of 60 Hz, each cycle takes approximately 16.67 milliseconds to complete.
You want to switch solenoids at a frequency of 60 Hz, you would need to alternate between solenoids approximately every
16.67 milliseconds to achieve that.

### State Management:

A boolean solenoidState keeps track of which solenoid is currently active.

### Pulsed Ground Input:

The code checks if the input pin (inputPin) is LOW, indicating that the input signal is grounded.

### Loop Function:

Within the loop() function, the Arduino continuously reads the state of the input pin using digitalRead().
If the input pin reads LOW, it indicates that the input signal is grounded.

### Interval Checking with millis():

Once the Arduino detects that the input is LOW (grounded), it starts a timer using millis(). millis() returns the number
of milliseconds since the Arduino board started running the current program.
The Arduino then checks if a certain interval has passed since the timer started. This interval is the time required to
switch between solenoids at a frequency of 60 Hz.

### Solenoid Switching:

If the interval has passed, the Arduino toggles the state of the solenoids (solenoidState). If solenoidState is true, it
switches on outputPinA and switches off outputPinB, and vice versa.
This switching action ensures that the solenoids are alternately activated based on the pulsed ground input signal.

### Turning Off Solenoids:

If the input pin reads HIGH (not grounded), it indicates that the input signal is in the HIGH state.
In this case, both solenoids are turned off (digitalWrite(outputPinA, LOW) and digitalWrite(outputPinB, LOW)) to
maintain the system's state.

## Summary:

The Arduino continuously checks if the input pin is grounded (LOW).
If the input is grounded, the Arduino starts a timer to keep track of the interval for switching solenoids.
Once the interval has passed, the Arduino alternately activates the solenoids based on the pulsed ground input signal.
If the input is not grounded (HIGH), both solenoids are turned off to maintain the system's state.