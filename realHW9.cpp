#include <iostream>
#include<cmath>
using namespace std;

bool tests(int q[],int c){
  for(int i=0;i<c; i++)
  if(q[c]==q[i]|| (c-i)==abs(q[i]-q[c])) return false;
  return true;
}

int solutions(int n){
  int* q = new int[n];
  int c=0;
  q[0]=0;
  int counter=0;
  while (c>=0){
    c++;
    if(c==n){
      counter++;
      c--;
      if(c==-1) break;
    }
    else{
      q[c]=-1;
    }
    while(c>=0){
      q[c]++;
      if(q[c]==n){
        c--;
      }
      else if(tests(q,c)) break;
    }
  }
  return counter;
}

int main(){
  int n;
  cout<<"What range of Queens problem solutions would you like?\nEnter an integer: ";
  cin>>n;
  for(int i=1;i<=n;i++){
    cout<< "There are "<< solutions(i)<< " answers to the "<< i << " queen problem"<<endl;
  }
  return 0;
}
