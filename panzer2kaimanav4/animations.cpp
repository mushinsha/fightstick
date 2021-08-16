//  animations.cpp
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
//  Kaimana animations based on original source released by ParadiseArcadeShop.com October 15, 2013
//
//  Created:  October 24, 2013    zonbipanda // gmail.com  -- Arduino 1.0.5 Support
//  Revised:  October 29, 2013    zonbipanda // gmail.com
//  Revised:  April   11, 2015    zonbipanda // gmail.com  -- Arduino 1.6.3 Support
//

#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "Arduino.h"
#include "kaimana.h"
#include "kaimana_custom.h"
#include "animations.h"

// Color Fade Animation when Idle
//
int animation_idle(void)
{
  int  index;
  int  i;

  // set initial color to BLACK
  kaimana.setALL(BLACK);

  while(true)
  {
    for(index=0;index<IDLE_SIZE;++index)
    {
      // update strip with new color2
      for(i=0;i<LED_COUNT;++i)
      {
        kaimana.setLED(
          i,
          pgm_read_byte_near(&colorCycleData[((index+IDLE_OFFSET_2+((LED_COUNT-i)*IDLE_OFFSET))%IDLE_SIZE)]),
          pgm_read_byte_near(&colorCycleData[((index+IDLE_OFFSET_1+((LED_COUNT-i)*IDLE_OFFSET))%IDLE_SIZE)]),
          pgm_read_byte_near(&colorCycleData[((index+IDLE_OFFSET_0+((LED_COUNT-i)*IDLE_OFFSET))%IDLE_SIZE)])
        );
      }

      // update the leds with new/current colors in the array
      kaimana.updateALL();

      // test all switches and exit idle animation if active switch found
      for(i=0;i<SWITCH_COUNT;++i)
      {
        if( !digitalRead(switchPins[i]) )
          return(false);
      }

      // place test for switches here and use calculated timer not delay
      //
      delay( IDLE_ANIMATION_DELAY );
    }
  }
}


// Hadouken (Fireball)
//
void animation_combo_1(void)
{
  int  index;
  int  i;
  int  counter;

  counter = FIREBALL_SIZE-1;

  kaimana.setALL( BLACK );

  while(counter >=0)
  {
    // P1 & K1
    if( (counter < FIREBALL_SIZE) && (counter >= 0) )
    {
      kaimana.setLED(
      LED_P1,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[counter%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[counter%FIREBALL_SIZE])
        );
      kaimana.setLED(
      LED_K1,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[counter%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[counter%FIREBALL_SIZE])
        );
    }
    else
    {
      kaimana.setLED( LED_P1, BLACK );
      kaimana.setLED( LED_K1, BLACK );
    }

    // P2 & K2
    if( ((counter+(FIREBALL_OFFSET_1)) < FIREBALL_SIZE) && ((counter+(FIREBALL_OFFSET_1)) >= 0) )
    {
      kaimana.setLED(
      LED_P2,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_1))%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_1))%FIREBALL_SIZE])
        );
      kaimana.setLED(
      LED_K2,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_1))%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_1))%FIREBALL_SIZE])
        );
    }
    else
    {
      kaimana.setLED( LED_P2, BLACK );
      kaimana.setLED( LED_K2, BLACK );
    }

    // P3 & K3
    if( ((counter+(FIREBALL_OFFSET_2)) < 768) && ((counter+(FIREBALL_OFFSET_2)) >= 0) )
    {
      kaimana.setLED(
      LED_P3,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_2))%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_2))%FIREBALL_SIZE])
        );
      kaimana.setLED(
      LED_K3,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_2))%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_2))%FIREBALL_SIZE])
        );
    }
    else
    {
      kaimana.setLED( LED_P3, BLACK );
      kaimana.setLED( LED_K3, BLACK );
    }

    // P4 & K4
    if( ((counter+(FIREBALL_OFFSET_3)) < 768) && ((counter+(FIREBALL_OFFSET_3)) >= 0) )
    {
      kaimana.setLED(
      LED_P4,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_3))%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_3))%FIREBALL_SIZE])
        );
      kaimana.setLED(
      LED_K4,
      0,  // no red just cyan used for fireball
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_3))%FIREBALL_SIZE]),
      pgm_read_byte_near(&colorCycleData[(counter+(FIREBALL_OFFSET_3))%FIREBALL_SIZE])
        );
    }
    else
    {
      kaimana.setLED( LED_P4, BLACK );
      kaimana.setLED( LED_K4, BLACK );
    }

    // update the leds with new/current colors in the array
    kaimana.updateALL();

    // slow down the fireball animation
    delayMicroseconds( FIREBALL_DELAY );

    counter -= 4;
  }

  kaimana.setALL( BLACK );
}

