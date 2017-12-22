/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    
    public int result=0;
    public int deepestLevel=1;
    
    public int depthSumInverse(List<NestedInteger> nestedList) {
        findDeepestLevel(nestedList,1);
        nestedSum(nestedList,deepestLevel);
        return result;
    }
    
    public void findDeepestLevel(List<NestedInteger> nestedList,int level){
        
        int size = nestedList.size();
        for(int i=0;i<size;i++){
            if(!nestedList.get(i).isInteger()){
                deepestLevel=Math.max(deepestLevel,level+1);
                findDeepestLevel(nestedList.get(i).getList(),level+1);
            }

            
        }
    }
    
     public void nestedSum(List<NestedInteger>nestedList,int level){
        
        int size = nestedList.size();
          
        for(int i=0;i<size;i++){
            if(nestedList.get(i).isInteger()){
                //System.out.println(nestedList.get(i).getInteger() + " "+ level);
                result+=(nestedList.get(i).getInteger() * level);
            }
            nestedSum(nestedList.get(i).getList(),level-1);
            
        }
        
    }
    
    
    
}