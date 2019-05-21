#! /bin/bash

final: main.o CreateMaster.o CalBitLen.o Unique.o OpenFile.o Initialize.o SelectComp.o Compress2.o Compress3.o Compress4.o Compress5.o Compress6.o Compress7.o Search.o decomp4.o decomp2.o showBits.o
	gcc -o final main.o CreateMaster.o CalBitLen.o Unique.o OpenFile.o Initialize.o SelectComp.o Compress2.o Compress3.o Compress4.o Compress5.o Compress6.o Compress7.o Search.o decomp4.o decomp2.o showBits.o -lm

Compress2.o: Compress2.c headers.h declarations.h
	gcc -c Compress2.c
Compress3.o: Compress3.c headers.h declarations.h
	gcc -c Compress3.c
Compress4.o: Compress4.c headers.h declarations.h
	gcc -c Compress4.c
Compress5.o: Compress5.c headers.h declarations.h
	gcc -c Compress5.c
Compress6.o: Compress6.c headers.h declarations.h
	gcc -c Compress6.c
Compress7.o: Compress7.c headers.h declarations.h
	gcc -c Compress7.c

Search.o: Search.c headers.h declarations.h
	gcc -c Search.c

decomp4.o: decomp4.c headers.h declarations.h
	gcc -c decomp4.c
decomp2.o: decomp2.c headers.h declarations.h
	gcc -c decomp2.c
showBits.o: showBits.c headers.h declarations.h
	gcc -c showBits.c

SelectComp.o: SelectComp.c headers.h declarations.h
	gcc -c SelectComp.c

OpenFile.o:OpenFile.c headers.h declarations.h
	gcc -c OpenFile.c

Unique.o: Unique.c headers.h declarations.h
	gcc -c Unique.c

CreateMaster.o: CreateMaster.c headers.h declarations.h
	gcc -c CreateMaster.c 

CalBitLen.o: CalBitLen.c headers.h declarations.h
	gcc -c CalBitLen.c 

Initialize.o: Initialize.c headers.h declarations.h
	gcc -c Initialize.c

main.o: main.c headers.h declarations.h
	gcc -c main.c 

clean:
	rm *.o

.PHONY:
	make clean
