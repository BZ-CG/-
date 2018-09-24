#include <iostream>
using namespace std;

bool find(int a[][3],int r,int l,int src){
	int row = r;
	int col = l;
	
	int rowTemp = -1;
	for(int i = 0;i < row;i++){
		if(a[i][0] <= src && src <= a[i][col-1]){
			rowTemp = i;
			break;
		}
	}
	
	if(rowTemp == -1) return false;
	
	int left = 0,right = col-1;
	while(left <= right){
		int mid = (left + right)/2;
		int midValue = a[rowTemp][mid];
		if(midValue == src) {
			return true;
		}else if(src < midValue){
			right = mid-1;
		}else{
			left = mid+1;	
		}
	}
	
	return false;
}

int main(void){
	int a[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	
	cout<<find(a,3,3,60)<<endl;	
	
	return 0;
}


