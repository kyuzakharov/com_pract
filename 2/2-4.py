import random
import numpy as np

a = random.uniform(1, 10)
b = random.uniform(1, 10)

A = random.uniform(-10, 10)
B = random.uniform(-10, 10)
C = random.uniform(-10, 10)
D = random.uniform(-10, 10)

x0 = random.uniform(-10, 10)
y0 = random.uniform(-10, 10)
z0 = random.uniform(-10, 10)
l = random.uniform(-10, 10)
m = random.uniform(-10, 10)
n = random.uniform(-10, 10)

x = random.uniform(-20, 20)
y = random.uniform(-20, 20)
z = random.uniform(-20, 20)

def pointhypercylinder(x, y, a, b):
    return np.isclose((x**2 / a**2) - (y**2 / b**2), 1, atol=1e-5)

pointbelongs = pointhypercylinder(x, y, a, b)
def planehypercylinder(A, B, C, D, a, b):
    for z_slice in np.linspace(-10, 10, 100):
        if np.any((A**2 / a**2) - (B**2 / b**2) != 0):
            return True
    return False

def linehypercylinder(x0, y0, z0, l, m, n, a, b):
    t_values = np.linspace(-10, 10, 100)
    for t in t_values:
        x_t = x0 + l * t
        y_t = y0 + m * t
        if pointhypercylinder(x_t, y_t, a, b):
            return True
    return False
print(f"Параметры гиперболического цилиндра: a = {a}, b = {b}")
print(f"Коэффициенты плоскости: A = {A}, B = {B}, C = {C}, D = {D}")
print(f"Коэффициенты прямой: (x - {x0})/{l} = (y - {y0})/{m} = (z - {z0})/{n}")
print(f"Координаты точки: ({x}, {y}, {z})")
print(f"Точка {'принадлежит' if pointbelongs else 'не принадлежит'} гиперболическому цилиндру")
print(f"Плоскость {'пересекает' if planehypercylinder(A, B, C, D, a, b) else 'не пересекает'} гиперболический цилиндр")
print(f"Прямая {'пересекает' if linehypercylinder(x0, y0, z0, l, m, n, a, b) else 'не пересекает'} гиперболический цилиндр")
