#include <iostream>
using namespace std;

int power(int base, int exp){
    // 指數運算, 計算 base^exp, 其中 exp 為正整數, 請使用遞迴手法完成.
}

int main(){
    int testcase[5][2] = {
        {2, 10}, // 1024
        {-3, 5}, // -243
        {6, 2},  // 36
        {1, 20}, // 1
        {99, 1}, // 99
    };

    for(int i=0; i<5; i++){
        int base = testcase[i][0];
        int exp = testcase[i][1];
        cout << base << "^" << exp << " = " << power(base, exp) << endl;
    }
}