// Shoryuken (Dragon Punch)
void animation_combo_2(void)
  {
    kaimana.setALL(BLACK);
    kaimana.setALL(RED);
    delay(2000);
    kaimana.setALL(BLACK);
  }


// Tatsumaki Senpukyaku (Hurricane Kick)
void animation_combo_3(void)
  {
    kaimana.setALL(BLACK);
  //RED WIPE
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
  
  //GREEN WIPE
    kaimana.setLED( LED_UP, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_K1, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_K2, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_K3, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_K4, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_P4, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_P3, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_P2, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_P1, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_RIGHT, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_DOWN, GREEN );
    delay(25);
    kaimana.updateALL();
    kaimana.setLED( LED_LEFT, GREEN );
    delay(25);
    kaimana.updateALL();
  
  //BLUE WIPE
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

  //BLACK WIPE
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
  } // END Tatsumaki Senpukyaku (Hurricane Kick)

// Super (Shinkuu Hadouken)
//
void animation_combo_4(void)
  {
    kaimana.setALL(BLACK);
    kaimana.setALL(BLUE);
    delay(2000);
    kaimana.setALL(BLACK);
  }

// Ultra 1 (Metsu Hadouken)
//
void animation_combo_5(void)
  {
    kaimana.setALL(BLACK);
    kaimana.setALL(PURPLE);
    delay(2000);
    kaimana.setALL(BLACK);
  }

// Ultra 2 (Metsu Shoryuken)
//
void animation_combo_6(void)
  {
    kaimana.setALL(BLACK);
    kaimana.updateALL();
    kaimana.setALL(WHITE);
    delay(100);
    kaimana.updateALL();
    kaimana.setALL(BLACK);
    delay(100);
    kaimana.updateALL();
    kaimana.setALL(WHITE);
    delay(80);
    kaimana.updateALL();
    kaimana.setALL(BLACK);
    delay(80);
    kaimana.updateALL();
    kaimana.setALL(WHITE);
    delay(60);
    kaimana.updateALL();
    kaimana.setALL(BLACK);
    delay(60);
    kaimana.updateALL();
    kaimana.setALL(WHITE);
    delay(40);
    kaimana.updateALL();
    kaimana.setALL(BLACK);
    delay(40);
    kaimana.updateALL();
    kaimana.setALL(WHITE);
    delay(20);
    kaimana.updateALL();
    kaimana.setALL(BLACK);
    delay(20);
    kaimana.setALL(WHITE);
    delay(10);
    kaimana.setALL(BLACK);
    delay(10);
    kaimana.setALL(WHITE);
    delay(5);
    kaimana.setALL(BLACK);
    delay(5);
    kaimana.setALL(BLACK);
  }

#define  COMBO_DELAY 90
#define  WAVE_DELAY 25

