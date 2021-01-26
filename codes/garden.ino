//Variables
int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
int c6=0;
int c7=0;
int c8=0;
int c9=0;
int c10=0;
int c11=0;


//Servo
#include <Servo.h>//Servo library
Servo servo_test1;//initialize a servo object for the connected servo  dejios
Servo servo_test2;//initialize a servo object for the connected servo aristeros
int angle = 0;    


//ρελεδες
// #define relay1 33 //Σύνδεση relay1 στο pin 33 

#define relay2 31 //Σύνδεση relay2 στο pin 23 Αντλία
#define sw1 22 //Διακόπτης Χειροκίνιτου Ελέγχου
#define sw2 19 //Διακόπτης Χειροκίνιτου Ελέγχου Λάμπα θέρμανσης


//DHT-11   //Αισθητήρας Θερμοκρασία Περιβάλλοντος
#include <dht.h>
dht DHT;
#define DHT11_PIN 32 // DHT-11(AM2302)
float hum;  
float temp;
int limit3 = 70;
int limit4 = 70; 
int limit5 = -5;


//HW-103   //Αισθητήρας Υγρασίας Εδάφους
int sensorPin1 = A8; 
int sensorValue1;  
int limit1 = 300; 
int sensorPin2 = A10; 
int sensorValue2;  
int limit2 = 300; 


//Fans
#define relay3 29 //Ενεργοποίηση Ανεμιστήρα 1
#define relay4 35 //Ενεργοποίηση Ανεμιστήρα 2
#define sw3 18 //Διακοπτης Χειροκίνιτου Ελέγχου Ανεμιστήρα 1
#define sw4 17 //Διακοπτης Χειροκίνιτου Ελέγχου Ανεμιστήρα 2


//LDR   //Ανυχνευτής Φωτός
int sensorPin = A9; //Σύνδεση LDR στο Analog pin 9
int sensorValue = 0;
int limit = 300; 

//Electric Valve
#define relay5 25 //Ηλεκτροβάνα για Πότισμα
#define sw5 16 //Διακόπτης Χειροκίνιτου Ελέγχου Ηλεκτροβάνας,Αντλία


//Led Ανάπτυξης
#define relay6 27//Ενεργοποιεί τα Led Ανάπτυξης
#define sw6 15 //Διακόπτης Χειροκίνιτου Ελέγχου Led Ανάπτυξης

//Lamp temperture
#define relay7 23 //Λάμπα Θέρμανσης


//Θέρμανση Νερού
#define relay8 21 //Θέρμανση Νερού
//#define sw8 32 //Διακόπτης Χειροκίνιτου Ελέγχου Θέρμανσης Νερού


//DS18B20   //Αδιάβροχος Αισθητήρας Θερμοκρασίας Νερού
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 34
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 float Celcius=0;
 
/*
//Check Battery   //Έλεγχος Της Τάσης Μπαταριας
int led_lowbatt= 36;
int sensorValue3 = 0;

*/



//D1 Robot   //Οθόνη
#include <LiquidCrystal.h>
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
const int lcd_buttons = A0;


//HC-SR04   //Αισθητήρας Μέτρησης Απόστασης
const int trigPin = 30;
const int echoPin = 28;
long duration;
int distance;




//Leds   //Μας Δείχνουν Ποιά Συσκευή Λειτουργεί
const int led1 = 39; 
const int led2 = 41; 
const int led3 = 43; 
const int led4 = 45; 
const int led5 = 47; 
const int led6 = 49; 
 


/*
//LedError
const int GreenLed = 50;//Καλή λειτουργία
const int LedError = 54;//Πρόβλημα
int k;

*/
int i;

