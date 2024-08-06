#include<iostream>
#include<vector>
using namespace std;
void merge(vector <int>& v1,vector <int>& v2,vector <int>& v){
    int n1=v1.size(),n2=v2.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(v1[i]<v2[j]){
            v[k++]=v1[i++];
        }
        else{
            v[k++]=v2[j++];
        }
    }
    if(i==n1){
        while(j<n2){
            v[k++]=v2[j++];
        }
    }
    if(j==n2){
        while(i<n1){
            v[k++]=v1[i++];
        }
    }
}
void mergesort(vector <int>& v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-n/2;
    vector <int> a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[n1+i];
    }
    mergesort(a);
    mergesort(b);
    merge(a,b,v);
    a.clear();
    b.clear();
}
int main(){
    int arr[]={1,4,5,8,56,3};
    int n1=sizeof(arr)/sizeof(arr[0]);
    vector <int> v(arr,arr+n1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}