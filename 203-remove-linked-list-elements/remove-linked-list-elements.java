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
        ListNode temp = head, prev = head, ret = head;
        while(temp != null){
            if(temp.val == val){
                if(prev == temp){
                    prev = temp.next;
                    temp = temp.next;
                    ret = temp;
                }
                else{
                    prev.next = temp.next;
                    temp = temp.next;
                }
            }
            else{
                prev = temp;
                temp = temp.next;
            }
        }
        return ret;
    }
}