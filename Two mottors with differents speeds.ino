
#define Velocity 6000
#define Velocity 8000

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
int volta = 200;

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

void loop() {
//if (button1 == LOW){
 // xerranca(200, true);   //front
 

//if (button2 == LOW){
  line(volta,true);  // line1
  delay(1000);
  
  
  }

void line (int volta, boolean dir) {
  digitalWrite(direction1, true);
  digitalWrite(direction2, false);
  for (int i = 0; i < volta; i++) {
    digitalWrite(steps1, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);
    delayMicroseconds(Velocity);
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, HIGH);
    delayMicroseconds(Velocity);
  }  
}