void animation_xfactor(void)
  {
    kaimana.setALL( BLACK );
    kaimana.updateALL();
    kaimana.setLED(LED_LEFT, ORANGE);
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED(LED_LEFT, YELLOW);
    kaimana.setLED(LED_DOWN, ORANGE); 
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED(LED_LEFT, ORANGE);
    kaimana.setLED(LED_DOWN, YELLOW);
    kaimana.setLED(LED_RIGHT, ORANGE);
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, YELLOW );
    kaimana.setLED ( LED_DOWN, ORANGE );
    kaimana.setLED ( LED_RIGHT, YELLOW );
    kaimana.setLED ( LED_P1, ORANGE ); 
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, ORANGE );
    kaimana.setLED ( LED_DOWN, YELLOW ); 
    kaimana.setLED ( LED_RIGHT, ORANGE );
    kaimana.setLED ( LED_P1, YELLOW );
    kaimana.setLED ( LED_P2, ORANGE );
    delay( 75 ); 
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, YELLOW );
    kaimana.setLED ( LED_DOWN, ORANGE );
    kaimana.setLED ( LED_RIGHT, YELLOW ); 
    kaimana.setLED ( LED_P1, ORANGE );
    kaimana.setLED ( LED_P2, YELLOW );
    kaimana.setLED ( LED_P3, ORANGE );
    delay( 75 ); 
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, ORANGE );
    kaimana.setLED ( LED_DOWN, YELLOW );
    kaimana.setLED ( LED_RIGHT, ORANGE );
    kaimana.setLED ( LED_P1, YELLOW ); 
    kaimana.setLED ( LED_P2, ORANGE );
    kaimana.setLED ( LED_P3, YELLOW );
    kaimana.setLED ( LED_P4, ORANGE );
    delay( 75 ); 
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, YELLOW );
    kaimana.setLED ( LED_DOWN, ORANGE );
    kaimana.setLED ( LED_RIGHT, YELLOW );
    kaimana.setLED ( LED_P1, ORANGE );
    kaimana.setLED ( LED_P2, YELLOW ); 
    kaimana.setLED ( LED_P3, ORANGE );
    kaimana.setLED ( LED_P4, YELLOW );
    kaimana.setLED ( LED_K4, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, ORANGE );
    kaimana.setLED ( LED_DOWN, YELLOW );
    kaimana.setLED ( LED_RIGHT, ORANGE );
    kaimana.setLED ( LED_P1, YELLOW );
    kaimana.setLED ( LED_P2, ORANGE );
    kaimana.setLED ( LED_P3, YELLOW ); 
    kaimana.setLED ( LED_P4, ORANGE );
    kaimana.setLED ( LED_K4, YELLOW );
    kaimana.setLED ( LED_P3, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, YELLOW );
    kaimana.setLED ( LED_DOWN, ORANGE );
    kaimana.setLED ( LED_RIGHT, YELLOW );
    kaimana.setLED ( LED_P1, ORANGE );
    kaimana.setLED ( LED_P2, YELLOW );
    kaimana.setLED ( LED_P3, ORANGE );
    kaimana.setLED ( LED_P4, YELLOW ); 
    kaimana.setLED ( LED_K4, ORANGE );
    kaimana.setLED ( LED_K3, YELLOW );
    kaimana.setLED ( LED_K2, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, ORANGE );
    kaimana.setLED ( LED_DOWN, YELLOW );
    kaimana.setLED ( LED_RIGHT, ORANGE );
    kaimana.setLED ( LED_P1, YELLOW );
    kaimana.setLED ( LED_P2, ORANGE );
    kaimana.setLED ( LED_P3, YELLOW );
    kaimana.setLED ( LED_P4, ORANGE );
    kaimana.setLED ( LED_K4, YELLOW ); 
    kaimana.setLED ( LED_K3, ORANGE );
    kaimana.setLED ( LED_K2, YELLOW );
    kaimana.setLED ( LED_K1, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, YELLOW );
    kaimana.setLED ( LED_DOWN, ORANGE );
    kaimana.setLED ( LED_RIGHT, YELLOW );
    kaimana.setLED ( LED_P1, ORANGE );
    kaimana.setLED ( LED_P2, YELLOW );
    kaimana.setLED ( LED_P3, ORANGE );
    kaimana.setLED ( LED_P4, YELLOW );
    kaimana.setLED ( LED_K4, ORANGE );
    kaimana.setLED ( LED_K3, YELLOW ); 
    kaimana.setLED ( LED_K2, ORANGE );
    kaimana.setLED ( LED_K1, YELLOW );
    kaimana.setLED ( LED_UP, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, BLACK );
    kaimana.setLED ( LED_DOWN, YELLOW );
    kaimana.setLED ( LED_RIGHT, ORANGE );
    kaimana.setLED ( LED_P1, YELLOW );
    kaimana.setLED ( LED_P2, ORANGE );
    kaimana.setLED ( LED_P3, YELLOW);
    kaimana.setLED ( LED_P4, ORANGE );
    kaimana.setLED ( LED_K4, YELLOW );
    kaimana.setLED ( LED_K3, ORANGE ); 
    kaimana.setLED ( LED_K2, YELLOW );
    kaimana.setLED ( LED_K1, ORANGE );
    kaimana.setLED ( LED_UP, YELLOW );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, BLACK );
    kaimana.setLED ( LED_RIGHT, YELLOW );
    kaimana.setLED ( LED_P1, ORANGE );
    kaimana.setLED ( LED_P2, YELLOW );
    kaimana.setLED ( LED_P3, ORANGE );
    kaimana.setLED ( LED_P4, YELLOW );
    kaimana.setLED ( LED_K4, ORANGE );
    kaimana.setLED ( LED_K3, YELLOW ); 
    kaimana.setLED ( LED_K2, ORANGE );
    kaimana.setLED ( LED_K1, YELLOW );
    kaimana.setLED ( LED_UP, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, BLACK );
    kaimana.setLED ( LED_P1, YELLOW );
    kaimana.setLED ( LED_P2, ORANGE );
    kaimana.setLED ( LED_P3, YELLOW );
    kaimana.setLED ( LED_P4, ORANGE );
    kaimana.setLED ( LED_K4, YELLOW );
    kaimana.setLED ( LED_K3, ORANGE );
    kaimana.setLED ( LED_K2, YELLOW ); 
    kaimana.setLED ( LED_K1, ORANGE );
    kaimana.setLED ( LED_UP, YELLOW );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, BLACK );
    kaimana.setLED ( LED_P2, YELLOW );
    kaimana.setLED ( LED_P3, ORANGE );
    kaimana.setLED ( LED_P4, YELLOW );
    kaimana.setLED ( LED_K4, ORANGE );
    kaimana.setLED ( LED_K3, YELLOW );
    kaimana.setLED ( LED_K2, ORANGE );
    kaimana.setLED ( LED_K1, YELLOW ); 
    kaimana.setLED ( LED_UP, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, BLACK );
    kaimana.setLED ( LED_P3, YELLOW );
    kaimana.setLED ( LED_P4, ORANGE );
    kaimana.setLED ( LED_K4, YELLOW );
    kaimana.setLED ( LED_K3, ORANGE );
    kaimana.setLED ( LED_K2, YELLOW );
    kaimana.setLED ( LED_K1, ORANGE );
    kaimana.setLED ( LED_UP, YELLOW ); 
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, BLACK );
    kaimana.setLED ( LED_P4, YELLOW );
    kaimana.setLED ( LED_K4, ORANGE );
    kaimana.setLED ( LED_K3, YELLOW );
    kaimana.setLED ( LED_K2, ORANGE );
    kaimana.setLED ( LED_K1, YELLOW );
    kaimana.setLED ( LED_UP, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, BLACK );
    kaimana.setLED ( LED_K4, YELLOW );
    kaimana.setLED ( LED_K3, ORANGE );
    kaimana.setLED ( LED_K2, YELLOW );
    kaimana.setLED ( LED_K1, ORANGE );
    kaimana.setLED ( LED_UP, YELLOW );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, BLACK );
    kaimana.setLED ( LED_K3, YELLOW );
    kaimana.setLED ( LED_K2, ORANGE );
    kaimana.setLED ( LED_K1, YELLOW );
    kaimana.setLED ( LED_UP, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, BLACK );
    kaimana.setLED ( LED_K2, YELLOW );
    kaimana.setLED ( LED_K1, ORANGE );
    kaimana.setLED ( LED_UP, YELLOW );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, BLACK );
    kaimana.setLED ( LED_K1, YELLOW );
    kaimana.setLED ( LED_UP, ORANGE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, BLACK );
    kaimana.setLED ( LED_UP, YELLOW );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, BLACK );
    delay( 75 );
    kaimana.updateALL();  
  }

