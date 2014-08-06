#include <iostream>
using namespace std;

struct stack {
// ��@�@�ӥi�H�B�z int ���A��ƪ� stack, �e�q�� 8.
    int array[8];
    int top;
    int size;
} globalStack;

void stackInit(){
// ��l�� stack.
    globalStack.top = 0;
    globalStack.size = 0;
}

void stackPush(int data){
// �� data �[�J stack ��.
    if( globalStack.size >= 8 )
        return; // ���~, stack �w��, �L�k�A stackPush ��ƶi�J.

    globalStack.array[globalStack.top] = data;
    globalStack.top++;
    globalStack.size++;
}

int stackPop(){
// �^�Ǩò��X stack �̤W�������.
    if( globalStack.size == 0 )
        return 0; // ���~, stack ����.

    int data = globalStack.array[globalStack.top - 1];
    globalStack.top--;
    globalStack.size--;
    return data;
}

int stackTop(){
// �^�� stack �̤W�������.
    if( globalStack.size == 0 )
        return 0; // ���~, stack ����.

    return globalStack.array[globalStack.top - 1];
}

bool stackEmpty(){
// �ˬd stack �O�_����.
    if( globalStack.size == 0 )
        return true;
    return false;
    // Quick Way: return globalStack.size == 0;
}

bool stackFull(){
// �ˬd stack �O�_�w��.
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
