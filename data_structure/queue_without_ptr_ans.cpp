#include <iostream>
using namespace std;

struct queue {
// ��@�@�ӥi�H�B�z int ���A��ƪ� queue, �e�q�� 8.
    int circularArray[8];
    int first, last;
    int size;
} globalQueue;

void queueInit(){
// ��l�� queue.
    globalQueue.first = 0;
    globalQueue.last = 0;
    globalQueue.size = 0;
}

void enqueue(int data){
// �� data �[�J queue ��.
    if( globalQueue.size >= 8 )
        return; // ���~, queue �w��, �L�k�A push ��ƶi�J.

    globalQueue.circularArray[globalQueue.last] = data;
    globalQueue.last = (globalQueue.last + 1) % 8;
    globalQueue.size++;
}

int dequeue(){
// �^�Ǩò��X�Ĥ@�Ӵ��J queue �����.
    if( globalQueue.size == 0 )
        return 0; // ���~, queue ����.

    int data = globalQueue.circularArray[globalQueue.first];
    globalQueue.first = (globalQueue.first + 1) % 8;
    globalQueue.size--;
    return data;
}

int queueFirst(){
// �^�ǲĤ@�Ӵ��J queue �����.
    if( globalQueue.size == 0 )
        return 0; // ���~, queue ����.

    return globalQueue.circularArray[globalQueue.first];
}

bool queueEmpty(){
// �ˬd queue �O�_����.
    if( globalQueue.size == 0 )
        return true;
    return false;
}

bool queueFull(){
// �ˬd queue �O�_�w��.
    if( globalQueue.size == 8 )
        return true;
    return false;
}

int main(){
    queueInit();

    cout << queueEmpty() << endl; // true
    cout << queueFull() << endl; // false

    enqueue(1);
    cout << queueEmpty() << endl; // false
    cout << queueFull() << endl; // false
    cout << queueFirst() << endl; // 1

    enqueue(2);
    cout << queueEmpty() << endl; // false
    cout << queueFull() << endl; // false
    cout << queueFirst() << endl; // 1

    cout << dequeue() << endl; // 1

    enqueue(3);
    cout << dequeue() << endl; // 2
    cout << dequeue() << endl; // 3
    cout << queueEmpty() << endl; // true

    enqueue(4);
    enqueue(5);
    cout << dequeue() << endl; // 4
    enqueue(6);
    enqueue(7);
    enqueue(8);
    cout << dequeue() << endl; // 5
    cout << dequeue() << endl; // 6
    enqueue(9);
    cout << dequeue() << endl; // 7
    cout << dequeue() << endl; // 8
    cout << dequeue() << endl; // 9
}
