#include"headers.h"

int Unique(char*string,char ch, int s)
{	if(string==NULL) 		//Empty String
		return 0;	
	int i;
	for(i=0;i<s;i++) //strlen() returns the length of string excluding the '\0'
	{
		if(ch==(*(string+i))) // Present 
			return 1;
		
		else //Not present but we have not scanned the whole array
		
			continue;

	
	}
	//if came out of the loop and nothing found
	return 0;
						
}
