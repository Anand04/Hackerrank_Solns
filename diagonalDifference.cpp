#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sum1=0,sum2=0,i,j;
    int n;
    cin>>n;
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(i=0,j=0;i<n,j<n;i++,j++)
        {
        sum1+=a[i][j];
    }
    for(i=0,j=n-1;i<n,j>=0;i++,j--)
        {
        sum2+=a[i][j];
    }
    if(sum1-sum2<0)
        cout<<(sum1-sum2)*-1;
    else
        cout<<(sum1-sum2);

    return 0;
}
