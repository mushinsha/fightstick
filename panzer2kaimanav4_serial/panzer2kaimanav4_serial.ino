//  example.ino
//
//  Copyright 2013 Paradise Arcade Shop, ParadiseArcadeShop.com  
//  All rights reserved.  Use is subject to license terms.
//
//  Code is provided for entertainment purposes and use with the Kaimana controller.
//  Code may be copied, modified, resused with this Copyright notice.
//  No commercial use without written permission from Paradise Arcade Shop.
//
//  Paradise Arcade Shop Kaimana LED Driver Board
//  Initial Release October 15, 2013
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Kaimana example based on original source released by ParadiseArcadeShop.com October 15, 2013
//
//  Created:  October 24, 2013    zonbipanda // gmail.com  -- Arduino 1.0.5 Support
//  Revised:  October 29, 2013    zonbipanda // gmail.com
//  Revised:  April   11, 2015    zonbipanda // gmail.com  -- Arduino 1.6.3 Support
//


#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "kaimana.h"
#include "kaimana_custom.h"
#include "animations.h"


// local function declarations
int  pollSwitches(void);
void showStartup(void);
void setLEDRandomColor(int index);


// ParadiseArcadeShop.com Kaimana features initialzied when Kaimana class instantiated
Kaimana kaimana;


// the setup routine runs first and once each time power is applied to the Kaimana board
void setup() 
{ 
  Serial.begin(9600);
  // while the serial stream is not open, do nothing:
  while (!Serial)
  {
    // do nothing
  } ;
  Serial.println("I am in setup");
  // light up all leds at boot to demonstrate everything is functional
  showStartup();
}


// the loop routine repeats indefinitely and executes immediately following the setup() function
void loop() 
{
  unsigned long  ulTimeout;
  uint8_t i;

  // initialize timeout value to now + some seconds
  ulTimeout = millis() + ( (unsigned long)IDLE_TIMEOUT_SECONDS * 1000 );


  // infinite loop of read switches, update LEDs and idle animation when necessary
  while(true)
  {
    // active -- poll switches and update leds
    if( pollSwitches() != 0 )
    {
        // some switches were active so reset idle timeout to now + some seconds
        ulTimeout = millis() + ( (unsigned long)IDLE_TIMEOUT_SECONDS * 1000 );
    }
    else
    {
        // no switches active so test for start of idle timeout  
        if( millis() > ulTimeout )
        {
          animation_idle();
        }  
    }
    
    // delay a little to avoid flickering (yea, updates happens really, really fast!)
    delay( MAIN_LOOP_DELAY );
  } 
}


// ==============================================================
//
//  local functions start here
//
// ==============================================================


// light up all leds at boot to demonstrate everything is functional
//
void showStartup(void)
{
  //Startup Wipe 
 //Red Wipe
  kaimana.setLED( LED_UP, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K1, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K2, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K3, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K4, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P4, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P3, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P2, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P1, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_RIGHT, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_DOWN, RED );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_LEFT, RED );
  delay(25);
  kaimana.updateALL();
  
 //White Wipe
  kaimana.setLED( LED_UP, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K1, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K2, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K3, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K4, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P4, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P3, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P2, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P1, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_RIGHT, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_DOWN, WHITE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_LEFT, WHITE );
  delay(25);
  kaimana.updateALL();

//Blue Wipe
  kaimana.setLED( LED_UP, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K1, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K2, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K3, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K4, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P4, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P3, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P2, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P1, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_RIGHT, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_DOWN, BLUE );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_LEFT, BLUE );
  delay(25);
  kaimana.updateALL();

//Black Wipe - END WIPE
  kaimana.setLED( LED_UP, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K1, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K2, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K3, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_K4, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P4, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P3, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P2, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_P1, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_RIGHT, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_DOWN, BLACK );
  delay(25);
  kaimana.updateALL();
  kaimana.setLED( LED_LEFT, BLACK );
  delay(25);
  kaimana.updateALL();
} 