//red snake that wipes from left to right twice, first time trailing white, second time trailing black
void animation_redsnake(void)
  {
    kaimana.setALL( BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT_B, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, WHITE );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, BLACK );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, RED );
    delay( WAVE_DELAY );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, BLACK );
    delay( 90 );
    kaimana.updateALL();
    kaimana.setALL( BLACK );
    delay( 90 );
    kaimana.updateALL();
  }

void animation_bootup(void)
  {
    kaimana.setALL( BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, WHITE );
    delay( 50 );
    kaimana.updateALL();
    delay( 50 );
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, WHITE );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, BLACK );
    delay( 50 );
    kaimana.updateALL();
    delay( 50 );
    kaimana.setLED ( LED_LEFT, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, BLACK );
    delay( 50 );
    kaimana.updateALL();
    kaimana.setALL( BLACK );
    kaimana.updateALL();
    delay( 120 );
  }

void animation_vshape(void)
  {
    kaimana.setALL( BLACK );
    kaimana.updateALL();
    kaimana.setLED(LED_UP, WHITE);
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED(LED_UP, CYAN);
    kaimana.setLED(LED_K1, WHITE); 
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED(LED_UP, WHITE);
    kaimana.setLED(LED_K1, CYAN);
    kaimana.setLED(LED_K2, WHITE);
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, CYAN );
    kaimana.setLED ( LED_K1, WHITE );
    kaimana.setLED ( LED_K2, CYAN );
    kaimana.setLED ( LED_K3, WHITE ); 
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, WHITE );
    kaimana.setLED ( LED_K1, CYAN ); 
    kaimana.setLED ( LED_K2, WHITE );
    kaimana.setLED ( LED_K3, CYAN );
    kaimana.setLED ( LED_K4, WHITE );
    delay( 75 ); 
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, CYAN );
    kaimana.setLED ( LED_K1, WHITE );
    kaimana.setLED ( LED_K2, CYAN ); 
    kaimana.setLED ( LED_K3, WHITE );
    kaimana.setLED ( LED_K4, CYAN );
    kaimana.setLED ( LED_P4, WHITE );
    delay( 75 ); 
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, WHITE );
    kaimana.setLED ( LED_K1, CYAN );
    kaimana.setLED ( LED_K2, WHITE );
    kaimana.setLED ( LED_K3, CYAN ); 
    kaimana.setLED ( LED_K4, WHITE );
    kaimana.setLED ( LED_P4, CYAN );
    kaimana.setLED ( LED_P3, WHITE );
    delay( 75 ); 
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, CYAN );
    kaimana.setLED ( LED_K1, WHITE );
    kaimana.setLED ( LED_K2, CYAN );
    kaimana.setLED ( LED_K3, WHITE );
    kaimana.setLED ( LED_K4, CYAN ); 
    kaimana.setLED ( LED_P4, WHITE );
    kaimana.setLED ( LED_P3, CYAN );
    kaimana.setLED ( LED_P2, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, WHITE );
    kaimana.setLED ( LED_K1, CYAN );
    kaimana.setLED ( LED_K2, WHITE );
    kaimana.setLED ( LED_K3, CYAN );
    kaimana.setLED ( LED_K4, WHITE );
    kaimana.setLED ( LED_P4, CYAN ); 
    kaimana.setLED ( LED_P3, WHITE );
    kaimana.setLED ( LED_P2, CYAN );
    kaimana.setLED ( LED_P1, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, CYAN );
    kaimana.setLED ( LED_K1, WHITE );
    kaimana.setLED ( LED_K2, CYAN );
    kaimana.setLED ( LED_K3, WHITE );
    kaimana.setLED ( LED_K4, CYAN );
    kaimana.setLED ( LED_P4, WHITE );
    kaimana.setLED ( LED_P3, CYAN ); 
    kaimana.setLED ( LED_P2, WHITE );
    kaimana.setLED ( LED_P1, CYAN );
    kaimana.setLED ( LED_RIGHT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, WHITE );
    kaimana.setLED ( LED_K1, CYAN );
    kaimana.setLED ( LED_K2, WHITE );
    kaimana.setLED ( LED_K3, CYAN );
    kaimana.setLED ( LED_K4, WHITE );
    kaimana.setLED ( LED_P4, CYAN );
    kaimana.setLED ( LED_P3, WHITE );
    kaimana.setLED ( LED_P2, CYAN ); 
    kaimana.setLED ( LED_P1, WHITE );
    kaimana.setLED ( LED_RIGHT, CYAN );
    kaimana.setLED ( LED_DOWN, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, CYAN );
    kaimana.setLED ( LED_K1, WHITE );
    kaimana.setLED ( LED_K2, CYAN );
    kaimana.setLED ( LED_K3, WHITE );
    kaimana.setLED ( LED_K4, CYAN );
    kaimana.setLED ( LED_P4, WHITE );
    kaimana.setLED ( LED_P3, CYAN );
    kaimana.setLED ( LED_P2, WHITE );
    kaimana.setLED ( LED_P1, CYAN ); 
    kaimana.setLED ( LED_RIGHT, WHITE );
    kaimana.setLED ( LED_DOWN, CYAN );
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_UP, BLACK );
    kaimana.setLED ( LED_K1, CYAN );
    kaimana.setLED ( LED_K2, WHITE );
    kaimana.setLED ( LED_K3, CYAN );
    kaimana.setLED ( LED_K4, WHITE );
    kaimana.setLED ( LED_P4, CYAN);
    kaimana.setLED ( LED_P3, WHITE );
    kaimana.setLED ( LED_P2, CYAN );
    kaimana.setLED ( LED_P1, WHITE ); 
    kaimana.setLED ( LED_RIGHT, CYAN );
    kaimana.setLED ( LED_DOWN, WHITE );
    kaimana.setLED ( LED_LEFT, CYAN );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K1, BLACK );
    kaimana.setLED ( LED_K2, CYAN );
    kaimana.setLED ( LED_K3, WHITE );
    kaimana.setLED ( LED_K4, CYAN );
    kaimana.setLED ( LED_P4, WHITE );
    kaimana.setLED ( LED_P3, CYAN );
    kaimana.setLED ( LED_P2, WHITE );
    kaimana.setLED ( LED_P1, CYAN ); 
    kaimana.setLED ( LED_RIGHT, WHITE );
    kaimana.setLED ( LED_DOWN, CYAN );
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K2, BLACK );
    kaimana.setLED ( LED_K3, CYAN );
    kaimana.setLED ( LED_K4, WHITE );
    kaimana.setLED ( LED_P4, CYAN );
    kaimana.setLED ( LED_P3, WHITE );
    kaimana.setLED ( LED_P2, CYAN );
    kaimana.setLED ( LED_P1, WHITE );
    kaimana.setLED ( LED_RIGHT, CYAN ); 
    kaimana.setLED ( LED_DOWN, WHITE );
    kaimana.setLED ( LED_LEFT, CYAN );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K3, BLACK );
    kaimana.setLED ( LED_K4, CYAN );
    kaimana.setLED ( LED_P4, WHITE );
    kaimana.setLED ( LED_P3, CYAN );
    kaimana.setLED ( LED_P2, WHITE );
    kaimana.setLED ( LED_P1, CYAN );
    kaimana.setLED ( LED_RIGHT, WHITE );
    kaimana.setLED ( LED_DOWN, CYAN ); 
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_K4, BLACK );
    kaimana.setLED ( LED_P4, CYAN );
    kaimana.setLED ( LED_P3, WHITE );
    kaimana.setLED ( LED_P2, CYAN );
    kaimana.setLED ( LED_P1, WHITE );
    kaimana.setLED ( LED_RIGHT, CYAN );
    kaimana.setLED ( LED_DOWN, WHITE );
    kaimana.setLED ( LED_LEFT, CYAN ); 
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P4, BLACK );
    kaimana.setLED ( LED_P3, CYAN );
    kaimana.setLED ( LED_P2, WHITE );
    kaimana.setLED ( LED_P1, CYAN );
    kaimana.setLED ( LED_RIGHT, WHITE );
    kaimana.setLED ( LED_DOWN, CYAN );
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P3, BLACK );
    kaimana.setLED ( LED_P2, CYAN );
    kaimana.setLED ( LED_P1, WHITE );
    kaimana.setLED ( LED_RIGHT, CYAN );
    kaimana.setLED ( LED_DOWN, WHITE );
    kaimana.setLED ( LED_LEFT, CYAN );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P2, BLACK );
    kaimana.setLED ( LED_P1, CYAN );
    kaimana.setLED ( LED_RIGHT, WHITE );
    kaimana.setLED ( LED_DOWN, CYAN );
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_P1, BLACK );
    kaimana.setLED ( LED_RIGHT, CYAN );
    kaimana.setLED ( LED_DOWN, WHITE );
    kaimana.setLED ( LED_LEFT, CYAN );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_RIGHT, BLACK );
    kaimana.setLED ( LED_DOWN, CYAN );
    kaimana.setLED ( LED_LEFT, WHITE );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_DOWN, BLACK );
    kaimana.setLED ( LED_LEFT, CYAN );
    delay( 75 );
    kaimana.updateALL();
    kaimana.setLED ( LED_LEFT, BLACK );
    delay( 75 );
    kaimana.updateALL();
  }

void animation_test(void)
{
  int  index;
  int  i;

  // set initial color to BLACK
  kaimana.setALL(BLACK);

  while(true)
  {
    for(index=0;index<IDLE_SIZE;++index)
    {
      // update strip with new color2
      for(i=0;i<LED_COUNT;++i)
      {
        kaimana.setLED(
          i,
          pgm_read_byte_near(&colorCycleData[((index+IDLE_OFFSET_2+((LED_COUNT-i)*IDLE_OFFSET))%IDLE_SIZE)]),
          pgm_read_byte_near(&colorCycleData[((index+IDLE_OFFSET_1+((LED_COUNT-i)*IDLE_OFFSET))%IDLE_SIZE)]),
          pgm_read_byte_near(&colorCycleData[((index+IDLE_OFFSET_0+((LED_COUNT-i)*IDLE_OFFSET))%IDLE_SIZE)])
        );
        
      }

      // update the leds with new/current colors in the array
      kaimana.updateALL();
        
          if( !digitalRead(switchPins[4]) )
          return(false);
        }
    }
}
