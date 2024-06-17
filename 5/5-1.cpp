#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void First(const vector<double>& x, const vector<double>& y, double& a0, double& a1) {
    int n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    a1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a0 = (sumY - a1 * sumX) / n;
}

void Second(const vector<double>& x, const vector<double>& y, double& a0, double& a1, double& a2) {
    int n = x.size();
    double sumX = 0, sumY = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0, sumXY = 0, sumX2Y = 0;

    for (int i = 0; i < n; ++i) {
        double x2 = x[i] * x[i];
        sumX += x[i];
        sumY += y[i];
        sumX2 += x2;
        sumX3 += x2 * x[i];
        sumX4 += x2 * x2;
        sumXY += x[i] * y[i];
        sumX2Y += x2 * y[i];
    }

    double denominator = n * (sumX2 * sumX4 - sumX3 * sumX3) - sumX * (sumX * sumX4 - sumX2 * sumX3) + sumX2 * (sumX * sumX3 - sumX2 * sumX2);
    a0 = (sumY * (sumX2 * sumX4 - sumX3 * sumX3) - sumX * (sumXY * sumX4 - sumX2Y * sumX3) + sumX2 * (sumXY * sumX3 - sumX2Y * sumX2)) / denominator;
    a1 = (n * (sumXY * sumX4 - sumX2Y * sumX3) - sumY * (sumX * sumX4 - sumX2 * sumX3) + sumX2 * (sumY * sumX3 - sumX2Y * sumX2)) / denominator;
    a2 = (n * (sumX2 * sumX2Y - sumXY * sumX3) - sumX * (sumX * sumX2Y - sumXY * sumX2) + sumY * (sumX * sumX3 - sumX2 * sumX2)) / denominator;
}

int main() {
    vector<double> x = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};
    vector<double> y = {-0.5, 0.0, 0.5, 0.86603, 1.0, 0.86603};

    double a0, a1, a2;

    First(x, y, a0, a1);
    cout << "Коэффициенты многочлена первой степени:" << endl;
    cout << "a0 = " << a0 << endl;
    cout << "a1 = " << a1 << endl;

    Second(x, y, a0, a1, a2);
    cout << "Коэффициенты многочлена второй степени:" << endl;
    cout << "a0 = " << a0 << endl;
    cout << "a1 = " << a1 << endl;
    cout << "a2 = " << a2 << endl;

    return 0;
}
