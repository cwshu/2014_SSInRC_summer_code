#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int a, int b){
    // 計算 a, b 的最大公因數.
    if( a < b )
        swap(&a, &b);

    if( a % b == 0 )
        return b;
    else
        return gcd(b, a%b);
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