void setup() {
Serial.begin(9600);


//Servo
servo_test1.attach(44);// attach the signal pin of servo to pin30 of arduino
servo_test2.attach(46);// attach the signal pin of servo to pin32 of arduino
servo_test1.write(0);  //dejios  
servo_test2.write(170); //aristeros

  
//ρελεδες
//pinMode(relay1, OUTPUT); //Set relay1 as an output
pinMode(relay2, OUTPUT); //Set relay2 as an output Αντλία
pinMode(sw1, INPUT);

//Fans
pinMode(relay3, OUTPUT); //Set relay3 as an output, Ενεργοποίηση Ανεμιστήρα 1
digitalWrite(relay3, LOW); 
pinMode(relay4, OUTPUT); //Set relay4 as an output, Ενεργοποίηση Ανεμιστήρα 2
digitalWrite(relay4, LOW);
pinMode(sw3, INPUT);
pinMode(sw4, INPUT);
pinMode(sensorPin1, INPUT); //A7
pinMode(sensorPin2, INPUT); //A8
digitalWrite(relay3, HIGH); //Switch relay3 off
digitalWrite(relay4, HIGH); //Swtich relay4 off

//LDR
pinMode(sensorPin, INPUT); //A9

//Electric Valve
pinMode(relay5, OUTPUT); //Set relay5 as an output, Ηλεκτροβάνα
pinMode(relay2, OUTPUT); //Set relay2 as an output, Αντλία
pinMode(sw5, INPUT);
digitalWrite(relay5, HIGH); //Switch relay5 off, Ηλεκτροβάνα
digitalWrite(relay2, HIGH); //Switch relay2 off, Αντλία


//Led Ανάπτυξης
pinMode(relay6, OUTPUT); //Set relay6 as an output, Led Ανάπτυξης
pinMode(sw6, INPUT);
digitalWrite(relay6, HIGH); //Switch relay6 off, Led Ανάπτυξης


//Lamp Temperture
pinMode(relay7, OUTPUT); //Set relay7 as an output,Λάμπα Θέρμανσης
pinMode(sw2, INPUT);
digitalWrite(relay7, HIGH); //Switch relay7 off



/*

//Αντίσταση Νερού
pinMode(relay8, OUTPUT); //Set relay8 as an output,Θέρμανση Νερού
//pinMode(sw8, INPUT);
digitalWrite(relay8, HIGH); //Switch relay8 off,//Θέρμανση Νερού
*/



//DS18B20
sensors.begin();



  
/*
//Check Battery
pinMode(led_lowbatt, OUTPUT);
  */

//D1 Robot
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("GreenTechZANNEIO");
lcd.setCursor(0,1);
lcd.print("1o EK PEIRAIA");
pinMode(lcd_buttons, INPUT); //A0




 //HC-SR04
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input




//Leds
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);




/*
//LedError
pinMode(GreenLed, OUTPUT);
digitalWrite(GreenLed, HIGH);
pinMode(LedError, OUTPUT);

*/

}



