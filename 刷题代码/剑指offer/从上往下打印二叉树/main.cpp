#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> res;

    if(root == NULL) return res;

    q.push(root);
    while(!q.empty()){
       TreeNode* cur = q.front();
       q.pop();
       if (!cur) continue;

       res.push_back(cur->val);
       q.push(cur->left);
       q.push(cur->right);
    }
    return res;
}

int main(void) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(1);

    vector<int> a = PrintFromTopToBottom(root);
    for(int i = 0;i < a.size();i++)
        cout<<a[i]<<" ";
    return 0;
}
