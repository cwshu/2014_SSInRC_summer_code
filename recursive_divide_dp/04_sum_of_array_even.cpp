#include <iostream>
using namespace std;

void array_copy(int arr1[], int arr2[], int term);
int array[10];

int sum_of_array_even(int term){
    // �p��}�C�����ƶ��M, term ��ܰ}�C���X��, �Шϥλ��j��k����.
    // ���ƶ�: 2, 4, 6 ... ���� array[1], array[3], array[5] ... 
}

int main(){
    int testcase[4][10] = {
        {1}, // 0
        {1, 2, 3, 4, 5}, // 6
        {-6, 18, -120, 2345}, // 2363
        {10, -9, 8, -7, 6, -5, 4, -3, 2, -1}, // -25
    };

    array_copy(array, testcase[0], 1);
    cout << sum_of_array_even(1) << endl;
    array_copy(array, testcase[1], 5);
    cout << sum_of_array_even(5) << endl;
    array_copy(array, testcase[2], 4);
    cout << sum_of_array_even(4) << endl;
    array_copy(array, testcase[3], 10);
    cout << sum_of_array_even(10) << endl;
}

void array_copy(int arr1[], int arr2[], int term){
    for(int i=0; i<term; i++){
        arr1[i] = arr2[i];
    }
}
