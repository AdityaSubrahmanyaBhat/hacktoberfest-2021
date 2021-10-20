package com.company;

import java.util.Arrays;

public class bubbleSortRecursion {
    public static void main(String[] args) {
        int[] arr={7,8,1,4,2,3,5,6,9};
        bubble(arr,0,arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    static void bubble(int[] arr,int s,int e)
    {
        if(e==0)
        {
            return;
        }
        else if(s<e)
        {
            if(arr[s]>arr[s+1])
            {
                swap(arr,s,s+1);
            }
            bubble(arr,s+1,e);
        }
        if(s==e)
        {
            bubble(arr,0,e-1);
        }
    }
    static void swap(int[] arr,int n1,int n2)
    {
        int t=arr[n1];
        arr[n1]=arr[n2];
        arr[n2]=t;
    }
}
