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
