#include<stdio.h>
#include<stdlib.h> 
#include<fcntl.h> // for open 
#include<unistd.h> //for close : without this  gcc takes implicit declatrations
#include<string.h> //for memset
#include<math.h>
#include<errno.h>
#define expected_file_size 50
