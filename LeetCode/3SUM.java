//https://leetcode.com/problems/3sum/description/

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
       // List<Integer>list=Arrays.asList(nums);      
        Arrays.sort(nums);
        List<List<Integer>>result=new ArrayList<>();
        List<Integer>summs=new ArrayList<>();
        
        for(int i=0;i<nums.length;i++){
            int sum= -nums[i];
            
            int l=0;
            int r=nums.length-1;
            
            while(l<r){

                if(l==i){
                    l++;
                    continue;
                }
                if(r==i){
                    r--;
                    continue;
                }
                if(nums[l]+nums[r]==sum && summs.indexOf(sum)==-1){
                    List<Integer>res=new ArrayList<>();
                    res.add(nums[l]);
                    res.add(nums[r]);
                    res.add(-sum);   
                    summs.add(sum);
                    //if(result.indexOf(res)==-1)
                    result.add(res);
                    System.out.println(l+" "+r+" "+sum);
                    break;
                }
                
                if(nums[l]+nums[r]<sum){
                    l++;
                }
                else{
                    r--;
                }
            }
            
        }
        
        
        
        return result;
        
        
    }
}



class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
    List<List<Integer>> res = new ArrayList<>();
    Arrays.sort(nums);
    for (int i = 0; i + 2 < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {              // skip same result
            continue;
        }
        int j = i + 1, k = nums.length - 1;  
        int target = -nums[i];
        while (j < k) {
            if (nums[j] + nums[k] == target) {
                res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;  // skip same result
                while (j < k && nums[k] == nums[k + 1]) k--;  // skip same result
            } else if (nums[j] + nums[k] > target) {
                k--;
            } else {
                j++;
            }
        }
    }
    return res;
}
}