/*
 IR reciver with four leds for ATTINY85 @8 Mhz
 This example sketch works with AnalogIRtinyTX.ino sketch for the TX part
 philteta@gmail.com
 IR reciver tsop341, data pin on attiny pin 2 (pin 3 in Arduino code)
 4 leds with adapted resistors
 led1 on attiny pin 3 (pin 4 in Arduino code)
 led2 on attiny pin 5(pin 0 in Arduino code)
 led3 on attiny pin 6(pin 1 in Arduino code)
 led4 on attiny pin 7(pin 2 in Arduino code)

 *---------------*
 |DIL 8 | Arduino|
 |------|--------|
 |  1   |        | reset 
 |  2   |   3    | Analog in / digial in or out
 |  3   |   4    | Analog in / digial in or out
 |  4   |        | GND
 |  5   |   0    | PWM / digial in or out
 |  6   |   1    | PWM / digial in or out
 |  7   |   2    | Analog in / digial in or out
 |  8   |        | VCC
 *---------------*
 For futur reference the IR library use some stuff (timer I think) and dosen't permit to use PWN hardware function
*/

#include <IRTinyRX.h>

#define RECV_PIN 3 //pin for IR tsop341 IR sensor
#define LED2_PIN 0 //led2 pin
#define LED3_PIN 1 //led3 pin
#define LED4_PIN 2 //led4 pin
#define LED1_PIN 4 //led1 pin

//IR codes list
//led status 0 = on , x = off   
#define alloff 0x00FF00FF // xxxx
#define led1x 0x00FF44BB  // 0xxx
#define led12 0x00FF34CB  // 00xx
#define led2x 0x00FF33CC  // x0xx
#define led23 0x00FF23DC  // x00x
#define led3x 0x00FF22DD  // xx0x
#define led34 0x00FF12ED  // xx00
#define led4x 0x00FF11EE  // xxx0
#define allon 0x00FFFF00  // 0000

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
	//init led pin to output
	pinMode(LED1_PIN,OUTPUT);  
	pinMode(LED2_PIN,OUTPUT); 
	pinMode(LED3_PIN,OUTPUT);
	pinMode(LED4_PIN,OUTPUT);
	
	//all leds off
	allshut();

	//start listening for IR code 
	irrecv.enableIRIn(); // Start receiver
}


void loop() 
{
  if (irrecv.decode(&results)) //if I have somethink 
  {
	if (results.value == alloff) allshut();
    else if (results.value == led1x) //if it s led1x code
	{
     allshut();
     digitalWrite (LED1_PIN, HIGH);   
    }
    else if (results.value == led12) //if it's led12 code
	{
		allshut();
		digitalWrite (LED1_PIN, HIGH);   
		digitalWrite (LED2_PIN, HIGH);   
    }
    else if (results.value == led2x) //if it's led2x code
	{
		allshut();
		digitalWrite (LED2_PIN, HIGH);   
    }
    else if (results.value == led23) //if it's led23 code
	{
		allshut();
		digitalWrite (LED2_PIN, HIGH);   
		digitalWrite (LED3_PIN, HIGH);   
    }
    else if (results.value == led3x) //if it's led3x code
	{
		allshut();
		digitalWrite (LED3_PIN, HIGH);   
    }
    else if (results.value == led34) //if it's led34 code
	{
		allshut();
		digitalWrite (LED3_PIN, HIGH);   
		digitalWrite (LED4_PIN, HIGH);   
    }
	else if (results.value == led4x) //if it's led4x code
	{
		allshut();
		digitalWrite (LED4_PIN, HIGH);   
    }
    else if (results.value == allon) //if it's allon code
	{
		allshut();
		digitalWrite (LED1_PIN, HIGH);   
		digitalWrite (LED2_PIN, HIGH);   
		digitalWrite (LED3_PIN, HIGH);   	
		digitalWrite (LED4_PIN, HIGH);   
    }
    else 
	{
    }
    irrecv.resume(); // restart IR code RX function (need)
  }
}

void allshut() //fonction qui eteint toutes les leds
{
	digitalWrite (LED1_PIN, LOW);   
	digitalWrite (LED2_PIN, LOW);   
	digitalWrite (LED3_PIN, LOW);   
	digitalWrite (LED4_PIN, LOW);  
}