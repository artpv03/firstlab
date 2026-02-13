#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int fib() {
    long long MAX;
    long long a = 0, b = 1, sum = a + b, n=2;
    cout << "Введите максимальное число:";
    cin >> MAX;
    while(sum<=MAX) {
        long long next = a + b;
        sum += next;
        n++;
        a = b;
        b = next;
    }
    cout << "Количество чисел: " << n << endl;
    cout << "Сумма: " << sum << endl;

    return 0;
}
int func() {
    float x;
    float ans = 0.0, y = 4; 
    cout << "Введите начальное значение интервала:";
    cin >> x;
    float  step = (y - x) / 9;
    for (int i = 0; i <= 9; i++) {
        ans = sin(x) / x;
        cout << ans << endl;
        x += step;
    }
    return 0;
}
int table() {
    double cred, perc;
    int mon;

    printf("Введите сумму кредита: ");
    scanf("%lf", &cred);

    printf("Введите срок кредита (в месяцах): ");
    scanf("%d", &mon);

    printf("Введите процентную ставку: ");
    scanf("%lf", &perc);

    double monthrate = perc / 12 / 100;
    double mainpay = cred / mon;
    double balance = cred;
    double totalperc = 0;

    printf("\n№   Долг        Процент    Платеж\n");

    for (int i = 1; i <= mon; i++) {
        double interest = balance * monthrate;
        double pay = mainpay + interest;
        printf("%-3d %-12.2lf %-12.2lf %-12.2lf\n", i, balance, interest, pay);
        totalperc += interest;
        balance -= mainpay;
    }

    printf("\nОбщий процент: %.2lf\n", totalperc);

    return 0;
}
int main() {
    setlocale(LC_ALL, "RU");
    short nom;
    cout << "Выберите задание(1-3):";
    cin >> nom;
    if (nom == 1) fib();
    if (nom == 2) func();
    if (nom == 3) table();
    return 0;
}