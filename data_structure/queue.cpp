#include <iostream>
using namespace std;

struct queue {
// ��@�@�ӥi�H�B�z int ���A��ƪ� queue, �e�q�� 8.
/* �i�Ѧ�
 * int circularArray[8];
 * int first, last;
 * int size;
 */
};

void queueInit(struct queue* pThis){
// ��l�� queue.
/* �i�Ѧ�
 * pThis->first = 0;
 * pThis->last = 0;
 * pThis->size = 0;
 */
}

void enqueue(struct queue* pThis, int data){
// �� data �[�J queue ��.
}

int dequeue(struct queue* pThis){
// �^�Ǩò��X�Ĥ@�Ӵ��J queue �����.
}

int queueFirst(struct queue* pThis){
// �^�ǲĤ@�Ӵ��J queue �����.
}

bool queueEmpty(struct queue* pThis){
// �ˬd queue �O�_����.
}

bool queueFull(struct queue* pThis){
// �ˬd queue �O�_�w��.
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

/* Learn More
 *  1. �q�`�w������Ƶ��c�|�����~�B�z, ��p�� queue �����ɭ�, enqueue �禡�|�Φ^�ǭȧi�D�A queue ���F.
 *  2. queue �j�p���d�Ω�.
 *      i. �q�`�|���Ө禡���A�]�w queue ���j�p, �άO�����b queue ����l�ƨ禡�M�w.
 *      ii. ��i��: queue �ϥΰʺA�j�p (�{����������M�w�j�p).
 *  3. �禡�w�䴩: c++ std::deque.
 */
