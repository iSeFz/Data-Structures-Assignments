#include <iostream>
#include <vector>
#include <Student.hpp>

class MaxBinaryHeap{
private:
    std::vector<Student> heap;
    int size;
public:
    explicit MaxBinaryHeap(const vector<Student> &students);
    MaxBinaryHeap() : size(0) {};
    void insert(const Student& student);
    // builds a max heap
    void buildMaxHeap();
    // corrects a single violation
    void maxHeapify(int index);
    void siftUp(int index);
    void printMaxHeap();

};

MaxBinaryHeap::MaxBinaryHeap(const vector<Student> &students) {
    size = (int) students.size();
    heap = students;
    buildMaxHeap();
}

void MaxBinaryHeap::insert(const Student &student) {
    heap.push_back(student);
    int index = size-1;
    int parent = (index-1)/2;
    while (parent>=0){
        if (heap[index].getGpa() > heap[parent].getGpa()){
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (parent-1)/2;
        } else break;
    }
}

void MaxBinaryHeap::buildMaxHeap() {
    // elements in this range [floor(size/2), size-1] are leaves
    // hence we need to only maxHeapify the other nodes that are not leaves

    for (int index = size / 2 - 1; index >= 0; index--){
        maxHeapify(index);
    }

}

void MaxBinaryHeap::maxHeapify(int index) {
    int left = 2*index+1, right = 2*index+1, largest = index;

    if (left<size && heap[left].getGpa() > heap[index].getGpa()){
        largest = left;
    }
    if (right<size && heap[right].getGpa() > heap[largest].getGpa()){
        largest = right;
    }
    if (largest!=index){
        swap(heap[index], heap[largest]);
        maxHeapify(largest);
    }
}


void MaxBinaryHeap::printMaxHeap() {
    for (auto &student : heap){
        cout << student.getId() << " - " << student.getName() << " - "
        << student.getDept() << " - " << student.getGpa() << '\n';
    }
}

// restore heap invariant after insertion
void MaxBinaryHeap::siftUp(int index) {
    while (true){
        int parent = (index-1)/2;
        if (heap[parent].getGpa()>=heap[index].getGpa())
            break;
        swap(heap[parent], heap[index]);
        index = parent;
    }
}
