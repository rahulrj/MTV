// https://www.interviewbit.com/problems/add-one-to-number/

public class Solution {
	public ArrayList<Integer> plusOne(ArrayList<Integer> a) {

	    int size=a.size();
	    ArrayList<Integer>result=new ArrayList<>();
	    int carry=0;
	    for(int i=size-1;i>=0;i--){
	       int res=a.get(i)+carry;

	       if(i==size-1){
	           res+=1;
	       }

	       carry=res/10;
	       int rem=res%10;

	       result.add(0,rem);

	    }

	    result.add(0,carry);

	    //System.out.println(result.size());
// 	    for(int i=0;i<result.size();i++){
// 		    System.out.println(result.get(i));
// 		}



	    if(carry!=0){
	        return result;
	    }
	    else{
	        int flag=0;
	        ArrayList<Integer>newResult=new ArrayList<>();
	        for(int i=0;i<size+1;i++){

	            if(result.get(i)==0 && flag==0){
	                continue;
	            }
	            else{
	                flag=1;
	                newResult.add(result.get(i));
	            }
	        }
            return newResult;

	    }
	}
}
