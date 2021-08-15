///////////////Speed/////////////
byte Speed;
#define max_speed 255

///////////////Arm////////////////
int main_Arm = 22;
int micro_Arm = 24;
int temp = 26;

///////////////Motors/////////////
/*PWM pins >> Motor number+1*/
/*Direction pins >> 23 to 39 (skipping 31)*/
byte dir1=23; byte dir2=25; byte dir3=27; byte dir4=29;
byte dir5=33; byte dir6=35; byte dir7=37; byte dir8=39;
//////////////////Micro motor//////////////////
byte dir_micro=41;
///******* front motors ****  (motor1,motor2)
///******* back motors  ****  (motor3,motor4)
///******* base motors  ****  (motor5,motor6,motor7,motor8)

/////// Recieve data from PI/////
char lastCommand;

/*===========================================================================*/ 


void setup() {
/////////// Serial channel Setup//////////////////////
Serial.begin(9600);

///////////// Arm Setup //////////////////////////////
 pinMode(main_Arm,OUTPUT); digitalWrite(main_Arm,LOW);
 pinMode(micro_Arm,OUTPUT); digitalWrite(micro_Arm,LOW);
/////////// Motors Directions Setup /////////////////
/*MOTOR 1 INITIATE DIRECTION*/
pinMode(dir1,OUTPUT);  digitalWrite(dir1,LOW); 
/* MOTOR 2 INITIATE DIRECTION*/
pinMode(dir2,OUTPUT);  digitalWrite(dir2,LOW); 
/* MOTOR 3 INITIATE DIRECTION*/
pinMode(dir3,OUTPUT);  digitalWrite(dir3,LOW); 
/* MOTOR 4 INITIATE DIRECTION*/
pinMode(dir4,OUTPUT);  digitalWrite(dir4,LOW); 
/* MOTOR 5 INITIATE DIRECTION*/
pinMode(dir5,OUTPUT);  digitalWrite(dir5,LOW); 
/* MOTOR 6 INITIATE DIRECTION*/
pinMode(dir6,OUTPUT);  digitalWrite(dir6,LOW); 
/* MOTOR 7 INITIATE DIRECTION*/
pinMode(dir7,OUTPUT);  digitalWrite(dir7,LOW); 
/* MOTOR 8 INITIATE DIRECTION*/
pinMode(dir8,OUTPUT);  digitalWrite(dir8,LOW);
///////////////////////////////////////////////////
pinMode(dir_micro,OUTPUT);  digitalWrite(dir_micro,LOW);
/////////// Motors PWM Setup /////////////////
/*PWM pins >> Motor number+1*/
for (int i=2;i<=10;i++){pinMode(i,OUTPUT); analogWrite(i,0);}
}

/*===========================================================================*/ 

