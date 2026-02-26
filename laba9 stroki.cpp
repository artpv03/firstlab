#include <iostream>
#include <cstring>
using namespace std;
int massstrC(){
    int len;
    cout<<"Введите размер массива: "<<endl;
    cin>>len;
    if (len<=0 || len>20){
        cout<<"Неверный размер";
        return 0;
    }
    cout<<"---------------------------------------"<<endl;
    char **str;
    str=new char*[len];
    for(int i=0; i<len; i++){
        str[i] = new char [20];
    }
    cout<<"Введите слова для массива: "<<endl;
    for(int i=0; i<len; i++){
        cin>>str[i];
        if(strlen(str[i])>20){
            cout<<"Слово длиннее 10 символов!"<<endl;
            for(int j=0; j<len; j++)
                delete[] str[j];
            delete[] str;
            return 0;
        }
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Введённые слова для массива: "<<endl;
    for(int i=0; i<len; i++){
        cout<<str[i]<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Вывод слов только с четным номерами: "<<endl;
    if(len==1){
        cout<<"Нет слов с четным номером"<<endl;
    }
    else{
        for(int i=1; i<len; i+=2)
        cout<<str[i]<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    for(int i=0; i<len; i++)
        delete[] str[i];
    delete[] str;
return 0;
}
int massstrCPP(){
    int len;
    cout<<"Введите размер массива: "<<endl;
    cin>>len;
    if (len<=0 || len>20){
        cout<<"Неверный размер";
        return 0;
    }
cout<<"---------------------------------------"<<endl;
    string str[20];
    cout<<"Введите слова для массива: "<<endl;
    for(int i=0; i<len; i++){
        cin>>str[i];
        if(str[i].length()>10){
            cout<<"Слово длиннее 10 символов!"<<endl;
            return 0;
        }
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Вывод слов только с четным номерами: "<<endl;
    if(len==1){
        cout<<"Нет слов с четным номером"<<endl;
    }
    else{
        for(int i=1; i<len; i+=2){
            cout<<str[i]<<endl;
        }
    }
    cout<<"---------------------------------------"<<endl;
    return 0;
}
int main(){
setlocale(LC_ALL, "RU");
    short nom;
    cout << "Выберите задание(1-2):";
    cin >> nom;
    if (nom == 1) massstrC();
    else if (nom == 2) massstrCPP();
}