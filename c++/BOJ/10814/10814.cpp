#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct student
{
    int age;
    char name[101];
    int num;
};

bool cmp(student a,student b){
    if(a.age!=b.age){
        return a.age<b.age;
    }
    else{
        return a.num<b.num;
    }
}

struct student arr[100001];

int main()
{
    int num;


    scanf("%d",&num);

    for(int i=0;i<num;i++){
        scanf("%d %s",&arr[i].age,arr[i].name);
        arr[i].num=i;
    }
    sort(arr,arr+num,cmp);
    for(int i=0;i<num;i++){
        printf("%d %s\n",arr[i].age,arr[i].name);
    }
}
