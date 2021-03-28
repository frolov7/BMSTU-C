# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость
.PHONY: clean unit

unit: array_utils.dll unit_tests.exe
	./unit_tests.exe

unit_tests.exe: $(O)check_main.o 
	gcc -o $@ $^ $(LFLAGS) -lcheck -L. -larray_utils

array_utils.dll: $(O)array_utils.o 
	gcc -o $@ $^ -shared $(LFLAGS)

$(O)check_main.o: ./unit_tests/check_main.c $(I)array_utils.h
	gcc $(CFLAGS) $< -o $@

$(O)array_utils.o: $(S)array_utils.c $(I)array_utils.h 
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f $(O)*.o *.exe *.a *.dll