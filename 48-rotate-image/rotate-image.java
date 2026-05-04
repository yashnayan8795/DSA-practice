class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        for (int l= 0;l<n/2; ++l){
            int start= l;
            int end= n-1-l;
            for(int i=start; i<end; ++i){
                int temp = matrix[start][i];
                matrix[start][i] = matrix[n - 1 - i][start];
                matrix[n - 1 - i][start] = matrix[end][n - 1 - i];
                matrix[end][n - 1 - i] = matrix[i][end];
                matrix[i][end] = temp;
            }
        }
    }
}

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         for (int layer = 0; layer < n / 2; ++layer) {
//             int start = layer;
//             int end = n - 1 - layer;
//             for (int i = start; i < end; ++i) {
//                 int temp = matrix[start][i];
//                 matrix[start][i] = matrix[n - 1 - i][start];
//                 matrix[n - 1 - i][start] = matrix[end][n - 1 - i];
//                 matrix[end][n - 1 - i] = matrix[i][end];
//                 matrix[i][end] = temp;
//             }
//         }
//     }
// };