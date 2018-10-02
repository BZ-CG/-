#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int visit[maxn] = {0};
vector<int> G[maxn];
int minDis = -1;
int res = 0;
int n,x,y;

bool isok(){
    for(int i = 1;i <= n;i++) {
        if(!visit[i])
            return false;
    }
    return true;

}

void dfs(int v,int num) {
    if(isok()){
        res = min(minDis,res);
        return;
    }
    int size = G[v].size();
    if(size == 1) {
        int v2 = G[v][0];
        visit[v2] = 1;
       // cout<<v2<<endl;
        dfs(v2,num++);
        visit[v2] = 0;
    }else{
        for(int i = 0;i < G[v].size();i++){
            int v2 = G[v][i];
            if(visit[v2]) continue;
            visit[v2] = 1;
           // cout<<v2<<endl;
            dfs(v2,num++);
            visit[v2] = 0;
        }
    }

}

int main(void) {

    cin>>n;
    for(int i = 0;i < n-1;i++) {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    visit[1] = 1;
    dfs(2,1);
    cout<<res<<endl;
    return 0;
}
