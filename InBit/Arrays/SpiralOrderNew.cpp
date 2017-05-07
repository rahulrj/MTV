// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>generateMatrix(int n){

    cout<<"Hey"<<endl;
    vector<vector<int>>matrix(n, vector<int> (n, 0));
    int i=0,j=0,k=1;
    int dir=0;

             //cout<<k<<" "<<(n*n)<<endl;



    while(k<=(n*n)){

        matrix[i][j]=k;


        if(dir==0){
            j+=1;
            if(j==n || matrix[i][j]!=0){
                dir=1;
                j-=1;
                i+=1;
            }
        }

        else if(dir==1){
            i+=1;
            if(i==n || matrix[i][j]!=0){
                dir=2;
                i-=1;
                j-=1;
            }

        }

        else if(dir==2){

            j-=1;
            if(j<0 || matrix[i][j]!=0){
                dir=3;
                j+=1;
                i-=1;
            }
        }

        else if(dir==3){
            i-=1;
            if(i<0 || matrix[i][j]!=0){
                dir=0;
                i+=1;
                j+=1;
            }
        }


        k+=1;

    }



    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    return matrix;
}

int main() {
	//code
	generateMatrix(4);


	return 0;
}
