#include<iostream>
#include<vector>
using namespace std;
int c=0;
int inversion(vector<int>& a , vector<int>& b){
    int count=0;
    int i=0;
    int j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count+=a.size()-i;
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}
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
    c+=inversion(a,b);
    merge(a,b,v);
    a.clear();
    b.clear();
}
int main(){
    int arr[]={5,1,3,0,4,2,6};
    int n1=sizeof(arr)/sizeof(arr[0]);
    vector <int> v(arr,arr+n1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergesort(v);
    cout<<c;
}