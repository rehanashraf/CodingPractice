public class ReverseLinkedListII {

    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */

        public static ListNode reverseBetween(ListNode head, int m, int n) {
            if(head == null){
                return null;
            }
            if(n <= m){
                return head;
            }
            int index = 1;
            ListNode current = head;
            ListNode prev = null;
            boolean b = false;
            ListNode start = head;
            while(current != null){
                if(index>=m && index <=n)
                {
                    ListNode next = current.next;
                    current.next = prev;
                    prev = current;

                    current = next;
                    if(index == n){
                        b = true;
                    }
                }
                else
                {
                    if(b){
                        // start and end manipulation
                        ListNode x = start.next;
                        start.next = prev;
                        x.next = current;
                        b = false;
                    }
                    else{
                        if(index + 1 < m) {
                            start = start.next;
                        }
                    }
                    current = current.next;
                }
                index++;
            }
            return head;

        }

    public static void main(String[] args) {
       ListNode head = new ListNode(1);
       head.next = new ListNode(2);
       head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        reverseBetween(head, 2, 5);
        System.out.println(head.toString());
    }

}
