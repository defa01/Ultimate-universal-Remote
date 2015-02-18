/*
by Joe DeFabrizio 10/25/2014
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *---------------*
 |DIL 8 | Arduino|
 |------|--------|
 |  1   |        | reset 
 |  2   |   3    | IR RECEIVER
 |  3   |   4    | RED LED
 |  4   |        | GND
 |  5   |   0    | RF DATA 
 |  6   |   1    | UNUSED
 |  7   |   2    | GREEN LED
 |  8   |        | VCC
 *---------------*
*/
#include <RCSwitch.h>
#include <IRTinyRX.h>

#define RECV_PIN 3 //pin for IR tsop341 IR sensor
#define ledg 2 //green led pin
#define ledr 4 //red led pin
//DEFINE IR Codes here and note what RF switch they represent
#define rm1on 0x0000000  // Switch 1
#define rm2on 0x0000000  // Switch 2
#define rm3on 0x0000000  // DSwitch 3
#define rm4on 0x0000000  // Switch 4
#define rm5on 0x0000000  // Tune Down - Switch 3
#define rm6on 0x0000000  // Cursor Down - ALL OFF
#define rm7on 0x0000000  // Cursor Left - ALL ON

IRrecv irrecv(RECV_PIN);
decode_results results;
RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(0); //define RF data pin
  mySwitch.setPulseLength(167);
  pinMode(ledr,OUTPUT);
  pinMode(ledg,OUTPUT);
  //start listening for IR code 
  irrecv.enableIRIn(); // Start receiver
  
}

void loop() {
  if (irrecv.decode(&results)) //Check to see if I have a IR pulse
  {
    if (results.value == rm1on) 
    {
      mySwitch.send("000000000000000000000000"); // switch 4
     blnkb();
      blnk();
    }
    else if (results.value == rm2on) 
    {
      mySwitch.send("000000000000000000000000"); // switch 1
     blnkb();
      blnk();
    }
    else if (results.value == rm3on) 
    {
      mySwitch.send("000000000000000000000000"); // switch 5
      blnkb();
      blnk();
    }
    else if (results.value == rm4on) 
    {
      mySwitch.send("000000000000000000000000"); // switch 2
      blnkb();
      blnk();
    }
    else if (results.value == rm5on) 
    {
      mySwitch.send("000000000000000000000000"); // switch 3
      blnkb();
      blnk();
    }
    else if (results.value == rm6on) 
    {
      mySwitch.send("000000000000000000000000"); // ALL OFF
      blnkb();
      blnk();
    }
    else if (results.value == rm7on) 
    {
      mySwitch.send("000000000000000000000000"); // ALL ON
      blnkb();
      blnk();
    }
    else 
    {
    }
    irrecv.resume(); // restart IR code
  }
}

//Optional Status LED blink pattern

void blnk(){
delay(150);
digitalWrite(ledr, LOW);
delay(150);
digitalWrite(ledg, LOW);
}
void blnkb(){
// red
digitalWrite(ledr, HIGH);
delay(75);
digitalWrite(ledr, LOW);
delay(75);
digitalWrite(ledr, HIGH);
delay(75);
digitalWrite(ledg, HIGH);
}
