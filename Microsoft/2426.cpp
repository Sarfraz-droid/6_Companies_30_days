#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long count;
    int d;
    void countValues(vector<int>& arr,int start,int mid,int end) {
        int l = start;
        int r = mid+1;

        while(l <= mid && r <= end) {
            if(arr[l] <= (arr[r] + d)) {
                count += (end-r+1);
                l++;
            }else{
                r++;
            }
        }

        sort(arr.begin()+start,arr.begin()+end+1);

    }

    void mergeSort(vector<int>& arr, int start,int end){
        if(start >= end)
            return;
        
        int mid = (end+start)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        countValues(arr,start,mid,end);
    }

    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();
        vector<int> c(n);
        count = 0;

        for(int i = 0;i<n;i++){
            c[i] = a[i] - b[i];
        }
        d= diff;

        mergeSort(c,0,n-1);

        return count;
    }   
};