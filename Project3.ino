const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup() {
  // put your setup code here, to run once:

  // Opens serial port
  Serial.begin(9600);

  // Set all pins to default locations
  for(int pinNumber = 2; pinNumber<5; pinNumber++) {

    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);

    
  }


}

void loop() {
  // put your main code here, to run repeatedly:

  // Read in and store sensor value, temp
  int sensorVal = analogRead(sensorPin);

  // Print sensor value
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Convert ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  // Convert voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;

  Serial.print(", Degrees C: ");
  Serial.println(temperature);

  if(temperature < baselineTemp+2) {

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
  }

  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4) {

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

    
  }

    else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6) {

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

    
  }

    else if(temperature >= baselineTemp+6) {

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);

    
  }

  delay(1);

}

