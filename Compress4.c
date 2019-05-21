#include"headers.h"
#include"declarations.h"


/*
 * 	Basic Algo:
 * 	Create a byte which is having four bits alloted to a single character according to their postion in the  master array
 * 	and then append that byte to the newly created file compressed(n)_txt.txt 
 */



int compress4(char *ma, int fd)
{	
	printf("Begin: %s\n",__func__);
	int x;
	unsigned char byte,ch,temp;
	unsigned int new_fd,file_size,flag=0,i=0;
	
	
	//Reading the character from the file
	lseek(fd,0,SEEK_SET);
	file_size=lseek(fd,0,SEEK_END);
	file_size=file_size-1; // Why? 
#ifdef DEBUG
	printf("File_Size: %d\n",file_size);
#endif

	lseek(fd,0,SEEK_SET);
	new_fd=(*_opn)("O_WRONLY|O_CREAT");

	while(1)
	{	
		if(flag == 1)
		{
			//data is over , push the EOF and take the EXIT
			byte=byte^byte;
			byte=byte|(0xF0);
			write(new_fd,&byte,1);	 	//Write a byte 
			break;
		
		}

		if(read(fd,&ch,1) == -1)
		{
#ifdef DEBUG
			perror("read");
#endif
			exit(EXIT_FAILURE);
		}
		i=(*_srh)(ma,ch);	 //Returns position/index Search works absolutely fine , no need of any work here 
		if(i==-1)
		{
			perror("Wrong Key Choosen");
			exit(EXIT_FAILURE);
		}

		byte=byte^byte;		 //Flushing data
		byte=(char)i;	//sprintf(&byte,"%d",i);			
#ifdef DEBUG
		printf("IntegerVal: %d\n",i);
#endif
		byte=byte<<4;
		file_size--;
		if(file_size==0)
		{
			flag=1; //putting the responsibilty of closing on the next stage
		}



///////////////////////////////////////////////////////////SECOND STAGE BEGINS////////////////////////////////////////////
	



		if(flag == 1) //check if there is no data left
		{
			temp=temp^temp;
			temp=0x0F;
			byte=byte|temp;
			write(new_fd,&byte,1);
			break;
		
		}
		if(read(fd,&ch,1) == -1)
		{
#ifdef DEBUG
			perror("read:");
#endif
			exit(-1);
		}

		i=(*_srh)(ma,ch); 	//Returns position/index
		temp=temp^temp;
		temp=(char)i;
		
		temp=temp<<4;
		temp=temp>>4;
		byte=byte|temp;
		write(new_fd,&byte,1);	 //Write a byte 
		file_size--;
		if(file_size==0)
		{
			flag=1; //putting the responsibility on the next stage
		}	
	
	}	
	
	close(new_fd);
	printf("End: %s\n",__func__);
return 0;



}
