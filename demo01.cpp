#include <bits/stdc++.h>

void quick_sort(int * arr,int start,int end){
    if(end-start<2){return;}
    int p=arr[start];
    int left=start+1,right=end;
    while(left<right){
        do{
            left++;
        }
        while(left<end&&arr[left]<p);


        while(arr[right]>p){
            right--;
        }
    }
    quick_sort(left+1,end);
}