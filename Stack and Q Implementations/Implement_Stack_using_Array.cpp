/*
Stack is a data structure that follows the Last In First Out (LIFO) rule.
*/

#include <iostream>
using namespace std;

class Stack{

private:    
    vector<int> arr;

public:    
    void push(int elem){
        arr.push_back(elem);
    }

    int pop(){
        if(arr.empty()){
            cout << "Stack Underflow\n";
            return -1;
        }
        int elem = arr.back();
        arr.pop_back();
        return elem;
    }

    int size(){
        return arr.size();
    }

    int top(){
        if(arr.empty()){
            cout << "Stack is empty\n";
            return -1;
        }
        int elem = arr.back();
        return elem;
    }

    bool empty(){
        return arr.empty();
    }
};