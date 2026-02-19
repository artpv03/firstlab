#include <iostream>
#include <cmath>
using namespace std;
int firstarr(){
    int statmas[10];
    for(int i=0; i<10; i++){
        statmas[i]=i*i;
        cout<<"Элементы статического массива (индекс) "<< i << ": "<< statmas[i] << endl;
    }
    return 0;
}
int secondarr(){
    int statmas[10];
    int *ptr=statmas;
    for(int i=0; i<10; i++){
        *(ptr+i)=i*i;
        cout<<"Элементы статического массива (указатель) "<< i << ": " << *(ptr+i) << endl;
    }
    return 0;
}
void thirdarr(){
    int len=10;
    int *arr = new int[len];
    for(int i=0; i<len; i++){
        arr[i]=i*i;
        cout<<"Элементы динамического массива (индекс) "<< i << ": "<< arr[i] << endl;
    }
    delete[] arr;
}
int main() {
    setlocale(LC_ALL, "RU");
    short nom;
    cout << "Выберите задание(1-3):";
    cin >> nom;
    if (nom == 1) firstarr();
    else if (nom == 2) secondarr();
    else if (nom == 3) thirdarr();
    else cout<<"Неверный выбор!";
    return 0;
}