#include <stdio.h>

int main() 
{
    float r1, r2, r3, r_total = 0;
  
    scanf("%f %f %f", &r1, &r2, &r3);
  
    r_total = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
  
    printf("%f", r_total);
}
