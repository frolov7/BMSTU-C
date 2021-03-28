#include "../inc/my_string.h"

int numlen(unsigned long int x) 
{ 
    int len = 0;

    while (x > 0)
    {
        len++; 
        x /= 10;
    }
    return len;
}

void change(char *newnum, int len)
{
    for (int i = 0; i < len / 2; ++i)
    {
        char buf = newnum[i];
        newnum[i] = newnum[len - i - 1];
        newnum[len - i - 1] = buf;       
    }
}

void conver(char *newnum, unsigned long long int num)
{
    int j = 0;
    while (num > 0)
    {
        newnum[j] = (num % 10) + '0';
        num = num / 10;
        j++;
    }
}

int tostring(char *newnum, unsigned long long int num)
{
    int len = numlen(num);
    
    conver(newnum, num);
    change(newnum, len);

    return len;
}

int copy(char *str, size_t len, size_t size, long x)
{
    if (x == 0)
    {
        str[len] = '0';
        len++;
    }
    else
    {
        int lenght;
        char newx[SIZEBUF] = "\0";
        if (x < 0)
        {
            str[len] = '-';
            len++;
            lenght = tostring(newx, -x);
        }
        else
        {
            lenght = tostring(newx, x);
        }
        int j = 0;
        while (j < lenght && newx[j])
        {
            if (str && size && len < size)
            {
                str[len] = newx[j];
            }
            j++;
            len++;
        }
    }
    return len;
}

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    size_t len = 0;

    while (*format)
    {
        if (*format != '%')
        {
            if (str && size && len < size)
                str[len] = *format++;
            else
                format++;

            len++;
        }
        else
        {
            if (*(format + 1) == 's')
            {
                char *s = va_arg(args, char *);
                
                while (*s != '\0')
                {
                    if (str && size && len < size)
                        str[len] = *s;
                    len++;
                    s++;
                }

                format += 2;
            }
            else if (*(format + 1) == 'c')
            {
                char c = va_arg(args, int);

                if (str && size && len < size)
                    str[len] = c;

                len++;
                format += 2;
            }
            else if (*(format + 1) == 'd')
            {
                len = copy(str, len, size, va_arg(args, int));
                format += 2;
            }
            else if (*(format + 1) == 'l' && *(format + 2) == 'd')
            {
                len = copy(str, len, size, va_arg(args, long));
                format += 3;
            }
            else if (*(format + 1) == 'l' && *(format + 2) == 'l' && *(format + 3) == 'd')
            {
                len = copy(str, len, size, va_arg(args, long));
                format += 4;
            }
        }
    }

    va_end(args);

    if (str && size)
    {
        if (len < size)
            str[len] = '\0';
        else
            str[size - 1] = '\0';
    }

    return len;
}
