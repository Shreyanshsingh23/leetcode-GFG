class MyLinkedList {

    private static class ListNode {
        int val;
        ListNode next;

        ListNode (int val){
            this.val = val;
        }

        ListNode(int val, ListNode next){
            this.val = val;
            this.next = next;
        }

    }

    private ListNode head;
    private ListNode tail;
    private int size;

    public MyLinkedList() {
        head = tail = null;
        size = 0;
    }
    
    public int get(int index) {
        if(index < 0 || index >= size)return -1;
        int cnt = 0;
        // ListNode t = head;
        // while(t != null || t.next != null){
        //     System.out.println(t.val);
        //     t = t.next;
        // }
        ListNode temp = head;
        
        while(index > 0){
            // System.out.println(temp.val);
            temp = temp.next;
            index --;
        }

        return temp.val;
    }
    
    public void addAtHead(int val) {
        ListNode temp = new ListNode(val);
        temp.next = head;
        head = temp;
        if(size == 0){
            tail = temp;
        }
        size++;
    }
    
    public void addAtTail(int val) {
        ListNode temp = new ListNode(val);
        if(tail == null){
            head = temp;
            tail = temp;
        }
        else{
            tail.next = temp;
            tail = temp;
        }
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }

        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }

         ListNode temp = head;
         int cnt = 0;
         while(cnt < index-1){
            temp = temp.next;
            cnt++;
         }
         ListNode newNode = new ListNode(val);
         newNode.next = temp.next;
         temp.next = newNode;
         size++;
         
    }
    
    public void deleteAtIndex(int index) {
        if(index < 0 || index >= size)return;

        if(index == 0){
            head = head.next;
            if(size-1 == 0)tail = null;
            size --;
            return;
        }

        int cnt = 0;
        ListNode temp = head;
        while(cnt < index - 1){
            temp = temp.next;
            ++cnt;
        }

        if(temp.next == tail){
            tail = temp;
        }
        temp.next = temp.next.next;
        size --;

    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

