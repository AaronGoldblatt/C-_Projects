#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool tests(int q[], int c){
  for(int i=0;i<c;i++){
    if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])) return false;
  }
  return true;
}

void backtrack(int &c, bool &isBackTrack){
    c--;
    if(c==-1) exit(0);
    isBackTrack=true;
}

void print(int q[], int c, int &counter){
  counter++;
  cout << "Solution #" << counter << endl;
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      if(q[j]==i) cout << 1;
      else cout<<0;
      cout << " ";
    }
    cout<<endl;
  }
}

int main(){
  int q[8], c=0, counter=0;
  bool isBackTrack=false;
  q[0]=0;
  while(true){
    if(isBackTrack==false){
      c++;
      q[c]=-1;
    }
    while(q[c]<8){
      q[c]++;
      if (tests(q, c)){
        isBackTrack=false;
        break;
      }
    }
    if(q[c]==8) backtrack(c, isBackTrack);
    if(c==8){
      print(q, c, counter);
      backtrack(c, isBackTrack);
    }
  }
}
