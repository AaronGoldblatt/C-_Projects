#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

typedef wchar_t box[5][7];
void NC(int[],int, int, box, box, box);
void NR(int[], int, int, box, box, box);
void backtrack(int[], int, box, box, box);
void print(int[],int, int, box, box, box);

bool tests(int q[], int c){
  for(int i=0;i<c;i++){
    if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
  }
  return true;
}

void backtrack(int q[], int c, box board, box wq, box bq){
    c--;
    if(c==-1) exit(0);
    int next=q[c]+1;
    NR(q, c, next, board, wq, bq);
}

void print(int q[], int c, box board, box wq, box bq){
  static int counter=0;
  for(int x=0;x<8;x++){
    if((x+q[x])%2==0) board[q[x]][x]=&wq;
    else board[q[x]][x]=&bq;
  }
  cout<<"Solution #"<<++counter<<endl;
  cout<<" ";
  for(int i=0;i<7*8;i++)
    cout<<'_'; cout<<endl;
// now print the board for(i=0;i<8;i++)
  for(int k=0;k<5;k++){
    cout<<" "<<char(179); //print left border
    for(int j=0;j<8;j++)
      for(int l=0;l<7;l++)
        wcout<<wchar_t((*board[i][j])[k][l]);
      cout<<char(179)<<endl; // at end of line print bar and then newline
  }
//before exiting print lower border cout<<" ";
  for(int i=0;i<7*8;i++) cout<<char(196);
  cout<<endl;
  //reset the pointer array
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++){
      if((i+j)%2==0) board[i][j]=&wb;
      else board[i][j]=&bb;
    }
  backtrack(q, c, board, wq, bq);
}

void NC(int q[], int c, box board, box wq, box bq){
  c++;
  if(c==8) print(q, c, board, wq, bq);
  q[c]=0;
  NR(q, c, q[c], board, wq, bq);
}

void NR(int q[], int c, int r, box board, box wq, box bq){
  for(int i=r;i<8;i++){ //i++ was i+=1
    q[c]=i;
    if((tests(q, c))) NC(q, c, board, wq, bq);
  }
  backtrack(q, c, board, wq, bq);
}

int main(){
  int q[8],c=0;
  typedef wchar_t box[5][7];
  box bb,wb,wq,bq,*board[8][8];
  for(i=0;i<5;i++)
    for(j=0;j<7;j++){
      wb[i][j]=' ';
      bb[i][j]=wchar_t(219);
      bq[i][j]=' ';
      wq[i][j]=wchar_t(219);
    }
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++){
        if((i+j)%2==0) board[i][j]=&wb;
        else board[i][j]=&bb;
      }
  for(int x=1;x<=3;x++){
    for(int y=1;y<=5;y++){
      if(x==1 && y%2==1){
        bq[x][y]=wchar_t(219);
        wq[x][y]=' ';
      }
      if(x>1){
        bq[x][y]=wchar_t(219);
        wq[x][y]=' ';
      }
    }
  }
  q[0]=0;
  NC(q, c, board, wq, bq);
  return 0;
}
