import java.util.HashMap;
import java.util.List;

public class IntersectionofTwoLinkedLists {

    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        // reference and node in map
        HashMap<Integer, ListNode> map = new HashMap<>();
        if(headA == null || headB == null){
            return null;
        }
        ListNode currentA = headA;
        ListNode currentB = headB;

        while(currentA != null) {

            map.put(currentA.hashCode(), currentA);
            currentA = currentA.next;
        }
        while (currentB != null)
        {
           if(map.containsKey(currentB.hashCode())){
               return currentB;
           }
            currentB = currentB.next;

        }
        return null;


    }

    public static ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        if(headA == null || headB == null){
            return null;
        }
        ListNode currentA = headA;
        ListNode currentB = headB;

        while(currentA.next != null) {

           // map.put(currentA.hashCode(), currentA);

            currentA = currentA.next;
        }
        //
        while (currentB.next != null)
        {
            currentB = currentB.next;

        }

        if(currentA == currentB)
        {
            return currentA;
        }
        else{
            return null;
        }
    }



    public static void main(String[] args) {
        ListNode headA = new ListNode(4);
        headA.next = new ListNode(1);
        ListNode common = new ListNode(8);
        headA.next.next = common;
        common.next = new ListNode(4);
        common.next.next = new ListNode(5);

        ListNode headB = new ListNode(5);
        headB.next = new ListNode(0);
        headB.next.next = new ListNode(1);
        headB.next.next.next = common;

        ListNode inter = getIntersectionNode2(headA, headB);
        System.out.println(inter.val);

    }
}