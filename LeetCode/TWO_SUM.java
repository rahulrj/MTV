class Solution {
    public int[] twoSum(int[] nums, int target) {
        
   int[] result = new int[2];
   Map<Integer, Integer> map = new HashMap<Integer, Integer>();
   for(int i=0;i<nums.length;i++){
       map.put(nums[i],i);
   }
        
   for(int i=0;i<nums.length;i++){
       int sum=target-nums[i];
       if(map.containsKey(sum) && map.get(sum)!=i){
           result[0]=i;
           result[1]=map.get(sum);
           break;
       }
   }     
        
        
        
    return result;
        
//         for(int i=0;i<nums.length;i++){
//             map.put(nums[i],i);
//         }
        
//         for(int i=0;i<nums.length;i++){
//             int sum=target-nums[i];
//             int tempIndex=map.get(nums[i]);
            
//             map.remove(nums[i]);
        
            
//             if(map.containsKey(sum)){
//                 res[0]=map.get(sum);
//                 res[1]=i;
//                 break;
//             }
//             map.put(nums[i],tempIndex);
//         }
        
        //return res;
        
    }
}