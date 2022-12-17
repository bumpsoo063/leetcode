#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
private:
	string const exp[4] = {"+", "-", "*", "/"};
	static void expAdd(stack<int> &s, long a, long b) {s.push(a + b);}
	static void expSub(stack<int> &s, long a, long b) {s.push(a - b);}
	static void expMul(stack<int> &s, long a, long b) {s.push(a * b);}
	static void expDiv(stack<int> &s, long a, long b) {s.push(a / b);}
public:
    int evalRPN(vector<string>& tokens) {
		void (*expfun[4])(stack<int> &, long, long ) = {&expAdd, &expSub, &expMul, &expDiv};
        stack<int> s;
		long tmp1, tmp2;
		for (string t : tokens) {
			for (int i = 0; i <= 4; i++) {
				if (i == 4) {
					s.push(stoi(t));
					break;
				}
				if (exp[i] == t) {
					tmp2 = s.top();
					s.pop();
					tmp1 = s.top();
					s.pop();
					expfun[i](s, tmp1, tmp2);
					break;
				}
			}
		}
		return s.top();
    }
};

int main() {
	vector<string> t = {"4","13","5","/","+"};
	Solution s;
	cout << s.evalRPN(t) << endl;
}