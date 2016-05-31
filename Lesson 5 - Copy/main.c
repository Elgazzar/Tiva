#include "tm4c123gh6pm.h"
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
void delay (int timer)
{
  int volatile counter=0;
  while (counter<timer){++counter;}
}
int main()
{
SYSCTL_RCGCGPIO_R |= (1U << 5); //enable clock for GPIOF
GPIO_PORTF_DIR_R  |= (LED_RED | LED_BLUE | LED_GREEN); //set pins 1,2 and 3 output
GPIO_PORTF_DEN_R  |= (LED_RED | LED_BLUE | LED_GREEN);
unsigned int volatile counter =0;
while (1)
{
counter =0;
GPIO_PORTF_DATA_R |=LED_RED;
GPIO_PORTF_DATA_R &= ~LED_BLUE;
GPIO_PORTF_DATA_R &= ~LED_GREEN;
delay(1000000); //delay loop
counter =0;
GPIO_PORTF_DATA_R |=LED_BLUE;
GPIO_PORTF_DATA_R &= ~LED_RED;
GPIO_PORTF_DATA_R &= ~LED_GREEN;
delay(1000000); //delay loop
counter =0;
GPIO_PORTF_DATA_R |=LED_GREEN;
GPIO_PORTF_DATA_R &= ~LED_RED;
GPIO_PORTF_DATA_R &= ~LED_BLUE;
delay(1000000); //delay loop
}
return 0;
}