#include <iostream>
#include <vector>

using namespace std;
int main(){
 vector<int> t[3];
 int n, candidate,to, from, move=0;
 cout<<"Please enter a number of rings to move: ";
 cin>>n;
 cout<<endl;

 for(int i=n+1;i>=1;i--) t[0].push_back(i);
 t[1].push_back(n+1);
 t[2].push_back(n+1);

while( t[1].size()<n+1){
  static int counter=1;
 cout<<"Move number "<<++move<<": Transfer ring " <<candidate<<
 " from tower "<< char(from+65)<<" to tower "<<char(to+65)<<endl;

 t[to].push_back(t[from].back());
 t[from].pop_back();

 int A=0,B=1,C=2;
 if(n%2==1){
   if(counter%3==0){
     from=A;
     to=B;
   }
   if(counter%2==0){
     from=A;
     to=C;
   }
   else{
     from=B;
     to=C;
   }
 }
else{
  if(counter%3==0){
    from=A;
    to=C;
  }
  if(counter%2==0){
    from=A;
    to=B;
  }
  else{
    from=B;
    to=C;
  }
 }
 counter++;
 candidate=t[from].back();
}
return 0;
}
