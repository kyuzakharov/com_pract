import numpy as np

def f(x):
    x1, x2 = x
    return 7*x1**2 + 2*x1*x2 + 5*x2**2 + x1 - 10*x2

def grad_f(x):
    x1, x2 = x
    df_dx1 = 14*x1 + 2*x2 + 1
    df_dx2 = 2*x1 + 10*x2 - 10
    return np.array([df_dx1, df_dx2])

# 1
def descent(f, grad_f, x0, step=0.01, tolerance=1e-6, max_iterations=10000):
    x = x0
    for i in range(max_iterations):
        gradient = grad_f(x)
        x_new = x - step * gradient
        if np.linalg.norm(x_new - x) < tolerance:
            break
        x = x_new
    return x

x0 = np.array([0, 0], dtype=float)

solution = descent(f, grad_f, x0)
print(f"Оптимальная точка: {solution}")
print(f"Значение функции в оптимальной точке: {f(solution)}")