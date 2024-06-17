import numpy as np
def suma(x, tolerance=1e-6):
    sum_value = 0.0
    k = 1
    term = tolerance

    while np.abs(term) >= tolerance:
        term = ((-1)**k) / (np.sin(k * x) + 2 + k**2)
        sum_value += term
        k += 1

    return sum_value

x = 1.0
result = suma (x)
print(f"Сумма ряда для x = {x} приближенно равна {result:.6f}")