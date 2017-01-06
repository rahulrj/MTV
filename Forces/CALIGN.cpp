// Example program
#include <iostream>
#include <string>
#include <string>


using namespace std;

int main()
{
   int n=0;
   string strings[1000];
   int lengths[1000];
   int maxlen=0;

   while(std::getline(std::cin, strings[n])){
       lengths[n]=strings[n].length();
       maxlen=lengths[n]>maxlen?lengths[n]:maxlen;
       n+=1;
   }
   maxlen+=2;

   for(int i=0;i<maxlen;i++)
   cout<<"*";
   cout<<endl;

   for(int i=0;i<n;i++){
      cout<<"*";
      int difflen=maxlen-lengths[i]-2;
      int diff2=difflen-difflen/2;
      if(difflen>0){
          for(int j=0;j<difflen/2;j++){
              cout<<" ";
          }
      }
      cout<<strings[i];
      if(diff2>0){
          for(int j=0;j<diff2;j++){
              cout<<" ";
          }
      }


      cout<<"*";

      cout<<endl;

   }

   for(int i=0;i<maxlen;i++)
   cout<<"*";
   cout<<endl;


//   for(int i=0;i<n;i++){
//       cout<<strings[i]<<" "<<lengths[i]<<endl;
//   }






}
