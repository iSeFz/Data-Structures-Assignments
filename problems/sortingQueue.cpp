#include <iostream>
#include "../structures/queue.hpp"
using namespace std;

int getMin(Queue<int>& q) {
    int min = q.dequeue();
    for (int i = 0; i < q.queueSize(); ++i) {
        if(min > q.first()) {
            // return min back to the queue
            q.enqueue(min);
            // get the min from the queue
            min = q.dequeue();
        }
        else {
            // put front of the queue to the back of the queue
            q.enqueue(q.dequeue());
        }
    }
    return min;
}

void sortingQueue(Queue<int> &q) {
    // sorted queue
    Queue<int> sorted;
    // get min value from queue and add it to sorted queue
    while (!q.isEmpty()) {
        sorted.enqueue(getMin(q));
    }
    // push sorted queue to original queue
    while (!sorted.isEmpty()) {
        q.enqueue(sorted.dequeue());
    }
}

int main() {
    // first test
    cout << "First test:\n";
    Queue<int> qTest1;
    qTest1.enqueue(3);
    qTest1.enqueue(15);
    qTest1.enqueue(2);
    qTest1.enqueue(4);
    cout << "Queue before sorting: ";
    qTest1.print();
    sortingQueue(qTest1);
    cout << "Queue after sorting: ";
    qTest1.print();
    // second test
    cout << "\nSecond test:\n";
    Queue<int> qTest2;
    qTest2.enqueue(9);
    qTest2.enqueue(1);
    qTest2.enqueue(2);
    qTest2.enqueue(1);
    cout << "Queue before sorting: ";
    qTest2.print();
    sortingQueue(qTest2);
    cout << "Queue after sorting: ";
    qTest2.print();
    return 0;
}