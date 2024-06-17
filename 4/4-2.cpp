#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double determinant(const vector<vector<double>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}
//Крамер
vector<double> cramer(const vector<vector<double>>& A, const vector<double>& B) {
    vector<double> X(3);
    double detA = determinant(A);

    if (abs(detA) < 1e-9) {
        throw runtime_error("Матрица не может быть решена методом Крамера");
    }

    for (int i = 0; i < 3; ++i) {
        vector<vector<double>> Ai = A;
        for (int j = 0; j < 3; ++j) {
            Ai[j][i] = B[j];
        }
        X[i] = determinant(Ai) / detA;
    }

    return X;
}

//Якоби
vector<double> jacobi(const vector<vector<double>>& A, const vector<double>& B, double tol = 1e-6, int maxIter = 1000) {
    int n = A.size();
    vector<double> X(n, 0.0);
    vector<double> X_new(n, 0.0);

    for (int iter = 0; iter < maxIter; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sum = B[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            X_new[i] = sum / A[i][i];
        }

        double norm = 0.0;
        for (int i = 0; i < n; ++i) {
            norm += pow(X_new[i] - X[i], 2);
        }
        norm = sqrt(norm);

        if (norm < tol) {
            return X_new;
        }

        X = X_new;
    }

    throw runtime_error("Матрица не может быть решена методом Якоби");
}

int main() {
    vector<vector<double>> A = {
            {5, -2, 1},
            {2, -1, 1},
            {18, -8, 4}
    };

    vector<double> B = {2, -1, 0};

    try {
        // Решение методом Крамера
        vector<double> X_cramer = cramer(A, B);
        cout << "Решение методом Крамера:" << endl;
        for (double x : X_cramer) {
            cout << x << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        // Решение методом Якоби
        vector<double> X_jacobi = jacobi(A, B);
        cout << "Решение методом Якоби:" << endl;
        for (double x : X_jacobi) {
            cout << x << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}