void loop() {
//i=i+1;
//Serial.println(i);



//Servo
if(digitalRead(sw1)==HIGH){
  if (c1==0){
c1=1;
digitalWrite(led1, LOW);
Serial.println("sw1 off");
Serial.print("c1=");
Serial.println(c1);
//disable
//dejios
servo_test1.write(5);//command to rotate the servo to the specified angle
delay(100);                       
//aristeros
servo_test2.write(170);//command to rotate the servo to the specified angle
delay(150);                       
}
}

else if(digitalRead(sw1)==LOW){
if (c1==1){
c1=0;
digitalWrite(led1, HIGH);
Serial.println("sw1 on ");
Serial.print("c1=");
Serial.println(c1);
//enable
//dejios
servo_test1.write(170);//command to rotate the servo to the specified angle
delay(150);                       
//aristeros
servo_test2.write(5);//command to rotate the servo to the specified angle
delay(150);                       

}
}

//end sw1

  



//DHT-11   //Ενεργοποιεί Τους Ανεμιστήρες Όταν Ζεσταθεί Ο Χώρος Και Θερμαίνει Τον Χώρο Με Την Λάμπα Θέρμανσης Αυτόματα Όταν Υπάρχει Πααγωνιά
int chk = DHT.read11(DHT11_PIN);
//Read data and store it to variables hum and temp
hum = DHT.humidity;
temp= DHT.temperature;
//Print temp and humidity values to serial monitor
Serial.print("Humidity: ");
Serial.print(hum);
Serial.print(" %, Temp: ");
Serial.print(temp);
Serial.println(" Celsius");
if (temp<1) {
//k=2;
//Led_Error(k);
lcd.clear();
lcd.print("DHT-11");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
delay(500); //Delay 2 sec.   



if (temp>limit3) {
if (c7==0){
c7=1;
Serial.println("sw3 off ");
Serial.print("c7=");
Serial.println(c7);
digitalWrite(relay3, LOW); //Ενεργοποίηση Ανεμιστήρα 1
digitalWrite(led3, HIGH);
delay(500);
digitalWrite(led3, LOW);
delay(500);

}
}
else {
if (c7==1){
c7=0;
Serial.println("sw3 off ");
Serial.print("c7=");
Serial.println(c7);
  digitalWrite(relay3, HIGH); 

}
}




if (temp>limit4) {
  if (c8==0){
c8=1;
Serial.println("sw3 off ");
Serial.print("c8=");
Serial.println(c8);
digitalWrite(relay3, LOW); //Ενεργοποίηση Ανεμιστήρα 1
digitalWrite(relay4, LOW); //Ενεργοποίηση Ανεμιστήρα 2
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
delay(500);
}
}else {
  if (c8==1){
c8=0;
Serial.println("sw3 off ");
Serial.print("c8=");
Serial.println(c8);
digitalWrite(relay3, HIGH); //Απενεργοποίηση Ανεμιστήρα 1
digitalWrite(relay4, HIGH); //Απενεργοποίηση Ανεμιστήρα 2
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
delay(500);
} 
}

/*
if (temp<limit5) {
digitalWrite(relay7, LOW); //Ενεργοποίηση Λάμπα Θέρμανσης
delay(500);
}
else {
digitalWrite(relay7, HIGH);
delay(500); 
}

*/







 
//HW-103   //Μετράμε Την Υγρασία Του Εδάφους Και Ενεργοποιούμε Με Μια Ηλεκτροβάνα Το Πότισμα
sensorValue1 = analogRead(sensorPin1); 
Serial.println("Analog Value : ");
sensorValue1 = sensorValue1/100.0;
 sensorValue1 = 10-sensorValue1;
 sensorValue1 = sensorValue1*10.0;
Serial.print(sensorValue1);
Serial.println("%");
if (sensorValue1<1) {
//k=3;
//Led_Error(k);
lcd.clear();
lcd.print("HW-103(1)");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if (sensorValue1<limit1) {
  if (c10==0){
c10=1;
Serial.print("c10=");
Serial.println(c10);
digitalWrite(relay5, HIGH); //Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, LOW);
delay(500);
}
}else {
if (c10==1){
c10=0;
Serial.print("c10=");
Serial.println(c10);  
digitalWrite(relay5, LOW); //Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, HIGH);
delay(500);
}
}
delay(500); 
sensorValue2 = analogRead(sensorPin2); 
Serial.println("Analog Value : ");
sensorValue2 = sensorValue2/100.0; 
sensorValue2 = 10-sensorValue2;
 sensorValue2 = sensorValue2*10.0;
Serial.print(sensorValue2);
Serial.println("%");
if (sensorValue2<1) {
//k=4;
//Led_Error(k);
lcd.clear();
lcd.print("HW-103(2)");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if (sensorValue2<limit2) {
  if (c11==0){
c11=1;
Serial.print("c11=");
Serial.println(c11);
digitalWrite(relay5, HIGH); //Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, LOW);
delay(500);
}
}else {
  if (c11==1){
c11=0;
Serial.print("c11=");
Serial.println(c11);
digitalWrite(relay5, LOW); //Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, HIGH);
delay(500);
}
} 











//Fans   //Έχουμε Την Δυνατότητα Να Ενεργοποιούμε Χειροκίνιτα Τους Ανεμιστήρες Με Διακόπτες
if(digitalRead(sw3)==HIGH){
if (c3==0){
c3=1;
Serial.println("sw3 off ");
Serial.print("c3=");
Serial.println(c3);
digitalWrite(relay3, HIGH);
digitalWrite(led3, LOW);
}
}else{
if (c3==1){
c3=0;
Serial.println("sw3 on ");
Serial.print("c3=");
Serial.println(c3);
digitalWrite(relay3, LOW);
digitalWrite(led3, HIGH);
}
}


if(digitalRead(sw4)==HIGH){
if (c4==0){
c4=1;
Serial.println("sw4 off ");
Serial.print("c4=");
Serial.println(c4);
digitalWrite(relay4, HIGH);
digitalWrite(led4, LOW);
}
}else{
if (c4==1){
c4=0;
Serial.println("sw4 on ");
Serial.print("c4=");
Serial.println(c4);
digitalWrite(relay4, LOW);
digitalWrite(led4, HIGH);
}
}




/*

//LDR   //Αισθητήρας Ανύχνευσης Φωτός Ο Οποίος Ενεργοποιεί Αυτόματα Το Φωτισμό Ανάπτυξης Των Φυτών
sensorValue = analogRead(sensorPin); //read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
if (sensorValue<1) {
k=5;
Led_Error(k);
lcd.clear();
lcd.print("LDR");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if (sensorValue<limit) {
digitalWrite(relay6, HIGH); //Led Ανάπτυξης
digitalWrite(led6, HIGH);
delay(500);
}
else {
digitalWrite(relay6, LOW); //Led Ανάπτυξης
digitalWrite(led6, LOW);
delay(500);
}

*/



 
//Electric Valve
if(digitalRead(sw5)==HIGH){
if (c5==1){
c5=0;
Serial.println("sw5 off ");
Serial.print("c5=");
Serial.println(c5);
digitalWrite(relay5, HIGH);//Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(relay2, HIGH);//Απενεργοποίηση Αντλία
digitalWrite(led5, LOW);
delay(500);
}
}else{
if (c5==0){
c5=1;
Serial.println("sw5 on ");
Serial.print("c5=");
Serial.println(c5);
digitalWrite(relay5, LOW);//Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(relay2, LOW);//Ενεργοποίηση Αντλία
digitalWrite(led5, HIGH);
delay(500);
}
}


 
//Led Ανάπτυξης
if(digitalRead(sw6)==HIGH){
if (c6==0){
c6=1;
Serial.println("sw6 off ");
Serial.print("c6=");
Serial.println(c6);
digitalWrite(relay6, HIGH);//Led Ανάπτυξης
digitalWrite(led6, LOW);
delay(500);
}
}else if(digitalRead(sw6)==LOW){
if (c6==1){
c6=0;
Serial.println("sw6 on ");
Serial.print("c6=");
Serial.println(c6);
digitalWrite(relay6, LOW);//Led Ανάπτυξης
digitalWrite(led6, HIGH);
delay(500);
}
}






//Lamp Temperature
if(digitalRead(sw2)==HIGH){
  if (c2==0){
c2=1;
Serial.println("sw2 off ");
Serial.print("c2=");
Serial.println(c2);
digitalWrite(relay7, HIGH);//Λάμπα Θερμοκρασίας
digitalWrite(led2, LOW);
delay(500);
}
}else if(digitalRead(sw2)==LOW){ 
if (c2==1){
c2=0;
Serial.println("sw2 on ");
Serial.print("c2=");
Serial.println(c2);
digitalWrite(relay7, LOW); //Λάμπα Θερμοκρασίας
digitalWrite(led2, HIGH);
delay(500);
}
}






/*
//Αντίσταση Νερού   //Την Ενεργοποιουμε για να ζεστανουμε το νερο με το ρελε 8
if(digitalRead(sw8)==HIGH){
if (c8==0){
c8=1
digitalWrite(relay8, HIGH);//Θέρμανση Νερού
digitalWrite(led8, LOW);
delay(500);
}
}else{
if (c8==1){
c8=0
digitalWrite(relay8, LOW);//Θέρμανση Νερού
digitalWrite(led8, HIGH);
delay(500);
}
}
*/







//DS18B20   //ψηφιακος αισθητηρας αδιαβροχος μετραει την θερμοκρασια νερου
sensors.requestTemperatures(); 
Celcius=sensors.getTempCByIndex(0);
Serial.print(" C  ");
Serial.print(Celcius);
delay(500);
if (Celcius<1) {
//k=6;
//Led_Error(k);
lcd.clear();
lcd.print("DS18B20");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if(Celcius<8){
  if (c9==0){
c9=1;
Serial.print("c9=");
Serial.println(c9);
digitalWrite(relay8, LOW);//Θέρμανση Νερού Ενεργοποιηση
delay(500);
}
}else{
  if (c9==1){
c9=0;
Serial.print("c9=");
Serial.println(c9);
digitalWrite(relay8, HIGH);//Θέρμανση Νερού Απενεργοποιηση
delay(500);
}
}








/*

//Check Battery   //ελεγχος σταθμης μπαταριας
int sensorValue3 = analogRead(A8); 
float voltage = sensorValue3 * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
Serial.print("voltage = ");
Serial.print(voltage); //print the voltage to LCD
Serial.println(" V");
if (voltage < 12.1) //set the voltage considered low battery here
{
digitalWrite(led_lowbatt, HIGH);
}
if (voltage < 12.1) {
k=7;
Led_Error(k);
lcd.clear();
lcd.print("Check Battery");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
  */









//D1 Robot
int x;
x = analogRead(lcd_buttons);
Serial.print("x of lcd buttons = ");
Serial.println(x);
lcd.setCursor(10,1);
if (x < 60) {

//RIGHT
lcd.clear();
lcd.print("GreenTechZANNEIO");
lcd.setCursor(0,1);  
lcd.print ("Battery=");
lcd.setCursor(8,1);
//lcd.print (voltage);
lcd.setCursor(13,1);
lcd.print ("V");
}
else if (x < 200) {
  
//UP
lcd.clear();
lcd.print("GreenTechZANNEIO");
lcd.setCursor(0,1);  
lcd.print ("HC-SR04=");
lcd.setCursor(9,1);
lcd.print (distance);
}
else if (x < 400){
  
//DOWN
lcd.clear();
lcd.print("GreenTechZANNEIO");
lcd.setCursor(0,1);  
lcd.print ("WaterTemp=");
lcd.setCursor(11,1);
lcd.print (Celcius);
}
else if (x < 600){
  
//LEFT
lcd.clear();
lcd.print("Hum.Soil_1=");
lcd.setCursor(11,0);
lcd.print (sensorValue1); 
lcd.setCursor(14,0);
lcd.print("%");
lcd.setCursor(0,1);
lcd.print ("Hum.Soil_2=");
lcd.setCursor(11,1);
lcd.print (sensorValue2);
lcd.setCursor(14,1);
lcd.print("%"); 
   
}
else if (x < 800){
  
//SELECT
lcd.clear();
lcd.print("Temp=");
lcd.setCursor(5,0);
lcd.print (temp); 
lcd.setCursor(0,1);
lcd.print ("Humidity=");
lcd.setCursor(9,1);
lcd.print (hum);
lcd.setCursor(14,1);
lcd.print("%");
}








//HC-SR04   //αισθητηρας αποστασης μετραει την αποσταση του νερου
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
//Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance <1) {
//k=8;
//Led_Error(k);
}




}
//end void loop




/*
//Led Error   //
 void Led_Error(int k)
{
digitalWrite(GreenLed, LOW);
for (int i = 1; i = k ; i++){
digitalWrite(LedError, HIGH);
delay (1000);
digitalWrite(LedError, LOW);
delay (1000);
}
digitalWrite(GreenLed, HIGH);
}


*/
