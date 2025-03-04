/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        ListNode cur = head;
        while(cur != null){
            if(cur.val != val){
                tail.next = cur;
                tail = cur;
            }
            cur = cur.next; // original list wala pointer to hamesha forward move karega
        }

        tail.next = null;
        return dummy.next;
    }
}