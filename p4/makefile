########################################
#Name: Songzi Wen 
#Section: 1
#Name: Xiaojian Nie
#Section: 1
########################################
CC = gcc
CFLAGS = -Wall -m32
all:cache1D cache2Drows cache2Dcols
	
cache1D:cache1D.c
	$(CC) $(CFLAGS) -o cache1D cache1D.c

cache2Drows:cache2Drows.c
	$(CC) $(CFLAGS) -o cache2Drows cache2Drows.c

cache2Dcols:cache2Dcols.c
	$(CC) $(CFLAGS) -o cache2Dcols cache2Dcols.c
	

run1D4:
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 4 -ds 16384 -da 1 -db 4 -- cache1D
run1D32:
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 32 -ds 16384 -da 1 -db 32 -- cache1D
run1D64:
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 64 -ds 16384 -da 1 -db 64 -- cache1D
run2Drows64:
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 64 -ds 16384 -da 1 -db 64 -- cache2Drows
run2Dcols64:
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 64 -ds 16384 -da 1 -db 64 -- cache2Dcols
