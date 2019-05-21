//User_defined _function_prototype
//#define DEBUG



char *CreateMaster(int); 
char* (*_crma)(int);

int  CalBitLen(char*);
int (*_cal)(char*);

int  OpenFile(char*);
int (*_opn)(char*);

int  Unique(char*,char,int);
int (*_uni)(char*,char,int);

int compress2(char*,int);
int(*_comp2)(char*,int); 


int compress3();
int(*_comp3)();


int compress4(char*,int);
int(*_comp4)(char*,int);

int compress5();
int(*_comp5)();


int compress6();
int(*_comp6)();


int compress7();
int(*_comp7)();

int Search(char*,char);
int (*_srh)(char*,char);

int decomp4(char*);
int decomp2(char*);

int SelectComp(int,char*,int);

int Initialize();

int showBits(unsigned char);

