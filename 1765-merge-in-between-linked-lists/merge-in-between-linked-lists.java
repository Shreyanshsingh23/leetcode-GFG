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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int i = 0;
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        ListNode cur = list1;
        while(i < a){
            tail.next = cur;
            tail = cur;
            cur = cur.next;
            ++i;
        }

        ListNode cur2 = list2;
        while(cur2 != null){
           tail.next = cur2;
            tail = cur2;
            cur2 = cur2.next;
        }

         while(i <= b){
            cur = cur.next;
            ++i;
        }

        while(cur != null){
            tail.next = cur;
            tail = cur;
            cur = cur.next;
        }

        return dummy.next;

    }
}