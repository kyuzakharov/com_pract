import cmath

z1 = complex(2, 1)
z2 = complex(2, -2)
z3 = complex(-1, 2)

sum_result = z1 + z2
difference = z1 - z2
product = z1 * z2
quotient = z1 / z2

z3_power4 = z3 ** 4

z3_root3 = z3 ** (1/3)

print(f"Сумма: {sum_result}")
print(f"Разность: {difference}")
print(f"Произведение: {product}")
print(f"Частное: {quotient}")
print(f"4 степень z3: {z3_power4}")
print(f"Кубический корень z3: {z3_root3}")
