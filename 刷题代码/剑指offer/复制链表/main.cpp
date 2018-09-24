//
// Created by intasect on 2018/9/14.
//

#include <iostream>
#include <cstdio>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

/**
 * 生成一个新的结点
 * @param node
 * @return
 */
RandomListNode* getNode(RandomListNode* node) {
    if (!node) return NULL;
    RandomListNode* newNode = new RandomListNode(node->label);
    return newNode;
}

/**
 * 复制链表，遍历原链表，对于每个位置上的结点，生成一个数据相等的新结点
 * @param pHead
 * @return
 */
RandomListNode* Clone(RandomListNode* pHead) {
    RandomListNode *temp = new RandomListNode(0);
    RandomListNode* head = NULL;
    head = temp;

    while (pHead) {
        RandomListNode* cur = new RandomListNode(pHead->label);
        RandomListNode* random = getNode(pHead->random);

        cur->random = random;

        temp->next = cur;
        temp = temp->next;
        pHead = pHead->next;
    }
    return head->next;
}

int main (void) {
    RandomListNode* temp = new RandomListNode(0);
    RandomListNode* head = NULL;
    head = temp;
    int a[] = {1,2,3,4,5,6,7};
    for (int i = 0;i < 7;i++) {
        temp->next = new RandomListNode(a[i]);
        temp = temp->next;
    }

    RandomListNode* res = Clone(head->next);
    while (res) {
        cout<<res->label<<endl;
        res = res->next;
    }
    return 0;
}
