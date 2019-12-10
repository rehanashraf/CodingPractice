import java.io.Serializable;
import java.lang.reflect.Method;
import java.util.HashMap;

class LRUCache {

    class DLinkedNode
    {
        int value;
        int key;
        DLinkedNode next;
        DLinkedNode prev;

    }

    void addNode(DLinkedNode node)
    {
        // add after head
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;

    }


    void removeNode(DLinkedNode node)
    {
        DLinkedNode prev = node.prev;
        DLinkedNode next = node.next;

        prev.next = next;
        next.prev = prev;

    }

    void popTail()
    {
        DLinkedNode lastNode = tail.prev;
        removeNode(lastNode);
    }

    void moveToHead(DLinkedNode node)
    {
        removeNode(node);
        addNode(node);

    }

    private HashMap<Integer, DLinkedNode> map = new HashMap<>();

    // set defaults or set up doubly linked list
//    DLinkedNode head = new DLinkedNode();
//    DLinkedNode tail = new DLinkedNode();
//    head.next = tail;
//    tail.prev = head;

    private int cap;
    private int size;
    private DLinkedNode head, tail;

    public LRUCache(int capacity) {
        this.size = 0;
        this.cap = capacity;

        head = new DLinkedNode();
        // head.prev = null;

        tail = new DLinkedNode();
        // tail.next = null;

        head.next = tail;
        tail.prev = head;
    }


    public int get(int key)
    {
        if(map.containsKey(key)){
            // move the accessed node to the head;
            DLinkedNode node = map.get(key);

            // move this node to head of the doubly linked list
            moveToHead(node);

            return node.value;
        }
        return -1;

    }

    public void put(int key, int value)
    {
        if(map.containsKey(key)){
            DLinkedNode node = map.get(key);
            node.value = value;

            // move this node to head of the doubly linked list
            moveToHead(node);

        }
        else{
            DLinkedNode node = new DLinkedNode();
            node.value = value;

            map.put(key, node);

            addNode(node);

            ++size;

            if(size > cap){
                DLinkedNode lastNode = tail.prev;
               popTail();

             //   nodeToDelete.prev.next = nodeToDelete.next;
            //    nodeToDelete.next.prev = nodeToDelete.prev;
                map.remove(lastNode.key);
                --size;
            }


        }

    }

    public static void main(String[] args) throws ClassNotFoundException {
        LRUCache cache = new LRUCache(2);
        Class LRUClass = cache.getClass();
        Method[] methods = LRUClass.getDeclaredMethods();
        System.out.println(methods[0]);

    }

}