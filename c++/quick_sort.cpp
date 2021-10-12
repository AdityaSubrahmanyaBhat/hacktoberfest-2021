#include<iostream>
using namespace std;
//hello bhattaa hengidya
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
   {
      cout << array[i] << " ";
   }
   cout << endl;
}
int partition(int *a,int low,int high){
    int pivot,start,end;
    pivot=a[0];
    start=low;
    end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[low],a[end]);
    return end;
}
void quicksort(int *a,int start,int end)
{
    if(start<end)
    {
        int loc= partition(a,start,end);
        quicksort(a,start,loc-1);
        quicksort(a,loc+1,end);

    }
}
int main()
{
    int a[20],i,n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"The sorted array is"<<endl;
    quicksort(a,0,n-1);
    display(a,n);
    return 0;
}