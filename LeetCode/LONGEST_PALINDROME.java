//https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
    public String longestPalindrome(String s) {
        
        boolean[][]table=new boolean[s.length()][s.length()];
        int max_length=1;
        int start_index=0;
        
        for(int i=0;i<s.length();i++){
            table[i][i]=true;
            
            if(i!=s.length()-1 && s.charAt(i)==s.charAt(i+1)){
                table[i][i+1]=true;
                max_length=2;
                start_index=i;
            }         
            
        }
        
        for(int j=3;j<=s.length();j++){
            for(int k=0;k<s.length()-j+1;k++){
                
                int x_index=k;
                int y_index=k+j-1;
                
                if(table[x_index+1][y_index-1] && s.charAt(x_index)==s.charAt(y_index)){
                    table[x_index][y_index]=true;
                    int len=y_index-x_index+1;
                    if(len>max_length){
                        max_length=len;
                        start_index=x_index;
                    }
                }
                
                
                
            }
        }
        
        //System.out.println(max_length);
        
        return s.substring(start_index,start_index+max_length);
        
        
        
    }
}