#include<iostream>
using namespace std;
int main() {
int a = 10;
int b = 20;
int c = 30;
int* const x = &a; 
a = 100; // line 11
 x = &b; // line 12 
 *x = 1000; // line 13
cout << a << endl;
cout << x << endl;
cout << x << endl;
return 0;
}