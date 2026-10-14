import jdk.nashorn.api.tree.Tree;

import java.util.*;

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode (int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class ConstructBST{
    int idx; //variable to store index during traversal
    ConstructBST(){
        this.idx = 0;
    }
    public TreeNode BSTusingPreorder(int[] a, int mn, int mx, int sz){
        if(idx >= sz) return null;
        int key = a[idx];
        TreeNode root = null; //initialize the root
        if(key > mn && key < mx){
            //condition for BST to find elements which are children of a[idx] node
            idx += 1;
            root = new TreeNode(key); //create a node when found
            root.left = BSTusingPreorder(a, mn, key, sz);
            root.right = BSTusingPreorder(a, key, mx, sz);
        }
        return root;
    }
    public void displayPreorder(TreeNode root){
        if(root == null) return;
        System.out.println(root.data);
        displayPreorder(root.left);
        displayPreorder(root.right);
    }
    public void displayInorder(TreeNode root){
        if(root == null) return;
        displayInorder(root.left);
        System.out.println(root.data);
        displayInorder(root.right);
    }
}

class ConstructBSTfromPreorder{
    public static void main(String[] args){
        //Pre array provides preorder traversal of a BST
        //int[] pre = {10, 7, 5, 8, 9, 15, 17};
        //int[] pre = {10, 7, 8, 9, 15, 17};
        //int[] pre = {1, 5, 7, 8, 9, 15, 17};
        //int[] pre = {17, 15, 9, 8, 7, 5, 1};
        int[] pre = {17};
        ConstructBST obj = new ConstructBST();
        obj.displayInorder(obj.BSTusingPreorder(pre, Integer.MIN_VALUE, Integer.MAX_VALUE, pre.length));
    }
}
