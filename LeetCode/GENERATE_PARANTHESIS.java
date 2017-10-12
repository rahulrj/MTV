//https://leetcode.com/problems/generate-parentheses/description/
class Solution {
    public List<String> generateParenthesis(int n) {
        
        List<String>result=new ArrayList<>();
        findResult(result,"",0,0,n);
        
        return result;
    }
    
    static void findResult(List<String>result,String str,int open,int close, int n){
        
        if(str.length()==2*n){
            result.add(str);
        }
        
        if(open<n){
            findResult(result,str+"(",open+1,close,n);
        }
        
        if(close<open && close<n){
            findResult(result,str+")",open,close+1,n);
        }
        
        
        
    }
}