/* We do not know much about C yet, but you probably heard about
 * recursion in other languages. Recursion works the same in C. We
 * will use it to write a very simple function, which computes the
 * factorial of a number. The standard library does not have a
 * function like this. */

int factorial( int n )
{
    if ( n <= 0 )
        return 1;
    else
        return n * factorial( n - 1 );
}

/* This was easy. Notice that we did not use any ‹#include›
 * statements. */
