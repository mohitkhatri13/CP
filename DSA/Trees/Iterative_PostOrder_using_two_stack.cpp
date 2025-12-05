/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         stack<TreeNode*>st;
         stack<TreeNode*>st2;
        
         st.push(root);
         vector<int>ans;
         if(root ==NULL) return ans;
         TreeNode* curr = root;

         while(!st.empty()){
            auto temp = st.top();
            st2.push(temp);
            st.pop();
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
         }
         while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
         }
         


         return ans;
    }
};