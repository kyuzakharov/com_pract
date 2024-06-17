#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> inverseMatrix(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> A_inv(n, vector<double>(n, 0.0));
    vector<vector<double>> augmented(A);

    for (int i = 0; i < n; ++i) {
        augmented[i].resize(2 * n);
        augmented[i][i + n] = 1.0;
    }

    for (int i = 0; i < n; ++i) {
        double pivot = augmented[i][i];
        if (abs(pivot) < 1e-9) {
            throw runtime_error("Ошибка");
        }
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= pivot;
        }
        for (int k = 0; k < n; ++k) {
            if (i != k) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A_inv[i][j] = augmented[i][j + n];
        }
    }

    return A_inv;
}
vector<double> multiplyMatrixVector(const vector<vector<double>>& A, const vector<double>& B) {
    int n = A.size();
    vector<double> result(n, 0.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i] += A[i][j] * B[j];
        }
    }

    return result;
}

//Гаусс для слау
vector<double> gaussMethod(vector<vector<double>> A, vector<double> B) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        for (int k = i; k < n; ++k) {
            swap(A[i][k], A[maxRow][k]);
        }
        swap(B[i], B[maxRow]);

        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = B[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    return x;
}

int main() {
    vector<vector<double>> A = {
            {-1, -7, -3, -2},
            {-8, 1, -9, 0},
            {8, 2, -5, -3},
            {-5, 3, 5, -9}
    };

    vector<double> B = {-12, -60, -91, -43};

    //метод обратной матрицы
    try {
        vector<vector<double>> A_inv = inverseMatrix(A);
        vector<double> X = multiplyMatrixVector(A_inv, B);
        cout << "Решение методом обратной матрицы:" << endl;
        for (double x : X) {
            cout << x << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    //Гаусс
    vector<double> X_gauss = gaussMethod(A, B);
    cout << "Решение методом Гаусса:" << endl;
    for (double x : X_gauss) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
