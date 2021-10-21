package com.company;

public class Main {

    public static void main(String[] args) {
        int n=5;
        printPattern(n);
    }
    static void printPattern(int n)
    {
        if(n==0)
        {
            return;
        }
        printRow(n);
        System.out.println();
        printPattern(n-1);
    }
    static void printRow(int n2)
    {
        if(n2==0)
        {
            return;
        }
        System.out.print("* ");
        printRow(n2-1);
    }
}
