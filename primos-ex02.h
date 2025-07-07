#ifndef PRIMOS-EX02_H_INCLUDED
#define PRIMOS-EX02_H_INCLUDED

void primo(int num)
{
    int i, resultado=0;
    for (i = 2; i <= num / 2; i++){
    if (num % i == 0) {
       resultado++;
       break;
    }
 }
 if (resultado == 0){
    printf("\n %d eh um numero primo. ", num);
    }
 else{
    printf("\n %d nao eh um numero primo. ", num);
    }
}

#endif // PRIMOS-EX02_H_INCLUDED
