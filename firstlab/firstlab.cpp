

#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "RU");
    short sum=1, MAX, a = 0, b = 1;
    cout << "Введите n-ый член:";
    cin >> MAX;
    if (MAX == 1) {
        cout <<"Число: "<< a << endl;
        cout << "Сумма: " << a << endl;
        return 0;
    }
    if (MAX == 2) {
        cout << "Число: " << b << endl;
        cout << "Cумма: " << b << endl;
        return 0;
    }
    for (short i = 3; i <= MAX; i++) {
        sum += a + b;
        short next = a + b;
        a = b;
        b = next;
    }
    cout <<"Число: "<< b << endl;
    cout<<"Сумма: "<< sum << endl;
 
    return 0;
}
