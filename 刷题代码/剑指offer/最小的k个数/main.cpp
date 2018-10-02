#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    int len = input.size();
    if (k == 0 || k > len) return res;
    int a[len];
    for (int i = 0;i < len;i++)
        a[i] = input[i];
    sort(a,a+len);
    for (int i = 0;i < k;i++)
        res.push_back(a[i]);
    return res;
}

int main(void) {
    int a[] = {4,5,1,6,2,7,3,8};
    vector<int> v(a,a+8);
    vector<int> res = GetLeastNumbers_Solution(v,4);
    for (int i = 0;i < res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}
