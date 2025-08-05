/*
Queuek is a data structure that follows the First in First Out (FIFO) rule.
*/

#include <iostream>
using namespace std;

class Queue{
    vector<int> arr;
    int frontIndex;

public:
    Queue(){
        frontIndex = 0;
    }

    void push(int elem){
        arr.push_back(elem);
    }

    int pop(){
        if(empty()){
            cout << "Queue is Empty\n";
            return -1;
        }
        int elem = arr[frontIndex];
        frontIndex++;

        if(frontIndex > arr.size() / 2){
            arr.erase(arr.begin(), arr.begin() + frontIndex);
            frontIndex = 0;
        }
        return elem;
    }

    int top(){
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }
    int size(){
        return arr.size() - frontIndex;        
    }

    bool empty(){
        return size() == 0;
    }
};