import java.util.ArrayList;

public class SymmetricTree
{
    public boolean isSymmetric(MaximumBinaryTree.TreeNode root) {
        return  isSymmetricHelper(root, root);


    }

    public boolean isSymmetricHelper(MaximumBinaryTree.TreeNode l, MaximumBinaryTree.TreeNode r){
        if(l == null && r != null){
            return false;
        }
        else if(l != null && r == null){
            return false;
        }
        else if( l == null && r == null){
            return true;
        }
        else if(l.val != r.val){
            return false;
        }
        else{
            return isSymmetricHelper(l.left, r.right) && isSymmetricHelper(l.right, r.left);
        }


    }
}
