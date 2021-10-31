## Rabin Karp Algorithm
---
* Rabin karp algorithm is a pattern searching algorithm.

### Logic
---
* In this algo we check for every window of length M(pattern length) and slide the M length window on given text.
* we first calculate hash value of pattern and hash value of M - length text.

* for getting Hash value , we create a hash Function which gives us hash value for a given string.
* Now one by one we slide the pattern on text and 
   * if (Hahs_value_pattern == Hash_value_textWindow) , then we check every character of pattern and cuurent text and if they all match we retuen `True`.
   
   * if(patterns not match then compute Hash value for Hash_value_text[i+1] using Hash_value_text[i]).

* after loop termination we are sure that pattern is not present in the given text. So return `False`.

### Example
---
> Input
* Lets Given text be ...
  
* text = "ABCCDDAEFG"
  
   ![text](https://cdn.programiz.com/sites/tutorial2program/files/rc-text.png "text")
* pattern ="CDD"
* 
   ![Pattern](https://cdn.programiz.com/sites/tutorial2program/files/rc-pattern.png "Pattern")
  

> Output
* Pattern is present in the text.


> Implementation

C++
#include <bits/stdc++.h>
using namespace std;
#define d 256
const int m = 201;

int hashFun(string s, int n)
{
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val = (val * d + s[i]) % m;
    }
    return val;
}

bool Rk_Search(string text, string pat)
{
    int N = text.length(), M = pat.length();
    // calculating (d^(M-1)) % m
    int h = 1;
    for (int i = 0; i < M; i++)
    {
        h = (h * d) % m;
    }

    int hash_pat = hashFun(pat, M);
    int hash_text = hashFun(text, M);

    for (int i = 0; i <= (N - M); i++)
    {
        if (hash_pat == hash_text)
        {
            bool flag = true;
            // checking every character when we face spurious hit
            for (int j = 0; j < M; j++)
            {
                if (text[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }

        //Compute hash_text(i+1) using hash_text(i)
        if (i < N - M)
        {
            hash_text = ((d * (hash_text - text[i] * h)) + text[i + M]) % m;

            // this corner case is for condition when hash_text become -ve.
            if (hash_text < 0)
                hash_text = hash_text + m;
        }
    }

    return false;
}

int main()
{
    string text, pat;

    cout << "Enter text : ";
    cin >> text;

    cout << "Eneter pattern to be searched : ";
    cin >> pat;

    if (Rk_Search(text, pat))
    {
        cout << "Pattern is present in the text." << endl;
    }
    else
    {
        cout << "Pattern is not present in the text." << endl;
    }
    return 0;
}


> Complexity Analysis

* *Time*
   * *Worst Case* : O((N-M+1)*M) , worst case of this algorithm occurs when we get spusrious hit.
   * *Best Case*  : O(M+N) and better than Brute force Solution.
 * *Space*
   * O(1) 

## Limitations of Rabin-Karp Algorithm
---
> Spurious Hit
* When the hash value of the pattern matches with the hash value of a window of the text but the window is not the actual pattern then it is called a spurious hit.

* Spurious hit increases the time complexity of the algorithm. In order to minimize spurious hit, we use modulus. It greatly reduces the spurious hit.

## Uses Of Rabin-Karp Algorithm 
---
* For pattern searching.
* For searching string in a large text.
