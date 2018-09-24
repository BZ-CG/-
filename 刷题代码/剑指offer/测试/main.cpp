#include <iostream>
#define size 10
using namespace std;
struct Student
{
	int num;
	double score;
};
void prim(int m,int n){
	if(m >= n){
		while (m%n) n++;
		m /= n;
		prim(m,n);
		cout<<n<<" ";
	}
}
void test() {
	#define size  20
	for(int i = 0;i < 10;i++)i++;
}

int main(void){
	
	Student stu[3]={{1001,80}, {1002,75}, {1003,91}}, *p=stu; 
	cout<<(*(p++)).num<<endl;
	cout<<p->num<<endl;
	
/*	int *p[3];
	int a[3] = {4,5,6};
	//p = a;
	//*p = a[0];
	//p = &a[0];
	p[0] = &a[0];
	cout<<p[0][0]<<endl;//4
	cout<<p[0][1]<<endl;//5
	cout<<p[0][2]<<endl;//6
	float x = 5.0;
	printf("%3.0f\n",x);
	test();
	cout<<size<<endl;*/
	
//	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,},*p=a+5,*q=NULL;
//    *q=*(p+5);
//   
//	printf("%d %d\n",*p,*q);

	//prim(15,2);
//	int a[10] = {10,0,-1.2};
//	for(int i = 0;i < 10;i++)
//		cout<<a[i]<<endl;
//	
//	static char x[ ]= "abcde";
//	static char y[ ]={ 'a', 'b', 'c', 'd', 'e'};
//	cout<<sizeof(x)<<endl;
//	cout<<sizeof(y)<<endl;
	return 0;
}
