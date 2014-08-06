#include <iostream>
using namespace std;

struct stack {
// 實作一個可以處理 int 型態資料的 stack, 容量為 8.
    int array[8];
    int top;
    int size;
};

void stackInit(struct stack* pThis){
// 初始化 stack.
    pThis->top = 0;
    pThis->size = 0;
}

void stackPush(struct stack* pThis, int data){
// 把 data 加入 stack 裡.
    if( pThis->size >= 8 )
        return; // 錯誤, stack 已滿, 無法再 stackPush 資料進入.

    pThis->array[pThis->top] = data;
    pThis->top++;
    pThis->size++;
}

int stackPop(struct stack* pThis){
// 回傳並移出 stack 最上面的資料.
    if( pThis->size == 0 )
        return 0; // 錯誤, stack 為空.

    int data = pThis->array[pThis->top - 1];
    pThis->top--;
    pThis->size--;
    return data;
}

int stackTop(struct stack* pThis){
// 回傳 stack 最上面的資料.
    if( pThis->size == 0 )
        return 0; // 錯誤, stack 為空.

    return pThis->array[pThis->top - 1];
}

bool stackEmpty(struct stack* pThis){
// 檢查 stack 是否為空.
    if( pThis->size == 0 )
        return true;
    return false;
    // Quick Way: return pThis->size == 0;
}

bool stackFull(struct stack* pThis){
// 檢查 stack 是否已滿.
    if( pThis->size == 8 )
        return true;
    return false;
}

int main(){
    struct stack stack1;
    stackInit(&stack1);

    cout << stackEmpty(&stack1) << endl; // true
    cout << stackFull(&stack1) << endl; // false

    stackPush(&stack1, 1);
    cout << stackEmpty(&stack1) << endl; // false
    cout << stackFull(&stack1) << endl; // false
    cout << stackTop(&stack1) << endl; // 1

    stackPush(&stack1, 2);
    cout << stackEmpty(&stack1) << endl; // false
    cout << stackFull(&stack1) << endl; // false
    cout << stackTop(&stack1) << endl; // 2

    cout << stackPop(&stack1) << endl; // 2

    stackPush(&stack1, 3);
    cout << stackPop(&stack1) << endl; // 3
    cout << stackPop(&stack1) << endl; // 1
    cout << stackEmpty(&stack1) << endl; // true

    stackPush(&stack1, 4);
    stackPush(&stack1, 5);
    cout << stackPop(&stack1) << endl; // 5
    stackPush(&stack1, 6);
    stackPush(&stack1, 7);
    stackPush(&stack1, 8);
    cout << stackPop(&stack1) << endl; // 8
    cout << stackPop(&stack1) << endl; // 7
    stackPush(&stack1, 9);
    cout << stackPop(&stack1) << endl; // 9
    cout << stackPop(&stack1) << endl; // 6
    cout << stackPop(&stack1) << endl; // 4
}
