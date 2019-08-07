#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void NC(int[],int, int);
void NR(int[], int, int);
void backtrack(int[], int);
void print(int[],int, int);

bool tests(int q[], int c){
  for(int i=0;i<c;i++){
    if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
  }
  return true;
}

void backtrack(int q[], int c){
    c--;
    if(c==-1) exit(0);
    int next=q[c]+1;
    NR(q, c, next);
}

void print(int q[], int c){
  static int counter=0;
  cout<<"Solution #"<<++counter<<endl;
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      if(q[j]==i) cout << 1;
      else cout<<0;
      cout << " ";
    }
    cout<<endl;
  }
  cout<<endl;
  backtrack(q, c);
}

void NC(int q[], int c){
  c++;
  if(c==8) print(q, c);
  q[c]=0;
  NR(q, c, q[c]);
}

void NR(int q[], int c, int r){
  for(int i=r;i<8;i++){ //i++ was i+=1
    q[c]=i;
    if((tests(q, c))) NC(q, c);
  }
  backtrack(q, c);
}

int main(){
  int q[8], c=0;
  q[0]=0;
  NC(q, c);
  return 0;
}
