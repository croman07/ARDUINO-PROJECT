  
/*Motor speed controller: 
If the value is small, the engine turns fast. 
If the value is large, the engine turns slow. */
#define Velocity 400  

//Variable definitions:
// constants won't change. They're used here to
// set pin numbers

int steps1 = 2;       // the number of the steps pin by motor 1
int steps2 = 4;       // the number of the steps pin by motor 2
int direction1 = 3;   // the number of the direction pin by motor 1
int direction2 = 5;   // the number of the direction pin by motor 2
int passos = 200;     // the number of the steps that the motor makes in a turn
int reset1 = 9;       // the number of the reset pin by motor 1
int reset2 = 10;      // the number of the reset pin by motor 2
int button1 = 13;     // the number of the pushbutton pin 1
int button2 = 12;     // the number of the pushbutton pin 2
int button3 = 11;     // the number of the pushbutton pin 3
int volta = 1248;     // The number that makes the motor when does when I tell it to make a "volta"
int t = 100;          // Time waiting for the car to perform an action behind another
int turn90 = 3075;    // Turns you have to make the car to rotate 90 degrees
int turn60 = 4050;    // Turns you have to make the car to rotate 60 degrees
int p2 = 0;           // the number of multiplier that tells us how fast one engine is more than another
int l = 0;            // defined the lastcurrent of the button 1
int l1 = 0;           // defined the lastcurrent of the button 2
int l2 = 0;           // defined the lastcurrent of the button 3
int c = 0;            // defined the current number of the button 1
int c1 = 0;           // defined the current number of the button 2
int c2 = 0;           // defined the current number of the button 3


