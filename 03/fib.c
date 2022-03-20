/* Like with factorial, there is a very simple recursive definition
 * of the Fibonacci numbers. Let's do that now. */

int fib( int n )
{
    if ( n <= 2 )
        return 1;
    else
        return fib( n - 1 ) + fib( n - 2 );
}
