# Переменные
CFLAGS = -std=c99 -Wall -Werror -c
#LFLAGS = -lsubunit -lpthread -lrt -lm
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость
.PHONY: clean unit

static: apps.exe

dynamic: work_arrd.dll appd.exe

appd.exe: $(O)main.o $(O)functions.o
	gcc -o $@ $^ -L . -l work_arrd

apps.exe: $(O)main.o $(O)functions.o work_arr.lib
	gcc -o $@ $^ $(LFLAGS)

work_arrd.dll: $(O)work_arr.o 
	gcc -o $@ $^ -shared $(LFLAGS)
		
work_arr.lib: $(O)work_arr.o
	ar rcs $@ $^

$(O)check_main.o: ./unit_tests/check_main.c $(I)key.h $(I)mysort.h
	gcc $(CFLAGS) $< -o $@

$(O)main.o: $(S)main.c $(I)work_arr.h $(I)functions.h 
	gcc $(CFLAGS) $< -o $@

$(O)work_arr.o: $(S)work_arr.c $(I)work_arr.h 
	gcc $(CFLAGS) $< -o $@

$(O)functions.o: $(S)functions.c $(I)functions.h 
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f $(O)*.o *.exe *.a *.so