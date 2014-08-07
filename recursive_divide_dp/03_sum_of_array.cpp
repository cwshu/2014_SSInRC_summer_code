#include <iostream>
using namespace std;

void array_copy(int arr1[], int arr2[], int term);
int array[10];

int sum_of_array(int term){
    // 計算陣列中每個數字的和, term 表示陣列有幾項
    if( term == 1 )
        return array[0];
    else
        return array[term-1] + sum_of_array(term-1);
}

int main(){
    int testcase[4][10] = {
        {1}, // 1
        {1, 2, 3, 4, 5}, // 15
        {-6, 18, -120, 2345}, // 2237
        {10, -9, 8, -7, 6, -5, 4, -3, 2, -1}, // 5
    };

    array_copy(array, testcase[0], 1);
    cout << sum_of_array(1) << endl;
    array_copy(array, testcase[1], 5);
    cout << sum_of_array(5) << endl;
    array_copy(array, testcase[2], 4);
    cout << sum_of_array(4) << endl;
    array_copy(array, testcase[3], 10);
    cout << sum_of_array(10) << endl;
}

void array_copy(int arr1[], int arr2[], int term){
    for(int i=0; i<term; i++){
        arr1[i] = arr2[i];
    }
}
