
int main()
{
*((unsigned int*)0x400FE608u)=0x20u;
*((unsigned int*)0x40025400u)=0x0Eu;
*((unsigned int*)0x4002551cu)=0x0Eu;
unsigned int counter =0;
while (1)
{
*((unsigned int*)0x400253fcu)=0x00u;
while (counter <10000000){++counter;}
*((unsigned int*)0x400253fcu)=0x02u;
while (counter <10000000){++counter;}
}
return 0;
}
