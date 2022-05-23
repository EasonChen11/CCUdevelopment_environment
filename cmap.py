import matplotlib.pyplot as plt
import numpy as np
x = int(input("please enter X of second picture:"))
y = int(input("please enter Y of second picture:"))
img = []
save = []


def factor(f):
    for i in range(y):
        for j in range(0, 256, f):
            save.append(j)
        img.append(save.copy())
        save.clear()


def multiple(param):
    for i in range(y):
        for a in range(256):
            for j in range(param):
                save.append(a)
        img.append(save.copy())
        save.clear()


if x <= 256:
    factor(256 // x)
else:
    multiple(x // 256)
if x > 1:
    for i in range(y):
        img[i][x-1] = 255
for i in range(len(img)):
    print(img[i])
plt.imshow(img, cmap='gray', vmin=0, vmax=255)
plt.show()
