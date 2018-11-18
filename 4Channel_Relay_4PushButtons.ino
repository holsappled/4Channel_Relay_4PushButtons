// Using a push button switch for stay-on/stay-off push button . 
// A very difficult way to turn on lights with a button 


int switch1 = A2; // connect a push button switch between this pin and ground
int relay1 = 4; // relay1=outside lights, 
boolean flag1 = true;

int switch2 = A3; // connect a push button switch between this pin and ground
int relay2 = 2; // relay2 inside light1, 
boolean flag2 = true;

int switch3 = A1; // connect a push button switch between this pin and ground
int relay3 = 7; // relay4 inside light2, 
boolean flag3 = true;

int switch4 = A5; // connect a push button switch between this pin and ground
int relay4 = 8; // relay4 inside light4, 
boolean flag4 = true;

void setup()
{
  pinMode(relay1,OUTPUT); // this pin controlled by flipflop() function
  pinMode (switch1,INPUT_PULLUP); // keeps pin HIGH via internal pullup resistor unless brought LOW with switch
  
  pinMode(relay2,OUTPUT); // this pin controlled by flipflop() function
  pinMode (switch2,INPUT_PULLUP); // keeps pin HIGH via internal pullup resistor unless brought LOW with switch
  
  pinMode(relay3,OUTPUT); // this pin controlled by flipflop() function
  pinMode (switch3,INPUT_PULLUP); // keeps pin HIGH via internal pullup resistor unless brought LOW with switch
  
  pinMode(relay4,OUTPUT); // this pin controlled by flipflop() function
  pinMode (switch4,INPUT_PULLUP); // keeps pin HIGH via internal pullup resistor unless brought LOW with switch
  

  Serial.begin(9600); // just for debugging, not needed.
}

void loop()
{ 
  if (digitalRead(switch1)==LOW){ // check the state of switch1(Button1) every time we run through the main loop  
  delay(5); // I don't REALLY know why this delay helps, but it does.
 
    flipflop(); // hops out of main loop and runs the flipflop function
 // end of check for button press.
}


  // other sketch code here

} // end of main loop.

void flipflop() //funtion flipflop 
{  
 

  flag1=!flag1;  // since we are here, the switch was pressed So FLIP the boolian "flag" state (we don't even care if switch was released yet)
  Serial.print("flag1 =   " );   Serial.println(flag1);   // not needed, but may help to see what's happening.

  if (flag1 == HIGH){  // Use the value of the flag var to change the state of the pin
    digitalWrite(relay1,HIGH ); // if the flag var is HIGH turn the pin on
  }
  if (flag1 == LOW) {
    digitalWrite(relay1,LOW); // if the flag var is LOW turn the pin off 
  }
 

while (digitalRead(switch1)==LOW) // for "slow" button release, keeps us in the function until button is pressed again
  // If you take out this "while" the function becomes a flipflop oscillator if the button is held down. 
  delay(50); // OPTIONAL - play with this value.  It is probably short enough to not cause problems. deals with very quick switch press.

}






















