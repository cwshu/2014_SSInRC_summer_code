#include <iostream>
using namespace std;

int factorial(int n){
    // �����禡, ��J n, �^�� n ���� (n!)
    if( n == 1 )
        return 1;
    return n * factorial(n-1);
}

int main(){
    int testcase[5] = {1, 4, 6, 7, 10};

    for(int i=0; i<5; i++)
        cout << testcase[i] << "! = " << factorial(testcase[i]) << endl;
        /* 1, 24, 720, 5040, 3628800 */
}
