#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
	stack<int> s1, s2;
	bool flag;
public:

    MyQueue() {
		s1 = stack<int>();
		s2 = stack<int>();
		flag = false;
    }
    
    void push(int x) {
		s1.push(x);
    }
    
    int pop() {
		int ret = 0;
		if (flag == true) {
			ret = s2.top();
			
			s2.pop();
			
			if (s2.empty())
				flag = false;
			return ret;
		} else {
			while (s1.empty() == false) {
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
			ret = s2.top();
			s2.pop();
			if (s2.empty())
				flag = false;
			else
				flag = true;
			return ret;
		}
    }
    
    int peek() {
        if (flag) {
			return s2.top();
		} else {
			while (s1.empty() == false) {
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
			int ret = s2.top();
			flag = true;
			return ret;
		}
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};