#include <iostream>
using namespace std;

struct queue {
// 實作一個可以處理 int 型態資料的 queue, 容量為 8.
    int circularArray[8];
    int first, last;
    int size;
} globalQueue;

void queueInit(){
// 初始化 queue.
    globalQueue.first = 0;
    globalQueue.last = 0;
    globalQueue.size = 0;
}

void enqueue(int data){
// 把 data 加入 queue 裡.
    if( globalQueue.size >= 8 )
        return; // 錯誤, queue 已滿, 無法再 push 資料進入.

    globalQueue.circularArray[globalQueue.last] = data;
    globalQueue.last = (globalQueue.last + 1) % 8;
    globalQueue.size++;
}

int dequeue(){
// 回傳並移出第一個插入 queue 的資料.
    if( globalQueue.size == 0 )
        return 0; // 錯誤, queue 為空.

    int data = globalQueue.circularArray[globalQueue.first];
    globalQueue.first = (globalQueue.first + 1) % 8;
    globalQueue.size--;
    return data;
}

int queueFirst(){
// 回傳第一個插入 queue 的資料.
    if( globalQueue.size == 0 )
        return 0; // 錯誤, queue 為空.

    return globalQueue.circularArray[globalQueue.first];
}

bool queueEmpty(){
// 檢查 queue 是否為空.
    if( globalQueue.size == 0 )
        return true;
    return false;
}

bool queueFull(){
// 檢查 queue 是否已滿.
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
