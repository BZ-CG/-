#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 10000000;


int MoreThanHalfNum_Solution(vector<int> numbers) {
    int res = 0;
    int max = -9999;
    for (int i = 0;i < numbers.size();i++)
        if (numbers[i] > max)
            max = numbers[i];

    int visit[max+1];
    memset(visit,0,sizeof(visit));
    //¼ÇÂ¼³öÏÖµÄ´ÎÊý
    for (int i = 0;i < numbers.size();i++) {
        visit[numbers[i]]++;
        if (visit[numbers[i]] > (numbers.size()/2)) {
            res = numbers[i];
            break;
        }
    }

    return res;
}

//map 方法
int MoreThanHalfNum_Solution2(vector<int> numbers) {
    int len = numbers.size();
    int res = 0;
    map<int,int> m;
    for (int i = 0;i < numbers.size();i++) {
        res = ++m[numbers[i]];
        if (res > len/2)
            return numbers[i];
    }
    return 0;
}
int main(void) {
    int a[] = {1};
    vector<int> numbers(a,a+1);
    cout<<MoreThanHalfNum_Solution(numbers)<<endl;
    cout<<MoreThanHalfNum_Solution2(numbers)<<endl;
    return 0;
}
