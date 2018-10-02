#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
    public:
        vector<string> Permutation(string str) {
            vector<string> s;
            int len = str.length();
            if (len == 0)
                return s;
            char arr[len+1];
            strcpy(arr,str.c_str());
            sort(arr,arr+len);
            do {
                string temp = arr;
                s.push_back(temp);
                //cout<<s<<endl;
            } while(next_permutation(arr,arr+len));

            return s;
        }
};



int main(void) {

    Solution s ;
    vector<string> str = s.Permutation("bdca");
    for(int i = 0;i < str.size();i++){
        cout<<str[i]<<endl;
    }
    return 0;
}


