/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Pair{
    TreeNode node;
    int v;
    int level;
    Pair(TreeNode node,int v,int level){
        this.node=node;
        this.v=v;
        this.level=level;
    }
}
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer,TreeMap<Integer,PriorityQueue<Integer>>> nodes= new TreeMap<>();
        Queue<Pair> q= new LinkedList<>();
        
        if(root==null) return new ArrayList<>();
        q.add(new Pair(root,0,0));

        while(!q.isEmpty()){
            Pair p= q.poll();
            TreeNode node= p.node;
            int col= p.v;
            int row= p.level;

            nodes.putIfAbsent(col, new TreeMap<>());
            nodes.get(col).putIfAbsent(row,new PriorityQueue<>());

            nodes.get(col).get(row).add(node.val);

            if(node.left!= null)
                q.add(new Pair(node.left, col-1, row+1));
            if(node.right!= null)
                q.add(new Pair(node.right, col+1, row+1));
        }

        List<List<Integer>> ans= new ArrayList<>();
        for(TreeMap<Integer, PriorityQueue<Integer>> rows : nodes.values()){
            List<Integer> column= new ArrayList<>();
            for(PriorityQueue<Integer> pq: rows.values()){
                while(!pq.isEmpty()){
                    column.add(pq.poll());
                }
            }
            ans.add(column);
        }
        return ans;
    }
}