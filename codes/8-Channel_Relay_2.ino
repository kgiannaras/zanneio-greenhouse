/*
Please note as I have used the android app you told , the string inputs are taken as
A,B,C,D,E,F,G and a,b,c,d,e,f,g.
I have also written code for voice on and off which has all on and all off function
but since the android app we are using dosent have such key so i didnt took them
*/
String inputs;
#define relay1 1 //Connect relay1 to pin 9
#define relay2 2 //Connect relay2 to pin 8
#define relay3 3 //Connect relay3 to pin 7
#define relay4 4 //Connect relay4 to pin 6
#define relay5 5 //Connect relay5 to pin 5
#define relay6 6 //Connect relay6 to pin 4
#define relay7 7 //Connect relay7 to pin 3
#define relay8 8 //Connect relay8 to pin 2
#define sw1 14
#define sw2 15
#define sw3 16
#define sw4 17
#define sw5 18
int button1;
int button2;
int button3;
int button4;
int button5;
void setup()
{
Serial.begin(9600); //Set rate for communicating with phone
pinMode(relay1, OUTPUT); //Set relay1 as an output
pinMode(relay2, OUTPUT); //Set relay2 as an output
pinMode(relay3, OUTPUT); //Set relay1 as an output
pinMode(relay4, OUTPUT); //Set relay2 as an output
pinMode(relay5, OUTPUT); //Set relay1 as an output
pinMode(relay6, OUTPUT); //Set relay2 as an output
pinMode(relay7, OUTPUT); //Set relay1 as an output
pinMode(relay8, OUTPUT); //Set relay2 as an output
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);
pinMode(sw3, INPUT);
pinMode(sw4, INPUT);
pinMode(sw5, INPUT);
digitalWrite(relay1, HIGH); //Switch relay1 off
digitalWrite(relay2, HIGH); //Swtich relay2 off
digitalWrite(relay3, HIGH); //Switch relay1 off
digitalWrite(relay4, HIGH); //Swtich relay2 off
digitalWrite(relay5, HIGH); //Switch relay1 off
digitalWrite(relay6, HIGH); //Swtich relay2 off
digitalWrite(relay7, HIGH); //Switch relay1 off
digitalWrite(relay8, HIGH); //Swtich relay2 off
}
void loop()
{
 button1=digitalRead(sw1);
 if(button1==HIGH){
  digitalWrite(relay1, HIGH);
  
 }else{
digitalWrite(relay1, LOW);
 }
 button2=digitalRead(sw2);
 if(button2==HIGH){
  digitalWrite(relay2, HIGH);
  
 }else{
digitalWrite(relay2, LOW);
 }
  button3=digitalRead(sw3);
 if(button3==HIGH){
  digitalWrite(relay3, HIGH);
  
 }else{
digitalWrite(relay3, LOW);
 }
  button4=digitalRead(sw4);
 if(button4==HIGH){
  digitalWrite(relay4, HIGH);
  
 }else{
digitalWrite(relay4, LOW);
 }
  button5=digitalRead(sw5);
 if(button5==HIGH){
  digitalWrite(relay5, HIGH);
  
 }else{
digitalWrite(relay5, LOW);
 }
}
