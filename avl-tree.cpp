#include<iostream>
#include <cassert>
#include <functional>
#include <string>
using namespace std;
class Exception {
public:
   Exception(const string& msg) : msg_(msg) {}
  ~Exception() {}

   string getMessage() const {
   		return(msg_);
   }
private:
   string msg_;
};
struct TreeNode{
	int val;
	string name;
	TreeNode *left;
	TreeNode *right;
	TreeNode(){
		left = right = NULL;
	}
	TreeNode(int val,string s){
		left = right = NULL;
		this->name = s;
		this->val = val;
	}
		TreeNode(int val){
		cout << "Called " << val << endl;
		left = right = NULL;
		this->val = val;
	}
};
int max(int x,int y){
	if(x > y)
		return x;
	else
		return y;
}
bool insertionBasedOnInt(TreeNode *node1 , TreeNode *node2){
//	cout << "Here" << endl;
	if(node1->val > node2->val)
		return true;
	return false;
}
bool insertionBasedOnStr(TreeNode *node1 , TreeNode *node2){
	if(node1 == NULL  && node2 != NULL)
		return false;
	else if(node1 != NULL  && node2 == NULL)
		return true;
	if(node1->name > node2->name)
		return true;
	return false;
}
class AvlTree{
	int height;
	TreeNode *root;
	TreeNode *addNode(TreeNode *root,int val,const std::function<bool(TreeNode*,TreeNode*)>&insertionCriteria){
//		cout << val << endl;
		if(root == NULL)
			return new TreeNode(val);
		if(insertionCriteria(root->right,root->left))
			root->right = addNode(root->right,val,insertionBasedOnInt);
		else
			root->left = addNode(root->left,val,insertionBasedOnInt);
		return root;	
	}
	void print_inorder(TreeNode *root){
		if(root == NULL)
			return;
		print_inorder(root->left);
		cout << root->val << " " << flush;
		print_inorder(root->right);
	}
	public:
		AvlTree(){
			root = NULL;
		}

	int getTreeHeight(TreeNode *root){
		if(root == NULL)
			return 0;
		int leftHeight = getTreeHeight(root->left);
		int rightHeight = getTreeHeight(root->right);
		return leftHeight + rightHeight + 1;
	}		
	int balanceFactor(TreeNode *root){
		int leftHeight = getTreeHeight(root->left);
		int rightHeight = getTreeHeight(root->right);
		return leftHeight - rightHeight;
	}
	void insertInt(int val){
		root = addNode(root,val,insertionBasedOnInt);
	}
	void inorder(){
		this->print_inorder(root);
	}
};
int main(){
	AvlTree tree;
	try{
		tree.insertInt(1);
	tree.insertInt(2);	
	}catch(Exception *e){
		cout << e->getMessage() << endl;
	}	
	return 0;
}

