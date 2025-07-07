#include <stdio.h>
#include <stdlib.h>

long fat(long n)
{
    if(n<=1)
        return 1;
    else{
        return(n* fat(n-1));
    }
}
