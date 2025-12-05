class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr || !st.empty()) {

            // Go to leftmost
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* node = st.top();

            // If right child not visited, go right
            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                // Visit the node
                ans.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }

        return ans;
    }
};
