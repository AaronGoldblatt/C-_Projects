// stable marriages

#include <iostream>
#include <cmath>
using namespace std;
bool ok(int * q, int i, int mp[][3], int wp[][3])
{
  for(int j=0;j<i;j++){
    if(q[i]==q[j]) return false;
    if(mp[j][q[i]]<mp[j][q[j]] && wp[q[i]][j]<wp[q[i]][i]) return false;
    if(mp[i][q[j]]<mp[i][q[i]] && wp[q[j]][i]<wp[q[j]][j]) return false;
  }
  return true;
}

void print(int * q)
{ static int count =0;
 cout<<"Solution #"<<++count<<endl;

 for (int k=0; k<3; k++)
 cout<< q[k];cout<<endl;
}
void move(int* q, int i, int mp[][3], int wp[][3])
{
 if(i==3)
 {
 print(q);
 return;
 }

 for(int j=0;j<3;j++)
 { q[i]=j;
 if(ok(q,i,mp,wp))
 move(q,i+1,mp,wp);
 }
}

int main()
{
 int q[8], mp[3][3]={{0,2,1},{0,2,1},{1,2,0}},
   wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};
 move(q,0,mp,wp);
}
