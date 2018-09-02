#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> s;
    int index = 0;
    for(int i = 0;i < pushV.size();i++) {
        s.push(pushV[i]);
        while (!s.empty() && s.top() == popV[index]) {
            s.pop();
            index++;
        }
    }
    return s.empty();
}
int main(void) {
    int push[] = {1,2,3,4,5};
    int pop[] = {4,3,5,1,2};
    vector<int> v1(push,push+5);
    vector<int> v2(pop,pop+5);

    cout<<IsPopOrder(v1,v2)<<endl;
    return 0;
}
