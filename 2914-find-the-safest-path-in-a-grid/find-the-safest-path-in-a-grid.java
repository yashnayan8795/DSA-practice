class Solution {

    class Pair {
        int row;
        int col;

        Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    int[] delRow = {-1, 0, 1, 0};
    int[] delCol = {0, 1, 0, -1};

    public int maximumSafenessFactor(List<List<Integer>> grid) {

        int n = grid.size();

        int[][] dist = new int[n][n];

        for (int[] row : dist)
            Arrays.fill(row, -1);

        Queue<Pair> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid.get(i).get(j) == 1) {

                    q.offer(new Pair(i, j));
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.isEmpty()) {

            Pair node = q.poll();

            int row = node.row;
            int col = node.col;

            for (int i = 0; i < 4; i++) {

                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newCol >= 0 &&
                    newRow < n && newCol < n &&
                    dist[newRow][newCol] == -1) {
                    dist[newRow][newCol] = dist[row][col] + 1;

                    q.offer(new Pair(newRow, newCol));
                }
            }
        }

        int low = 0;
        int high = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = Math.max(high, dist[i][j]);
            }
        }

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(dist, mid)) {

                ans = mid;
                low = mid + 1;

            } else {

                high = mid - 1;
            }
        }

        return ans;
    }

    public boolean isPossible(int[][] dist, int mid) {

        int n = dist.length;

        if (dist[0][0] < mid)
            return false;

        Queue<Pair> q = new LinkedList<>();

        boolean[][] vis = new boolean[n][n];

        q.offer(new Pair(0, 0));
        vis[0][0] = true;

        while (!q.isEmpty()) {

            Pair node = q.poll();

            int row = node.row;
            int col = node.col;

            if (row == n - 1 && col == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {

                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newCol >= 0 &&
                    newRow < n && newCol < n &&
                    !vis[newRow][newCol] &&
                    dist[newRow][newCol] >= mid) {

                    vis[newRow][newCol] = true;
                    q.offer(new Pair(newRow, newCol));
                }
            }
        }

        return false;
    }
}