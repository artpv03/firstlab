#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Вывод решения в виде доски
void printBoard(const vector<vector<int>>& board) {
    int k = static_cast<int>(board.size());
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << '\n';
    }
    cout << '\n';
}

// 1) РЕШЕНИЕ "В ЛОБ" С ИСПОЛЬЗОВАНИЕМ МАТРИЦЫ
bool canPlaceMatrix(const vector<vector<int>>& board, int row, int col) {
    int k = static_cast<int>(board.size());

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < k; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveQueensMatrixRec(vector<vector<int>>& board, int row, long long& count, bool printSolutions) {
    int k = static_cast<int>(board.size());

    if (row == k) {
        count++;
        if (printSolutions) {
            cout << "Решение #" << count << " (матрица):\n";
            printBoard(board);
        }
        return;
    }

    for (int col = 0; col < k; col++) {
        if (canPlaceMatrix(board, row, col)) {
            board[row][col] = 1;
            solveQueensMatrixRec(board, row + 1, count, printSolutions);
            board[row][col] = 0;
        }
    }
}

long long solveQueensMatrix(int k, bool printSolutions) {
    vector<vector<int>> board(k, vector<int>(k, 0));
    long long count = 0;
    solveQueensMatrixRec(board, 0, count, printSolutions);
    return count;
}

// 2) ЛЕКЦИОННЫЙ ВАРИАНТ: МАССИВЫ СТОЛБЦОВ И ДИАГОНАЛЕЙ
void printPlacement(const vector<int>& pos) {
    int k = static_cast<int>(pos.size());
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << (pos[i] == j ? "Q " : ". ");
        }
        cout << '\n';
    }
    cout << '\n';
}

void solveQueensFastRec(
    int row,
    int k,
    vector<int>& pos,
    vector<int>& usedCol,
    vector<int>& usedDiag1,
    vector<int>& usedDiag2,
    long long& count,
    bool printSolutions
) {
    if (row == k) {
        count++;
        if (printSolutions) {
            cout << "Решение #" << count << " (быстрый алгоритм):\n";
            printPlacement(pos);
        }
        return;
    }

    for (int col = 0; col < k; col++) {
        int d1 = row - col + (k - 1);
        int d2 = row + col;

        if (!usedCol[col] && !usedDiag1[d1] && !usedDiag2[d2]) {
            pos[row] = col;
            usedCol[col] = 1;
            usedDiag1[d1] = 1;
            usedDiag2[d2] = 1;

            solveQueensFastRec(row + 1, k, pos, usedCol, usedDiag1, usedDiag2, count, printSolutions);

            usedCol[col] = 0;
            usedDiag1[d1] = 0;
            usedDiag2[d2] = 0;
        }
    }
}

long long solveQueensFast(int k, bool printSolutions) {
    vector<int> pos(k, -1);
    vector<int> usedCol(k, 0);
    vector<int> usedDiag1(2 * k - 1, 0);
    vector<int> usedDiag2(2 * k - 1, 0);

    long long count = 0;
    solveQueensFastRec(0, k, pos, usedCol, usedDiag1, usedDiag2, count, printSolutions);
    return count;
}

int main() {
    setlocale(LC_ALL, "RU");

    int k;
    cout << "Введите K: ";
    cin >> k;

    if (k <= 0) {
        cout << "K должно быть положительным.\n";
        return 1;
    }

    char answer;
    cout << "Выводить все решения? (y/n): ";
    cin >> answer;
    bool printSolutions = (answer == 'y' || answer == 'Y');

    cout << "1) Решение в лоб с матрицей\n";

    auto start1 = high_resolution_clock::now();
    long long countMatrix = solveQueensMatrix(k, printSolutions);
    auto end1 = high_resolution_clock::now();

    auto duration1 = duration_cast<milliseconds>(end1 - start1);

    cout << "Количество решений (матрица): " << countMatrix << '\n';
    cout << "Время работы (матрица): " << duration1.count() << " мс\n\n";

    cout << "2) Решение алгоритмом из лекций\n";

    auto start2 = high_resolution_clock::now();
    long long countFast = solveQueensFast(k, printSolutions);
    auto end2 = high_resolution_clock::now();

    auto duration2 = duration_cast<milliseconds>(end2 - start2);

    cout << "Количество решений (быстрый алгоритм): " << countFast << '\n';
    cout << "Время работы (быстрый алгоритм): " << duration2.count() << " мс\n\n";

    return 0;
}