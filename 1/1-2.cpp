#include <iostream>
#include <cmath>
#include <functional>

double f(double x) {
    return x * exp(x) - x - 1;
}

double df(double x) {
    return exp(x) * (x + 1) - 1;
}

double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        std::cerr << "Неправильный начальный интервал [a, b]." << std::endl;
        return NAN;
    }
    while ((b - a) / 2.0 > tol) {
        double midpoint = (a + b) / 2.0;
        if (f(midpoint) == 0) {
            return midpoint;
        } else if (f(a) * f(midpoint) < 0) {
            b = midpoint;
        } else {
            a = midpoint;
        }
    }
    return (a + b) / 2.0;
}

double fixed_point_iteration(double x0, double tol, int max_iter) {
    auto g = [](double x) {
        return (x + 1) / exp(x);
    };

    double x_prev = x0;
    for (int i = 0; i < max_iter; ++i) {
        double x_next = g(x_prev);
        if (fabs(x_next - x_prev) < tol) {
            return x_next;
        }
        x_prev = x_next;
    }
    return NAN;
}

double secant(double x0, double x1, double tol, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        double f_x0 = f(x0);
        double f_x1 = f(x1);
        if (fabs(f_x1 - f_x0) < tol) {
            std::cerr << "Метод хорд не сходится." << std::endl;
            return NAN;
        }
        double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        if (fabs(x2 - x1) < tol) {
            return x2;
        }
        x0 = x1;
        x1 = x2;
    }
    return NAN;
}

double newton(double x0, double tol, int max_iter) {
    for (int i = 0; i < max_iter; ++i) {
        double f_x0 = f(x0);
        double df_x0 = df(x0);
        if (fabs(df_x0) < tol) {
            std::cerr << "Ошибка" << std::endl;
            return NAN;
        }
        double x1 = x0 - f_x0 / df_x0;
        if (fabs(x1 - x0) < tol) {
            return x1;
        }
        x0 = x1;
    }
    return NAN;
}

int main() {
    double a = 0;
    double b = 1;
    double tol = 1e-6;
    int max_iter = 1000;
    double x0 = 0.5;
    double x1 = 0.6;

    double root_bisection = bisection(a, b, tol);
    double root_fixed_point_iteration = fixed_point_iteration(x0, tol, max_iter);
    double root_secant = secant(x0, x1, tol, max_iter);
    double root_newton = newton(x0, tol, max_iter);

    std::cout << "Корень методом дихотомии: " << root_bisection << std::endl;
    std::cout << "Корень методом итераций: " << root_fixed_point_iteration << std::endl;
    std::cout << "Корень методом хорд: " << root_secant << std::endl;
    std::cout << "Корень методом Ньютона: " << root_newton << std::endl;

    return 0;
}
