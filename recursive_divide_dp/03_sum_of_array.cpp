#include <iostream>
using namespace std;

int sum_of_array(int array[], int term){
    // 計算陣列中每個數字的和, term 表示陣列有幾項
    if( term == 1 )
        return array[0];
    else
        return array[term-1] + sum_of_array(array, term-1);
}

int main(){
    int testcase[4][10] = {
        {1}, // 1
        {1, 2, 3, 4, 5}, // 15
        {-6, 18, -120, 2345}, // 2237
        {10, -9, 8, -7, 6, -5, 4, -3, 2, -1}, // 5
    };

    cout << sum_of_array(testcase[0], 1) << endl;
    cout << sum_of_array(testcase[1], 5) << endl;
    cout << sum_of_array(testcase[2], 4) << endl;
    cout << sum_of_array(testcase[3], 10) << endl;
}
