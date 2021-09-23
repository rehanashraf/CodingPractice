//import java.util.HashMap;
//import java.util.HashSet;
//import java.util.Set;
//import java.util.concurrent.atomic.AtomicInteger;
//
//public class CopyListwithRandomPointer {
//    class Node {
//        public int val;
//        public Node next;
//        public Node random;
//
//        public Node() {
//        }
//
//        public Node(int _val, Node _next, Node _random) {
//            val = _val;
//            next = _next;
//            random = _random;
//        }
//    }
//
//    public Node copyRandomList(Node head) {
//            Node current1 = head;
//            if(current1 == null){
//                return null;
//            }
//
//            HashMap<Node, Node> map = new HashMap<>();
//            Node headNode = new Node(current1.val, null, null);
//
//            Node current2 = headNode;
//
//        map.put(current1, current2);
//
//            while(current1 != null)
//            {
//
//                if(current1.random != null && !map.containsKey(current1.next)){
//
//                    Node newNode = new Node(current1.next.val, null, null);
//                    map.put(current1.next, newNode);
//                    current2.next = map.get(current1.next);
//                }
//                else{
//                    current2.next = map.get(current1.next);
//                }
//                if(current1.random != null && !map.containsKey(current1.random)){
//
//                    Node newNode = new Node(current1.random.val, null, null);
//                    map.put(current1.random, newNode);
//                    current2.random = map.get(current1.random);
//                }
//                else{
//                    current2.random = map.get(current1.random);
//                }
//                current1 = current1.next;
//                current2 = current2.next;
//
//
//
//            }
//            return headNode;
//
//
//    }
//
//    public static void main(String[] args) {
//        Node head = new Node(1);
//
//
//    }
//
//}