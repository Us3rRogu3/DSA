gcc -c sort.c
gcc -c driver.c
gcc -o test sort.o driver.o
./test < test1.txt
