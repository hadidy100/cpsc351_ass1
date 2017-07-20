all: dl_parallel dl_serial

dl_parallel: dl.c
	gcc -o dl_parallel -DPARALLEL dl.c

dl_serial: dl.c
	gcc -o dl_serial dl.c
