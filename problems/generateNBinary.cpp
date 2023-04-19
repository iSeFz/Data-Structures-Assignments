#include "../structures/queue.hpp"
#include <string>

// Generate & Print N binary numbers using a queue
void generateNBinary(int N){
    Queue<string> q;
    q.enqueue("1");
    // Loop until N binary numbers are generated
    while (N--){
        // Delete the front item and print it
        string binNum = q.dequeue();
        cout << binNum << " ";
        // Enqueue the binary numbers with 0 and 1 at the end
        // As a binary tree with root 1, left node 0 and right node 1
        q.enqueue(binNum + "0");
        q.enqueue(binNum + "1");
    }
    // Clear the queue after finishing
    q.clear();
}

// Driver function
int main(){
    cout << "Enter the # of binary numbers to generate: ";
    int N; cin >> N;
    generateNBinary(N);
    cout << "\n";
    return 0;
}