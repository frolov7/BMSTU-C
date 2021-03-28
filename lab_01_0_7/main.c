#include <stdio.h>
#include <math.h>

double calculation(double x, double eps)
{
    double s = 0, curr = 1;
    int n = 0;

    while (fabs(curr) > eps)
    {
        if (n != 0)
            curr *= x / n;
        s += curr;
        n += 1;
    }

    return s;
}

int main()
{
    double x, eps, summ, f;

    if (scanf("%lf%lf", &x, &eps) != 2 || eps < 0 || eps >= 1)
    {
        printf("Error\n");
        return 1;
    }

    summ = calculation(x, eps);
    f = exp(x);
    printf("\ns(x) = %.6lf\n", summ);
    printf("f(x) = %.6lf\n", f);
    printf("Абсолютная ошибка %.6lf\n", fabsf(f - summ));
    printf("Относительная ошибка %.6lf", fabs((f - summ) / f));

    return 0;
}

