/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        
        if(lists==null || lists.length==0){
            return null;
        }
        
        PriorityQueue<ListNode> queue=new PriorityQueue<ListNode>(new Comparator<ListNode>(){
                                                                  public int compare(ListNode l1,ListNode l2){
                                                                      return l1.val-l2.val;
                                                                  }
                                                                  });
        
        for(int i=0;i<lists.length;i++){
            if(lists[i]!=null){
              queue.offer(lists[i]);
            }
        }
        
        
        ListNode tempNode=new ListNode(0);
        ListNode tempNode2=tempNode;
        Iterator<ListNode> iter = queue.iterator();
        while (true) {
           ListNode current = queue.poll();
            if(current==null){
                break;
            }
            tempNode2.next=current;
            tempNode2=tempNode2.next;
            
            if(current.next!=null){
                queue.offer(current.next);
            }
            
        }
        
        return tempNode.next;
        
                                                                 
        
        
    }
}