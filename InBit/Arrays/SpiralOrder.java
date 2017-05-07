// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

public class Solution {
	public ArrayList<ArrayList<Integer>> generateMatrix(int a) {

	    int size=a*a;
	    int mat[][]=new int[size][size];
	    int ctr=1,i=0,j=0;
	    int i_ctr=0;


	    int var1_k=-1,var1_max=a+1,var1_i=-1;
	    int var2_k=0,var2_max=a+1,var2_j=a;
	    int var3_k=a-1,var3_max=-1,var3_i=a;
	    int var4_k=a-1,var4_max=0,var4_j=-1;

	    while(ctr<=size){

	    var1_i+=1;
	    var1_k+=1;
	    var1_max-=1;
	    for(int k=var1_k;k<var1_max;k++){
	        mat[var1_i][k]=ctr;
	        ctr+=1;
	    }

	    if(ctr>size){
	        break;
	    }

	    var2_k+=1;
	    var2_max-=1;
	    var2_j-=1;
	    for(int k=var2_k;k<var2_max;k++){
	        mat[k][var2_j]=ctr;
	        ctr+=1;
	    }

	     if(ctr>size){
	        break;
	    }

	    var3_k-=1;
	    var3_max+=1;
	    var3_i-=1;
	    for(int k=var3_k;k>=var3_max;k--){
	        mat[var3_i][k]=ctr;
	        ctr+=1;
	    }

	     if(ctr>size){
	        break;
	    }

	    var4_k-=1;
	    var4_max+=1;
	    var4_j+=1;
	    for(int k=var4_k;k>=var4_max;k--){
	        mat[k][var4_j]=ctr;
	        ctr+=1;
	    }

	    //System.out.println("ctr"+ctr);



	     if(ctr>size){
	        break;
	    }

	 }


	 ArrayList<ArrayList<Integer>>result=new ArrayList<>();


	 for(int l=0;l<a;l++){
	     ArrayList<Integer>temp=new ArrayList<>();
	     for(int m=0;m<a;m++){
	        temp.add(mat[l][m]);
	     }
	     result.add(temp);
	 }

	 return result;

	}
}
