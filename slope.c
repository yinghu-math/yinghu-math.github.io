// Created by Ying Hu (yinghu@unomaha.edu) in 09/2019
 
#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    printf("\nINSTRUCTION:\n\nINPUTS: Please input the slope p/q and the genus g, such that g > 0,  p > 0, p and q are coprime. \n(The program will check the gcd of p and q.)\n\n");
    printf("OUTPUT: Given a rational solid torus X whose longitude is null-homologous, the program determines whether a \ntaut foliation on X(p/q) that is transverse to the core of the filling solid torus can have zero Euler class. \nIf it is possible that the Euler class equals to zero, then the required value of the relative Euler class in \nH_2(X,\\partial X) for that to happen is also returned. \nWe assume that the orientation on the foliation agrees with the orientation on the meridian disk of the \nfilling solid torus.\n\n");
    int p, q, g;
    
    do{
        printf("\nPlease enter the values of p, q and g, so that p > 0, g > 0 and (p , q) = 1:\n\n");
    	printf("p: ");
    	scanf("%i", &p);
    	printf("q: ");
    	scanf("%i", &q);
    	printf("g: ");
    	scanf("%i", &g);
    }while(p <= 0 || g <= 0 || gcd (p, q) != 1);
 
    // check whether the Euler class can be zero.
    if (p == 1 || p == 2)
    {
        printf("The Euler class of any taut foliation on X(p/q) is zero by Proposition 2.1\n\n");
    }
    else
    {
        int r;
        r = q % p;  //p/q and p/r represents the same slope upon a change of the meridian
        if (r > 0 && (p / r > 2 * g || p / (r - p) < -2 * g))
        {
            printf("The Euler class can not be zero by Corollary 4.8\n\n");
        }
        else if (r < 0 && (p / r  < - 2 * g || p / (r + p) > 2 * g))
        {
            printf("The Euler class can not be zero by Corollary 4.8\n\n");
        }
        else
        {
            int i = 0;
            int b = 0;
            do{
                b = q * (2 * i + 1) % p;
                if ((q > 0 && (b == 1 || b == p - 1)) || (q < 0 && (b == -1 || b == 1 - p)))
                {
                    printf("The Euler class can be zero, with the relative Euler class a = %i (mod %i) an odd integer between %i and %i. \n\n", 2 * i + 1, p, -2 * g + 1, 2 * g - 1);
                    return 0;
                }
                i ++;
            }while(i < g);
            printf("The Euler class can not be zero by Theorem 3.3 with k = 1.\n\n");
        }
    }
    return 0;
}

// compute the gcd of two integers.
int gcd(int a, int b)
{
    // if one of the integers is negative, then the sign of the number is changed to positive
    a = (a > 0) ? a : -a;
    b = ( b > 0) ? b : -b;
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
