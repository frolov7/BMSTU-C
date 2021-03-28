#include <string.h>
#include "my_strchr.h"
char *my_strchr(const char *str, int c)
{
	int i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (c == str[i])
		return (char*)str + i;
	else
		return NULL;
}