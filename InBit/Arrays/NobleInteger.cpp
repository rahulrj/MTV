// https://www.interviewbit.com/problems/noble-integer/#

int Solution::solve(vector<int> &A) {

  std::sort (A.begin(), A.end());
        int size=A.size();





    // for(int i=0;i<size;i++){
    //     cout<<A[i]<<" ";
    // }

    //     cout<<endl;


    for(int i=0;i<size;i++){

            if(A[i]>=0){

            vector<int>::reverse_iterator it=find(A.rbegin(), A.rend()-i, A[i]);
            int lastPos=it.base() - A.begin();
            //cout<<A[i]<<" "<<size<<" "<<i<<endl;

             int p=size-lastPos;
             //cout<<size<<" "<<A[i]<<" "<<lastPos<<" "<<p<<endl;

            if(A[i]==p){
                return 1;
            }
        }
    }

    return -1;

}
