# Arduino Stepper

## Explanation:

### Power Supply:

The positive terminal of the 12V power supply is connected to the positive terminals of both solenoids.
The negative terminal of the 12V power supply is connected to the ground.

### Pins Setup:
inputPin is set to pin 0.
outputPinA and outputPinB are set to pins 3 and 4 respectively.

### Interval Calculation:
The interval for switching solenoids is calculated as 1000 / 60, which gives approximately 16.67 milliseconds (60 Hz frequency).

T=1/60
T≈0.0167 seconds

In milliseconds:

Period (in milliseconds) = 0.0167 × 1000
Period (in milliseconds) ≈ 16.67  milliseconds

So, for a signal with a frequency of 60 Hz, each cycle takes approximately 16.67 milliseconds to complete.
You want to switch solenoids at a frequency of 60 Hz, you would need to alternate between solenoids approximately every 16.67 milliseconds to achieve that.

### State Management:
A boolean solenoidState keeps track of which solenoid is currently active.

### Loop Function:
The loop function reads the state of the input pin.
If the input is HIGH, it checks if the interval has passed using millis() and switches the solenoids accordingly.
If the input is LOW, both solenoids are turned off.