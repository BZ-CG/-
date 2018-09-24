#include <iostream>
#include <vector>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> res;
	
	int r = matrix.size();
	if(r == 0) return res;
	
	int l = matrix[0].size();

	int rIndex = 0,lIndex = 0;
	int cnt = 0;
	
	while(true) {
		//向右走 
		for(int i = lIndex;i < l-lIndex;i++) {
		 	res.push_back(matrix[rIndex][i]);
			cnt++;
			if(cnt == r*l) return res;	
		}
		//向下走
		for(int i = rIndex+1;i < r-rIndex;i++) {
			res.push_back(matrix[i][l-lIndex-1]);
			cnt++;
			if(cnt == r*l) return res;
		}
		//向左走 
		for(int i = l-lIndex-1-1 ;i >=lIndex;i--) {
		 	res.push_back(matrix[r-rIndex-1][i]);
			cnt++;
			if(cnt == r*l) return res;
		}
		//向上走 
		for(int i = r-rIndex-2;i >rIndex;i--) {
			res.push_back(matrix[i][lIndex]);
			cnt++;
			if(cnt == r*l) return res;
		} 

		rIndex++;
		lIndex++;

	}
	return res;
}
//准备数据 
void init(vector<vector<int> > &a,int n,int m) {
	int cnt = 1;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++) {
			a[i][j] = cnt++;
		}
		
}
int main(void) {
	int n,m;
	n = 5,m = 3;
	vector<vector<int> > a(n,vector<int>(m));
	
	init(a,n,m);
	vector<int> res = printMatrix(a);
	for(int i = 0;i < res.size();i++)
		cout<<res[i]<<" ";
	
	return 0;
} 
