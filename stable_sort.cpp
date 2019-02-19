#include<stdio.h>
#define maxn 1000005
int a[maxn],temp[maxn];
void merge(int l,int r,int m){
    int i = l, j = m + 1,k = l;
    while(i<=m&&j<=r){
        if(a[i] > a[j]){
            temp[k++] = a[j++];
        }else{
            temp[k++] = a[i++];
        }
    }
    while(i<=m)
        temp[k++] = a[i++];
    while(j<=r)
        temp[k++] = a[j++];
    for(i = l;i<=r;i++)
        a[i] = temp[i];
}
void mergesort(int l,int r){
    if(l<r){
        int m = (l + r) / 2;
        mergesort(l,m);
        mergesort(m+1,r);
        merge(l,r,m);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        mergesort(0,n-1);
    }
    return 0;
}
