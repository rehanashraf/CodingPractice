import java.util.HashMap;

public class TimeBasedKeyValueStore {

    HashMap<String, TMNode> map = null;

    /**
     * Initialize your data structure here.
     */
    public TimeBasedKeyValueStore() {
        this.map = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {

        TMNode newNode = new TMNode(value, timestamp);
        if (!map.containsKey(key)) {
            map.put(key, newNode);
        } else {
            TMNode head = map.get(key);
            newNode.next = head;
            map.put(key, newNode);

        }

    }

    public String get(String key, int timestamp) {
        return map.get(key).val;
    }

    class TMNode {
        String val;
        int timestamp;
        TMNode next;

        public TMNode(String s, int t) {
            this.val = s;
            this.timestamp = t;
        }
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
