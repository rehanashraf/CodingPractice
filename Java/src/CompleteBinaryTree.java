import apple.laf.JRSUIUtils;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CompleteBinaryTree {

    public static boolean isCompleteTree(TreeNode root) {
        if(root == null) {
            return true;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean foundNull = false;
        while(!queue.isEmpty()) {
            TreeNode current = queue.poll();
            if(current.left != null)
            {
                queue.add(current.left);
            }
            else{
                if(foundNull){
                    return false;
                }
                foundNull = true;

            }
            if(current.right != null)
            {
                queue.add(current.right);
            }
            else{
                if(foundNull){
                    return false;
                }
                foundNull = true;
            }

        }
        return true;
    }

    public static boolean isCompleteTree2(TreeNode root) {
        if (root == null) {
            return true;
        }
        TreeNode[] list = new TreeNode[100];

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int ind = 0;
        list[ind++] = root;

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            if (current.left != null) {
                queue.add(current.left);
                list[ind++] =(current.left);
            }
            else{
                TreeNode nullNode = null;
                list[ind++] = (nullNode);
            }

            if (current.right != null) {
                queue.add(current.right);
                list[ind++]= (current.right);
            }
            else{
                TreeNode nullNode = null;
                list[ind++]=(nullNode);
            }


        }
      //  TreeNode nNode = list[7];
        boolean foundNull = false;
        for(int i=0; i < list.length; i++){
            TreeNode cur = list[i];
            if(list[i] != null && foundNull){
                return false;
            }
            if(list[i] == null){
                foundNull = true;
            }
        }
        return true;

    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        //root.right.right = new TreeNode(8);
        System.out.println(isCompleteTree2(root));

    }
}
