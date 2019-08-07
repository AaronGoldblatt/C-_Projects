#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void NC(int[],int[][3], int[][3], int);
void NR(int[], int[][3], int[][3], int, int);
void backtrack(int[], int[][3], int[][3], int);
void print(int[], int[][3], int[][3], int);

bool tests(int q[], int mp[][3], int wp[][3], int c){
  for(int i=0;i<c;i++){
    if(q[c]==q[i]) return false;
    if(mp[i][q[c]]<mp[i][q[i]] && wp[q[c]][i]<wp[q[c]][c]) return false;
    if(mp[c][q[i]]<mp[c][q[c]] && wp[q[i]][c]<wp[q[i]][i]) return false;
  }
  return true;
}

void backtrack(int q[], int mp[][3], int wp[][3], int c){
    c--;
    if(c==-1) exit(0);
    int next=q[c]+1;
    NR(q, mp, wp, c, next);
}

void print(int q[], int mp[][3], int wp[][3], int c){
  static int counter=0;
  cout<<"Solution #"<<++counter<<endl;
  for (int i=0; i<3; i++) {
    cout<<q[i]<<" ";
  }
  cout<<endl;
  backtrack(q, mp, wp, c);
}

void NC(int q[], int mp[][3], int wp[][3], int c){
  c++;
  if(c==3) print(q, mp, wp, c);
  q[c]=0;
  NR(q, mp, wp, c, q[c]);
}

void NR(int q[], int mp[][3], int wp[][3], int c, int r){
  for(int i=r;i<3;i++){
    q[c]=i;
    if((tests(q, mp, wp, c))) NC(q, mp, wp, c);
  }
  backtrack(q, mp, wp, c);
}

int main(){
  int q[3], c=0, mp[3][3]={{0,2,1},{0,2,1},{1,2,0}},
    wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
  q[0]=0;
  NC(q, mp, wp, c);
  return 0;
}
