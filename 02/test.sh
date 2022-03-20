cc -E write.c -o write.i
cc -S write.i -o write.s
cc -c write.s -o write.o
cc write.o
cat write.c | ./a.out copy.c
./a.out ~/bin/write.c
