class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        
        int len=s.length();
        boolean wb[]=new boolean[len+1];
        
        for(int i=1;i<=len;i++){
            String substr=s.substring(0,i);
            
            if(wordDict.indexOf(substr)!=-1){
                wb[i]=true;
            }
            
            if(wb[i] && i==len){
                return true;
            }
            
            if(wb[i]){
               for(int j=i+1;j<=len;j++){                   
                  String substr2=s.substring(i,j);
                   
                  if(wb[j]==false && wordDict.indexOf(substr2)!=-1){
                      wb[j]=true;
                  } 
                   
                  if(wb[j]==true && j==len){
                      return true;
                  } 
                   
               }
            } 
                
            
        }
        
        return false;
      
    }
}