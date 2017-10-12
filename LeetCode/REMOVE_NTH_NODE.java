/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        if(head==null){
            return null;
        }
        if(head.next==null){
            return null;
        }
        
        
        ListNode temp1=head;
        ListNode temp2=head;
        ListNode temp3=head;
        int count=1;
        
        while(count<n && temp2.next!=null){
            temp2=temp2.next;
            count=count+1;
            
            if(count==n){
                break;
            }
        }
                
        int x=1;
        while(temp2.next!=null){
            temp2=temp2.next;
            temp1=temp1.next;
            if(x!=1){
                temp3=temp3.next;
            }
            x=2;
        }
        
        if(temp3==temp1){
            return head.next;
        }
        
        // while(temp3.next!=temp1){
        //     temp3=temp3.next;
        // }
        
        temp3.next=temp1.next;
        
        return head;
        
      
        
    }
}