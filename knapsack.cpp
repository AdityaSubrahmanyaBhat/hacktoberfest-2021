#include<iostream>
using namespace std;

int n;
int W;

void sort(int *w,int *p) {
    for(int i=1; i<n; i++) {
        int temp_p = p[i];
        int temp_w = w[i];
        int j = i-1;
        while(j >= 0 && (p[j]/(float)w[j]) < (temp_p/(float)temp_w)) {
            p[j+1] = p[j];
            w[j+1] = w[j];
            j--;
        }
        p[j+1] = temp_p;
        w[j+1] = temp_w;
    }
}

void knapsack(int *w, int *p) {
    float *x = new float[n]();
    float prof = 0, cw = 0;
    for(int i=0; i<n; i++) {
        if(cw+w[i] <= W) {
            x[i] = 1;
            cw += x[i]*w[i];
            prof += x[i]*p[i];
        }
        else {
            x[i] = (W-cw)/(float)w[i];
            cw += x[i]*w[i];
            prof += x[i]*p[i];
            break;
        }
    }
    cout<<endl<<"The total profit = "<<prof<<endl;
    cout<<"The objects selected are "<<endl;
    for(int i=0; i<n; i++)
        cout<<"x"<<i+1<<": "<<x[i]<<endl;
}

int main() {
    cout<<"Enter the number of objects"<<endl;
    cin>>n;
    int *w = new int[n];
    int *p = new int[n];
    cout<<"Enter the maximum capacity of the bag"<<endl;
    cin>>W;
    cout<<"Enter the weights of "<<n<<" objects"<<endl;
    for(int i=0; i<n; i++)
        cin>>w[i];
    cout<<"Enter the profit for "<<n<<" objects"<<endl;
    for(int i=0; i<n; i++)
        cin>>p[i];

    sort(w,p);
    knapsack(w,p);
    cout<<endl;
    return 0;
}
