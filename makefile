main: main1.o matrixmul.o
	gcc -o main main1.o matrixmul.o -O1 /usr/lib/arm-linux-gnueabihf/libgfortran.so.3 -l:blas_LINUX.a -l:cblas_LINUX.a -l:libblas.so.3
svd: main2.o svd.o matrixmul.o
	gcc -o svd main2.o svd.o matrixmul.o -O1 /usr/lib/arm-linux-gnueabihf/libgfortran.so.3 -l:blas_LINUX.a -l:cblas_LINUX.a -l:libblas.so.3 -l:liblapacke.a -l:liblapack.so.3
main1.o: main1.c matrixmul.h
	gcc -c main1.c matrixmul.c
matrixmul.o: matrixmul.c  /usr/include/cblas.h /usr/include/lapacke.h
	gcc -c matrixmul.c
main2.o: main2.c svd.h matrixmul.h
	gcc -c main2.c svd.c matrixmul.c
svd.o: svd.c /usr/include/cblas.h /usr/include/lapacke.h
	gcc -c svd.c
clean:
	rm main svd *.o
	
