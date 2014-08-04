#include <iostream>
using namespace std;

int gcd(int a, int b){
    // 計算 a, b 的最大公因數.
}

int main(){
    int testcase[4][2] = {
        {15, 10}, // 5
        {63, 35}, // 7
        {221, 1001}, // 13
        {390, 1155}, // 15
    };

    for(int i=0; i<4; i++){
        int a = testcase[i][0];
        int b = testcase[i][1];
        cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    }
}
