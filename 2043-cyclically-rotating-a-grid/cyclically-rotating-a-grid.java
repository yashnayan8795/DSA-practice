class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {

        int n = grid.length;
        int m = grid[0].length;

        int ttlLayers = Math.min(n / 2, m / 2);
        int[][] res = new int[n][m];

        int layer = 0;
        while (layer < ttlLayers) {
            Queue<Integer> q = new LinkedList<>();

            // top row
            for (int j = layer; j < m - layer; j++) {
                q.add(grid[layer][j]);
            }

            // right column
            for (int i = layer + 1; i < n - layer - 1; i++) {
                q.add(grid[i][m - 1 - layer]);
            }

            // bottom row
            for (int j = m - 1 - layer; j >= layer; j--) {
                q.add(grid[n - 1 - layer][j]);
            }

            // left column
            for (int i = n - 1 - layer - 1; i >= 1 + layer; i--) {
                q.add(grid[i][layer]);
            }

            int size = q.size();
            int rotate = k % size;

            while (rotate > 0) {
                q.add(q.poll());
                rotate--;
            }

            // top row
            for (int j = layer; j < m - layer; j++) {
                res[layer][j] = q.poll();
            }

            // right column
            for (int i = layer + 1; i < n - layer - 1; i++) {
                res[i][m - 1 - layer] = q.poll();
            }

            // bottom row
            for (int j = m - 1 - layer; j >= layer; j--) {
                res[n - 1 - layer][j] = q.poll();
            }

            // left column
            for (int i = n - 1 - layer - 1; i >= 1 + layer; i--) {
                res[i][layer] = q.poll();
            }

            layer++;
        }

        return res;
    }
}