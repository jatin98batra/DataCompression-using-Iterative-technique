#include"headers.h"
#include"declarations.h"

int decomp2(char *ma)

{	
unsigned int i,fd,extractedNumber,rightShift=6,loopNum=4;
unsigned char ch,mask,extractedChar;
printf("fourbit.txt\n");
fd=(*_opn)("O_RDONLY");

while(1)
{	
	if(read(fd,&ch,1) == -1)
	{
#ifdef DEBUG
		perror("read_decomp2");
#endif
		exit(-1);
	}
	mask=0xC0;
	rightShift=6;
	loopNum=4;
	while(loopNum--)
	{
		extractedChar=ch&mask;
		extractedChar=extractedChar>>rightShift;
		if(extractedChar == 0x03)
			{
				printf("\n");
				return 0;
			}
		extractedNumber=(int)extractedChar;
		printf("%c",*(ma+extractedNumber));
		rightShift=rightShift-2;
		mask=mask>>2;
	}
		
}

return 0;
}
