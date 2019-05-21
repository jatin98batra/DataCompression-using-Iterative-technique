#include"headers.h"
#include"declarations.h"

int decomp4(char *ma)
{	int count =40;
	unsigned int i,comp_fd,up,down;
	unsigned char ch,upper_ch,lower_ch;
	printf("fourbit.txt\n");
	comp_fd=(*_opn)("O_RDONLY");
	
	while(1)
	{	
		read(comp_fd,&ch,1);
		upper_ch=upper_ch^upper_ch;
		upper_ch= ch & 0xF0;
		if(upper_ch==0xF0)
		{
			printf("\n");	
			break;
		}
		upper_ch=upper_ch>>4;
		up= (int)upper_ch;//Inplicit typecasting
		printf("%c",*(ma+up));
		lower_ch=lower_ch^lower_ch;
		lower_ch=ch & 0x0F;
		if(lower_ch==0x0F)
		{
			printf("\n");	
			break;
		}
		lower_ch=lower_ch<<4;
		lower_ch=lower_ch>>4;
		down= (int)lower_ch; //implicit typecasting
		printf("%c",*(ma+down));

	}

	return 0;




}
