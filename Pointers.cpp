#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    int *ptr = &num;

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;

    *ptr = 10;

    cout << "After changing the value of num using the pointer" << endl;
    cout << "Value of num: " << num << endl;
    cout << "Value of ptr: " << *ptr << endl;

    return 0;
}