#include"headers.h"
#include"declarations.h"

// Start
int main()
{
	Initialize();
	int count=0;
	char* master_arr;	
	int fd;		
	//Opening_File : file.txt
	fd=(*_opn)("O_RDONLY"); 
	
	//Creating master array: All unique characters
	master_arr=(*_crma)(fd);
#ifdef DEBUG
	printf("%s\n",__func__);
	printf("%d\n",strlen(master_arr));
	printf("%s\n",master_arr);
#endif


	int bits=(*_cal)(master_arr);
#ifdef DEBUG
	printf("%s\n",__func__);
	printf("Max number of bits needed: %d\n",bits);
#endif
	SelectComp(bits,master_arr,fd);

	decomp2(master_arr);
	
	
	free(master_arr);
	close(fd);
	return 0;
}

