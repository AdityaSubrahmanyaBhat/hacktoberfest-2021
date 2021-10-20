package com.company;

import java.util.Arrays;

public class inPlaceMergeSort {
    public static void main(String[] args) {
        int[] arr={4,2,1,3,7,5,6,9,8,10,13,12,11,15,16,14};
        sort(arr,0,arr.length);
        System.out.println(Arrays.toString(arr));
    }
static void sort(int[] arr,int s,int e)
{
    if(e-s==1)
    {
        return;
    }
    int m=s+(e-s)/2;
    sort(arr,s,m);
    sort(arr,m,e);
    merge(arr,s,m,e);
}
static void merge(int[] arr,int s,int m,int e)
{
    int[] mix=new int[e-s];
    int i=s,j=m,k=0;
    while(i<m && j<e)
    {
        if(arr[i]<arr[j])
        {
            mix[k]=arr[i];
            i++;
        }
        else
        {
            mix[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<m)
    {
        mix[k]=arr[i];
        i++;
        k++;
    }
    while(j<e)
    {
        mix[k]=arr[j];
        j++;
        k++;
    }
    for(int l=0;l<mix.length;l++)
    {
        arr[s+l]=mix[l];
    }
}
}

