#include <stdio.h>

int main()
{
    int xm, ym, xr, yr, distancia;
    scanf("%d %d %d %d", &xm, &ym, &xr, &yr);
    if (xm < xr)
    {
        distancia = (xr - xm);
    }
    else if (xm > xr)
    {
        distancia = (xm - xr);
    }
    else
    {
        distancia = 0;
    }

    if (ym < yr)
    {
        distancia += (yr - ym);
    }
    else if (ym > yr)
    {
        distancia += (ym - yr);
    }
    else
    {
        distancia += 0;
    }

    printf("%d\n", distancia);

    return 0;
}