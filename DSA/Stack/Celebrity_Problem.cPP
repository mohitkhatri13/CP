
Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
      int n = mat.size();
        stack<int> st;
        // Step 1: Push all persons into stack
        for(int i = 0; i < n; i++) {
            st.push(i);
        }
        
        // Step 2:
        while(st.size() > 1) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            // a knows b?
            if(mat[a][b] == 1) {
                // a is not celebrity, b might be
                st.push(b);
            }
            else {
                // b is not celebrity, a might be
                st.push(a);
            }
        }
        
        // Step 3: Verify that last person is actually celebrity
        int c = st.top();
        st.pop();
        
        // Celebrity should not know anyone
        for(int i = 0; i < n; i++) {
            if(mat[c][i] != 0 && i != c) {
                return -1;
            }
        }
        
        // Everyone should know celebrity
        for(int i = 0; i < n; i++) {
            if(mat[i][c] == 0 )
                return -1;
        }
        
        return c;
    }
};