
.PHONY: all
all: aes-asm aes-c benchmarker

aes-asm: aesdqw.asm
	 nasm -felf64 -o aex.o aesdqw.asm
	 ld -o aex aex.o

aes-c:  aesc.c
	gcc aesc.c -o aesc -march=native -O3 -maes

benchmarker: benchDrive.c 
	gcc  -o benchDrive benchDrive.c
	
run: aex aesc benchDrive
	./benchDrive ./aex ./aesc


