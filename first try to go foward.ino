
#define Velocity 4000


int steps1 = 2;
int steps2 = 4;
int direction1 = 3;
int direction2 = 5;
int passos = 200;
int reset1 = 9;
int reset2 = 10;
int x = 3;

void setup() {

  pinMode(steps1,OUTPUT);
  pinMode(steps2,OUTPUT);
  pinMode(direction1,OUTPUT);
  pinMode(direction2,OUTPUT);
  pinMode(reset1,OUTPUT);
  pinMode(reset2,OUTPUT);
}

void loop(){
  digitalWrite(reset1, LOW);    //Mientras reset este en LOW el motor permanecerá apagado y no sufrirá. El chip apagará todos los puertos y no leerá comandos.
  digitalWrite(reset2, LOW);
  delay(100);
  digitalWrite(reset1, HIGH);//Cuando reset se encuentre en HIGH el motor arrancará y leerá los comandos enviados.
  digitalWrite(reset2, HIGH);
  digitalWrite(direction1, HIGH);
  digitalWrite(direction2, HIGH);

  for (int i = 0; i<passos*x; i++){
    digitalWrite(steps1, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps1, LOW); // al A4988 de avanzar una vez por cada pulso de energia.  
    digitalWrite(steps2, HIGH);  // This LOW to HIGH change is what creates the
    digitalWrite(steps2, LOW); // al A4988 de avanzar una vez por cada pulso de energia.  
    delayMicroseconds(Velocity);
    
  }

  
}

