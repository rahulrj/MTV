// https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;

    int m=A.size();
    int n=A[0].size();

    int i1=0,j1=0;
    int count=0;

    //cout<<m*n<<endl;
    int total=m*n;

    while(count<total){

        int i=i1;
        for(int j=j1;j<n;j++){
            result.push_back(A[i][j]);
            count+=1;
        }

        //cout<<"c1"<<count<<endl;
        if(count==total){
            break;
        }

        int j=n-1;
        for(int i=i1+1;i<m;i++){
            result.push_back(A[i][j]);
            count+=1;
        }

        //cout<<"c2"<<count<<endl;
        if(count==total){
            break;
        }

        i=m-1;
        for(int j=n-2;j>=0 && j>=j1;j--){
            result.push_back(A[i][j]);
            count+=1;
        }

        //cout<<"c3"<<count<<endl;
        if(count==total){
            break;
        }

        j=j1;
        for(int i=m-2;i>=0 && i>i1;i--){
            result.push_back(A[i][j]);
            count+=1;
        }

        //cout<<"c4"<<count<<endl;
        if(count==total){
            break;
        }

        i1+=1;
        j1+=1;
        m=m-1;
        n=n-1;
    }


	return result;
}
