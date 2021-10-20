package com.company;

import java.util.Arrays;

public class selectionSort {
    public static void main(String[] args) {
        int[] arr={4,2,1,3,7,5,6,9,8,10,13,12,11,15,16,14};
        selection(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void selection(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            int j=arr.length-i-1;
            int max=maxi(arr,0,j);
            swap(arr,max,j);
        }

    }
    static int maxi(int[] arr,int s,int e)
    {
        int max=0;
        for(int i=s;i<=e;i++)
        {
            if(arr[i]>arr[max])
            {
                max=i;
            }
        }
        return max;
    }
   static void swap(int[] arr,int f1,int f2)
   {
       int t=arr[f1];
       arr[f1]=arr[f2];
       arr[f2]=t;
   }
}
