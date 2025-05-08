#include <msp430.h>
#include <stdio.h>
#include <libTimer.h>

#include "lcdutils.h"

#include "lcddraw.h"

#include "led.h"

#include "switches.h"

#include "libTimer.h"

#include "buzzer.h"




void wink(){
  P1OUT |= LEDS;
  delay(500);
  buzzer_set_period(G4); delay(500);
  P1OUT &= ~LED_RED;
  buzzer_set_period(D4); delay(500);
  P1OUT |= LED_RED;
  buzzer_set_period(0);
}
void lastOne(){
  buzzer_set_period(C4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(0);
}
void chime(){
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(B4); delay(Q);
  buzzer_set_period(B4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  
  buzzer_set_period(0);
}
void twinkle(){
  buzzer_set_period(C4); delay(Q);
  buzzer_set_period(C4); delay(Q);
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(G4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(A4); delay(Q);
  buzzer_set_period(G4); delay(W);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(F4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(E4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(D4); delay(Q);
  buzzer_set_period(C4); delay(W);
  buzzer_set_period(0);
}

void mary(){
  buzzer_set_period(E4); delay(H);
  buzzer_set_period(D4); delay(H);
  buzzer_set_period(C4); delay(H);
  buzzer_set_period(D4); delay(H);
  buzzer_set_period(E4); delay(H);
  buzzer_set_period(D4); delay(H);
  buzzer_set_period(E4); delay(H);
  buzzer_set_period(G4); delay(H);
  buzzer_set_period(G4); delay(H);
  buzzer_set_period(0);
}

void fillTriangle(char colMin, char rowMin, char width, char height, int colorBGR)
{

  if (width % 2 == 0) width--;

  u_char halfWidth = width / 2;

  for (u_char row = 0; row < height; row++) {

    float ratio = (float)row / height;

    u_char lineWidth = width * (1.0 - ratio);


    if (lineWidth == 0) lineWidth = 1; 
    u_char colStart = colMin + halfWidth - lineWidth / 2;
    u_char colEnd = colStart + lineWidth;

    lcd_setArea(colStart, rowMin + row, colEnd - 1, rowMin + row);
    for (u_char col = 0; col < (colEnd - colStart); col++) {
      lcd_writeColor(colorBGR);
    }
  }
}

void drawStar(char colCenter, char rowCenter, char size, int colorBGR) {


  fillRectangle(colCenter, rowCenter - size, 1, size * 2 + 1, colorBGR);


  fillRectangle(colCenter - size, rowCenter, size * 2 + 1, 1, colorBGR);


  for (int i = -size; i <= size; i++) {

    lcd_setArea(colCenter + i, rowCenter - i, colCenter + i, rowCenter - i);

    lcd_writeColor(colorBGR);

    lcd_setArea(colCenter + i, rowCenter + i, colCenter + i, rowCenter + i);

    lcd_writeColor(colorBGR);

  }

}



void states(int n){
  char word[15];
  switch(n){
  case 1:
    limit=-1;
    clearScreen(COLOR_BLUE);
    fillRectangle(screenWidth/2,screenHeight/2,50,50,COLOR_RED);
    sprintf(word,"HELLO");
    //drawString5x7(screenWidth,10,name,COLOR_WHITE, COLOR_RED);
    drawString5x7(screenWidth - 100, 5, word, COLOR_WHITE, COLOR_RED);
    mary();
    wink();
    break;

   case 2:
     limit=-1;
     clearScreen(COLOR_GREEN);
     fillTriangle(screenWidth/2, (screenHeight/2) , 30, 50, COLOR_RED);
     sprintf(word,"triangle");
     drawString5x7(screenWidth-60,5,word,COLOR_WHITE, COLOR_BLUE);
     limit =-1;
     twinkle();
     wink();
     break;
    
  case 3:
    limit=-1;
    clearScreen(COLOR_BLACK);
    sprintf(word,"STARS");
    drawString5x7(screenWidth-60,5,word,COLOR_WHITE,COLOR_BLACK);
    drawStar(screenWidth / 2, screenHeight / 2, 5, COLOR_YELLOW);
    drawStar(screenWidth - 50, screenHeight-20, 5, COLOR_YELLOW);
    drawStar(screenWidth -30, screenHeight-10, 5, COLOR_RED);
    drawStar(screenWidth-100, screenHeight-50, 5, COLOR_YELLOW);
    chime();
    wink();
    break;

  case 4:
     limit = -1;
     clearScreen(COLOR_GOLD);
     sprintf(word,"done");
     drawString5x7(screenWidth/2,screenHeight/2,word,COLOR_WHITE,COLOR_GOLD);
     lastOne();
     wink();
     break;
  }
}
