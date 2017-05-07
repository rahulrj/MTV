// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     vector<vector<int>>result(A+1);

    for(int i=0;i<=A;i++){

        vector<int>v(i+1);
        if(i==0){
            v[0]=1;
            //cout<<result[0][0]<<" ";

        }
        else{

            for(int j=0;j<=i;j++){
                if(j==0){
                    v[j]=1;
                    //cout<<result[i][j]<<" ";
                    continue;
                }
                if(j==i){
                    v[j]=1;
                    //cout<<result[i][j]<<" ";
                    continue;
                }

                v[j]=result[i-1][j]+result[i-1][j-1];
                //cout<<result[i][j]<<" ";
            }
        }

        result[i]=v;

    }
    return result[A];
}
