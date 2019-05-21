
#include"headers.h"

int CalBitLen(char* ma)
{  
	printf("start: %s",__func__);
	int i;
	int stringlength=strlen(ma);
	printf("String_Length:%d\n",stringlength);
	for(i=0;i<stringlength;i++)
        {
                if((pow(2,i)-1)>=stringlength) //This thing is really cleverly done ! the -1 is for making a space for EOF that can be 11,111,1111,11111,111111 or 1111111
                {
                        break;
                }


        }


        return i;
}