void loop() {
  if(Serial.available()>0){
    char text = Serial.read();
    
/////////// ARM (OPEN,CLOSE) ORDERS /////////
/*ARM OPEN*/
    if (text == 'p'){digitalWrite(main_Arm,LOW);Serial.println("MAIN ARM OPEN !");}
/*MICRO ARM OPEN*/
    if (text == 'y'){digitalWrite(micro_Arm,LOW);Serial.println("MICRO ARM OPEN !");}
    
/*ARM CLOSE*/
    if (text == 'o'){ digitalWrite(main_Arm,HIGH); Serial.println("MAIN ARM CLOSE !");}
/*MICRO ARM CLOSE*/
    if (text == 'u'){ digitalWrite(micro_Arm,HIGH); Serial.println("MICRO ARM CLOSE !");}
    

/////////// MICRO ROV Motion /////////
/***********FORWARD****************/
if (text == 'h'){micro_speed(150); Speed=150;
    digitalWrite(dir_micro,LOW);
      Serial.println("UP 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='h';}

/***********BACKWARD****************/
if (text == 'g'){ micro_speed(150); Speed=150;
    digitalWrite(dir_micro,HIGH);
      Serial.println("UP 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='g';}
///////////////// MICRO ROV STOP//////////////////////////
if (text == 'm'){ STOP();
      analogWrite(10,0);
      Serial.println("MICRO ROV STOPPED !! ");
      lastCommand='g';}



/////////// Motors Motion /////////
/***********Upward****************/
    if (text == 'q'){ zSpeed(150); up(); Speed=150;
      Serial.println("UP 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='q';}
    
    else if (text == ';'){zSpeed(240); up(); Speed=240;
      Serial.println("UP 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand=';';}
    
/***********Down****************/
    else if (text == 'e'){ zSpeed(150); down(); Speed=150;
      Serial.println("DOWN 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='e';}
    
    else if (text == '/'){zSpeed(240); down(); Speed=240;
      Serial.println("DOWN 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='/';}

/***********Forward****************/
    else if (text == 'w'){ xySpeed(150); forward(); Speed=150;
      Serial.println("FORWARD 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='w';}
    
    else if (text == 'b'){xySpeed(200); forward(); Speed=200;
      Serial.println("FORWARD 200 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='b';}
      
    else if (text == 'f'){xySpeed(240); forward(); Speed=240;
      Serial.println("FORWARD 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='f';}

      
/***********Backward****************/
    else if (text == 's'){ xySpeed(150); backward(); Speed=150;
      Serial.println("BACKWARD 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='s';}
    
    else if (text == ','){xySpeed(200); backward(); Speed=200;
      Serial.println("BACKWARD 200 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand=',';}
      
    else if (text == '.'){xySpeed(240); backward(); Speed=240;
      Serial.println("BACKWARD 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='.';}

/***********Right****************/
    else if (text == 'd'){ xySpeed(150); right(); Speed=150;
      Serial.println("RIGHT 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='d';}
    
    else if (text == 'z'){xySpeed(200); right(); Speed=200;
      Serial.println("RIGHT 200 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='z';}
      
    else if (text == 'x'){xySpeed(240); right(); Speed=240;
      Serial.println("RIGHT 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='x';}
      
/***********Left****************/
    else if (text == 'a'){ xySpeed(150); left(); Speed=150;
      Serial.println("LEFT 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='a';}
    
    else if (text == 'c'){xySpeed(200); left(); Speed=200;
      Serial.println("LEFT 200 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='c';}
      
    else if (text == 'v'){xySpeed(240); left(); Speed=240;
      Serial.println("LEFT 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='v';}

/***********Rotate Left****************/
    else if (text == 'r'){ xySpeed(150); rotateLeft(); Speed=150;
      Serial.println("ROTATE LEFT 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='r';}
    
    else if (text == '<'){xySpeed(240); rotateLeft(); Speed=240;
      Serial.println("ROTATE LEFT 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='<';}

/***********Rotate Right****************/
    else if (text == 't'){ xySpeed(150); rotateRight(); Speed=150;
      Serial.println("ROTATE RIGHT 150 !");
      Serial.print("PWM = ");
      Serial.println(Speed);
      lastCommand='t';}
    
    else if (text == '>'){xySpeed(240); rotateRight(); Speed=240;
      Serial.println("ROTATE RIGHT 240 !");
      Serial.print("PWM = "); 
      Serial.println(Speed);
      lastCommand='>';}
      
/***********STOP****************/
    if (text == 'l'){ STOP();
      Serial.println("ROV STOPPED !!");
      lastCommand='l';}     
}}

/*===========================================================================*/ 

//////////////Speed Funtions////////////////
/* zSpeed >> up & down , xySpeed >> directional (left & right)*/
/*Takes PWM value as input*/
void zSpeed(int a)
{ if(a>=240){a=240;}
  for (int i=2;i<=5;i++){analogWrite(i,0);}
  for (int i=6;i<=9;i++){analogWrite(i,a);}
  }
void xySpeed(int b)
{ if(b>=240){b=240;}
  for (int i=6;i<=9;i++){analogWrite(i,0);}
  for (int i=2;i<=5;i++){analogWrite(i,b);}
  }
void micro_speed(int c)
{ if(c>=150){c=150;}
  analogWrite(10,c);
  }
void STOP(){
  for (int i=2;i<=10;i++){analogWrite(i,0);}}
  
//////////////Motors Directions////////////////
/*based on its connection with the driver & test*/
void m1(char x){
  if (x=='f'){digitalWrite(dir1,LOW);}
  else if (x=='b'){digitalWrite(dir1,HIGH);}
}
void m2(char x){
  if (x=='f'){digitalWrite(dir2,LOW);}
  else if (x=='b'){digitalWrite(dir2,HIGH);}
}
void m3(char x){
  if (x=='f'){digitalWrite(dir3,LOW);}
  else if (x=='b'){digitalWrite(dir3,HIGH);}
}
void m4(char x){
  if (x=='f'){digitalWrite(dir4,HIGH);}
  else if (x=='b'){digitalWrite(dir4,LOW);}
}
void m5(char x){
  if (x=='f'){digitalWrite(dir5,LOW);}
  else if (x=='b'){digitalWrite(dir5,HIGH);}
}
void m6(char x){
  if (x=='f'){digitalWrite(dir6,LOW);}
  else if (x=='b'){digitalWrite(dir6,HIGH);}
}
void m7(char x){
  if (x=='f'){digitalWrite(dir7,LOW);}
  else if (x=='b'){digitalWrite(dir7,HIGH);}
}
void m8(char x){
  if (x=='f'){digitalWrite(dir8,LOW);}
  else if (x=='b'){digitalWrite(dir8,HIGH);}
}
//////////////Direction Funtions////////////////
/*based on thrusters rotation with direction*/

void down(){m5('f');m6('f');m7('f');m8('f');}
void up(){m5('b');m6('b');m7('b');m8('b');}
void forward(){m1('b');m2('b');m3('f');m4('f');}
void backward(){m1('f');m2('f');m3('b');m4('b');}
void left(){m1('f');m2('b');m3('f');m4('b');}
void right(){m1('b');m2('f');m3('b');m4('f');}
void rotateRight(){m1('b');m2('f');m3('f');m4('b');}
void rotateLeft(){m1('f');m2('b');m3('b');m4('f');}
