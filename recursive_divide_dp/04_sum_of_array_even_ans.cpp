#include <iostream>
using namespace std;

int sum_of_array_even(int array[], int term){
    // 計算陣列中偶數項和, term 表示陣列有幾項, 請使用遞迴手法完成.
    // 偶數項: 2, 4, 6 ... 項為 array[1], array[3], array[5] ... 
    term = term - (term % 2); // 結尾奇數項去掉. Quick Way: term = (term >> 1) << 1
    if( term < 2 )
        return 0;
    else if( term == 2 )
        return array[1];
    else
        return array[term-1] + sum_of_array_even(array, term-2);
}

int main(){
    int testcase[4][10] = {
        {1}, // 0
        {1, 2, 3, 4, 5}, // 6
        {-6, 18, -120, 2345}, // 2363
        {10, -9, 8, -7, 6, -5, 4, -3, 2, -1}, // -25
    };

    cout << sum_of_array_even(testcase[0], 1) << endl;
    cout << sum_of_array_even(testcase[1], 5) << endl;
    cout << sum_of_array_even(testcase[2], 4) << endl;
    cout << sum_of_array_even(testcase[3], 10) << endl;
}
