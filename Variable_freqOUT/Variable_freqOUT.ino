

/*
  0 mph  = 1hz
  10 mph = 40hz
  20 mph = 80hz
  30 mph = 120hz
  50 mph = 200hz
  1  / (val * 2) = freqeuncy

  frequency = 3.9851 (velocity) + 0.527

  velocity(mph) = 30.651(pressure in kPa) + 62.954

  Pressure in kPa = 20mV

  Print out fequency
  Print out MPH
  Print out differential Pressure
  Input Sensors readings
  Ouput Square wave

  Don't update speed unless large change is seen
  Store current speed then check to see if new speed is different

*/
float result[2];
float difference;
float bias = 0.00;
const int inputPin1 = A0;
const int inputPin2 = A1;
const float cycleTime = 1.2;
float val = 1000;
float rho = 1.204; // density of air
float voltage;

const int potPin = A2;      // Potentiometer input pin
const int OutputPin = 12;    // Output pin
unsigned long wait = 0;     // variable to store the value coming from the sensor
unsigned long freq = 0;
int offset;

void setup() {
  Serial.begin(9600);
  pinMode(OutputPin, OUTPUT); // Set pin as output
  result[0] = (analogRead(inputPin1) + analogRead(inputPin1) + analogRead(inputPin1) + analogRead(inputPin1) + analogRead(inputPin1)) / 5;
  result[1] = (analogRead(inputPin2) + analogRead(inputPin2) + analogRead(inputPin2) + analogRead(inputPin2) + analogRead(inputPin2)) / 5;
  offset = analogRead(potPin);  // read the value from the sensor
  difference = result[0] - result[1];
  if (difference < 0) {
    bias = difference;
  }
}

void loop() {
  //float time1 = micros();
  result[0] = (analogRead(inputPin1) + analogRead(inputPin1) + analogRead(inputPin1) + analogRead(inputPin1) + analogRead(inputPin1)) / 5;
  result[1] = (analogRead(inputPin2) + analogRead(inputPin2) + analogRead(inputPin2) + analogRead(inputPin2) + analogRead(inputPin2)) / 5;
  difference = result[0] - result[1] - bias;
  //mph = (difference * 7.4904692082) + 62.954; // convert to mV voltage value then divide by 20mV to get kPa
  //val = 1 / (3.9851*( (difference * 7.4904692082) + 62.954)+0.527);
  val = -0.00007791964322 * difference + 0.001708922;
  //float time2 = micros();
  //Serial.println(time2 - time1);
  //float veloc = 0.0;
  //val = 1 / 2 * (3.222* difference + 0.527);
  //val = 1 / 2 * (8.9144295 * sqrt((10000.0 * ((difference / 1023.0) - 0.5)) / rho) + 0.527);
                 
  delay(val*1000 - cycleTime);            // MILLISECONDS delay calculated duration and subtract calculation time
  digitalWrite(OutputPin, HIGH);     // turn the ledPin on
  delay(val*1000);                        // stop the program for some time
  digitalWrite(OutputPin, LOW);      // turn the ledPin off
  
}
