#include <iostream>
using namespace std;
const int MAX_VALUE = 17;
const int VALUE_COUNT = 18;
void pack(const int source[], int n, int packed[]) {
    for (int i = 0; i < VALUE_COUNT; i++) packed[i] = 0;
    for (int i = 0; i < n; i++) packed[source[i]]++;
}
void unpack(const int packed[], int restored[], int n) {
    int index = 0;
    for (int val = 0; val < VALUE_COUNT; val++) {
        for (int count = 0; count < packed[val]; count++) {
            restored[index++] = val;
        }
    }
}
int main() {
    const int N = 1000000;
    int* original = new int[N];

    int pos = 0;
    for (int val = 0; val <= MAX_VALUE; val++) {
        int count = N / VALUE_COUNT;

        if (val < N % VALUE_COUNT) count++;
        for (int j = 0; j < count; j++) original[pos++] = val;
    }
    cout << "Исходный массив: " << N << " элементов, " 
         << N * sizeof(int) << " байт" << endl;
    int packed[VALUE_COUNT] = {0};
    pack(original, N, packed);
    cout << "Упаковано: " << VALUE_COUNT << " элементов, " 
         << VALUE_COUNT * sizeof(int) << " байт" << endl;
    int* restored = new int[N]; 
    unpack(packed, restored, N);
    cout << "Распаковано: " << N << " элементов, " 
         << N * sizeof(int) << " байт" << endl;
    delete[] original;
    delete[] restored; 
    return 0;
}
