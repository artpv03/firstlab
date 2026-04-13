#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

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
Метод Гаусса-Жордана:
1. Перестановка строк
2. Перестановка столбцов
3. Деление строки на ведущий элемент
4. Вычитание из остальных строк ведущей строки
*/
void metod_Gaussa_Jordana(double** matrix, int M, int N, int& r, int* L) {
    int i, j, k, v, u, p;
    double z, c;

    for (i = 0; i < N; i++) {
        L[i] = i;
    }

    i = 0;
    r = (N < M) ? N : M;

    while (i < r) {
        v = i;
        u = i;

        // Поиск ведущего элемента
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
            break;
        }

        // Перестановка строк
        if (v != i) {
            for (j = 0; j <= N; j++) {
                z = matrix[i][j];
                matrix[i][j] = matrix[v][j];
                matrix[v][j] = z;
            }
        }

        // Перестановка столбцов
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

        // Деление строки на ведущий элемент
        c = matrix[i][i];
        for (j = i; j <= N; j++) {
            matrix[i][j] /= c;
        }

        // Обнуление остальных элементов столбца
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

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
        cout << "Не удалось открыть input.txt" << endl;
        return 1;
    }

    // Задача А: пересечение двух прямых
    // a1*x + b1*y = c1
    // a2*x + b2*y = c2
    const int M = 2;
    const int N = 2;

    double a1, b1, c1;
    double a2, b2, c2;

    if (!(inFile >> a1 >> b1 >> c1)) {
        cout << "Ошибка чтения первой прямой из input.txt" << endl;
        return 1;
    }

    if (!(inFile >> a2 >> b2 >> c2)) {
        cout << "Ошибка чтения второй прямой из input.txt" << endl;
        return 1;
    }

    double** matrix = new double*[M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new double[N + 1];
    }

    // Заполняем расширенную матрицу
    matrix[0][0] = a1;
    matrix[0][1] = b1;
    matrix[0][2] = c1;

    matrix[1][0] = a2;
    matrix[1][1] = b2;
    matrix[1][2] = c2;

    int* L = new int[N];
    double* X = new double[N];
    int r;

    outFile << "Задача: найти точку пересечения двух прямых на плоскости" << endl;
    outFile << "Уравнения прямых заданы в виде:" << endl;
    outFile << "a1*x + b1*y = c1" << endl;
    outFile << "a2*x + b2*y = c2" << endl << endl;

    outFile << "Первая прямая: "
            << a1 << "*x + " << b1 << "*y = " << c1 << endl;
    outFile << "Вторая прямая: "
            << a2 << "*x + " << b2 << "*y = " << c2 << endl << endl;

    outFile << "Исходная расширенная матрица системы:" << endl;
    printMatrix(matrix, M, N + 1, outFile);

    metod_Gaussa_Jordana(matrix, M, N, r, L);

    outFile << "Матрица после преобразований:" << endl;
    printMatrix(matrix, M, N + 1, outFile);

    int i = r;
    while (i < M && fabs(matrix[i][N]) < eps) {
        i++;
    }

    if (i < M) {
        outFile << "Система несовместна." << endl;
        outFile << "Следовательно, прямые параллельны и не имеют точки пересечения." << endl;
    }
    else if (r == N) {
        for (int j = 0; j < N; j++) {
            X[L[j]] = matrix[j][N];
        }

        for (int j = 0; j < N; j++) {
            if (fabs(X[j]) < eps) {
                X[j] = 0.0;
            }
        }

        outFile << "Система имеет единственное решение." << endl;
        outFile << "Точка пересечения прямых:" << endl;
        outFile << "x = " << fixed << setprecision(6) << X[0] << endl;
        outFile << "y = " << fixed << setprecision(6) << X[1] << endl;

        // Запись данных для Lazarus-программы
        ofstream graphFile("graph.txt");
        if (graphFile) {
            graphFile << a1 << " " << b1 << " " << c1 << endl;
            graphFile << a2 << " " << b2 << " " << c2 << endl;
            graphFile << X[0] << " " << X[1] << endl;
            graphFile.close();

            outFile << endl;
            outFile << "Данные для графической иллюстрации записаны в файл graph.txt" << endl;
        } else {
            outFile << endl;
            outFile << "Не удалось создать файл graph.txt" << endl;
        }
    }
    else {
        outFile << "Система имеет бесконечно много решений." << endl;
        outFile << "Следовательно, прямые совпадают." << endl;
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

    // Запускаем программу рисования
    system("risunok.exe");

    return 0;
}