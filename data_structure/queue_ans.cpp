#include <iostream>
using namespace std;

struct queue {
// ��@�@�ӥi�H�B�z int ���A��ƪ� queue, �e�q�� 8.
    int circularArray[8];
    int first, last;
    int size;
};

void queueInit(struct queue* pThis){
// ��l�� queue.
    pThis->first = 0;
    pThis->last = 0;
    pThis->size = 0;
}

void enqueue(struct queue* pThis, int data){
// �� data �[�J queue ��.
    if( pThis->size >= 8 )
        return; // ���~, queue �w��, �L�k�A push ��ƶi�J.

    pThis->circularArray[pThis->last] = data;
    pThis->last = (pThis->last + 1) % 8;
    pThis->size++;
}

int dequeue(struct queue* pThis){
// �^�Ǩò��X�Ĥ@�Ӵ��J queue �����.
    if( pThis->size == 0 )
        return 0; // ���~, queue ����.

    int data = pThis->circularArray[pThis->first];
    pThis->first = (pThis->first + 1) % 8;
    pThis->size--;
    return data;
}

int queueFirst(struct queue* pThis){
// �^�ǲĤ@�Ӵ��J queue �����.
    if( pThis->size == 0 )
        return 0; // ���~, queue ����.

    return pThis->circularArray[pThis->first];
}

bool queueEmpty(struct queue* pThis){
// �ˬd queue �O�_����.
    if( pThis->size == 0 )
        return true;
    return false;
}

bool queueFull(struct queue* pThis){
// �ˬd queue �O�_�w��.
    if( pThis->size == 8 )
        return true;
    return false;
}

int main(){
    struct queue queue1;
    queueInit(&queue1);

    cout << queueEmpty(&queue1) << endl; // true
    cout << queueFull(&queue1) << endl; // false

    enqueue(&queue1, 1);
    cout << queueEmpty(&queue1) << endl; // false
    cout << queueFull(&queue1) << endl; // false
    cout << queueFirst(&queue1) << endl; // 1

    enqueue(&queue1, 2);
    cout << queueEmpty(&queue1) << endl; // false
    cout << queueFull(&queue1) << endl; // false
    cout << queueFirst(&queue1) << endl; // 1

    cout << dequeue(&queue1) << endl; // 1

    enqueue(&queue1, 3);
    cout << dequeue(&queue1) << endl; // 2
    cout << dequeue(&queue1) << endl; // 3
    cout << queueEmpty(&queue1) << endl; // true

    enqueue(&queue1, 4);
    enqueue(&queue1, 5);
    cout << dequeue(&queue1) << endl; // 4
    enqueue(&queue1, 6);
    enqueue(&queue1, 7);
    enqueue(&queue1, 8);
    cout << dequeue(&queue1) << endl; // 5
    cout << dequeue(&queue1) << endl; // 6
    enqueue(&queue1, 9);
    cout << dequeue(&queue1) << endl; // 7
    cout << dequeue(&queue1) << endl; // 8
    cout << dequeue(&queue1) << endl; // 9
}
