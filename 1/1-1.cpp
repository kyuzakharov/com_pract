#include <iostream>
#include <complex>
#include <cmath>

int main() {
    std::complex<double> z1(2, 1);
    std::complex<double> z2(2, -2);
    std::complex<double> z3(-1, 2);

    std::complex<double> sum = z1 + z2;
    std::complex<double> difference = z1 - z2;
    std::complex<double> product = z1 * z2;
    std::complex<double> quotient = z1 / z2;

    std::complex<double> z3_power4 = std::pow(z3, 4);

    std::complex<double> z3_root3 = std::pow(z3, 1.0 / 3.0);

    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Разность: " << difference << std::endl;
    std::cout << "Произведение: " << product << std::endl;
    std::cout << "Частное: " << quotient << std::endl;
    std::cout << "4 Степень z3: " << z3_power4 << std::endl;
    std::cout << "Кубический корень z3: " << z3_root3 << std::endl;

    return 0;
}