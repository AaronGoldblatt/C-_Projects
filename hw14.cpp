#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int min(int x, int y, int z){
  if(x<y && x<z) return x;
  if(y<x && y<z) return y;
  else return z;
}

int cost(int i, int j){ // i is the row, j is the column
 int weight[rows][cols]={
 {3,4,1,2,8,6},
 {6,1,8,2,7,4},
 {5,9,3,9,9,5},
 {8,4,1,3,2,6},
 {3,7,2,8,6,4}};
 static int memo[rows][cols]={0};
 //base case
 if(j==0)
 return weight[i][0];

 if(memo[i][j]!=0) return memo[i][j];
 int s;
 int left=cost(i,j-1);
 int up;
 if (i==0) {
   up=cost(rows-1,j-1);
 }
 else up=cost(i-1,j-1);
 int down;
 if (i==rows-1) {
   down=cost(0,j-1);
 }
 else down=cost(i+1,j-1);

 s=min(left,up,down)+weight[i][j];
 memo[i][j]=s;
 return s;
 }

int main(){
 int ex[rows];

 // get the shortest path out of each cell on the right
 for(int i=0; i<rows; i++)
 ex[i]=cost(i,cols-1);

 // now find the smallest of them
 int min=ex[0];
 for(int k=1;k<rows;k++){
   if(ex[k]<min) min=ex[k];
 }

 cout<<"The shortest path is of length "<<min<<"."<<endl;
 cout<<"The path used is ";
 for (int i=0; i<rows; i++) cout<<ex[i]<<" ";
 cout<<endl;
 return 0;
}
