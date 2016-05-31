#define RCGCGPIO (*((unsigned int*)0x400FE608u)) //clock gating control
#define GPIOF_BASE 0x40025000u
#define GPIOF_DIR (*((unsigned int*)(GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int*)(GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int*)(GPIOF_BASE + 0x3FCU)))
int main()
{
RCGCGPIO = 0x20u; //enable clock for GPIOF
GPIOF_DIR = 0x0Eu; //set pins 1,2 and 3 output
GPIOF_DEN = 0x0Eu;
unsigned int counter =0;
while (1)
{
counter =0;
GPIOF_DATA=0x02u;
while (counter <1000000){++counter;} //delay loop
counter =0;
GPIOF_DATA=0x04u;
while (counter <1000000){++counter;} //delay loop
counter =0;
GPIOF_DATA=0x08u;
while (counter <1000000){++counter;} //delay loop
}
return 0;
}
