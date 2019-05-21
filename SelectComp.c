#include"headers.h"
#include"declarations.h"

int SelectComp(int bits,char*ma,int fd)
{
	printf("Bits:%d\n",bits);
	printf("Begin:%s\n",__func__);
	switch(bits)
	{
		case 2: (*_comp2)(ma,fd); 
			break;
		case 3: (*_comp3)(); 
			break;
		case 4:	(*_comp4)(ma,fd);
		       	break;
		case 5: (*_comp5)();
		       	break;
		case 6: (*_comp6)();
		       	break;
		case 7: (*_comp7)(); 
			break;
		default: printf("Compression Not Possible\n");
	
	}

return 0;





}
