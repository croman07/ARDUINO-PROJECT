
#define Velocity 4000

//Define the variables to the pins 
int steps1 = 2; 
int steps2 = 4;
int direction1 = 3;
int direction2 = 5;
int passos = 200;
int reset1 = 9;
int reset2 = 10;
int x = 3;
int button1 = 11;
int button2 = 12;

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(steps1, OUTPUT);
  pinMode(steps2, OUTPUT);
  pinMode(direction1, OUTPUT);
  pinMode(direction2, OUTPUT);
  pinMode(reset1, OUTPUT);
  pinMode(reset2, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
if (button1 == LOW){
  line(200, true);   //front
  delay(1000);
}
if (button2 == LOW){
   line(200,false);  //back
  delay(1000);
}

  
  


}

void line (int p, boolean dir) {
  digitalWrite(direction1, dir);
  for (int i = 0; i < p; i++) {
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, HIGH);
    delayMicroseconds(Velocity);
    digitalWrite(steps1, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);
    delayMicroseconds(Velocity);
  }  
}



