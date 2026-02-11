

#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "RU");
    short MAX, a = 0, b = 1;
    cout << "Введите n-ый член:";
    cin >> MAX;
    if (MAX == 0) {
        cout << a << endl;
        return 0;
    }
    if (MAX == 1) {
        cout << b << endl;
        return 0;
    }
    for (short i=2; i<=MAX; i++) {
        short next = a + b;
        a = b;
        b = next;
    }
    cout << b << endl;
    return 0;
        
    
}
