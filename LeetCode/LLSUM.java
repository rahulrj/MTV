/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        if(l1==null){
            return l2;
        }
        if(l2==null){
            return l1;
        }
        int carry=0;
        ListNode result=null;
        ListNode pointerNode=null;
        while(l1!=null && l2!=null){
            
            int sum=carry+l1.val+l2.val;
            int rem=sum%10;
            int quo=sum/10;
            ListNode temp=new ListNode(rem);
            carry=quo;
            //temp.val=sum;
            
            if(result==null){
                result=temp;
                pointerNode=result;
            }
            else{
                pointerNode.next=temp;
                pointerNode=pointerNode.next;
            }
            
            l1=l1.next;
            l2=l2.next;
        }
        
        while(l1!=null){
            int sum=carry+l1.val;
            int rem=sum%10;
            int quo=sum/10;
            ListNode temp=new ListNode(rem);
            carry=quo;
            //temp.val=sum;
            pointerNode.next=temp;
            pointerNode=pointerNode.next;
            l1=l1.next;
            
        }
        
        while(l2!=null){
            int sum=carry+l2.val;
            int rem=sum%10;
            int quo=sum/10;
            ListNode temp=new ListNode(rem);
            carry=quo;
            //temp.val=sum;
            pointerNode.next=temp;
            pointerNode=pointerNode.next;
            l2=l2.next;
        }
        if(carry!=0){
            ListNode temp=new ListNode(carry);
            //temp.val=sum;
            pointerNode.next=temp;
        }
        
        return result;
        
        
        
    }
}