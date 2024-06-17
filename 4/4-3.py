import numpy as np

def gauss_seidel(A, b, tolerance=0.01, max_iterations=1000):
    n = len(b)
    x = np.zeros_like(b, dtype=np.float64)
    for it_count in range(max_iterations):
        x_new = np.zeros_like(x)
        for i in range(n):
            s1 = sum(A[i][j] * x_new[j] for j in range(i))
            s2 = sum(A[i][j] * x[j] for j in range(i + 1, n))
            x_new[i] = (b[i] - s1 - s2) / A[i][i]
        if np.allclose(x, x_new, atol=tolerance, rtol=0.):
            break
        x = x_new
    return x

A = np.array([[26, -19, -8, 8],
              [9, -21, -2, 8],
              [-3, 2, -18, 8],
              [1, -6, -1, 11]], dtype=np.float64)

b = np.array([20, -164, 140, -81], dtype=np.float64)

solution = gauss_seidel(A, b)
print(f"Решение системы: {solution}")