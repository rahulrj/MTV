class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        Map<String,Integer>map=new HashMap<>();
        
        int max_len=0;
        int len=0;
        int start_index=0;
        for(int i=0;i<s.length();i++){
            String ss=""+s.charAt(i);
            len+=1;
            if(!map.containsKey(ss)){
                System.out.println(len);
                if(max_len<len){
                    max_len=len;
                }
            }
             else{
                int index=map.get(ss);
                 start_index=index;
                 len=i-start_index;
                 System.out.println("len2"+len);
                 for(int k=0;k<=index;k++){
                     map.remove(""+s.charAt(k));
                 }
                
             }
            map.put(ss,i);
        }
        
        return max_len;
        
    }
}