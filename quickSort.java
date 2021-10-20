package com.company;

import java.util.Arrays;

public class quickSort {
    public static void main(String[] args) {
        int[] arr={3,2,1,4,5,7,12,15,13,14,6,9,8,11,10};
        sort(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    static void sort(int[] arr,int low,int hi)
    {
        if(low>=hi)
        {
            return;
        }
        int s=low,e=hi;
        int m=s+(e-s)/2;
        int pivot=arr[m];
        while(s<=e)
        {
            while(arr[s]<pivot)
            {
                s++;
            }
            while(arr[e]>pivot)
            {
                e--;
            }
            if(s<=e)
            {
                swap(arr,s,e);
                s++;
                e--;
            }
            sort(arr,low,e);
            sort(arr,s,hi);
        }
    }
    static void swap(int[] arr,int f1,int f2)
    {
        int t=arr[f1];
        arr[f1]=arr[f2];
        arr[f2]=t;
    }
}
