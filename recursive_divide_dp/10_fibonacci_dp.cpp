#include <iostream>
using namespace std;

const int MAX_TERM = 100;
int fibonacci_data[MAX_TERM+1] = {0}; // dp_table 初始值 0.

int fibonacci_dp(int n){
    // 計算 fibonacci series 第 n 項值
    // fibonacci series: f(1) = 1, f(2) = 1, f(n) = f(n-1) + f(n-2)
    if( n == 1 || n == 2 )
        return 1;
    else if(fibonacci_data[n] != 0) // dp_table 不為初始值, 代表這項算過了 => 直接取值.
        return fibonacci_data[n];
    else{
        fibonacci_data[n] = fibonacci_dp(n-1) + fibonacci_dp(n-2); // 正常遞迴計算, 並把值存入 dp_table.
        return fibonacci_data[n];
    }
}

int main(){
    int testcase[8] = {1, 4, 6, 10, 13, 20, 26, 45};

    for(int i=0; i<8; i++)
        cout << "f(" << testcase[i] << ") = " << fibonacci_dp(testcase[i]) << endl;
        /* 1, 3, 8, 55, 233, 6765, 121393, 1134903170 */
}
