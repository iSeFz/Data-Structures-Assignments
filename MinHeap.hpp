#ifndef _MIN_HEAP_HPP
#define _MIN_HEAP_HPP

#include <vector>
#include "Student.hpp"

class MinBinaryHeap{
private:
    std::vector<Student> heap;
    int size;
public:
    explicit MinBinaryHeap(const vector<Student> &students);
    MinBinaryHeap() : size(0) {};
    void insert(const Student& student);
    // builds a min heap
    void buildMinHeap();
    // corrects a single violation
    void minHeapify(int index);
    //restore heap invariant after insertion
    void siftUp(int index);
    void printSorted();

};

MinBinaryHeap::MinBinaryHeap(const vector<Student> &students) {
    size = (int) students.size();
    heap = students;
    buildMinHeap();

}

void MinBinaryHeap::insert(const Student &student) {
    heap.push_back(student);
    size++;
    siftUp(size-1);
}

void MinBinaryHeap::buildMinHeap() {
    // elements in this range [floor(size/2), size-1] are leaves
    // hence we need to only minHeapify the other nodes that are not leaves
    for (int index = size / 2 - 1; index >= 0; index--)
        minHeapify(index);
}

void MinBinaryHeap::minHeapify(int index) {
    int left = 2*index+1, right = 2*index+2, smallest = index;
    if (left<size && heap[left].getGpa() < heap[index].getGpa())
        smallest = left;
    if (right<size && heap[right].getGpa() < heap[smallest].getGpa())
        smallest = right;
    if (smallest!=index){
        swap(heap[index], heap[smallest]);
        minHeapify(smallest);
    }
}

void MinBinaryHeap::siftUp(int index) {
    while (true){
        int parent = (index-1)/2;
        if (index==0 || heap[parent].getGpa()<=heap[index].getGpa())
            break;
        swap(heap[index], heap[parent]);
        index = parent;
    }
}

void MinBinaryHeap::printSorted() {
    while (size>1){
        swap(heap[0], heap[size-1]);
        cout << heap[size-1];
        size--;
        minHeapify(0);
    }
    cout << heap[0];
    size = (int) heap.size();
    buildMinHeap();
}

#endif
