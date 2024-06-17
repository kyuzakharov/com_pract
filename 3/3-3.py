def sum_series(epsilon=1e-6):
    k = 1
    series_sum = 0
    term = 1

    while abs(term) > epsilon:
        term = 2 / (2 ** (k - 1)) + ((-1) ** (k - 1)) / (2 * (3 ** (k - 1)))
        series_sum += term
        k += 1
    return series_sum

series_1_sum = sum_series()
print(f"Сумма ряда: {series_1_sum}")