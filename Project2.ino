// Projects Book Project 2: Spaceship Interface

// Switch state variable
int switchState = 0;

void setup() {

  //Sets up the pins to be input or output
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Reads the state of the switch
  switchState = digitalRead(2);

  // If button is not pressed
  if (switchState == LOW) {

    digitalWrite(3, HIGH);  // Green LED
    digitalWrite(4, LOW);   // Red LED
    digitalWrite(5, LOW);   // Red LED
    
  }

  // If button is pressed
  else {

    digitalWrite(3, LOW);  // Green LED
    digitalWrite(4, HIGH);   // Red LED
    digitalWrite(5, HIGH);   // Red LED

    delay(250);   // Wait for a quarter second before rechecking
    digitalWrite(4, HIGH);   // Red LED
    digitalWrite(5, LOW);   // Red LED
    delay(250);   // Wait for a quarter second before rechecking

  }

}
