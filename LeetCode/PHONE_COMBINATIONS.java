class Solution {
    public List<String> letterCombinations(String digits) {
        
        String letters[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        
        List<String>result=new ArrayList<>();
        getResult(digits,letters,result,"",0);
        System.out.println(result);
        return result;
        
    }
    
    private void getResult(String digits,String letters[],List<String>result,String prefix,int index){
            
            if(index>=digits.length()){
                return ;
            }
            int digit=digits.charAt(index)-'0';
            
            String group=letters[digit];
            
            for(int j=0;j<group.length();j++){
                String res=prefix+group.charAt(j);
                if(res.length()==digits.length()){
                    result.add(res);
                }
                getResult(digits,letters,result,res,index+1);
            }
        
        
    }
}


// Other solution by a genius
class Solution {
    
    public List<String> letterCombinations(String digits) {
    LinkedList<String> ans = new LinkedList<String>();
    String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    ans.add("");
        
        
    for(int i =0; i<digits.length();i++){
        int x = Character.getNumericValue(digits.charAt(i));
        System.out.println(""+x);
         System.out.println(ans);
        System.out.println(ans.peek());
        while(ans.peek().length()==i){
            String t = ans.remove();
            for(char s : mapping[x].toCharArray())
                ans.add(t+s);
            System.out.println("ans"+ans);
        }
    }
    return ans;
}
}