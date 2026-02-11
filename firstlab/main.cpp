

#include <iostream>
#include <cmath>
using namespace std;
int fib() {
    unsigned short MAX;
    long sum = 0, a = 0, b = 1;
    cout << "Введите n-ый член:";
    cin >> MAX;
    if (MAX == 1) {
        cout << "Число: " << a << endl;
        cout << "Сумма: " << a << endl;
        return 0;
    }
    if (MAX == 2) {
        cout << "Число: " << b << endl;
        cout << "Cумма: " << b << endl;
        return 0;
    }
    sum = a + b;
    for (unsigned short i = 3; i <= MAX; i++) {
        long next = a + b;
        sum += next;
        a = b;
        b = next;
    }
    cout << "Число: " << b << endl;
    cout << "Сумма: " << sum << endl;

    return 0;
}
int func() {
    float ans = 0.0, x = 1, y = 4, step = (y - x) / 9;
    for (int i = 0; i <= 9; i++) {
        ans = sin(x) / x;
        cout << ans << endl;
        x += step;
    }
    return 0;
}
int main() {
    setlocale(LC_ALL, "RU");
    short nom;
    cout << "Выберите задание(1-3):";
    cin >> nom;
    if (nom == 1) fib();
    if (nom == 2) func();
    return 0;
}