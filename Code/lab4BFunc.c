/**
 * Lab4.c - Etch-a-Sketch and Pong
 * Description: Uses nokiaBFunc.asm to create a bouncing block.
 * Author: C2C Sean Gavan
 * Date Last Editted: 22 Oct. 14
 * Started: 22 Oct. 14
 * Documentation: None
 */
#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)


void main() {

	unsigned char	x, y, button_press;
	signed int	 xVel, yVel;			// Define new velocity variables

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;	xVel=1;		yVel=1;		// Initialized new velocity variables
	drawBlock(y,x);

	while(1) {

			if (AUX_BUTTON == 0) {				// Syntax similar to other buttons
				while(AUX_BUTTON == 0);
				if(y<=1) {						// Check for walls and reverse velocity
					yVel=1;						// as needed
				} else if (y>=7) {
					yVel=-1;
				} else if (x<=1) {
					xVel=1;
				} else if (x>=11) {
					xVel=-1;
				}

				y=y+yVel;						// Moving uses SW3 as the delay
				x=x+xVel;

				button_press = TRUE;
			}

			if (button_press) {
				button_press = FALSE;
				clearDisplay();					// Clear and redraw in new spot
				drawBlock(y,x);
			}
		}
}

