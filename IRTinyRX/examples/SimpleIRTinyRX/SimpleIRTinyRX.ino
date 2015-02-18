/*
 IR reciver with 1 led for ATTINY85 @8 Mhz
 This example sketch works with SimpleIRtinyTX.ino sketch for the TX part
 philteta@gmail.com
 IR reciver tsop341, data pin on attiny pin 2 (pin 3 on Arduino code)
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
#define LED1_PIN 4 //led1 pin

//IR codes list
#define alloff 0x00FF00FF 
#define allon 0x00FFFF00  
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  //init led pin to output
  pinMode(LED1_PIN,OUTPUT);  
  digitalWrite (LED1_PIN, LOW);
  //start listening for IR code 
  irrecv.enableIRIn(); // Start receiver
}


void loop() 
{
  if (irrecv.decode(&results)) //if I have somethink 
  {
    if (results.value == alloff) digitalWrite (LED1_PIN, LOW);
    else if (results.value == allon) digitalWrite (LED1_PIN, HIGH);//if it s led1x code
    else 
    {
    }
    irrecv.resume(); // restart IR code RX function (need)
  }
}
