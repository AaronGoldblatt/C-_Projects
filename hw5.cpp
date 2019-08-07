#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void NC(int[],int[][8],int);
void NR(int[], int[][8], int, int);
void backtrack(int[], int[][8], int);
void print(int[], int[][8], int);

bool tests(int q[], int a[][8], int c){
  for(int i=0;i<c;i++){
    if(q[c]==q[i]) return false;
  }
  int k=0;
  while (a[c][k]!=-1){
   if (abs(q[c]-q[a[c][k]])==1) return false;
   k++;
  }
  return true;
}

void backtrack(int q[], int a[][8], int c){
    c--;
    if(c==-1) exit(0);
    int next=q[c]+1;
    NR(q, a, c, next);
}

void print(int q[], int a[][8], int c){
  static int counter=0;
  cout<<"Solution #"<<++counter<<endl;
  for (int i=0; i<8; i++) {
    cout<<q[i]<<" ";
  }
  cout<<endl;
  backtrack(q, a, c);
}

void NC(int q[], int a[][8], int c){
  c++;
  if(c==8) print(q, a, c);
  q[c]=0;
  NR(q, a, c, q[c]);
}

void NR(int q[], int a[][8], int c, int r){
  for(int i=r;i<8;i++){ //i++ was i+=1
    q[c]=i;
    if((tests(q, a, c))) NC(q, a, c);
  }
  backtrack(q, a, c);
}

int main(){
  int q[8], c=0, a[8][8]={{-1},{0,-1},{1,-1},{0,1,2,-1},
    {1,2,3,-1},{2,4,-1},{0,3,4,-1},{5,4,3,6,-1}};
  q[0]=1;
  NC(q, a, c);
  return 0;
}
