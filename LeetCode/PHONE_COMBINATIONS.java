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