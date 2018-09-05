//
// Created by ps on 18-9-2.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:

    MinStack() {
        // do intialization if necessary
    }

    void push(int number) {
        m_stack.push(number);
        if (m_min.empty() || number <= m_min.top())
            m_min.push(number);
    }

    int pop() {
        int num1;
        if (m_stack.top() == m_min.top()) {
            m_stack.pop();
            num1 = m_min.top();
            m_min.pop();
        } else {
            num1 = m_stack.top();
            m_stack.pop();
        }
        return num1;
    }

    int top() {
        return m_stack.top();

    }

    int getMin() {
        return m_min.top();
    }

private:
    std::stack<int> m_stack;
    std::stack<int> m_min;
};

int main(int argc, char *argv[]) {
    return 0;
}