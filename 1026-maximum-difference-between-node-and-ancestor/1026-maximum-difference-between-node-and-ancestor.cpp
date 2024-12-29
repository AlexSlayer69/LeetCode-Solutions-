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
class Solution {
    public int maxAncestorDiff(TreeNode root) {
        int minv= root.val;
        int maxv = root.val;
        return findMax(root, minv, maxv);
    }
    public int findMax(TreeNode root, int minv, int maxv){
        if(root == null){
            return Math.abs(minv - maxv);
        }
        minv= Math.min(minv , root.val);
        maxv = Math.max(maxv , root.val);

        int l = findMax(root.left,minv, maxv);
        int r= findMax(root.right, minv , maxv);

        return Math.max(l,r);
    }
}