
#include "io430.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
 //DCO Trabajando a 1MHz aprox.
  BCSCTL1 = CALBC1_1MHZ; //T = 1/f  @1MHz T=1us
  DCOCTL  = CALDCO_1MHZ;
 
  
  //Timer0 , UP, SMCLK
  TACTL = TASSEL_2+MC_1;
  TACCR0 = 255;       //Valor para tener 255 niveles de brillo
  
  TACCTL1 = OUTMOD_7;   //Reset/set
  TACCR1 = 150;         //LED VERDE (Brillo entre 0 y 255)

  P1SEL_bit.P6 = 1;     //La terminal P1.6 E/S del sistema temporizador TIMER0
  P1DIR_bit.P6 = 1;     //La terminal P1.6 salida de comparación PWM
  
  //Timer1 , UP, SMCLK
  TA1CTL = TASSEL_2+MC_1;
  TA1CCR0 = 255;       //Valor para tener 255 niveles de brillo
  
  TA1CCTL1 = OUTMOD_7;   //Reset/set
  TA1CCR1 = 241;         //LED ROJO (Brillo entre 0 y 255)

  P2SEL_bit.P1 = 1;     //La terminal P2.1 E/S del sistema temporizador TIMER1
  P2DIR_bit.P1 = 1;     //La terminal P2.1 salida de comparación PWM
  
  TA1CCTL2 = OUTMOD_7;   //Reset/set
  TA1CCR2 = 96;         //LED AZUL (Brillo entre 0 y 255)

  P2SEL_bit.P5 = 1;     //La terminal P2.5 E/S del sistema temporizador TIMER1
  P2DIR_bit.P5 = 1;     //La terminal P2.5 salida de comparación PWM
  
  while(1)
  {}
}
