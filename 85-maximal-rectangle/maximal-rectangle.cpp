class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int maxArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0; // reset if it's 0
                }
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = leftsmallest(heights);
        vector<int> right = rightsmallest(heights);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }

    vector<int> leftsmallest(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> rightsmallest(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }
};
