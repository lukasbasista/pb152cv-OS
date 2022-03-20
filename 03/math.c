/* This program uses the two functions from ‹libmath.a›, ‹factorial›
 * and ‹fib›.  We will not bother with a header file, instead, we
 * will provide prototypes here: */

int fib( int );
int factorial( int );

/* We will need some system functions though: */

#include <stdio.h>

/* As usual, we will have a ‹main› function. */

int main()
{
    /* Let us compute the fourth Fibonacci number and the factorial
     * of 4. */

    int x = fib( 4 );
    int y = factorial( 4 );

    /* But alas, we do not know yet how to print numbers to the
     * screen, only strings. For that, we need a function known as
     * ‹printf›. It is pretty magical, so I will only show you how
     * to use it to print numbers, not how it works. */

    printf( "fourth fibonacci number: %d\n", x );
    printf( "factorial of four: %d\n", y );

    /* It is the ‹%d› in the string that is ‘magical’ and tells
     * ‹printf› that the next argument is a number that it should
     * put in the place of that ‹%d›. It is not very hard to use,
     * until you make a mistake. Then it becomes hard to understand
     * what is happening. It is better to not make mistakes. */
}
