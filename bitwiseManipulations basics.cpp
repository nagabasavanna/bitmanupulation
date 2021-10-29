#include <iostream>
#include <string>
#include <algorithm>
 using namespace std;

int getBit(int n,int pos){//function to get bit at pos from right to left(indexing starts from 0)
  return ((n&(1<<pos))!=0);
}
int setBit(int n, int pos){//function to set bit(set it to 1) at pos from right to left
  return (n|(1<<pos));
}
int clearBit(int n, int pos){//function to clear bit(set it to 0) at pos from right to left
  int mask=~(1<<pos);
  return (mask & n);
}
int updateBit(int n,int pos, int value){
   n=clearBit(n,pos);
  return (n|(value<<pos));
}
int isPowerOf2(int n){
  if(n==0){
    return 0;
  }
  return !((n)&(n-1));
}
int noOfOnes(int n){
  int count=0;
  while(n!=0){
    n=n & n-1;
    count++;
  }
  return count;
}
void printSubsets(int arr[],int n){
  for(int i=0;i<(1<<n);i++){//1<<n => 2 to the power n
    for(int j=0;j<n;j++){
      if(i & 1<<j){
        cout<<arr[j]<<" ";
      }
    }cout<<endl;
  }
}
int unique(int arr[],int n){//unique no. where all other no. are repeated twice
  int zorsum=0;
  for(int i=0;i<n;i++){
    zorsum=arr[i]^zorsum;
  }
return zorsum;
}
int main(){
  //cout<<getBit(4,2)<<endl;//returns 1
  //cout<<setBit(4,1);//4 becomes 6
  //cout<<clearBit(6,1);
  //cout<<updateBit(7,1,0);
  //cout<<isPowerOf2(124);
  //cout<<noOfOnes(19);
  int arr[]={2,5,1,2,5,1,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  //printSubsets(arr,n);
  cout<<unique(arr,n);
return 0;
}