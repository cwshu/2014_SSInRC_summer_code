#include <iostream>
using namespace std;

int fibonacci(int n){
    // ­pºâ fibonacci series ²Ä n ¶µ­È
    // fibonacci series: f(1) = 1, f(2) = 1, f(n) = f(n-1) + f(n-2)
    if( n == 1 || n == 2 )
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int testcase[5] = {1, 4, 6, 10, 13};

    for(int i=0; i<5; i++)
        cout << "f(" << testcase[i] << ") = " << fibonacci(testcase[i]) << endl;
        /* 1, 3, 8, 55, 233 */
}
