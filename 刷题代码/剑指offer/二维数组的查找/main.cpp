#include <iostream>
#include <vector>
using namespace std;
/**
    注意空的二维数组：{{},{}}
*/
bool find(int key,int a[3][3]){
    int r = 3,l = 3;
    //int r = a.size();
    for(int i = 0;i < r;i++){
        int l = a[i].size();

        if(l == 0 ) return false;

        int left = a[i][0];
        int right = a[i][l - 1];
        if(key >= left && key <= right){
            int left2 = 0;
            int right2 = l-1;

            while(left2 <= right2){
                int mid = (left2 + right2) / 2;
                if(a[i][mid] < key){
                    left2 = mid + 1;
                }else if(a[i][mid] > key){
                    right2 = mid - 1;
                }else{
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    int a[3][3] = {{1,5,7},{2,6,8},{3,7,9}};

    cout<<find(93,a)<<endl;

    return 0;
}
