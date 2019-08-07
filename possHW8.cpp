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
  cout<<endl;
  cout<<"Solution #"<<++counter<<endl;
  int i,j,k,l;
 typedef char box[5][7];
 box bb,wb,wq,bq,*board[8][8];
 //fill in bb=black box and wb=whitebox
 for(i=0;i<5;i++)
 for( j=0;j<7;j++)
 {wb[i][j]=' ';
 bb[i][j]=char(219);
 bq[i][j]=' ';
 wq[i][j]=char(219);
 }
 for(int x=1;x<=3;x++){
   for(int y=1;y<=5;y++){
     if(x==1 && y%2==1){
       bq[x][y]=char(219);
       wq[x][y]=' ';
     }
     if(x>1){
       bq[x][y]=char(219);
       wq[x][y]=' ';
     }
   }
 }
 //fill board with pointers to bb and wb in alternate positions
 for(i=0;i<8;i++)
 for(j=0;j<8;j++)
 if((i+j)%2==0)
 board[i][j]=&wb;
 else
 board[i][j]=&bb;
 for(int x=0;x<8;x++){
   if((x+q[x])%2==0) board[q[x]][x]=&wq;
   else board[q[x]][x]=&bq;
 }
 // print the board via the pointers in array board
 // first print upper border
 cout<<" ";
 for(i=0;i<7*8;i++)
 cout<<'_';
 cout<<endl;
 // now print the board
 for(i=0;i<8;i++)
 for(k=0;k<5;k++)
 {cout<<" "<<char(179); //print left border
 for(j=0;j<8;j++)
 for(l=0;l<7;l++)
 cout<<(*board[i][j])[k][l];
 cout<<char(179)<<endl; // at end of line print bar and then newline
 }
 //before exiting print lower border
 cout<<" ";
 for(i=0;i<7*8;i++)
 cout<<char(196);
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
