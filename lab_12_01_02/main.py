import ctypes
import tkinter as tk

class array_utils:
    def __init__(self):
        self.__lib = ctypes.WinDLL("./array_utils.dll")
        self.__cycle_shift = self.__lib.cycle_shift
        self.__copy_squares = self.__lib.copy_squares
        self.__copy_squares.restype = ctypes.c_size_t
    
    def cycle_shift(self, l, k):
        src_len = len(l)
        arr = (ctypes.c_int * src_len)(*l)
        self.__cycle_shift(arr, ctypes.c_size_t(src_len), ctypes.c_size_t(k))
        return list(arr)

    def copy_squares(self, l):
        arr = (ctypes.c_int * len(l))(*l)
        count = self.__copy_squares(arr, ctypes.c_size_t(len(l)), ctypes.c_void_p(0))
        res = (ctypes.c_int * count)()
        self.__copy_squares(arr, ctypes.c_size_t(len(l)), res)
        return list(res)


utils = array_utils()


print(utils.copy_squares([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
print(utils.cycle_shift([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 5))


window = tk.Tk()
window.resizable(False, False)

window.title("Library test")

label1 = tk.Label(window, text="Исходный массив")
label1.grid(column=0, row=0)

source = tk.Entry(window, width=128)
source.grid(column=0, row=1)

label2 = tk.Label(window, text="Сдвиг")
label2.grid(column=0, row=2)

offset = tk.Entry(window, width=128)
offset.grid(column=0, row=3)


label3 = tk.Label(window, text="Сдвинутый массив")
label3.grid(column=0, row=5)

res_offset = tk.Entry(window, width=128)
res_offset.grid(column=0, row=6)

label4 = tk.Label(window, text="Полные квадраты")
label4.grid(column=0, row=7)

res_squares = tk.Entry(window, width=128)
res_squares.grid(column=0, row=8)

def clicked():
    try:
        l = [int(i) for i in source.get().split()]
        
        res_offset.delete(0, tk.END)
        res_offset.insert(0, str(utils.cycle_shift(l, int(offset.get()))))
        
        res_squares.delete(0, tk.END)
        res_squares.insert(0, str(utils.copy_squares(l)))

    except:
        res_offset.delete(0, tk.END)
        res_offset.insert(0, "Ошибка")
        res_squares.delete(0, tk.END)
        res_squares.insert(0, "Ошибка")

calculate = tk.Button(window, text="Посчитать", command=clicked)
calculate.grid(column=0, row=4)

window.mainloop()