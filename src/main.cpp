#include <Arduino.h>
#include <video_broadcast.h>
#include <user_main.h>
#include <custom_commands.h>
#include <IRremote.h>
//#include <Wire.h>
#define IR_pin 16 // ESP8266 D0 (GPIO16)
const int RECV_PIN = IR_pin; // IR Receiver pin
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
 //Serial.begin(9600);
 testi2s_init();
 irrecv.enableIRIn();
}
	 
void loop() {


	 if(irrecv.decode(&results)){
    
      switch (results.value)
      {
	 case 3772811383:
	  showstate =0;
	   break;
	   case 3772784863:
	   showstate =1;
	   break;
       case 3772817503:
	  showstate =2;
	   break;
	    case 3772801183:
	  showstate =3;
	   break;
       case 3772780783:
	   showstate =4;
	   break;
	   case 3772813423:
	  showstate =5;
	   break;
	   case 3772797103:
	  showstate =6;
	   break;
	   case 3772788943:
	  showstate =7;
	   break;
	   case 3772821583:
	  showstate =8;
	   break;
	   case 3772805263:
	  showstate =9;
	   break;
	   case 3772809343:
	   showstate =10;
		break;
		default:
		showstate = 9;
		break;
	  }
	
	 }
	 irrecv.resume();
	   static uint8_t lastframe = 0;
	uint8_t tbuffer = !(gframe&1);
	if( lastframe != tbuffer )
	{
		frontframe = (uint8_t*)&framebuffer[((FBW2/4)*FBH)*tbuffer ];
		DrawFrame( );
		lastframe = tbuffer;
	}
	system_os_post(procTaskPrio, 0, 0 );
	   
	
}            