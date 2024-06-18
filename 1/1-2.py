import math

def f(x):
    return x * math.exp(x) - x - 1


def df(x):
    return math.exp(x) * (x + 1) - 1

def bisection(a, b, tol):
    if f(a) * f(b) >= 0:
        print("Неправильный начальный интервал [a, b].")
        return None
    while (b - a) / 2.0 > tol:
        midpoint = (a + b) / 2.0
        if f(midpoint) == 0:
            return midpoint
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    return (a + b) / 2.0


def fixed_point_iteration(x0, tol, max_iter):
    def g(x):
        return (x + 1) / math.exp(x)

    x_prev = x0
    for i in range(max_iter):
        x_next = g(x_prev)
        if abs(x_next - x_prev) < tol:
            return x_next
        x_prev = x_next
    return None


def secant(x0, x1, tol, max_iter):
    for i in range(max_iter):
        f_x0 = f(x0)
        f_x1 = f(x1)
        if abs(f_x1 - f_x0) < tol:
            print("Метод хорд не сходится.")
            return None
        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0)
        if abs(x2 - x1) < tol:
            return x2
        x0 = x1
        x1 = x2
    return None


def newton(x0, tol, max_iter):
    for i in range(max_iter):
        f_x0 = f(x0)
        df_x0 = df(x0)
        if abs(df_x0) < tol:
            print("Ошибка")
            return None
        x1 = x0 - f_x0 / df_x0
        if abs(x1 - x0) < tol:
            return x1
        x0 = x1
    return None


a = 0
b = 1
tol = 1e-6
max_iter = 1000
x0 = 0.5
x1 = 0.6

root_bisection = bisection(a, b, tol)
root_fixed_point_iteration = fixed_point_iteration(x0, tol, max_iter)
root_secant = secant(x0, x1, tol, max_iter)
root_newton = newton(x0, tol, max_iter)

print("Корень методом дихотомии:", root_bisection)
print("Корень методом итераций:", root_fixed_point_iteration)
print("Корень методом хорд:", root_secant)
print("Корень методом Ньютона:", root_newton)
