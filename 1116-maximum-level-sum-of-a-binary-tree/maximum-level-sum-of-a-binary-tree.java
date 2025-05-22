class Solution {
    public int maxLevelSum(TreeNode root) {
        List<Integer> levelSums = new ArrayList<>();
        computeLevelSums(root, 0, levelSums);

        int maxSum = Integer.MIN_VALUE;
        int maxLevel = 0;

        for (int i = 0; i < levelSums.size(); i++) {
            if (levelSums.get(i) > maxSum) {
                maxSum = levelSums.get(i);
                maxLevel = i + 1; // Convert 0-based index to 1-based level
            }
        }

        return maxLevel;
    }

    private void computeLevelSums(TreeNode node, int level, List<Integer> levelSums) {
        if (node == null) return;

        // Extend list if this level hasn't been encountered yet
        if (level == levelSums.size()) {
            levelSums.add(node.val);
        } else {
            levelSums.set(level, levelSums.get(level) + node.val);
        }

        computeLevelSums(node.left, level + 1, levelSums);
        computeLevelSums(node.right, level + 1, levelSums);
    }
}
