gcc -c linkedlist.c
gcc -c driver.c
gcc -o test linkedlist.o driver.o
./test < test1.txt
