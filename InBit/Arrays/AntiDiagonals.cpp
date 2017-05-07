// https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int>> &A) {

    int n=A.size();
    vector<vector<int>>result;


    int i=0,j=0;
    while(j<n){

        vector<int>v;
        for(int i=0,j1=j;i<n && j1>=0;i++,j1--){
            v.push_back(A[i][j1]);
        }

        result.push_back(v);
        j+=1;

    }


    i=1;
    while(i<n){
        
        vector<int>v;
        for(int i1=i,j=n-1;i1<n && j>=0;i1++,j--){
            v.push_back(A[i1][j]);
        }

        result.push_back(v);
        i+=1;

    }


    return result;


}
