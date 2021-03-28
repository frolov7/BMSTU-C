#include <stdlib.h>
#include "my_strchr.h"
#include <string.h>

int main()
{
	if (my_strchr("465", '6') != strchr("465", '6'))
		return EXIT_FAILURE;
	if (my_strchr("abcdef", 'c') != my_strchr("abcdef", 'c'))
		return EXIT_FAILURE;
	if (my_strchr("aaa\nffw", '\n') != strchr("aaa\nffw", '\n'))
		EXIT_FAILURE;
	if (my_strchr("aaa,ffw", ',') != strchr("aaa,ffw", ','))
		return EXIT_FAILURE;
	if (my_strchr("-5", '5') != strchr("-5", '5'))
		return EXIT_FAILURE;
	if (my_strchr("5", 'c') != strchr("5", 'c'))
		return EXIT_FAILURE;
	if (my_strchr("-5", '4') != strchr("-5", '4'))
		return EXIT_FAILURE;
	if (my_strchr("ssfrr", '4') != strchr("ssfrr", '4'))
		return EXIT_FAILURE;
	if (my_strchr("456", '0') != strchr("456", '0'))
		return EXIT_FAILURE;
	if (my_strchr("sad", '0') != strchr("sad", '0'))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}