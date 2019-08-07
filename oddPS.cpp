#include <iostream>
using namespace std;

int main(){
  long i=1;
  while(true){
    long sq=i*i;
    if(((sq%2)!=0) && (((sq/10)%10)%2!=0)){
      cout << "The answer is " << sq << endl;
      return 0;
    }
    i++;
  }
  return 0;
}
