#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
}; 
//递归版
ListNode* Merge2(ListNode* pHead1, ListNode* pHead2){
	if(!pHead1) return pHead2;
	if(!pHead2) return pHead1;
	
	if(pHead1->val < pHead2->val) {
		pHead1->next = Merge2(pHead1->next,pHead2);
		return pHead1;
	}
	else {
		pHead2->next = Merge2(pHead1,pHead2->next);
		return pHead2;
	}
	
}

//循环版 
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
	if(pHead1 == NULL) return pHead2;
	if(pHead2 == NULL) return pHead1;
	
	ListNode *head = new ListNode(0);//头结点 
	ListNode *temp = NULL;			 //用来保存最开始的头结点，在后面 head 会变化，所以用来保存其最原始的位置 

	while(pHead1 != NULL && pHead2 != NULL){
		if(pHead1->val < pHead2->val) {
			head->next = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			head->next = pHead2;
			pHead2 = pHead2->next;
		}
		if(temp == NULL) temp = head;
		head = head->next;
	}
	//处理末尾的数据，当一条链表到达尾部时，直接把另一条链表接过来。      
	pHead1 == NULL ? head->next = pHead2 : head->next = pHead1;
	
	return temp == NULL ? temp : temp->next;
}
int main(void) {
	ListNode* p1 = new ListNode(0);
	ListNode* p2 = new ListNode(0);
	ListNode* temp1 = NULL,*temp2 = NULL;

	for(int i = 2;i < 10;i++) {
		ListNode* t = new ListNode(i);
		
		p1->next = t;

		if(temp1 == NULL) temp1 = p1;
		p1 = p1->next;
	}
	for(int i = 3;i < 20;i++) {
		ListNode* t = new ListNode(i);
		
		p2->next = t;

		if(temp2 == NULL) temp2 = p2;
		p2 = p2->next;
	}
	
	ListNode* merge = Merge2(temp1->next,temp2->next);
	while(merge != NULL) {
		cout<<merge->val<<" ";
		merge = merge->next;
	}
	return 0;
}
