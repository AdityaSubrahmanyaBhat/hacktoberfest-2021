#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int get_Max_value(int arr[], int n) {  
  int max=arr[0];  
  for (int i=1;i<n;i++)  
    if (arr[i]>max)  
      max=arr[i];  
  return max;  
}  

void bucket(int arr[], int n) {  
  int max = get_Max_value(arr,n);   
  int b[max];  
  for (int i=0;i<=max;i++)  {  
    b[i]=0;  
  }  
  for (int i=0;i<n;i++)  {  
    b[arr[i]]++;  
  } 

  for (int i=0,j=0;i<=max;i++)  {  
    while (b[i] > 0)  {  
      arr[j++] = i;  
      b[i]--;  
    }  
  }  
}  

void print_arr(int arr[], int n) {  
  for (int i=0;i<n;++i)  
    printf("%d ",arr[i]);  
}  

int main() {    
  int n;
  //cout<<"Enter the value of n: ";
  cin>>n;  
  int arr[n+1];
  cout<<"Enter the elements of the array: ";
  for(int i=0;i<n;i++) {
      cin>>arr[i];
  } 
  cout<<"\nThe elements before sorting --- "<<endl;
  print_arr(arr,n);  
  bucket(arr,n);  
  cout<<"\nThe elements after sorting ---"<<endl;  
  print_arr(arr, n);  
}  