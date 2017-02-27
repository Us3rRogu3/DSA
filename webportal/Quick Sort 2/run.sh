gcc -c driver.c
gcc -c qsort.c
gcc -o test driver.o qsort.o
./test < test1.txt
