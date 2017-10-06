import java.io.*;
import java.util.*;

class GFG {
	public static void main (String[] args) {
		System.out.println("GfG!");
		
		List<String>dict=new ArrayList<>(Arrays.asList("mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"));
        String s="iloveicecreamandmango";
         wordBreak(s,dict,"",s.length());
	}
	static void wordBreak(String s,List<String>dict,String result,int len){
	    
	    for(int i=1;i<=s.length();i++){
	        String substr=s.substring(0,i);
	        if(dict.indexOf(substr)!=-1){
	            String temp=result+(substr+" ");
	            
	            String wws=temp.replaceAll("\\s+","");
	            if(wws.length()==len){
	                System.out.println(temp);
	            }
	            
	            wordBreak(s.substring(i),dict,temp,len);
	        }
	        
	    }
	}
}