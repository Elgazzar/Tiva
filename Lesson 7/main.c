#include "tm4c123gh6pm.h"
int main()
{
SYSCTL_RCGCGPIO_R = 0x20; //enable clock for GPIOF
GPIO_PORTF_DIR_R = 0x0E; //set pins 1,2 and 3 output
GPIO_PORTF_DEN_R = 0x0E;
unsigned int counter =0;
while (1)
{
counter =0;
GPIO_PORTF_DATA_R=0x02;
while (counter <1000000){++counter;} //delay loop
counter =0;
GPIO_PORTF_DATA_R=0x04;
while (counter <1000000){++counter;} //delay loop
counter =0;
GPIO_PORTF_DATA_R=0x08;
while (counter <1000000){++counter;} //delay loop
}
return 0;
}
