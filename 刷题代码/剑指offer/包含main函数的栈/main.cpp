#include <iostream>
#include <stack>
using namespace std;

/*
    ����һ������ջ��ȥ�����ڵ�ǰԪ��λ����ջ����Сֵ��
    �� push ʱ����� push ��Ԫ��С�ڸ���ջ��Ԫ�أ���
    ����ǰֵѹ�븨��ջ�����򽫸���ջջ��Ԫ���ٴ�ѹ��
    ����ջ��

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
