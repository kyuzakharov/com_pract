#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
double f(double x1, double x2) {
    return x1 * x1 + 3 * x2 * x2 + cos(x1 + x2);
}
double l_search(double x1, double x2, int coordinate, double step_size) {
    double best_val = f(x1, x2);
    double best_coord = (coordinate == 0) ? x1 : x2;

    for (int i = -10; i <= 10; ++i) {
        double new_coord = ((coordinate == 0) ? x1 : x2) + i * step_size;
        double new_val;
        if (coordinate == 0) {
            new_val = f(new_coord, x2);
        } else {
            new_val = f(x1, new_coord);
        }

        if (new_val < best_val) {
            best_val = new_val;
            best_coord = new_coord;
        }
    }

    return best_coord;
}
void coord_descent(vector<double>& x, double step_size, int max_iter) {
    int n = x.size();

    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < n; ++i) {
            x[i] = l_search(x[0], x[1], i, step_size);
        }
    }
}

int main() {
    vector<double> x = {0.0, 0.0};
    double step_size = 0.1;
    int max_iter = 100;
    coord_descent(x, step_size, max_iter);
    cout << "Минимум функции достигается в точке: (" << x[0] << ", " << x[1] << ")" << endl;
    cout << "Значение функции в этой точке: " << f(x[0], x[1]) << endl;

    return 0;
}
