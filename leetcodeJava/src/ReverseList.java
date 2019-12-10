public class ReverseList {
    static ListNode temp = null;
    public static ListNode reverseList(ListNode head)
    {

        ListNode result = recurList(head);
        result.next = null;
        return temp;


    }
    public static ListNode recurList(ListNode head){

        if(head.next == null){
            temp = head;
            return head;
        }

        ListNode rev = recurList(head.next);

        rev.next = head;
        return head;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        reverseList(head);
    }
}
