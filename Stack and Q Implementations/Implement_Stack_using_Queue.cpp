#include <iostream>
using namespace std;
class MyStack {
    queue<int> q;
public:
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int elem = q.front();
        q.pop();
        return elem;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */