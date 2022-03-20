#include<iostream>
#include<vector>
using namespace std;

//ִ����ʱ��12 ms, ������ C++ �ύ�л�����46.22%���û�
//�ڴ����ģ�20.7 MB, ������ C++ �ύ�л�����66.72%���û�

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Tree{
private:
    TreeNode* root;
public:
    void Create(vector<int>& nums,int len){
        root=CreateTree(nums,len,0);
    }
    TreeNode* CreateTree(vector<int>& nums,int len,int index){
        if(index>=len)
            return nullptr;
        TreeNode* node;
        int val=nums[index];
        if(val==0){
            node=nullptr;
        }else{
            node=new TreeNode(val);
            node->left=CreateTree(nums,len,2*index+1);
            node->right=CreateTree(nums,len,2*index+2);
        }
        return node;
    }

    TreeNode *getRoot() const {
        return root;
    }
};

//���۸��ĺ������
class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;
        //����Ҷ�ӽ��
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    int n,num;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>num;
        nums.push_back(num);
    }

    Tree* tree=new Tree();
    tree->Create(nums,n);
    Solution sol;
    int targetSum;
    cin>>targetSum;
    bool ans=sol.hasPathSum(tree->getRoot(),targetSum);
    cout<<(bool)ans<<endl;
    return 0;
}
