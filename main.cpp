#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int statmas[10];
    int *ptr=statmas;
    for(int i=0; i<10; i++){
        *(ptr+i)=pow(i,2.0);
        cout<<"Element "<< i << ": " << *(ptr+i) << endl;
    }
    return 0;
}