#include <iostream>
using namespace std;

struct queue {
// ��@�@�ӥi�H�B�z int ���A��ƪ� queue, �e�q�� 8.
/* �i�Ѧ�
 * int circularArray[8];
 * int first, last;
 * int size;
 */
} globalQueue;

void queueInit(){
// ��l�� queue.
/* �i�Ѧ�
 * globalQueue.first = 0;
 * globalQueue.last = 0;
 * globalQueue.size = 0;
 */
}

void enqueue(int data){
// �� data �[�J queue ��.
}

int dequeue(){
// �^�Ǩò��X�Ĥ@�Ӵ��J queue �����.
}

int queueFirst(){
// �^�ǲĤ@�Ӵ��J queue �����.
}

bool queueEmpty(){
// �ˬd queue �O�_����.
}

bool queueFull(){
// �ˬd queue �O�_�w��.
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
