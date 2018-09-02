#include <iostream>
#include <stack>
using namespace std;

/*
    利用一个辅助栈，去保存在当前元素位置下栈中最小值，
    当 push 时，如果 push 的元素小于辅助栈顶元素，就
    将当前值压入辅助栈，否则将辅助栈栈顶元素再次压入
    辅助栈。

*/
stack<int> dataSta,minSta;

void push(int value) {
    dataSta.push(value);
    if(minSta.empty()) {
        minSta.push(value);
    }
    else {
        int top = minSta.top();
        value < top ? minSta.push(value) : minSta.push(top);
    }
}
void pop() {
    dataSta.pop();
    minSta.pop();
}
int top() {
    return dataSta.top();
}
int min() {
    return minSta.top();
}
int main(void) {
    push(10);
    push(9);
    push(20);

    cout<<min()<<endl;
    return 0;
}
