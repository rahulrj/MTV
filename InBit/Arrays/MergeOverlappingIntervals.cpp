//https://www.interviewbit.com/problems/merge-overlapping-intervals/#

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 void swap(Interval i){
     int temp=i.end;
     i.end=i.start;
     i.start=temp;
 }

 bool compareVec(Interval a, Interval b)
{
    return a.start <b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {

   int n=A.size();
   vector<Interval>res;
   for(int i=0;i<n;i++){
       Interval iv=A[i];
       if(iv.start>iv.end){
           swap(iv);
       }
   }

   sort(A.begin(),A.end(),compareVec);

//   for(int i=0;i<n;i++){
//       cout<<A[i].start<<" "<<A[i].end<<endl;
//   }

   Interval resInt;
   resInt.start=A[0].start;
   resInt.end=A[0].end;

   if(n==1){
       res.push_back(resInt);
       return res;
   }

   //cout<<resInt.start<<" "<<resInt.end<<endl;

   for(int i=0;i<n-1;i++){

       Interval v1=A[i];
       Interval v2=A[i+1];


       if(v2.start<=resInt.end){
           if(v2.end>resInt.end){
               resInt.end=v2.end;
           }

           if(i+1==n-1){
               if(v2.end>resInt.end){
                    resInt.end=v2.end;
               }
               res.push_back(resInt);
           }
           continue;
       }

       if(v2.start>v1.end){
           //resInt.end=A[i].end;
           res.push_back(resInt);

           resInt.start=v2.start;
           resInt.end=v2.end;
           if(i+1==n-1){
               if(v2.end>resInt.end){
                    resInt.end=v2.end;
               }
               res.push_back(resInt);
           }
       }
   }

   return res;


}
