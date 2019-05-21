#include"headers.h"
#include"declarations.h"

	//this function will have file_desc as argument and not anything else

char *CreateMaster(int fd)
{
	int retval,uni;
 	int file_size,count;
	int index_filled=0;
	char *master_arr=NULL,ch;

	//Using lseek(int FILE_DESC, int OFFSET, int WHENCE )
	
	file_size=lseek(fd,0,SEEK_END);
	printf("OMG! THis is file Size:%d\n",file_size);
	if(file_size<=1)
	{
		printf("OMG! THis is file Size:%d\n",file_size);
		exit(-1);
	}
	count=file_size-1;								 //????????????????Take a LOOK
	//printf("File_Size:%d , Count Size: %d \n", file_size,count);
	//Getting pointer to the beginning
	lseek(fd,0,SEEK_SET);
	while(count)	
	{		
#ifdef DEBUG
			printf("current_count: %d\n",count);
#endif

			retval=read(fd,&ch,1); //One byte at a time  
			if(retval==-1) //When error is encountered       
       			{
				perror("read");
				close(fd);
				exit(EXIT_FAILURE);
		               
			}
		
			else if(retval==1) 
			{
				//fill master_array
				
				uni=(*_uni)(master_arr,ch,index_filled);
					if(uni==0)
					{
						// The character is unique 
#ifdef DEBUG
						printf("uniqueValue: %c\n",ch);
#endif
						master_arr=(char*)realloc(master_arr,index_filled+1); //Allocate memory
						*(master_arr+index_filled)=ch; //fill character and also increment the space afterwards
						index_filled++;
#ifdef DEBUG
						printf("Index_Filled: %d\n",index_filled);
#endif
						count--;
					}
	
					else if(uni==1) //not unique
					{
					count--;
					}	
	
			}

	}	
	
	master_arr=(char*)realloc(master_arr,index_filled+1); //Allocate memory
	*(master_arr+index_filled)='\0'; //fill character and also increment the space after	       
#ifdef DEBUG
	printf("final array size:%d\n",strlen(master_arr));	
#endif
	return master_arr;
	

}
