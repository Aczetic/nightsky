#include<iostream>
using namespace std;

void merge(int arr[], int l, int m , int r){
    int n1 = m-l+1;
    int n2 = r-m;
    
    int a[n1] , b[n2];
    int i , j , k = 0;
    for( i = 0 ; i < n1; i++){
        a[i] = arr[l + i];
    }
    
    for(j = 0 ; j < n2;j++){
        b[j] = arr[m + j + 1];
    }
    
    i = j = k =0;
    
    while( i < n1 && j < n2){
        
        if( a[i] <= b[j]){
            arr[k++] = a[i++];
        }else{
            arr[k++] = b[j++];
        }   
    }
    
    while( i < n1){
        arr[k++] = a[i++];
    }
    
    while( j < n2){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[] , int l, int r){
    
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr,l, m);
        mergeSort(arr,l,m+1);
        merge(arr,l,m,r);
        cout << l << ' ' << r << endl;
    }
}


int main(){
    
 int arr[5];
 for(int &i: arr){
     cin>> i;
 }
 
 mergeSort(arr, 0 , 4);
    
    for(int i : arr){
        cout << i << ' ';
    }
    
    return 0;
}