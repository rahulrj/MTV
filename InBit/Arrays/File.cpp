//https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {

    int n=A.size();
    int size=1;
    int *arr=new int[n];


    int max=0;
    int L=-1,R=-1;
    vector<int>res;


    if(A[0]=='1'){
        arr[0]=1;
    }
    else{
        arr[0]=0;
    }

    for(int i=1;i<n;i++){
        size+=1;
        if(A[i]=='1'){
            arr[i]=arr[i-1]+1;
        }
        else{
            arr[i]=arr[i-1];
        }
    }


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ones=0;
            int flipones=0;
            int totalOnes=0;



            if(i==j){
               // ones=arr[i];
                if(A[i]=='0'){
                    flipones=1;
                }
                else{
                    ones=1;
                }
            }

            else if(i==0){
                ones=arr[j];
            }

            else {
                ones=arr[j]-arr[i-1];
            }

            if(i!=j){
                flipones=(j-i+1)-(ones);
            }
            totalOnes=arr[n-1]-(ones)+flipones;

          // cout<<"tot"<<" "<<totalOnes<<" "<<arr[n-1]<<" "<<ones<<" "<<flipones<<" "<<i<<" "<<j<<endl;


            if(totalOnes>arr[n-1]){

                if(totalOnes>max){
                max=totalOnes;
                L=i;
                R=j;
            }

            else if(totalOnes==max){
                if(i<L || (i>L && j<R)){
                    L=i;
                    R=j;
                }
            }
            }

        }
    }

    if(L>-1){
        res.push_back(L+1);
        res.push_back(R+1);
    }

    return res;




}
