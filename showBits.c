#include"declarations.h"
#include"headers.h"
int showBits(unsigned char byte) 
{
	printf("MSB->");

	for(int i=0;i<8;i++)
	{
		if((byte & 0x80 ) == 0x80)
			printf("1");
		else
			printf("0");
	byte=byte<<1;
		
	}
	printf("<-LSB\n");



return 0;
}
