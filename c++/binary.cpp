#include <iostream>
using namespace std;

int arr[10], c = 0;

void read(int n)
{
    cout << "Enter the " << n << " elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int binarySearch(int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        c++;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(low, mid - 1, key);
        }
        else
        {
            return binarySearch(mid + 1, high, key);
        }
    }
    return INT8_MIN;
}

int main()
{
    int n, key;
    cout<<"Enter the number of elements : "<<endl;
    cin >> n;
    read(n);
    cout << "Enter the element to be searched : " << endl;
    cin >> key;
    int res = binarySearch(0,n-1,key);
    if (res == INT8_MIN)
    {
        cout << "Element not found" << endl
             << "Time complexity is O(" << c << ") and it is the worst case" << endl;
    }
    else if (res == (n-1)/2)
    {
        cout << "Element " << key << " found at index " << res << endl
             << "Time complexity is O(" << c << ") and it is the best case" << endl;
    }
    else
    {
        cout << "Element " << key << " found at index " << res << endl
             << "Time complexity is O(" << c << ") and it is the average case" << endl;
    }
    return 0;
}