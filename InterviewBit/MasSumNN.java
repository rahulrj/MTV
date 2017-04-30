// https://www.interviewbit.com/problems/max-non-negative-subarray/

public class Solution {
	public ArrayList<Integer> maxset(ArrayList<Integer> a) {

	     int size=a.size();
	    long resSum=-1;
	    int resCtr=Integer.MIN_VALUE;
	    int resI=0;

	    long sum=0;
	    int ctr=0;
	    //ArrayList<Integer>temp=new ArrayList<>();
	    for(int i=0;i<size;i++){
	        if(a.get(i)<0){
	            if(sum>resSum){

	                    resSum=sum;
	                    resI=i-1;
	                    resCtr=ctr;

	            }

	            else if(sum==resSum){
	                if(ctr>resCtr){
	                     resSum=sum;
	                    resI=i-1;
	                    resCtr=ctr;
	                }
	            }


	            sum=0;
	            ctr=0;
	            continue;
	        }

	        sum=sum+a.get(i);
	        ctr+=1;


	        if(i==size-1){
	            if(sum>resSum){
	                    resSum=sum;
	                    resI=i;
	                    resCtr=ctr;
	            }
	            else if(sum==resSum){
	                if(ctr>resCtr){
	                    resSum=sum;
	                    resI=i;
	                    resCtr=ctr;
	                }
	            }



	            sum=0;
	            ctr=0;
	        }




	    }

	    ArrayList<Integer>aa=new ArrayList<>();
	   // System.out.println(resI+" "+resCtr);
	   // System.out.println(resCtr);

	    int rr=0;
	    for(int i=(resI-resCtr+1);rr<resCtr;rr++){
	        aa.add(a.get(i+rr));
	    }


	    return aa;
	}
}
