//float SensorValue[5][2];
char j, k;
float result[2];
const int inputPin1 = A1;
const int inputPin2 = A0;
float time1;
float time2;

void serialEventRun() {}

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  Serial.print("Port1");
  Serial.print("\t");
  Serial.print("Port2");
  Serial.print("\t");
  Serial.print("difference");
  Serial.println();
}

void loop() {  
  time1 =  micros();
  result[0] = 0.00;
  result[1] = 0.00;
  /*
   for (j = 0; j < 10; j++) {
    
    result[0] += SensorValue[j][0] = analogRead(inputPin1);
    result[1] += SensorValue[j][1] = analogRead(inputPin2);
  }
 */
  // we now have 10 readings, so average them
  //memset(result,0,sizeof(result));
  //Serial.print(result);
  //Serial.println();
  //result1 = 0
  //for (j = 0; j < 10; j++) {
  //  result[0] = result[0] + SensorValue[j][0]; // add them up
  //  result[1] = result[1] + SensorValue[j][1];
  //}
  result[0] = (analogRead(inputPin1)+analogRead(inputPin1)+analogRead(inputPin1)+analogRead(inputPin1)+analogRead(inputPin1)) / 5;
  result[1] = (analogRead(inputPin2)+analogRead(inputPin2)+analogRead(inputPin2)+analogRead(inputPin2)+analogRead(inputPin2)) / 5;
  //ResultkPa1 = (SensorValue*(.00488)/(.022)+20);
  time2 = micros();
  
  Serial.print(result[0]);
  Serial.print(",");
  Serial.print(result[1]);
  Serial.print(",");
  Serial.print(result[0]-result[1]);
  Serial.print(",");
  Serial.print(time2 - time1);
  Serial.println();
 
}
