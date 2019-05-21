#include"headers.h"
#include"declarations.h"

int compress2(char * ma, int fd)
{
#ifdef DEBUG
printf("Begin: %s",__func__);
#endif

int file_size;
int new_fd;
unsigned int i,flag=0;
char ch;
unsigned char byte,temp;
new_fd=(*_opn)("O_WRONLY|O_CREAT"); //for writing compressed file
file_size=lseek(fd,0,SEEK_END);
printf("file_size:%d\n",file_size);
return 0;
if(!file_size)
{
	byte=byte^byte;
	byte=0xC0;
	write(new_fd,&byte,1);
	return 0;
}
file_size--; //(WHY?) to ignore the EOF, Not comparing EOF as if its a character. Just putting the EOF in the end
lseek(fd,0,SEEK_SET);


while(1)
{
	////////////////////////First STAGE Begins////////////////////////////
	if(flag == 1)
	{
		byte=byte^byte;
		byte=0xC0;
		write(new_fd,&byte,1);
		break;
	
	}
	if(read(fd,&ch,1) == -1)
	{
		#ifdef DEBUG
			perror("read_compress2");
		#endif
			exit(EXIT_FAILURE);
	}
	
	
	i=(*_srh)(ma,ch);        //Returns position/index Search works absolutely fine , no need of any work here 
	if(i==-1)
	{
#ifdef DEBUG
               perror("Wrong Key Choosen");
#endif
	       exit(EXIT_FAILURE);
	}

	byte=byte^byte; 
	byte=(char)i;
	byte=byte<<6;
	file_size--;
	if(file_size==0)
	{
		flag=1;
	}
	////////////////////////////////////////////Second Stage Begins/////////////////////
	

	if(flag == 1)
	{
		temp^=temp;
		temp=0x30;
		byte=byte|temp;
		write(new_fd,&byte,1);
		break;	
	}
	if(read(fd,&ch,1) == -1)
	{
		#ifdef DEBUG
			perror("read_compress2");
		#endif
			exit(EXIT_FAILURE);
	}
	
	
	i=(*_srh)(ma,ch);        //Returns position/index Search works absolutely fine , no need of any work here 
	if(i==-1)
	{
#ifdef DEBUG
               perror("Wrong Key Choosen");
#endif
		exit(-1);
	}

	temp^=temp;
	temp=(char)i;
	temp=temp<<4;
	byte=byte|temp;
	file_size--;
	if(file_size == 0)
	{
		flag=1;
	}


	//////////////////////////////third Stage//////////////////////////////////

        if(flag == 1)
        {
                temp^=temp;
                temp=0x0C;
                byte=byte|temp;
                write(new_fd,&byte,1);
                break;
        }
        if(read(fd,&ch,1) == -1)
        {
                #ifdef DEBUG
                        perror("read_compress2");
                #endif
                        exit(EXIT_FAILURE);
        }


        i=(*_srh)(ma,ch);        //Returns position/index Search works absolutely fine , no need of any work here 
        if(i==-1)
        {
#ifdef DEBUG
               perror("Wrong Key Choosen");
#endif
                exit(-1);
        }

        temp^=temp;
        temp=(char)i;
        temp=temp<<2;
        byte=byte|temp;
        file_size--;
        if(file_size == 0)
        {
                flag=1;
        }
	/////////////////////////////fourth stage/////////////////////////////

        if(flag == 1)
        {
                temp^=temp;
                temp=0x03;
                byte=byte|temp;
                write(new_fd,&byte,1);
                break;
        }
        if(read(fd,&ch,1) == -1)
        {
                #ifdef DEBUG
                        perror("read_compress2");
                #endif
                        exit(EXIT_FAILURE);
        }


        i=(*_srh)(ma,ch);        //Returns position/index Search works absolutely fine , no need of any work here 
        if(i==-1)
        {
#ifdef DEBUG
               perror("Wrong Key Choosen");
#endif
                exit(-1);
        }

        temp^=temp;
        temp=(char)i;
        byte=byte|temp;
	write(new_fd,&byte,1);
        file_size--;
        if(file_size == 0)
        {
                flag=1;
        }

}	
	

printf("End: %s",__func__);
return 0;




}