void setup() {
  // initialize the moviment motor pin as an output:
  pinMode(steps1, OUTPUT);
  pinMode(steps2, OUTPUT);
  pinMode(direction1, OUTPUT);
  pinMode(direction2, OUTPUT);
  pinMode(reset1, OUTPUT);
  pinMode(reset2, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  
  Serial.begin (9600);
  
}

void loop() {
  // save the current state as the last state,
  //for next time through the loop
  l = c;                  //button 1             
  l1 = c1;                //button 2               
  l2 = c2;                //button 3

  // read the current pushbutton input pin:
  c = digitalRead(13);    //button 1
  c1 = digitalRead(12);   //button 2
  c2 = digitalRead(11);   //button 3

   // Delay a little bit to avoid bouncing
  delay(30);

  if (c == 0 && l == 1){      //When you press the first button that pass the following:
 tresenratlla (turn90, 1000, t, true);
  //xerranca (turn90, volta, t, true);
 
 
  

  }

  if (c1 ==0 && l1 ==1){        // When you press the second button that pass the following
// tresenratlla (turn90, volta*3, t, true);
archright (volta,2, true);
  }
  


  if (c2 ==0 && l2 ==1){         // When you press the third button that pass the following
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
    rotation (turn90 + 150 , true);
    square (volta, true);
  }


}


// Function to create a straight line

void straight (int p, boolean dir) {       
  // We define "p" as long as we want it to be the straight line 
  // We define "dir" to go forward or backward: true = front & false = Back
  digitalWrite(direction1, !dir);     // if the motor 1 goes forward
  digitalWrite(direction2, !dir);     // the motor 2 goes forward, or the opposite
  
  for (int i = 0; i < p; i++) {       //While "i" is smaller than "p", which I saw repeating it by adding one. 
                                      //It is equivalent to the number of turns (200 is 360 degrees) or micropas
    digitalWrite(steps1, LOW);        // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);        
    delayMicroseconds(Velocity);      // It regulates the speed, the lower the speed.
    digitalWrite(steps1, HIGH);       // to the A4988 (driver) to advance once per power pulse.
    digitalWrite(steps2, HIGH);       
    delayMicroseconds(Velocity);      // It regulates the speed, the lower the speed.
  }
}


// Function to create a rotation:

void rotation (int p, boolean dir) {
  // We define "p" as long as we want it to turn
  // We define "dir" to turn left or right: true = left & false = right
  digitalWrite(direction1, dir);      // the motor 1 goes forward
  digitalWrite(direction2, !dir);     // the motor 2 goes backward, or the opposite
  
  for (int i = 0; i < p; i++) {       // While "i" is smaller than "p", which I saw repeating it by adding one. 
                                      //It is equivalent to the number of turns (200 is 360 degrees) or micropas
    digitalWrite(steps1, LOW);        // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW);        
    delayMicroseconds(Velocity);      // It regulates the speed, the lower the speed.
    digitalWrite(steps1, HIGH);       // to the A4988 (driver) to advance once per power pulse.
    digitalWrite(steps2, HIGH);       
    delayMicroseconds(Velocity);      // It regulates the speed, the lower the speed.
  }
}



// Function to create a left arch:

void archleft (int p, int p2, boolean dir) {
  // We define "p" as long as we want it to turn
  // We define "p2" that is the number of multiplier that tells us how fast one engine is more than another
  // We define "dir" to go left or right: true = left (forward) & false = right (backward)
  digitalWrite(direction1, dir);      // the motor 1 goes forward
  digitalWrite(direction2, !dir);     // the motor 2 goes backward, or the opposite
  
  for (int i = 0; i < p; i++) { 
    digitalWrite(steps1, LOW);
    delayMicroseconds(Velocity);  
    digitalWrite(steps1, HIGH);
    delayMicroseconds(Velocity);

    for (int j = 0; j < p2; j++) {
      digitalWrite(steps2, LOW);
      delayMicroseconds(Velocity);
      digitalWrite(steps2, HIGH);
      delayMicroseconds(Velocity);
    }

  }
}

// Function to create a right arch:

void archright (int p, int p2, boolean dir) {
  // We define "p" as long as we want it to turn
  // We define "p2" that is the number of multiplier that tells us how fast one engine is more than another
  // We define "dir" to go left or right: true = right (forword) & false = left (backward)
  digitalWrite(direction1, dir);
  digitalWrite(direction2, !dir);

  
  for (int i = 0; i < p; i++) {
    digitalWrite(steps2, LOW);  
    delayMicroseconds(Velocity);
    digitalWrite(steps2, HIGH);  
    delayMicroseconds(Velocity);

    for (int j = 0; j < p2; j++) {
      digitalWrite(steps1, LOW);
      delayMicroseconds(Velocity);
      digitalWrite(steps1, HIGH);
      delayMicroseconds(Velocity);
    }

  }
}


// Function to create a square:

void square (int p, boolean dir){
// We define "p" as long as we want it to be the straight line 
// We define "dir" to go forward or backward: true = front & false = Back
// We define "dir" to turn 90 degrees left or right: true = right & false = left
straight (p, dir);         // Make a straight (p = long & dir = forward)
rotation (turn90, !dir);    // rotate right 90 degrees
straight (p, dir);         // Make a straight (p = long & dir = forward)
rotation (turn90, !dir);    // rotate right 90 degrees
straight (p, dir);         // Make a straight (p = long & dir = forward)
rotation (turn90, !dir);    // rotate right 90 degrees
straight (p, dir);         // Make a straight (p = long & dir = forward)
}


// Function to create a triangle:

void triangle (int p, boolean dir){
// We define "p" as long as we want it to be the straight line 
// We define "dir" to go forward or backward: true = front & false = Back
// We define "dir" to turn 60 degrees left or right: true = right & false = left
straight (p, dir);          // Make a straight (p = long & dir = forward)
rotation (turn60, !dir);    // rotate right 60 degrees
straight (p, dir);          // Make a straight (p = long & dir = forward)
rotation (turn60, !dir);    // rotate right 60 degrees
straight (p, dir);          // Make a straight (p = long & dir = forward)
}


// Function to create a "xerranca":

void xerranca (int turn, int p, int temps, boolean dir){
// We define "turn" to turn degrees left or right: true = right & false = left
// We define "p" as long as we want it to be the straight line 
// We define "temps" as time waiting for the car to perform an action behind another
// We define "dir" to turn 90 degrees left or right: true = right & false = lef
 straight(p*6,dir);  // line1
  delay(temps);

  rotation(turn,!dir);  //rotationB
  delay(temps);

  straight(p*3,dir);  // line2
  delay(temps);

  rotation(turn,!dir);  //rotationC
  delay(temps);

  straight(p*2,dir);    //line3
  delay(temps);

  rotation(turn,!dir);  //rotationD
  delay(temps);

  straight(p*3, dir);    //line4
  delay(temps);

  straight(p*3,!dir);  //line5
  delay(temps);

  rotation(turn,dir);  // rotationD
  delay(temps);

  straight(p*2,dir);    //line6
  delay(temps);

  rotation(turn,!dir);  //rotationE
  delay(temps);

  straight(p*3,dir);    //line7
  delay(temps);

  straight(p*3,!dir);  //line8
  delay(temps);

  rotation(turn,dir);  // rotationE
  delay(temps);

  straight(p*2,dir);    //line9
  delay(temps);

  rotation(turn,!dir);  //rotationF
  delay(temps);

  straight(p*4.5,dir);    //line10
  delay(temps);

  rotation(turn,dir);  // rotationG
   delay(temps);

  straight(p*2,dir);    //line11
  delay(temps);

  rotation(turn,dir);  // rotationH
  delay(temps);

  straight(p*6,dir);    //line12
  delay(temps);

  rotation(turn,dir);  // rotationI
  delay(temps);

  straight(p*2,dir);    //line13
  delay(temps);

  rotation(turn,dir);  // rotationJ
  delay(temps);

  straight(p*3,dir);    //line14
  delay(temps);

  rotation(turn,dir);  // rotationK
  delay(temps);

  straight(p*2,dir);    //line15
  delay(temps);

  rotation(turn,!dir);  // rotationL
  delay(temps);

  straight(p*1.5,dir);    //line16
  delay(temps);

  rotation(turn,dir);  // rotationM
  delay(temps);

  straight(p*2,dir);    //line17
  delay(temps);

  rotation(turn,dir);  // rotationN
  delay(temps);

  straight(p*3,dir);    //line18
delay(temps);

  rotation(turn,dir);  // rotationO
  delay(temps);

  straight(p*2,dir);    //line19
  delay(temps);

  straight(p*2,!dir);  //line20
  delay(temps);

  rotation(turn,!dir);  // rotationO
  delay(temps);

  straight(p*1.5,dir);    //line21
  delay(temps);

  rotation(turn,!dir); //rotationP
  delay(temps);

  straight(p*2, dir);  //line22
  delay(temps);

  rotation(turn, !dir);  //rotationQ
  delay(temps);

  straight(p*6, dir);  //line23
  delay(temps);

  rotation(turn, !dir);  //rotationR
  delay(temps);

  straight(p*2, dir);    //line24
  delay(temps);

  rotation(turn, !dir);   //rotationS
  delay(temps);

  straight(p*3, dir); //line25  
  delay(temps);

  rotation(turn, !dir); //rotationT
  delay(temps);

  straight(p*2, dir); //line26  
  delay(temps);

  rotation(turn, !dir); //rotationU
  delay(temps);

  straight(p*1.5, dir); //line27  
  delay(temps);

  rotation(turn, dir);  // rotationV
  delay(temps);

  straight(p*2, dir); //line28 
  delay(temps);

  rotation(turn,dir);  // rotationW
  delay(temps);

 straight(p*3, dir); //line29 
  delay(temps);

  rotation(turn,dir);  // rotationX
  delay(temps);

  straight(p*2, dir); //line29 
  delay(temps);
  
}


// Function to create a "tres en ratlla":

void tresenratlla (int turn, int p, int temps, boolean dir){
// We define "turn" to turn degrees left or right: true = right & false = left
// We define "p" as long as we want it to be the straight line 
// We define "temps" as time waiting for the car to perform an action behind another
// We define "dir" to turn 90 degrees left or right: true = right & false = lef
  straight(p*3,dir); //front 1 (A - B)
  delay (temps);
  
  rotation(turn,!dir);  //rotationB
  delay(temps);

  straight(p*3,dir); //front 2 (B - C)
  delay (temps);

  rotation(turn,!dir);  //rotationC
  delay(temps);

  straight(p*3,dir); //front 3 (C - D)
  delay (temps);

  rotation(turn,!dir);  //rotationD
  delay(temps);

  straight(p*3,dir); //front 4 (D - A)
  delay (temps);

  rotation(turn,!dir);  //rotationA
  delay(temps);

  straight(p,dir); //front 5 (A - E)
  delay (temps);

  rotation(turn,!dir);  //rotationE
  delay(temps);

  straight(p*3,dir); //front 6 (E - F)
  delay (temps);

  rotation(turn,dir);  // rotationF
  delay(temps);

  straight(p,dir); //front 7 (F - G)
  delay (temps);

  rotation(turn, dir);  // rotationG
  delay(temps);

  straight(p*3,dir); //front 8 (G - H)
  delay (temps);

  rotation(turn,!dir);  //rotationH
  delay(temps);

  straight(p,dir); //front 9 (H - B2)
  delay (temps);

  rotation(turn,!dir);  //rotationB2
  delay(temps);

  straight(p,dir); //front 10 (B2 - I)
  delay (temps);

  rotation(turn,!dir);  //rotationI
  delay(temps);

  straight(p*3,dir); //front 11 (I - J)
  delay (temps);

  rotation(turn,dir);  // rotationJ
  delay(temps);

  straight(p,dir); //front 12 (J - K)
  delay (temps);

  rotation(turn,dir);  // rotationK
  delay(temps);

  straight(p*3,dir); //front 13 (K - L)
  delay (temps);
 
 }


