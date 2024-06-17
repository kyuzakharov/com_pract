#include <iostream>
#include <cmath>
#include <functional>

double integrand(double x) {
    return (x * x * x * x) / (2 + x * x);
}
//прямоугол
double rectangl(double a, double b, double epsilon, std::function<double(double)> func) {
    int n = 1;
    double h = b - a;
    double integral = h * func((a + b) / 2.0);

    while (true) {
        n *= 2;
        double sum = 0.0;
        h = (b - a) / n;

        for (int i = 0; i < n; ++i) {
            sum += func(a + i * h + h / 2);
        }

        double new_integral = h * sum;
        if (std::abs(new_integral - integral) < epsilon) {
            return new_integral;
        }
        integral = new_integral;
    }
}
//Трап
double trapezoidal(double a, double b, double epsilon, std::function<double(double)> func) {
    int n = 1;
    double h = b - a;
    double integral = (func(a) + func(b)) * h / 2.0;

    while (true) {
        n *= 2;
        double sum = 0.0;
        h = (b - a) / n;

        for (int i = 1; i < n; ++i) {
            sum += func(a + i * h);
        }

        double new_integral = h * ((func(a) + func(b)) / 2.0 + sum);
        if (std::abs(new_integral - integral) < epsilon) {
            return new_integral;
        }
        integral = new_integral;
    }
}

//Симпсона
double simpson(double a, double b, double epsilon, std::function<double(double)> func) {
    int n = 1;
    double h = b - a;
    double integral = (func(a) + func(b)) * h / 6.0;

    while (true) {
        n *= 2;
        double sum1 = 0.0;
        double sum2 = 0.0;
        h = (b - a) / n;

        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) {
                sum2 += func(a + i * h);
            } else {
                sum1 += func(a + i * h);
            }
        }

        double new_integral = h / 3.0 * (func(a) + func(b) + 4 * sum1 + 2 * sum2);
        if (std::abs(new_integral - integral) < epsilon) {
            return new_integral;
        }
        integral = new_integral;
    }
}

int main() {
    double a = 0.0;
    double b = 100.0;
    double epsilon = 1e-6;

    double resultRectangle = rectangl(a, b, epsilon, integrand);
    double resultTrapezoidal = trapezoidal(a, b, epsilon, integrand);
    double resultSimpson = simpson(a, b, epsilon, integrand);

    std::cout << "Метод прямоугольников: " << resultRectangle << std::endl;
    std::cout << "Метод трапеций: " << resultTrapezoidal << std::endl;
    std::cout << "Метод Симпсона: " << resultSimpson << std::endl;
    return 0;
}