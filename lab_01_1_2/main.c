#include <stdio.h>
#include <math.h>

int main() 
{
    double a, alpha, b, h = 0, s = 0, pi = 3.1415926;
  
    scanf("%lf %lf %lf", &a, &b, &alpha);
  
    alpha = alpha * pi / 180;
  
    h = fabs(((b - a) / 2) * tan(alpha));
  
    s = ((a + b) / 2) * h;
  
    printf("%lf", s);
}
