package com.company;

import java.util.Arrays;

public class selectionRecursion {
    public static void main(String[] args) {
        int[] arr={3,1,2,5,4,6};
        selection(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    static void selection(int[] arr,int s,int e)
    {
        if(e==0)
        {
            return;
        }
        int index=findMaxIndex(arr,s,e);
        swap(arr,index,e);
        selection(arr,s,e-1);
    }
    static int findMaxIndex(int[] arr,int s,int e)
    {
        int max=0;
        for(int i=s;i<=e;i++)
        {
            if(arr[max]<arr[i])
            {
                max=i;
            }
        }
        return max;
    }
    static void swap(int[] arr,int n1,int n2)
    {
        int t=arr[n1];
        arr[n1]=arr[n2];
        arr[n2]=t;
    }
}