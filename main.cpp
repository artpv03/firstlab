#include <iostream>
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
    int *ptr=arr;
    for(int i=0; i<len; i++){
        *(ptr+i)=i*i;
        cout<<"Элементы динамического массива (индекс) "<< i << ": "<< *(ptr+i) << endl;
    }
    delete[] arr;
}
void fourtharr(){
    int len=10;
    int *arr = new int[len];
    for(int i=0; i<len; i++){
        arr[i]=i*i;
        cout<<"Элементы динамического массива (указатель) "<< i << ": "<< arr[i] << endl;
    }
    delete[] arr;
}
int sort(){
    int len1;
    cout<<"Введите длину 1-го массива(до 15):";
    cin>>len1;
    if (len1<0 || len1>15){
        cout<<"Неверный размер";
    }
    int len2;
    cout<<"Введите длину 2-го массива(до 15):";
    cin>>len2;
    if (len2<0 || len2>15){
        cout<<"Неверный размер";
    }
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    srand(time(0));
    arr1[0]=rand()%10;
    for(int i=0; i<len1; i++){
        arr1[i] = arr1[i-1] + rand()%5 + 1;
        cout<<"Элемент 1-го массива: "<<arr1[i]<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    arr2[0]=rand()%10;
    for(int i=0; i<len2; i++){
        arr2[i] = arr2[i-1] + rand()%5 + 1;
        cout<<"Элемент 2-го массива: "<<arr2[i]<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    int *mergeresult = new int[len1+len2];
    int lind=0;
    int rind=0;
    int mind=0;
    while(lind<len1 && rind<len2){
    if(arr1[lind]<arr2[rind]){
        mergeresult[mind++] = arr1[lind++];
    } else {
            mergeresult[mind++] = arr2[rind++];
        }
    }
    while(lind<len1){
        mergeresult[mind++] = arr1[lind++];
    }
    while(rind<len2){
        mergeresult[mind++] = arr2[rind++];
    }
    for(int i=0; i<len1+len2;i++){
        cout<<"Элемент отсортированного массива: "<<mergeresult[i]<<endl; 
    }
    delete[] arr1;
    delete[] arr2;
    delete[] mergeresult;
    return 0;
}
struct Node{
    int data;
    Node *next;
    Node *prev;
};
int list(){
    Node* head = nullptr;
    Node* tail = nullptr;

    // Создание списка из 10 элементов
    for (int i = 1; i <= 10; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }
    cout << "Список вперед:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\nСписок назад:\n";
    temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
int main() {
    setlocale(LC_ALL, "RU");
    short nom;
    cout << "Выберите задание(1-6):";
    cin >> nom;
    if (nom == 1) firstarr();
    else if (nom == 2) secondarr();
    else if (nom == 3) thirdarr();
    else if (nom == 4) fourtharr();
    else if (nom == 5) sort();
    else if (nom == 6) list();
    else cout<<"Неверный выбор!";
    return 0;
}