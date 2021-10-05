#include <bits/stdc++.h>
#include<vector>
using namespace std;

void cycle_sort(int arr[], int n){
    int element,small;  
    for(int i=0; i<=n-2; i++){  
        element=arr[i];  
        small=i;  
        for(int j=i+1; j<n; j++){  
            if(arr[j]<element) {  
                small++;
            }
        }  
        if(small==i){  
            continue; 
        } 
        while(element==arr[small]){ 
            small++; 
        } 
        if(small!=i) {     
            swap(arr[small],element);     
        }  
        while (small!=i) {  
            small=i;  
            for(int j=i+1; j<n; j++) { 
                if(arr[j]<element){  
                    small+=1;
                }
            }  
            while(element==arr[small]) {  
                small+=1;
            }  
            if(element!=arr[small]) {   
                swap(arr[small],element);       
            }  
        }  
    } 
}

int main() {
    int n;
    //cout<<"Enter the size of n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"\nArray before being sorted: \n";
    for(auto i:arr){
        cout<<i<<" ";
    }
    cycle_sort(arr,n);
    cout<<"\nArray after being sorted: \n";
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}