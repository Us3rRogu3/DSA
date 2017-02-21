gcc -c linkedlist.c
gcc -c driver.c
gcc -c bucketSort.c
gcc -o test linkedlist.o driver.o bucketSort.o
./test < test1.txt
