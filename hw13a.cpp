// 8 cross recursion

#include <iostream>
#include <cmath>
using namespace std;
bool ok(int * q, int i, int a[][8])
{
 for (int k=0; k <i; k++)
 for(int j=0;j<i;j++){
   if(q[i]==q[j]) return false;
 }
 int k=0;
 while (a[i][k]!=-1){
  if (abs(q[i]-q[a[i][k]])==1) return false;
  k++;
 }
 return true;
}

void print(int * q)
{ static int count =0;
 cout<<"Solution #"<<++count<<endl;

 for (int k=0; k<8; k++)
 cout<< q[k];cout<<endl;
}
void move(int* q, int i, int a[][8]) 
{
 if(i==8)
 {
 print(q);
 return;
 }

 for(int j=0;j<8;j++)
 { q[i]=j;
 if(ok(q,i,a))
 move(q,i+1,a);
 }

}

int main()
{
 int q[8], a[8][8]={{-1},{0,-1},{1,-1},{0,1,2,-1},
   {1,2,3,-1},{2,4,-1},{0,3,4,-1},{5,4,3,6,-1}};
 move(q,0,a);
}
