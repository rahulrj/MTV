void Solution::setZeroes(vector<vector<int> > &A) {
	int col=-1;
	int row=-1;

	int rownum=A.size();
	int colnum=A[0].size();

	for(int i=0;i<rownum;i++){
	    for(int j=0;j<colnum;j++){

	        if(A[i][j]==0){

	            if(i==0){
	                row=0;
	            }
	            else{
	               A[i][0]=2;
	            }

	            if(j==0){
	                col=0;
	            }
	            else{
	               A[0][j]=2;
	            }

	        }
	    }
	}


	for(int i=1;i<rownum;i++){
	    for(int j=1;j<colnum;j++){

	        if(A[i][0]==2 || A[0][j]==2){
	            A[i][j]=0;
	        }
	    }
	}

	for(int i=0;i<colnum;i++){
	    if(A[0][i]==2){
	        A[0][i]=0;
	    }

	    if(row==0){
	        A[0][i]=0;
	    }
	}

		for(int i=0;i<rownum;i++){
	    if(A[i][0]==2){
	        A[i][0]=0;
	    }

	    if(col==0){
	        A[i][0]=0;
	    }
	}





}
