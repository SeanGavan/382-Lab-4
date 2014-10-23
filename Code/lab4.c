/**
 * Lab4.c - Etch-a-Sketch and Pong
 * Description: Uses button pressed on the LCD display to call subroutines of
 * nokia.asm and draw a black or white block.
 * Author: C2C Sean Gavan
 * Date Last Editted: 22 Oct. 14
 * Started: 21 Oct. 14
 * Documentation: C2C Terragnoli and I discussed ideas on how to define the color
 * variable, and how to implement changing it.
 */
#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);	// Additional variable color

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define		BLACK			2				// Defined the two colors to change between using arbitrary numbers
#define		WHITE			3

void main() {

	unsigned char	x, y, button_press, color;			// Define new variable color

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;	color=2;			// Initialized new variable color to 2 (BLACK)
	drawBlock(y,x,color);			// New call with color variable

	while(1) {

			if (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (y>=1) y=y-1;
				button_press = TRUE;
			} else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y<=6) y=y+1;
				button_press = TRUE;
			} else if (LEFT_BUTTON == 0) {
				while(LEFT_BUTTON == 0);
				if (x>=1) x=x-1;
				button_press = TRUE;
			} else if (RIGHT_BUTTON == 0) {
				while(RIGHT_BUTTON == 0);
				if (x<=10) x=x+1;
				button_press = TRUE;
			} else if (AUX_BUTTON == 0) {				// Syntax similar to other buttons
				while(AUX_BUTTON == 0);
				if (color == BLACK) color = WHITE;		// If BLACK, change to WHITE
				else if (color == WHITE) color = BLACK;	// Else if WHITE, change to BLACK
				button_press = TRUE;
			}

			if (button_press) {
				button_press = FALSE;
				//clearDisplay();			// Commented out to leave block drawings behind
				drawBlock(y,x,color);		// New call again
			}
		}
}
