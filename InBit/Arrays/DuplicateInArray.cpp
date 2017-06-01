int Solution::repeatedNumber(const vector<int> &A) {

    const int n=A.size();
    const int aSize=n/2;
    std::vector<int> arr(n/2);
    //int *arr=new int[n/2];
    //std::fill(arr, arr+(n/2), 0);

    for(int i=0;i<n;i++){
        int num=A[i];
        int originalNum=num;
        if(num>n/2){
            num=num-n/2;
        }


        int index=num-1;
        if(arr[index]==0){
            arr[index]=originalNum;
        }
        else{

            if(arr[index]==originalNum){
                //cout<<"H1"<<originalNum<<" "<<arr[index];
                return originalNum;
            }
            else if(arr[index]<0){
                //cout<<"H2"<<originalNum<<" "<<arr[index];
                return originalNum;
            }
            else{
                arr[index]=-1;
            }

        }
    }

    return -1;
}
