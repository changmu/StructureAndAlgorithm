#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 300
struct Node{
    double x;double y1;double y2;
    int flag;
}node[N];
bool cmp(Node a,Node b){
    return a.x-b.x<0.0000001;
}
double y[N];
struct node{
    int l;int r;double ml;double mr;int s;double len;
}a[N*3];
void build(int i,int left,int right){
    a[i].l=left;
    a[i].r=right;
    a[i].ml=y[left];
    a[i].mr=y[right];
    a[i].s=0;
    a[i].len=0;
    if(a[i].l+1==a[i].r){
        return ;
    }
    int mid=(left+right)>>1;
    build(i*2,left,mid);
    build(i*2+1,mid,right);//建树时注意这里不是mid+1，因为做相减的时候如果mid+1这么建回到值左孩子的右边与有孩子的左边无法进行运算
}
void callen(int i){

    if(a[i].s>0){//注意这里不是所有边都是左孩子的长度加上右孩子的长度，他存在一个覆盖问题
        a[i].len=a[i].mr-a[i].ml;
    }else if(a[i].r-a[i].l==1){
        a[i].len=0;
    }else{
        a[i].len=a[i*2].len+a[i*2+1].len;
    }
    return ;
}
void updata(int i,Node b){
    if(a[i].ml==b.y1&&a[i].mr==b.y2){
        a[i].s+=b.flag;
        callen(i);
        return ;
    }
    if(b.y2<=a[i*2].mr) updata(i*2,b);
    else if(b.y1>=a[i*2+1].ml) updata(i*2+1,b);
    else{
        Node temp=b;
        temp.y2=a[i*2].mr;
        updata(i*2,temp);
        temp=b;
        temp.y1=a[i*2+1].ml;
        updata(i*2+1,temp);
    }
    callen(i);
    return ;
}
int main(){
//    freopen("in.txt","r",stdin);
    int n,t,p=1,te;
    double x1,x2,y1,y2;
    while(scanf("%d",&n),n){
            t=1;
            for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            node[t].x=x1;
            node[t].y1=y1;
            node[t].y2=y2;
            node[t].flag=1;//入边
            y[t++]=y1;
            node[t].x=x2;
            node[t].y1=y1;
            node[t].y2=y2;
            node[t].flag=-1;//出边
            y[t++]=y2;
        }
        sort(node+1,node+t,cmp);
        sort(y+1,y+t);
        build(1,1,t-1);
        updata(1,node[1]);
        double sum=0;
        for(int i=2;i<t;i++){
            sum+=a[1].len*(node[i].x-node[i-1].x);
            updata(1,node[i]);
        }
        printf("Test case #%d\n",p++);
        printf("Total explored area: %.2lf\n\n",sum);
    }
    return 0;
}
