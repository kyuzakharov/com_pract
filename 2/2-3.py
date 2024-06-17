import random
import numpy as np
a = random.uniform(1, 10)
b = random.uniform(1, 10)

x = random.uniform(-20, 20)
y = random.uniform(-20, 20)

def pointhyper(x, y, a, b):
    return np.isclose((x**2 / a**2) - (y**2 / b**2), 1, atol=1e-5)

pointbelongs = pointhyper(x, y, a, b)

c = np.sqrt(a**2 + b**2)
foci = [(-c, 0), (c, 0)]

eccentricity = c / a
directrixdist = 2 * a**2 / c

print(f"Параметры гиперболы: a = {a}, b = {b}")
print(f"Координаты точки: ({x}, {y})")
print(f"Точка {'принадлежит' if pointbelongs else 'не принадлежит'} гиперболе")
print(f"Координаты фокусов гиперболы: {foci}")
print(f"Длина действительной полуоси: {a}")
print(f"Длина мнимой полуоси: {b}")
print(f"Эксцентриситет гиперболы: {eccentricity}")
print(f"Расстояние между директрисами гиперболы: {directrixdist}")
