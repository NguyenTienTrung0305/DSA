#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        queue<int> q1;
        queue<int> q2;
    
    public:
        Stack(){}

        void push(int x){
            q1.push(x);
        }

        int top(){
            if (q2.empty()){
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
            }
            return q2.front();
        }

        void destack(){
            if (q2.empty() && q1.empty()) return;
            if (q2.empty()){
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
            }
            q2.pop();
        }

        bool isEmpty(){
            return q2.empty() && q1.empty();
        }

};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.destack();
    st.push(5);
    while(!st.isEmpty()){
        cout << st.top() << " ";
        st.destack();
    }
    return 0;
}