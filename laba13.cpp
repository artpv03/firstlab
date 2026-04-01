#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double eps = 1e-9;

void printMatrix(double** matrix, int rows, int cols, ostream& out) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out << setw(10) << fixed << setprecision(3) << matrix[i][j] << " ";
        }
        out << endl;
    }
    out << endl;
}

/*
Элементарные преобразования матриц, используемые в методе Гаусса-Жордана:
1. Перестановка строк
2. Перестановка столбцов
3. Деление строки на ненулевой ведущий элемент
4. Вычитание из одной строки другой строки, умноженной на число
*/
void metod_Gaussa_Jordana(double** matrix, int M, int N, int& r, int* L) {
    int i, j, k, v, u, p;
    double z, c;

    /* задание индексного массива L */
    for (i = 0; i < N; i++) L[i] = i;

    i = 0;
    if (N < M) r = N;
    else r = M;

    while (i < r) {
        /* выбор ведущего элемента A[v][u] */
        v = i;
        u = i;
        for (j = i; j < M; j++) {
            for (k = i; k < N; k++) {
                if (fabs(matrix[j][k]) > fabs(matrix[v][u])) {
                    v = j;
                    u = k;
                }
            }
        }

        if (fabs(matrix[v][u]) < eps) {
            r = i;
        } else {
            /* перестановка строк */
            if (v != i) {
                for (j = i; j <= N; j++) {
                    z = matrix[i][j];
                    matrix[i][j] = matrix[v][j];
                    matrix[v][j] = z;
                }
            }

            /* перестановка столбцов */
            if (u != i) {
                for (k = 0; k < M; k++) {
                    z = matrix[k][i];
                    matrix[k][i] = matrix[k][u];
                    matrix[k][u] = z;
                }
                p = L[i];
                L[i] = L[u];
                L[u] = p;
            }

            /* деление i-й строки на A[i][i] */
            c = matrix[i][i];
            for (j = i; j <= N; j++) {
                matrix[i][j] /= c;
            }

            /* вычитание уравнений */
            for (k = 0; k < M; k++) {
                if (k != i) {
                    c = matrix[k][i];
                    for (j = i; j <= N; j++) {
                        matrix[k][j] -= c * matrix[i][j];
                    }
                }
            }

            i++;
        }
    }
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
        cout << "Не удалось открыть input.txt" << endl;
        return 1;
    }

    int M, N;
    inFile >> M >> N;

    if (M <= 0 || N <= 0) {
        cout << "Некорректные размеры системы" << endl;
        return 1;
    }

    double** matrix = new double*[M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new double[N + 1];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= N; j++) {
            inFile >> matrix[i][j];
        }
    }

    int* L = new int[N];
    double* X = new double[N];
    int r;

    outFile << "Исходная система:" << endl;
    printMatrix(matrix, M, N + 1, outFile);

    metod_Gaussa_Jordana(matrix, M, N, r, L);

    outFile << "Матрица после преобразований:" << endl;
    printMatrix(matrix, M, N + 1, outFile);

    /* проверка решения системы уравнений */
    int i = r;
    while (i < M && fabs(matrix[i][N]) < eps) i++;

    if (i < M) {
        outFile << "Система не имеет решений." << endl;
    }
    else if (r == N) {
        outFile << "Система имеет единственное решение:" << endl;
        for (int j = 0; j < N; j++) {
            X[L[j]] = matrix[j][N];
        }
        for (int j = 0; j < N; j++) {
            outFile << "x" << j + 1 << " = " << X[j] << endl;
        }
    }
    else {
        outFile << "Система имеет бесконечно много решений (общее решение)." << endl;

        /* задание значений независимым переменным */
        for (int k = r; k < N; k++) {
            X[L[k]] = 0.0;
        }

        /* вычисление зависимых переменных */
        for (int j = 0; j < r; j++) {
            X[L[j]] = matrix[j][N];
            for (int k = r; k < N; k++) {
                X[L[j]] -= matrix[j][k] * X[L[k]];
            }
        }

        outFile << "Свободные переменные:" << endl;
        for (int k = r; k < N; k++) {
            outFile << "x" << L[k] + 1 << " - свободная переменная" << endl;
        }

        outFile << endl << "Общее решение:" << endl;
        for (int j = 0; j < r; j++) {
            outFile << "x" << L[j] + 1 << " = " << matrix[j][N];
            for (int k = r; k < N; k++) {
                if (fabs(matrix[j][k]) > eps) {
                    if (matrix[j][k] > 0)
                        outFile << " - " << matrix[j][k] << "*x" << L[k] + 1;
                    else
                        outFile << " + " << fabs(matrix[j][k]) << "*x" << L[k] + 1;
                }
            }
            outFile << endl;
        }
    }

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] L;
    delete[] X;

    inFile.close();
    outFile.close();

    cout << "Проверьте файл output.txt" << endl;
    return 0;
}