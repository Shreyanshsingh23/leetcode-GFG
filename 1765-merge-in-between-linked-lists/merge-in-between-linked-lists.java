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
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        ListNode cur = list1;
        for(int i = 0; i < a; ++i){
            tail.next = cur;
            tail = cur;
            cur = cur.next;
        }

        ListNode cur2 = list2;
        while(cur2 != null){
           tail.next = cur2;
            tail = cur2;
            cur2 = cur2.next;
        }

         for(int i = a; i <= b; ++i){
            cur = cur.next;
        }

        tail.next = cur;
        //Aage ke links dubara jodna jaruri nhi hai bss ek to tail se jod do baaki toh jude hi hain

        return dummy.next;

    }
}