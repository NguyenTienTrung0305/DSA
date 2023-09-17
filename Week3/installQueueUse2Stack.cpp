#include <bits/stdc++.h>
using namespace std;

class Queue {
    private:
        stack<int> stack1;
        stack<int> stack2;

    public:
        Queue() {}

        void enqueue(int x) {
            stack1.push(x);
        }

        int front() {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            return stack2.top();
        }
        void dequeue(){
            if (stack1.empty() && stack2.empty()) return;
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            stack2.pop();
        }

        bool isEmpty(){
            if (stack1.empty() && stack2.empty()) return true;
            return false;
        }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.front() <<" ";
    q.dequeue();
    q.enqueue(4);
    q.enqueue(5);
    while(!q.isEmpty()){
        cout << q.front() <<" ";
        q.dequeue();
    }
    return 0;
}