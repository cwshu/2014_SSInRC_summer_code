#include <iostream>
using namespace std;

struct queue {
// 實作一個可以處理 int 型態資料的 queue, 容量為 8.
/* 可參考
 * int circularArray[8];
 * int first, last;
 * int size;
 */
};

void queueInit(struct queue* pThis){
// 初始化 queue.
/* 可參考
 * pThis->first = 0;
 * pThis->last = 0;
 * pThis->size = 0;
 */
}

void enqueue(struct queue* pThis, int data){
// 把 data 加入 queue 裡.
}

int dequeue(struct queue* pThis){
// 回傳並移出第一個插入 queue 的資料.
}

int queueFirst(struct queue* pThis){
// 回傳第一個插入 queue 的資料.
}

bool queueEmpty(struct queue* pThis){
// 檢查 queue 是否為空.
}

bool queueFull(struct queue* pThis){
// 檢查 queue 是否已滿.
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
 *  1. 通常安全的資料結構會做錯誤處理, 比如說 queue 滿的時候, enqueue 函式會用回傳值告訴你 queue 滿了.
 *  2. queue 大小的範用性.
 *      i. 通常會有個函式讓你設定 queue 的大小, 或是直接在 queue 的初始化函式決定.
 *      ii. 更進階: queue 使用動態大小 (程式執行期間決定大小).
 *  3. 函式庫支援: c++ std::deque.
 */
