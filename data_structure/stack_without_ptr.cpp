#include <iostream>
using namespace std;

struct stack {
// 實作一個可以處理 int 型態資料的 stack, 容量為 8.
    int array[8];
    int top;
    int size;
} globalStack;

void stackInit(){
// 初始化 stack.
    globalStack.top = 0;
    globalStack.size = 0;
}

void stackPush(int data){
// 把 data 加入 stack 裡.
    if( globalStack.size >= 8 )
        return; // 錯誤, stack 已滿, 無法再 stackPush 資料進入.

    globalStack.array[globalStack.top] = data;
    globalStack.top++;
    globalStack.size++;
}

int stackPop(){
// 回傳並移出 stack 最上面的資料.
    if( globalStack.size == 0 )
        return 0; // 錯誤, stack 為空.

    int data = globalStack.array[globalStack.top - 1];
    globalStack.top--;
    globalStack.size--;
    return data;
}

int stackTop(){
// 回傳 stack 最上面的資料.
    if( globalStack.size == 0 )
        return 0; // 錯誤, stack 為空.

    return globalStack.array[globalStack.top - 1];
}

bool stackEmpty(){
// 檢查 stack 是否為空.
    if( globalStack.size == 0 )
        return true;
    return false;
    // Quick Way: return globalStack.size == 0;
}

bool stackFull(){
// 檢查 stack 是否已滿.
    if( globalStack.size == 8 )
        return true;
    return false;
}

int main(){
    stackInit();

    cout << stackEmpty() << endl; // true
    cout << stackFull() << endl; // false

    stackPush(1);
    cout << stackEmpty() << endl; // false
    cout << stackFull() << endl; // false
    cout << stackTop() << endl; // 1

    stackPush(2);
    cout << stackEmpty() << endl; // false
    cout << stackFull() << endl; // false
    cout << stackTop() << endl; // 2

    cout << stackPop() << endl; // 2

    stackPush(3);
    cout << stackPop() << endl; // 3
    cout << stackPop() << endl; // 1
    cout << stackEmpty() << endl; // true

    stackPush(4);
    stackPush(5);
    cout << stackPop() << endl; // 5
    stackPush(6);
    stackPush(7);
    stackPush(8);
    cout << stackPop() << endl; // 8
    cout << stackPop() << endl; // 7
    stackPush(9);
    cout << stackPop() << endl; // 9
    cout << stackPop() << endl; // 6
    cout << stackPop() << endl; // 4
}
