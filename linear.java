package com.company;

public class linearWithRecursion {
    public static void main(String[] args) {
        int[] arr={3,2,1,18,9};
        int target=18;
        System.out.println(findElement(arr,0,target));
        System.out.println(findElementRev(arr,arr.length-1,target));
    }
    static int findElement(int[] arr,int s,int target)
    {
        if(s==arr.length)
        {
            return -1;
        }
        else if(arr[s]==target)
        {
            return s;
        }
          return findElement(arr,s+1,target);
    }
    static int findElementRev(int[] arr,int s,int target)
    {
        if(s==-1)
        {
            return -1;
        }
        else if(arr[s]==target)
        {
            return s;
        }
        return findElement(arr,s-1,target);
    }