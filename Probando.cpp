#include <iostream>
using namespace std;
int main(){
    int y=20;
    int* y1=&y;

    cout<<*y1<<endl;

    y*=20;
    cout<<*y1;
}