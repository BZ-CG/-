#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    public:
        vector<string> s;

        int visit[1000];
        char res[1000];
        int len = 0;
        vector<string> Permutation(string str) {
            len = str.length();
            if (len == 0)
                return s;
            char arr[len+1];
            strcpy(arr,str.c_str());
            sort(arr,arr+len);
            //cout<<arr<<endl;
            dfs(arr,0);

            return s;
        }
        void dfs(char* str,int k) {
            //cout<<"str:"<<str<<endl;
            if (k == len) {
                string temp = res;
               // cout<<"dfs:"<<temp<<endl;
                s.push_back(temp);
                return;
            }
            for (int i = k;i < len;i++) {
                bool flag = true;
                if (!visit[i]) {
                   for (int j = i + 1;j < len;j++) {
                       if (str[i] == str[j] && visit[j]) {
                           flag = false;
                           break;
                       }
                   }
                }
                if (flag) {
                    visit[i] = 1;
                    res[k] = str[i];
                    dfs(str,k+1);
                    visit[i] = 0;
                }
            }
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
