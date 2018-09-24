#include <iostream>
using namespace std;
void replaceSpace(char *str,int length) {
	char temp[100];
	int cnt = 0;
	for(int i = 0;i < length;i++) {
		if(str[i] == ' '){
			temp[cnt++] = '%';
			temp[cnt++] = '2';
			temp[cnt++] = '0';
		}else{
			temp[cnt++] = str[i];
		}
	}
	for(int i = 0;i < cnt;i++){
		str[i] = temp[i];
	}
	str[cnt] = '\0';
}
int main(void){
	char a[] = "sadasd ads ad a ";	
	replaceSpace(a,16);
	for(int i = 0;a[i] != '\0';i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
