#include <Servo.h>
Servo servo_1;
Servo servo_2;
#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
// Convert normal decimal numbers to binary coded decimal

byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}

// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}

void setup()
{
  Wire.begin();
  Serial.begin(9600);
    servo_1.attach(2);
  servo_2.attach(3);
  servo_1.write(180);
  servo_2.write(180);
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  //setDS3231time(10,8,9,6,11,03,22);
}

void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}

void readDS3231time(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  
// request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}

void displayTime()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  // retrieve data from DS3231
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  // send it to the serial monitor
  Serial.print(hour, DEC);

  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
   

  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  Serial.print(" Day of week: ");
  switch(dayOfWeek){
  case 1:
    Serial.println("Sunday");
    break;
  case 2:
    Serial.println("Monday");
    break;
  case 3:
    Serial.println("Tuesday");
    break;
  case 4:
    Serial.println("Wednesday");
    break;
  case 5:
    Serial.println("Thursday");
    break;
  case 6:
    Serial.println("Friday");
    break;
  case 7:
    Serial.println("Saturday");
    break;
  }

    int Hrs=hour;
    int Min=minute;
     
     //----------Hrs-----------------//
    if (Hrs == 1) servo_1.write(165);
    if (Hrs == 2) servo_1.write(150);
    if (Hrs == 3) servo_1.write(135);
    if (Hrs == 4) servo_1.write(120);
    if (Hrs == 5) servo_1.write(105);
    if (Hrs == 6) servo_1.write(90);
    if (Hrs == 7) servo_1.write(75);
    if (Hrs == 8) servo_1.write(60);
    if (Hrs == 9) servo_1.write(45);
    if (Hrs == 10) servo_1.write(30);
    if (Hrs == 11) servo_1.write(15);
    if (Hrs == 12) servo_1.write(0);

    if (Hrs == 13) servo_1.write(165);
    if (Hrs == 14) servo_1.write(150);
    if (Hrs == 15) servo_1.write(135);
    if (Hrs == 16) servo_1.write(120);
    if (Hrs == 17) servo_1.write(105);
    if (Hrs == 18) servo_1.write(90);
    if (Hrs == 19) servo_1.write(75);
    if (Hrs == 20) servo_1.write(60);
    if (Hrs == 21) servo_1.write(45);
    if (Hrs == 22) servo_1.write(30);
    if (Hrs == 23) servo_1.write(15);
    if (Hrs == 0) servo_1.write(0);
    
    //--------------Min--------------//
    if (Min == 0) servo_2.write(0);
    if (Min == 1) servo_2.write(3);
    if (Min == 2) servo_2.write(6);
    if (Min == 3) servo_2.write(9);
    if (Min == 4) servo_2.write(12);
    if (Min == 5) servo_2.write(15);
    if (Min == 6) servo_2.write(18);
    if (Min == 7) servo_2.write(21);
    if (Min == 8) servo_2.write(24);
    if (Min == 9) servo_2.write(27);
    if (Min == 10) servo_2.write(30);
    if (Min == 11) servo_2.write(33);
    if (Min == 12) servo_2.write(36);
    if (Min == 13) servo_2.write(39);
    if (Min == 14) servo_2.write(42);
    if (Min == 15) servo_2.write(45);
    if (Min == 16) servo_2.write(48);
    if (Min == 17) servo_2.write(51);
    if (Min == 18) servo_2.write(54);
    if (Min == 19) servo_2.write(57);
    if (Min == 20) servo_2.write(60);
    if (Min == 21) servo_2.write(63);
    if (Min == 22) servo_2.write(66);
    if (Min == 23) servo_2.write(69);
    if (Min == 24) servo_2.write(72);
    if (Min == 25) servo_2.write(75);
    if (Min == 26) servo_2.write(78);
    if (Min == 27) servo_2.write(81);
    if (Min == 28) servo_2.write(84);
    if (Min == 29) servo_2.write(87);
    if (Min == 30) servo_2.write(90);
    if (Min == 31) servo_2.write(93);
    if (Min == 32) servo_2.write(96);
    if (Min == 33) servo_2.write(99);
    if (Min == 34) servo_2.write(102);
    if (Min == 35) servo_2.write(105);
    if (Min == 36) servo_2.write(108);
    if (Min == 37) servo_2.write(111);
    if (Min == 38) servo_2.write(114);
    if (Min == 39) servo_2.write(117);
    if (Min == 40) servo_2.write(120);
    if (Min == 41) servo_2.write(123);
    if (Min == 42) servo_2.write(126);
    if (Min == 43) servo_2.write(129);
    if (Min == 44) servo_2.write(132);
    if (Min == 45) servo_2.write(135);
    if (Min == 46) servo_2.write(138);
    if (Min == 47) servo_2.write(141);
    if (Min == 48) servo_2.write(144);
    if (Min == 49) servo_2.write(147);
    if (Min == 50) servo_2.write(150);
    if (Min == 51) servo_2.write(153);
    if (Min == 52) servo_2.write(156);
    if (Min == 53) servo_2.write(159);
    if (Min == 54) servo_2.write(162);
    if (Min == 55) servo_2.write(165);
    if (Min == 56) servo_2.write(168);
    if (Min == 57) servo_2.write(171);
    if (Min == 58) servo_2.write(174);
    if (Min == 59) servo_2.write(177);


}

void loop()
{
  displayTime(); // display the real-time clock data on the Serial Monitor,
  delay(1000); // every second
 

  
}
