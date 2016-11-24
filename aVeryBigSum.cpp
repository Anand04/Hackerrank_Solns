#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    long long int sum;
    long long int array[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>array[i];

    }
    for(int i=0;i<n;i++){
    sum+=array[i];
    }
    cout<<sum;
    return 0;
}
