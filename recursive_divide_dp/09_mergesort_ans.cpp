#include <iostream>
using namespace std;

const int MAX_TERM = 10000;

void array_copy(int array1[], int array2[], int term){
    for(int i=0; i<term; i++){
        array1[i] = array2[i];
    }
}

void mergesort(int array[], int term){
    // 顧名思義, 請實做合併排序法, array 項數不超過 MAX_TERM.
    int tmp_array[MAX_TERM] = {0};

    if(term == 1) // 起始條件
        return;

    // divide(分割)
    mergesort(array, term/2);
    mergesort(&array[term/2], term - term/2);

    // merge(合併)
    int first_index = 0, second_index = term/2, merge_index = 0;
    while(first_index < term/2 && second_index < term){
        if( array[first_index] <= array[second_index] ){
            tmp_array[merge_index] = array[first_index];
            merge_index++;
            first_index++;
        }
        else{
            tmp_array[merge_index] = array[second_index];
            merge_index++;
            second_index++;
        }
    }

    if(first_index < term/2)
        array_copy(&tmp_array[merge_index], &array[first_index], term/2 - first_index);
    if(second_index < term)
        array_copy(&tmp_array[merge_index], &array[second_index], term - first_index);

    array_copy(array, tmp_array, term);
}

void print_array(int array[], int term){
    for(int i=0; i<term; i++){
        if( i == term - 1 )
            cout << array[i] << endl;
        else
            cout << array[i] << ", ";
    }
}

int main(){
    int testcase[5][100] = {
        {8, 3, 8, 2, 4, 10, 9, 4, 7, 3},
        // 2, 3, 3, 4, 4, 7, 8, 8, 9, 10
        {-24, 54, 56, 77, 50, -26, 73, 53, -17, 10},
        // -26, -24, -17, 10, 50, 53, 54, 56, 73, 77
        {95, 46, 49, 18, 77, 98, 55, 76, 56, 54, 34, 11, 95, 52, 89, 63, 90, 40},
        // 11, 18, 34, 40, 46, 49, 52, 54, 55, 56, 63, 76, 77, 89, 90, 95, 95, 98
        {1, -2, 3, -4, 5, -6, 7, -8, 9},
        // -8, -6, -4, -2, 1, 3, 5, 7, 9
        {1, 1, 1, -1, 2, 2, 3, -1, 5, 5, 5, -2, 6},
        // -2, -1, -1, 1, 1, 1, 2, 2, 3, 5, 5, 5, 6
    };
    int testcase_term[5] = {10, 10, 18, 9, 13};

    for(int i=0; i<5; i++){
        cout << "unsorted array: ";
        print_array(testcase[i], testcase_term[i]);
        mergesort(testcase[i], testcase_term[i]);
        cout << "sorted array: ";
        print_array(testcase[i], testcase_term[i]);
        cout << endl;
    }
}