// set LED to one of 8 predefined colors selected at random
//
void setLEDRandomColor(int index)
{
  switch(random(1,8))    // pick a random color between 1 and 8
  {
    case 1:
      kaimana.setLED(index, COLOR_RANDOM_1);
      break;
    case 2:
      kaimana.setLED(index, COLOR_RANDOM_2);
      break;
    case 3:
      kaimana.setLED(index, COLOR_RANDOM_3);
      break;
    case 4:
      kaimana.setLED(index, COLOR_RANDOM_4);
      break;
    case 5:
      kaimana.setLED(index, COLOR_RANDOM_5);
      break;
    case 6:
      kaimana.setLED(index, COLOR_RANDOM_6);
      break;
    case 7:
      kaimana.setLED(index, COLOR_RANDOM_7);
      break;
    case 8:
      kaimana.setLED(index, COLOR_RANDOM_8);
      break;
    default:   // any undefined value so discard data and set led to BLACK
      kaimana.setLED(index, BLACK);    
      break;
  }  
}



int pollSwitches(void)
{
  static int  iLED[LED_COUNT];
  static int  iActiveSwitchCount;
  static int  i;  
  static int  j;  
  static int  firsttime;
  static uint16_t  joystickDirection;
  static uint16_t  switchActivity;

  // reset LED status
  if (firsttime == 1)
  {
    for(i=0;i<LED_COUNT;++i)
    {
      iLED[i] = false;
      firsttime = 0;
    }
  }

  // read arduino pins and save results in the mapped LED if button is pressed (pin grounded)

  // complex special case for joystick but it's worth the effort
  joystickDirection = ATTACK_NONE;
  
  if(!digitalRead(PIN_RIGHT))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_RIGHT: ");
    Serial.print(ATTACK_RIGHT);
    Serial.println("");
    switchActivity |= ATTACK_RIGHT;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_RIGHT] == true)
    {
      Serial.print("PIN_RIGHT Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_RIGHT);  //SERIAL
      Serial.println("");  //SERIAL

      
      //maintain color while switch is active
      iLED[LED_RIGHT] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_RIGHT_ON      
        setLEDRandomColor(LED_RIGHT);  
      #else
         kaimana.setLED(LED_RIGHT, LED_RIGHT_COLOR_ON);
      #endif
      iLED[LED_RIGHT] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_RIGHT_OFF
        setLEDRandomColor(LED_RIGHT);
      #else
        kaimana.setLED(LED_RIGHT, LED_RIGHT_COLOR_OFF);
      #endif    
      iLED[LED_RIGHT] = false;
  }
  
    if(!digitalRead(PIN_LEFT))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_LEFT: ");
    Serial.print(ATTACK_LEFT);
    Serial.println("");
    switchActivity |= ATTACK_LEFT;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_LEFT] == true)
    {
      Serial.print("PIN_LEFT Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_LEFT);  //SERIAL
      Serial.println("");  //SERIAL

      //maintain color while switch is active
      iLED[LED_LEFT] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_LEFT_ON      
        setLEDRandomColor(LED_LEFT);  
      #else
         kaimana.setLED(LED_LEFT, LED_LEFT_COLOR_ON);
      #endif
      iLED[LED_LEFT] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_LEFT_OFF
        setLEDRandomColor(LED_LEFT);
      #else
        kaimana.setLED(LED_LEFT, LED_LEFT_COLOR_OFF);
      #endif    
      iLED[LED_LEFT] = false;
  }

  if(!digitalRead(PIN_UP))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_UP: ");
    Serial.print(ATTACK_UP);
    Serial.println("");
    switchActivity |= ATTACK_UP;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_UP] == true)
    {
      Serial.print("PIN_UP Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_UP);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_UP] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_UP_ON      
        setLEDRandomColor(LED_UP);  
      #else
         kaimana.setLED(LED_UP, LED_UP_COLOR_ON);
      #endif
      iLED[LED_UP] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_UP_OFF
        setLEDRandomColor(LED_UP);
      #else
        kaimana.setLED(LED_UP, LED_UP_COLOR_OFF);
      #endif    
      iLED[LED_UP] = false;
  }

    if(!digitalRead(PIN_DOWN))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_DOWN: ");
    Serial.print(ATTACK_DOWN);
    Serial.println("");
    switchActivity |= ATTACK_DOWN;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_DOWN] == true)
    {
      Serial.print("PIN_DOWN Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_DOWN);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_DOWN] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_DOWN_ON      
        setLEDRandomColor(LED_DOWN);  
      #else
         kaimana.setLED(LED_DOWN, LED_DOWN_COLOR_ON);
      #endif
      iLED[LED_DOWN] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_DOWN_OFF
        setLEDRandomColor(LED_DOWN);
      #else
        kaimana.setLED(LED_DOWN, LED_DOWN_COLOR_OFF);
      #endif    
      iLED[LED_DOWN] = false;
  }

  // clear results for switch activity
  switchActivity = ATTACK_NONE;
  
  // test switch and set LED based on result       // HOME = GUIDE
  if(!digitalRead(PIN_HOME))
  {
  Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_HOME: ");
    Serial.print(ATTACK_HOME);
    Serial.println("");
    switchActivity |= ATTACK_HOME;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    switchActivity |= ATTACK_HOME;
    // switch is active
    if(iLED[LED_HOME] == true)
  {
    {
      Serial.print("PIN_HOME Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_HOME);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_HOME] = true;
    }
  }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_HOME_ON      
        setLEDRandomColor(LED_HOME);  
      #else
         kaimana.setLED(LED_HOME, LED_HOME_COLOR_ON);
      #endif
      iLED[LED_HOME] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_HOME_OFF
        setLEDRandomColor(LED_HOME);
      #else
        kaimana.setLED(LED_HOME, LED_HOME_COLOR_OFF);
      #endif    
      iLED[LED_HOME] = false;
  }


  // test switch and set LED based on result    // SELECT = BACK 
  if(!digitalRead(PIN_SELECT))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_SELECT: ");
    Serial.print(ATTACK_SELECT);
    Serial.println("");
    switchActivity |= ATTACK_SELECT;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_SELECT] == true)
    {
      Serial.print("PIN_SELECT Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_SELECT);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_SELECT] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_SELECT_ON        //mwolak 11-01-2015 switch between random or solid colors
        setLEDRandomColor(LED_SELECT);  //mappings in kaimana_custom.h
      #else
         kaimana.setLED(LED_SELECT, LED_SELECT_COLOR_ON);
      #endif
      iLED[LED_SELECT] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_SELECT_OFF
        setLEDRandomColor(LED_SELECT);
      #else
        kaimana.setLED(LED_SELECT, LED_SELECT_COLOR_OFF);
      #endif       
      iLED[LED_SELECT] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_START))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_START: ");
    Serial.print(ATTACK_START);
    Serial.println("");
    switchActivity |= ATTACK_START;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_START] == true)
    {
      Serial.print("PIN_START Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_START);  //SERIAL
      Serial.println("");  //SERIAL
    
      //maintain color while switch is active
      iLED[LED_START] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_START_ON        //mwolak 11-01-2015 switch between random or solid colors
        setLEDRandomColor(LED_START);  //mappings in kaimana_custom.h
      #else
         kaimana.setLED(LED_START, LED_START_COLOR_ON);
      #endif
      iLED[LED_START] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_START_OFF
        setLEDRandomColor(LED_START);
      #else
        kaimana.setLED(LED_START, LED_START_COLOR_OFF);
      #endif      
      iLED[LED_START] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_P1))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_P1: ");
    Serial.print(ATTACK_P1);
    Serial.println("");
    switchActivity |= ATTACK_P1;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_P1] == true)
    {
      Serial.print("PIN_P1 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_P1);  //SERIAL
      Serial.println("");  //SERIAL
  
      //maintain color while switch is active
      iLED[LED_P1] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P1_ON
        setLEDRandomColor(LED_P1);
      #else
         kaimana.setLED(LED_P1, LED_P1_COLOR_ON);
      #endif
      iLED[LED_P1] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_P1_OFF
        setLEDRandomColor(LED_P1);
      #else
        kaimana.setLED(LED_P1, LED_P1_COLOR_OFF);
      #endif     
      iLED[LED_P1] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_P2))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_P2: ");
    Serial.print(ATTACK_P2);
    Serial.println("");
    switchActivity |= ATTACK_P2;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_P2] == true)
    {
      Serial.print("PIN_P2 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_P2);  //SERIAL
      Serial.println("");  //SERIAL

      
      //maintain color while switch is active
      iLED[LED_P2] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P2_ON
        setLEDRandomColor(LED_P2);
      #else
         kaimana.setLED(LED_P2, LED_P2_COLOR_ON);
      #endif
      iLED[LED_P2] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_P2_OFF
        setLEDRandomColor(LED_P2);
      #else
        kaimana.setLED(LED_P2, LED_P2_COLOR_OFF);
      #endif    
      iLED[LED_P2] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_P3))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_P3: ");
    Serial.print(ATTACK_P3);
    Serial.println("");
    switchActivity |= ATTACK_P3;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_P3] == true)
    {
      Serial.print("PIN_P3 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_P3);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_P3] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P3_ON
        setLEDRandomColor(LED_P3);
      #else
         kaimana.setLED(LED_P3, LED_P3_COLOR_ON);
      #endif
      iLED[LED_P3] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_P3_OFF
        setLEDRandomColor(LED_P3);
      #else
        kaimana.setLED(LED_P3, LED_P3_COLOR_OFF);
      #endif   
      iLED[LED_P3] = false;
  }
  

  // test switch and set LED based on result
  if(!digitalRead(PIN_P4))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_P4: ");
    Serial.print(ATTACK_P4);
    Serial.println("");
    switchActivity |= ATTACK_P4;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_P4] == true)
    {
      Serial.print("PIN_P4 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_P4);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_P4] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_P4_ON
        setLEDRandomColor(LED_P4);
      #else
         kaimana.setLED(LED_P4, LED_P4_COLOR_ON);
      #endif
      iLED[LED_P4] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_P4_OFF
        setLEDRandomColor(LED_P4);
      #else
        kaimana.setLED(LED_P4, LED_P4_COLOR_OFF);
      #endif 
      iLED[LED_P4] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K1))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_K1: ");
    Serial.print(ATTACK_K1);
    Serial.println("");
    switchActivity |= ATTACK_K1;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_K1] == true)
    {
      Serial.print("PIN_K1 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_K1);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_K1] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K1_ON
        setLEDRandomColor(LED_K1);
      #else
         kaimana.setLED(LED_K1, LED_K1_COLOR_ON);
      #endif
      iLED[LED_K1] = true;
    }
  }
  else
  {
      // switch is inactive
      #ifdef RANDOM_COLOR_K1_OFF
        setLEDRandomColor(LED_K1);
      #else
        kaimana.setLED(LED_K1, LED_K1_COLOR_OFF);
      #endif    
      iLED[LED_K1] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K2))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_K2: ");
    Serial.print(ATTACK_K2);
    Serial.println("");
    switchActivity |= ATTACK_K2;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_K2] == true)
    {
      Serial.print("PIN_K2 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_K2);  //SERIAL
      Serial.println("");  //SERIAL

      
      //maintain color while switch is active
      iLED[LED_K2] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K2_ON
        setLEDRandomColor(LED_K2);
      #else
         kaimana.setLED(LED_K2, LED_K2_COLOR_ON);
      #endif
      iLED[LED_K2] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_K2_OFF
        setLEDRandomColor(LED_K2);
      #else
        kaimana.setLED(LED_K2, LED_K2_COLOR_OFF);
      #endif      
      iLED[LED_K2] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K3))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_K3: ");
    Serial.print(ATTACK_K3);
    Serial.println("");
    switchActivity |= ATTACK_K3;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_K3] == true)
    {
      Serial.print("PIN_K3 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_K3);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_K3] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K3_ON
        setLEDRandomColor(LED_K3);
      #else
         kaimana.setLED(LED_K3, LED_K3_COLOR_ON);
      #endif
      iLED[LED_K3] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_K3_OFF
        setLEDRandomColor(LED_K3);
      #else
        kaimana.setLED(LED_K3, LED_K3_COLOR_OFF);
      #endif    
      iLED[LED_K3] = false;
  }


  // test switch and set LED based on result
  if(!digitalRead(PIN_K4))
  {
    Serial.print("switchActivity: ");
    Serial.print(switchActivity);
    Serial.print(" ATTACK_K4: ");
    Serial.print(ATTACK_K4);
    Serial.println("");
    switchActivity |= ATTACK_K1;

    Serial.print("switchActivity after OR operation: ");
    Serial.print(switchActivity);
    Serial.println("");
    
    // switch is active
    if(iLED[LED_K4] == true)
    {
      Serial.print("PIN_K4 Has been pressed, number is: ");  //SERIAL OUTPUT
      Serial.print(PIN_K4);  //SERIAL
      Serial.println("");  //SERIAL
      
      //maintain color while switch is active
      iLED[LED_K4] = true;
    }
    else
    {
      // select new color when switch is first activated
      #ifdef RANDOM_COLOR_K4_ON
        setLEDRandomColor(LED_K4);
      #else
         kaimana.setLED(LED_K4, LED_K4_COLOR_ON);
      #endif
      iLED[LED_K4] = true;
    }
  }
  else
  {
      // switch is inactive
      // switch is inactive
      #ifdef RANDOM_COLOR_K4_OFF
        setLEDRandomColor(LED_K4);
      #else
        kaimana.setLED(LED_K4, LED_K4_COLOR_OFF);
      #endif       
      iLED[LED_K4] = false;
  }



  // convert joystick, P1-P4, K1-K4 into a single unsigned int
  switchActivity = joystickDirection + switchActivity;
  kaimana.switchHistorySet(switchActivity);
  

  // test for combinations from most complext to least complex
  // test for switches in reverse order (newest to oldest)


  // combo #6
  // test for: Ultra 2 (Metsu Shoryuken)
  // combo is: DOWN, DOWN+RIGHT, RIGHT, DOWN, DOWN+RIGHT, RIGHT, RIGHT+K3
  if( kaimana.switchHistoryTest( COMBO_PATTERN_6A ) )
      animation_combo_6();

  // combo #5
  // test for: Ultra 1 (Metsu Hadouken)
  // combo is: DOWN, DOWN+RIGHT, RIGHT, <NONE>, DOWN, DOWN+RIGHT, RIGHT, RIGHT+P3
  if( kaimana.switchHistoryTest( COMBO_PATTERN_5A ) )
      animation_combo_5();

  // combo #4
  // test for: Super (Shinkuu Hadouken)
  // combo is: DOWN, DOWN+RIGHT, RIGHT, <NONE>, DOWN, DOWN+RIGHT, RIGHT, RIGHT+P1
  if( kaimana.switchHistoryTest( COMBO_PATTERN_4A ) )
      animation_combo_4();

  // combo #3
  // test for: Tatsumaki Senpukyaku (Hurricane Kick)
  // combo is: DOWN, DOWN+LEFT, LEFT, LEFT+K1 or LEFT+K2
  if( kaimana.switchHistoryTest( COMBO_PATTERN_3A ) )
      animation_combo_3();
  if( kaimana.switchHistoryTest( COMBO_PATTERN_3B ) )
      animation_combo_3();

  // combo #2
  // test for: Ryu Shoryuken (Dragon Punch)
  // combo is: RIGHT, <NONE>, DOWN, DOWN+RIGHT, DOWN+RIGHT+P1 or DOWN+RIGHT+P2
  if( kaimana.switchHistoryTest( COMBO_PATTERN_2A ) )
      animation_combo_2();
  if( kaimana.switchHistoryTest( COMBO_PATTERN_2B ) )
      animation_combo_2();

  // combo #1
  // test for: Ryu Hadouken (Fireball) 
  // combo is: DOWN, DOWN+RIGHT, RIGHT, RIGHT+P1 or RIGHT+P2  
  if( kaimana.switchHistoryTest( COMBO_PATTERN_1A ) )
      animation_combo_1();
  if( kaimana.switchHistoryTest( COMBO_PATTERN_1B ) )
      animation_combo_1();

// xfactor combo
 if( kaimana.switchHistoryTest( XFACTOR_PATTERN ) )
      animation_xfactor();
 
 // Red Snake Animation
 if( kaimana.switchHistoryTest( REDSNAKE_PATTERN ) )
      animation_redsnake();
      
 // Blue Snake Animation
 if( kaimana.switchHistoryTest( BLUESNAKE_PATTERN ) )
      animation_bluesnake();

 // Bootup Animation
 if( kaimana.switchHistoryTest( BOOTUP_PATTERN ) )
      animation_bootup();
      
 // VShape Animation
 if( kaimana.switchHistoryTest( VSHAPE_PATTERN ) )
      animation_vshape();
      
  // zero active switch counter (note: 4 way joystick counts as 1)
  iActiveSwitchCount = 0;
  
  // set LED color based on switch
  for(i=0;i<LED_COUNT;++i)
  {
    if(iLED[i] == true)
      ++iActiveSwitchCount;
  }  

  // update the leds with new/current colors in the array
  kaimana.updateALL();
  
  // return number of active switches
  return(iActiveSwitchCount);
}  
