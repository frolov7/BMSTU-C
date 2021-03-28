#include <stdio.h>

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4, input = 0;
    input = scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (input != 8)
    {
        printf("Input error");
        return 1;
    }
    if (((x1 == x2) && (y1 == y2)) || ((x3 == x4) && (y3 == y4)))
    {
        printf("Error. It's point");
        return 2;
    }
    else
    {
        double vec1, vec2;
        vec1 = ((x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1)) * ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
        vec2 = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) * ((x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3));
        
        double m1_m2_x = x2 - x1, m1_m2_y = y2 - y1;
        double p1_x = x3 - x1, p1_y = y3 - y1;
        double p2_x = x4 - x1, p2_y = y4 - y1;
        
        vec1 = m1_m2_x * p1_y - m1_m2_y * p1_x; 
        vec2 = m1_m2_x * p2_y - m1_m2_y * p2_x; 
        
        if (vec1 * vec2 < 0)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    return 0;
}
