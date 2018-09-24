#include <iostream>
#include <vector>
using namespace std;

bool isBST(vector<int> seque,int left,int right) { 
	if (left >= right) return true;
	
	int i = right;
	while(i > left && seque[i-1] > seque[right]) i--;

	for(int j = left;j < i;j++)
		if (seque[j] > seque[right]) return false;
	
	return isBST(seque,left,i-1) && isBST(seque,i,right-1); 
}

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() == 0) return false;
	return isBST(sequence,0,sequence.size()-1);
}

int main(void) {
	vector <int> sque {2,4,3,6,10,9,7,5};
	cout<<VerifySquenceOfBST(sque)<<endl;
	
	return 0;
}
