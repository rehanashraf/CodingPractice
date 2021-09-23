import java.util.List;

public class AddTwoNumbers {


 // Definition for singly-linked list.
  public static class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
  }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      if(l1 == null){
          return l2;
      }
      if(l2 == null){
          return l1;
      }

      ListNode res = new ListNode(-1);
      ListNode head = res;
      int carry = 0;
      int sumDigits = -1;
      while(l1 != null && l2 != null){
           sumDigits = l1.val + l2.val + carry;
          int nNode = -1;
          if(sumDigits > 9){
              nNode = sumDigits%10;
              carry = 1;
          }
          else
              {

              carry = 0;
              nNode = sumDigits;
          }
          res.next = new ListNode(nNode);
          res = res.next;
          l1 = l1.next;
          l2 = l2.next;


      }
      while(l1 != null){
          int nNode = -1;
          sumDigits = l1.val + carry;

          if(sumDigits > 9){
              nNode = sumDigits%10;
              carry = 1;
          }
          else{
              carry = 0;
              nNode = sumDigits;
          }
          res.next = new ListNode(nNode);
          res = res.next;
          l1 = l1.next;
      }
        while(l2 != null){
            int nNode = -1;
            sumDigits = l2.val + carry;

            if(sumDigits > 9){
                nNode = sumDigits%10;
                carry = 1;
            }
            else{
                carry = 0;
                nNode = sumDigits;
            }
            res.next = new ListNode(nNode);
            res = res.next;

            l2 = l2.next;
        }
        if(carry > 0){
            res.next = new ListNode(carry);

        }
        return head.next;

    }

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
       // l1.next = new ListNode(4);
        // l1.next.next = new ListNode(3);
        ListNode l2 = new ListNode(9);
        l2.next = new ListNode(9);
        //l2.next.next = new ListNode(4);

        ListNode r = addTwoNumbers(l1, l2);
        System.out.println(r.toString());




  }
}