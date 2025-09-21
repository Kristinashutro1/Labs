#include <iostream>
#include <cmath>

using namespace std;

int main (){ 
int k;
cout << "Enter k > 1:";
cin >>k;
long double e = 1;
for (int i =0; i <k; i++)
e/=10;
long double x;
cout << "Enter x:";
cin >>x;
long double arctg_x = 3.1415926535/2;
long double l = -1/x;
int n = 1;
int a = -1;
for (int i = 0; fabs(l) > e; i++) {
arctg_x+=l;
l*=a;
l/=x;
l/=x;
l*=(n+2);
l/=(n+4);
n+=2;
}
cout.precision(k);
cout << arctg_x << endl;
cout << atan(x);
 

return 0;
}
