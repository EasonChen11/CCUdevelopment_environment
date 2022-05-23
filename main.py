import matplotlib.pyplot as plt
import numpy as np
BLACK = 0
WHITE = 255
y_color = BLACK
x_color = y_color
x = int(input("please enter X of picture:"))
y = int(input("please enter Y of picture:"))
size = int(input("please enter size of picture:"))

img = []
save = []


def func():
    global x_color, y_color
    for i in range(0, y, size):
        for y_times in range(size):
            x_color = y_color
            for j in range(0, x, size):
                for x_times in range(size):
                    save.append(x_color)
                if x_color == BLACK:
                    x_color = WHITE
                else:
                    x_color = BLACK
            img.append(save.copy())
            save.clear()
        if y_color == BLACK:
            y_color = WHITE
        else:
            y_color = BLACK


func()
for i in range(len(img)):
    print(img[i])
plt.imshow(img, cmap='gray', vmin=0, vmax=255)
plt.show()
