class Node {
    int key;
    int val;
    Node next;
    Node prev;

    public Node(int key, int val){
        this.key = key;
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {
    int capacity;
    HashMap<Integer,Node> mp;
    Node head = new Node(-1,-1), tail = new Node(-1,-1);
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.mp = new HashMap<>();
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if(mp.containsKey(key)){
            int value = mp.get(key).val;
            delete(mp.get(key));
            insertMru(key,value);
            return value;
        }
        else {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key))
        {
            delete(mp.get(key));
            insertMru(key,value);
        }
        else
        {
            if(mp.size() == capacity)
            {
            // if(key == 3 && value == 3){
            //     System.out.println(mp);
            //     System.out.println(tail.key + " " + tail.val);
            // }
                delete(tail.prev);
            // if(key == 3 && value == 3)System.out.println(mp);
            }
                insertMru(key,value);
        }
    }

   

    void insertMru(int key, int value)
    {
        Node node = new Node(key,value);
        mp.put(key,node);
        Node temp = head.next;
        node.next = temp;
        temp.prev = node;

        head.next = node;
        node.prev = head;
    }

    void delete(Node node)
    {
        Node delPrev = node.prev;
        Node delNext = node.next;
        delPrev.next = delNext;
        delNext.prev = delPrev;
        node.next = null;
        node.prev = null;
        mp.remove(node.key);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */