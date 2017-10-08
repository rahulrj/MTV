//https://leetcode.com/problems/regular-expression-matching/description/

class Solution {
   public boolean isMatch(String text, String pattern) {
       
       if(text.length()==0 && pattern.length()==0){
           return true;
       }
       
       //  if(text.length()==0 && pattern.length()!=0){
       //     return false;
       // }
       
        if(text.length()!=0 && pattern.length()==0){
           return false;
       }
       
       boolean isFirstMatch=false;
       if(text.length()>=1){
           isFirstMatch=(text.charAt(0)==pattern.charAt(0))|| (pattern.charAt(0)=='.');
       }
       
       if(pattern.length()>=2 && pattern.charAt(1)=='*'){
           return (isFirstMatch && isMatch(text.substring(1),pattern))||
               (isMatch(text,pattern.substring(2)));
       }
       
       else{
           return isFirstMatch && isMatch(text.substring(1),pattern.substring(1));
       }
       
       
   }
     
}