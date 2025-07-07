
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

partir (int x, int p)
{
    if ((x<0)||(p==0))
    {
        return 0;
    }
    else
        if (x==0)
        {
            return 1;
        }
        else
        {
            return(partir (x-p, p) + partir (x,p-1));
        }
}

main ()
{
    int x;
    int q_particao;
    int particao;

    printf("Inteiro a particionar: ");
    scanf("%d",&x);

    printf("Quant. max de particoes: ");
    scanf("%d",&q_particao);
    q_particao = SHRT_MAX; // VALOR 32767

    particao = partir (x, q_particao);

    printf("\n\nResultado: %d",particao);

}
