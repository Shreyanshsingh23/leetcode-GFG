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
    Node head = null, tail = null;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.mp = new HashMap<>();
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
                deleteLru();
            // if(key == 3 && value == 3)System.out.println(mp);
            }
                insertMru(key,value);
        }
    }

    void deleteLru()
    {
        if(tail != null){
            int key = tail.key;
            mp.remove(key);
            if(tail.prev != null){
                tail.prev.next = null;
                Node z = tail.prev;
                tail.next = null;
                tail.prev = null;
                tail = z;
            }else{
                // is the only element in list
                head = null;
                tail = null;
            }
        }
    }

    void insertMru(int key, int value)
    {
        Node newNode = new Node(key,value);
        mp.put(key,newNode);
        newNode.next = head;
        if(head != null){
            head.prev = newNode;
        }
        head = newNode;
        if(tail == null)tail = newNode;
    }

    void delete(Node node)
    {
        if(node == tail)tail = node.prev;
        if(node == head)head = node.next;
        if(node.prev != null){
            node.prev.next = node.next;
        }
        if(node.next != null){
            node.next.prev = node.prev;
        }
        // node.prev = null;
        // node.next = null;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */