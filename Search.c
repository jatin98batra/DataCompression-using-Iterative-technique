#include"headers.h" 


int Search(char *ma,char ch)
{	int i=0;
	while(*(ma+i)!='\0') //finding the entry in the master array

                {	
                        if((*(ma+i))==ch)
				{
	                               	return i;
				
				}
			i++;
                }
return -1;
}

