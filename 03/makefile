CFLAGS += -std=c99
CFLAGS += -MD -MP

SRC = factorial.c fib.c math.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

libmath.a:factorial.c fib.c
	make factorial.o
	make fib.o
	ar r libmath.a factorial.o fib.o

math: math.o libmath.a
	cc -o math math.o libmath.a

-include $(DEP)