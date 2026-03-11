#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int a;
    char text[100];

    // cin / cout
    cout << "Enter number: ";
    cin >> a;

    // printf
    printf("You entered: %d\n", a);

    // ввод строки
    printf("Enter text: ");
    getchar();
    gets(text);

    // вывод строки
    puts(text);

    // запись в файл
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "%d %s", a, text);
    fclose(f);

    // чтение из файла
    int b;
    char text2[100];

    f = fopen("data.txt", "r");
    fscanf(f, "%d %s", &b, text2);
    fclose(f);

    printf("From file: %d %s\n", b, text2);

    cout << "Results written to file data.txt" << endl;

    return 0;
}