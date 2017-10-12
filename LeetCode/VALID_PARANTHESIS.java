class Solution {
    public boolean isValid(String s) {
        
        Stack stack=new Stack();
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='['){
                stack.push(s.charAt(i));
                
            }
            
             if(s.charAt(i)==')' || s.charAt(i)=='}' || s.charAt(i)==']'){
                if(stack.empty()){
                    return false;
                }
                 
                Character a = (Character) stack.pop(); 
                 if(a=='(' && s.charAt(i)!=')'){
                     return false;
                 }
                 if(a=='{' && s.charAt(i)!='}'){
                     return false;
                 }
                 if(a=='[' && s.charAt(i)!=']'){
                     return false;
                 }
                              
                
            }           
            
        }
        
        if(!stack.empty()){
            return false;
        }
        
        return true;
        
        
    }
}