#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n){
  int countMatch=0;
  int shift=0;
  for(int i=0;i<n;i++){
    if(a[0]==b[i]){
      shift=i;
      for(int j=0;j<n;j++){
        if(a[j]==b[(j+shift)%n]) countMatch++;
        if(countMatch==n) return true;
      }
      countMatch=0;
    }
  }
  return false;
}

int main(){
  int a[5]={1,2,3,4,5};
  int b[5]={3,4,5,1,2};
  if (equivalent(a, b, 5)) cout << "True\n";
  else cout << "False\n";
  return 0;
}
