#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void NC(int[],int, int, int, int);
void NR(int[], int, int, int, int);
void backtrack(int[], int, int, int, int);
void print(int[],int, int, int, int);
int solutions(int, int);

bool tests(int q[], int c){
  for(int i=0;i<c;i++){
    if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
  }
  return true;
}

int backtrack(int q[], int c, int n, int counter){
    c--;
    if(c==-1) return solutions(n, counter);//need to get to returning value of counter to program
    int next=q[c]+1;
    NR(q, c, next, n, counter);
}

void print(int q[], int c, int n, int counter){
  counter++;
  //c--;
  //if(c==-1)
  backtrack(q, c, n, counter);
}

void NC(int q[], int c, int n, int counter){
  c++;
  if(c==n) print(q, c, n, counter);
  q[c]=0;
  NR(q, c, q[c], n, counter);
}

void NR(int q[], int c, int r, int n, int counter){
  for(int i=r;i<n;i++){ //i++ was i+=1
    q[c]=i;
    if((tests(q, c))) NC(q, c, n, counter);
  }
  backtrack(q, c, n, counter);
}

int solutions(int n, int counter){
  int* q=new int[n], c=0;
  if(c==-1){
    delete []q;
    return counter;
  }
  q[0]=0;
  NC(q, c, n, counter);
}

int counter=0;
int main(){
  int n;
  cout<< "What range of Queens problem solutions would you like?\nEnter an integer: ";
  cin>>n;
  for(int i=n;i<=n;i++){
    counter=0;
    cout<<"For the "<<n<<" Queens problem there are "<<solutions(i, counter) << " solutions."<<endl;
  }
  return 0;
}
