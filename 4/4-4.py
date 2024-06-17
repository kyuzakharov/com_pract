import numpy as np

def prog(a, b, c, d):
    n = len(d)
    c_prime = np.zeros(n-1)
    d_prime = np.zeros(n)

    c_prime[0] = c[0] / b[0]
    d_prime[0] = d[0] / b[0]

    for i in range(1, n-1):
        c_prime[i] = c[i] / (b[i] - a[i-1] * c_prime[i-1])
    for i in range(1, n):
        d_prime[i] = (d[i] - a[i-1] * d_prime[i-1]) / (b[i] - a[i-1] * c_prime[i-1])

    x = np.zeros(n)
    x[-1] = d_prime[-1]
    for i in reversed(range(n-1)):
        x[i] = d_prime[i] - c_prime[i] * x[i+1]

    return x

a = np.array([-9, -1, -7, 6], dtype=float)
b = np.array([-14, 15, -11, 12, -7], dtype=float)
c = np.array([-6, -1, 1, 3], dtype=float)
d = np.array([-78, -73, -38, 77, 91], dtype=float)

solution = prog(a, b, c, d)
print(f"Решение системы: {solution}")