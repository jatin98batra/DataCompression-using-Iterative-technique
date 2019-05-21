#include"headers.h"

extern int errno;
int OpenFile(char* filemod)
{	//char ch;
	//read(0,&ch,1);	 //flushing
	int file_desc;
	printf("File or Path?\n");
	char* filename=(char*)malloc(19);
	scanf(" %s",filename);					//fgets(filename,18,stdin);
								//*(filename+(strlen(filename)-1))='\0';
	if(strncmp(filemod,"O_RDONLY",8)==0)
        	file_desc=open(filename,O_RDONLY);
	else if(strncmp(filemod,"O_WRONLY",8)==0)	
	        file_desc=open(filename,O_WRONLY);
	else if(strncmp(filemod,"O_WRONLY|O_CREAT",16)==0)
		 file_desc=open(filename,O_WRONLY|O_CREAT);

        if(file_desc==-1)
	{
      		  perror("Open");
		printf("ErrorNo: %d\n",errno);
      	          exit(EXIT_FAILURE);
	 }
        printf("File descripter choosen due to availability:%d\n",file_desc);

return file_desc;
}
