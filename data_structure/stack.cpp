#include <iostream>
using namespace std;

struct stack {
// ��@�@�ӥi�H�B�z int ���A��ƪ� stack, �e�q�� 8.
    int array[8];
    int top;
    int size;
};

void stackInit(struct stack* pThis){
// ��l�� stack.
    pThis->top = 0;
    pThis->size = 0;
}

void stackPush(struct stack* pThis, int data){
// �� data �[�J stack ��.
    if( pThis->size >= 8 )
        return; // ���~, stack �w��, �L�k�A stackPush ��ƶi�J.

    pThis->array[pThis->top] = data;
    pThis->top++;
    pThis->size++;
}

int stackPop(struct stack* pThis){
// �^�Ǩò��X stack �̤W�������.
    if( pThis->size == 0 )
        return 0; // ���~, stack ����.

    int data = pThis->array[pThis->top - 1];
    pThis->top--;
    pThis->size--;
    return data;
}

int stackTop(struct stack* pThis){
// �^�� stack �̤W�������.
    if( pThis->size == 0 )
        return 0; // ���~, stack ����.

    return pThis->array[pThis->top - 1];
}

bool stackEmpty(struct stack* pThis){
// �ˬd stack �O�_����.
    if( pThis->size == 0 )
        return true;
    return false;
    // Quick Way: return pThis->size == 0;
}

bool stackFull(struct stack* pThis){
// �ˬd stack �O�_�w��.
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
