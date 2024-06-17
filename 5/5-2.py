import numpy as np

def newtoncoef(x, y):
    n = len(x)
    coefficients = np.copy(y)

    for j in range(1, n):
        for i in range(n - 1, j - 1, -1):
            coefficients[i] = (coefficients[i] - coefficients[i - 1]) / (x[i] - x[i - j])

    return coefficients

def newtonpolyn(x, coefficients, x_val):
    n = len(x)
    result = coefficients[-1]

    for i in range(n - 2, -1, -1):
        result = result * (x_val - x[i]) + coefficients[i]

    return result

x = [0.1 * np.pi, 0.2 * np.pi, 0.3 * np.pi, 0.4 * np.pi]
y = [np.cos(xi) for xi in x]

coefficients = newtoncoef(x, y)

x_star = 0.25 * np.pi
y_star = np.cos(x_star)

y_interpolated = newtonpolyn(x, coefficients, x_star)

error = abs(y_star - y_interpolated)

print(f"Значение интерполяционного многочлена в точке x* = {x_star} равно: {y_interpolated}")
print(f"Истинное значение функции в точке x* = {y_star}")
print(f"Погрешность интерполяции: {error}")
