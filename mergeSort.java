package com.company;

import java.util.Arrays;

public class mergeSort {

    public static void main(String[] args) {
        int[] arr = {3,2,1,4,5,7,6,9,8,11,10,14,12,13};
        int[] ans=sort(arr);
        System.out.println(Arrays.toString(ans));
    }
   static int[] sort(int[] arr)
   {
       if(arr.length==1)
       {
           return arr;
       }
       int[] left=sort(Arrays.copyOfRange(arr,0,arr.length/2));
       int[] right=sort(Arrays.copyOfRange(arr,arr.length/2,arr.length));

       return merge(left,right);
   }
   static int[] merge(int[] first,int[] second)
   {
       int[] mix=new int[first.length+second.length];
       int i=0,j=0,k=0;
       while(i<first.length && j<second.length)
       {
           if(first[i]<second[j])
           {
               mix[k]=first[i];
               i++;
           }
           else
           {
               mix[k]=second[j];
               j++;
           }
           k++;
       }
       while(i<first.length)
       {
           mix[k]=first[i];
           i++;
           k++;
       }
       while(j<second.length)
       {
           mix[k]=second[j];
           j++;
           k++;
       }
       return mix;
   }
}
