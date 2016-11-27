
#define Velocity 500


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
int volta = 800;
int turn90 = 4500;

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
  front(volta,true);  // line1
  delay(1000);

  rotationright(turn90,true);  //rotationB
  delay(1000);

  front(volta,true);  // line2
  delay(1000);

  rotationright(volta*5/4,true);  //rotationC
  delay(1000);

  front(volta*2,true);    //line3
  delay(1000);

  rotationright(turn90,true);  //rotationD
  delay(1000);

  front(volta*3,true);    //line4
  delay(1000);

  back(volta*3,true);  //line5
  delay(1000);

  rotationleft(turn90,true);  // rotationD
  delay(1000);

  front(volta*2,true);    //line6
  delay(1000);

  rotationright(turn90,true);  //rotationE
  delay(1000);

  front(volta*3,true);    //line7
  delay(1000);

  back(volta*3,true);  //line8
  delay(1000);

  rotationleft(turn90,true);  // rotationE
  delay(1000);

  front(volta*2,true);    //line9
  delay(1000);

  rotationright(turn90,true);  //rotationF
  delay(1000);

  front(volta*4.5,true);    //line10
  delay(1000);

  rotationleft(turn90,true);  // rotationG
  delay(1000);

  front(volta*2,true);    //line11
  delay(1000);

  rotationleft(turn90,true);  // rotationH
  delay(1000);

  front(volta*6,true);    //line12
  delay(1000);

  rotationleft(turn90,true);  // rotationI
  delay(1000);

  front(volta*2,true);    //line13
  delay(1000);

  rotationleft(volta*5/4,true);  // rotationJ
  delay(1000);

  front(volta*3,true);    //line14
  delay(1000);

  rotationleft(turn90,true);  // rotationK
  delay(1000);

  front(volta*2,true);    //line15
  delay(1000);

  rotationright(turn90,true);  // rotationL
  delay(1000);

  front(volta*1.5,true);    //line16
  delay(1000);

  rotationleft(turn90,true);  // rotationM
  delay(1000);

  front(volta*2,true);    //line17
  delay(1000);

  rotationleft(turn90,true);  // rotationN
  delay(1000);

  front(volta*3,true);    //line18
  delay(1000);

  rotationleft(turn90,true);  // rotationO
  delay(1000);

  front(volta*2,true);    //line19
  delay(1000);

  back(volta*2,true);  //line20
  delay(1000);

  rotationright(turn90,true);  // rotationO
  delay(1000);

  front(volta*1.5,true);    //line21
  delay(1000);

  rotationright(turn90,true); //rotationP
  delay(1000);

  front(volta*2, true);  //line22
  delay(1000);

  rotationright(turn90, true);  //rotationQ
  delay(1000);

  front(volta*6, true);  //line23
  delay(1000);

  rotationright(turn90, true);  //rotationR
  delay(1000);

  front(volta*2, true);    //line24
  delay(1000);

  rotationright(turn90, true);   //rotationS
  delay(1000);

  front(volta*3, true); //line25  
  delay(1000);

  rotationright(turn90, true); //rotationT
  delay(1000);

  front(volta*2, true); //line26  
  delay(1000);

  rotationright(turn90, true); //rotationU
  delay(1000);

  front(volta*1.5, true); //line27  
  delay(1000);

  rotationleft(turn90,true);  // rotationV
  delay(1000);

  front(volta*2, true); //line28 
  delay(1000);

  rotationleft(turn90,true);  // rotationW
  delay(1000);

  front(volta*3, true); //line29 
  delay(1000);

  rotationleft(turn90,true);  // rotationX
  delay(1000);

  front(volta*2, true); //line29 
  delay(10000);
  
}

void front (int p, boolean dir) {
  digitalWrite(direction1, true);
  digitalWrite(direction2, false);
  for (int i = 0; i < p; i++) {
    digitalWrite(steps1, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);
    delayMicroseconds(Velocity);
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, HIGH);
    delayMicroseconds(Velocity);
  }  
}

void back (int p, boolean dir) {
  digitalWrite(direction1, false);
  digitalWrite(direction2, true);
  for (int i = 0; i < p; i++) {
    digitalWrite(steps1, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);
    delayMicroseconds(Velocity);
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, HIGH);
    delayMicroseconds(Velocity);
  }  
}

void rotationleft (int p, boolean dir) {
  digitalWrite(direction1, true);
  digitalWrite(direction2, true);
  for (int i = 0; i < p; i++) {
    digitalWrite(steps1, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);
    delayMicroseconds(Velocity);
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, HIGH);
    delayMicroseconds(Velocity);
  }  
}

void rotationright (int p, boolean dir) {
  digitalWrite(direction1, false);
  digitalWrite(direction2, false);
  for (int i = 0; i < p; i++) {
    digitalWrite(steps1, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);
    delayMicroseconds(Velocity);
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, HIGH);
    delayMicroseconds(Velocity);
  }  
}

/*void 2velocitats (int a, int b){

  if (millis()%1000 ==0){
    
    digitalWrite (steps1,HIGH);
    
  }else if (millis()%1001   
}*/



