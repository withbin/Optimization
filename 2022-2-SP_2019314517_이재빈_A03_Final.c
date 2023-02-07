#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void randlist(int (*arr));
 //List를 배열 요소 값으로 난수로 채우기
void randpointlist(int *arr);
 //List를 포인터로 접근하여 난수로 채우기
void calculatecheck(int (*arr));
 //List에 Index로 접근하여 계산 결과 출력하기. 배열 할당 유무, 접근 확인.
int selectsumlist(int (*arr), int(*arr1));
 //두 리스트의 첫 20개의 값을 더한 값이 큰 리스트를 선택.
int selectduplist(int (*arr), int(*arr1));
 //두 리스트의 첫 10개의 값을 곱한 값이 큰 리스트를 선택.
int selectpick(int (*arr), int(*arr1));
 // 위 두 함수의 결과가 동률이면 이 함수를 실행해서 최종 리스트를 선택.
void asciitobig(char (*arr));
 // 아스키코드를 통해 소문자인 배열을 대문자로 변환.(아스키코드 활용)
void asciitosmall(char (*arr));
 // 아스키코드를 통해 대문자인 배열을 소문자로 변환.(아스키코드 활용)
void calculateascii(char (*arr));
 // 아스키코드가 정수로 계산도 가능한지 확인.
void changeascii(int (*arr), char(*arr1), int length);
 // 선택된 리스트를 아스키코드를 통해 char 리스트에 넣기.
void countab(char *arr,int *a, int *b,int *c);
 // 생성된 리스트에서 a,b의 개수가 몇 개인지 출력해주는 함수.
int mincount(char *arr);
 // 리스트에서 생성된 요소들 중 가장 적게 생성된 요소 출력 함수.
int maxcount(char *arr);
 // 리스트에서 생성된 요소들 중 가장 많이 생성된 요소 출력 함수.
void summinmax(char *arr);
 // 리스트에서 최대, 최소 카운트 된 요소를 호출하여 아스키코드 10진수를 더한 값을 출력.(함수에서 함수 호출 확인)
void bubblesort(char *arr,int a);
 // a에서 끝까지 구간에서 아스키코드를 통해 bubble sort를 수행.
void functioncall(int (*arr),char(*arr2));
 // main이 아닌 함수 call을 통한 실행.
int main(){
    srand((unsigned int)time(NULL));
    int list[40000];
    int list1[40000];
    int list2[40000];
    char list3[40001];
    char list4[9]={'a','b','c','d','A','B','C','D','\0'};
    int list5[40000];
    int acnt;
    int bcnt;
    int ccnt;
    randlist(list1);
    randpointlist((int*)list2);
    calculatecheck(list1);
    int sumselect=selectsumlist(list1,list2);
    int dupselect=selectduplist(list1,list2);
    if(sumselect==0&dupselect==0){
            memmove(list,list1,sizeof(int)*40000);
        }
    else if(sumselect==1&dupselect==1){
        memmove(list,list2,sizeof(int)*40000);
        }
    else{
        if(selectpick(list1,list2)==0){
            memmove(list,list1,sizeof(int)*40000);
            }
        else{
            memmove(list,list2,sizeof(int)*40000);
            }
    }
    asciitobig(list4);
    asciitosmall(list4);
    calculateascii(list4);
    changeascii(list,list3,39999);
    list3[39999]='\0';
    countab(list3,&acnt,&bcnt,&ccnt);
    printf("a : %d b : %d Other : %d\n",acnt,bcnt,ccnt);
    summinmax(list3);
    bubblesort(list3,36500);
    functioncall(list5,list3);
}


void randlist(int (*arr)){
    int leng=sizeof(*arr);
   for(int i=0;i<leng*10000;i+=2){
        int a=rand()%40+65;
        int b=rand()%40+65;
        arr[i]=a;
        arr[i+1]=b;
   }
};

void randpointlist(int *arr){
    int leng=sizeof(*arr);
    for(int i=0;i<leng*10000;i++){
        int a=rand()%40+65;
        *(arr+i)=a;
   }
};

void calculatecheck(int (*arr)){
    printf("Calculate Success : %d\n",arr[100]+arr[2405]*arr[1]);
};
int selectsumlist(int (*arr), int(*arr1)){
    int sumlist[2]={0,0};
    for(int i=0;i<20;i++){
        sumlist[0]+=arr[i];
        sumlist[1]+=arr1[i];
    }
    if(sumlist[0]>sumlist[1]){
        return 0;
    }
    else{
        return 1;
    }
};

int selectduplist(int (*arr), int(*arr1)){
    int sumlist[2]={0,0};
    for(int i=0;i<10;i++){
        sumlist[0]*=arr[i];
        sumlist[1]*=arr1[i];
    }
    if(sumlist[0]>sumlist[1]){
        return 0;
    }
    else{
        return 1;
    }
};

int selectpick(int (*arr), int(*arr1)){
    int i=0;
    while(1){
        if(arr[i]>arr1[i]){
            return 0;
            break;
        }
        else{
            return 1;
            break;
        }
    }
};

void asciitobig(char (*arr)){
    printf("TO Big : ");
    int leng=strlen(arr);
    for(int i=0;i<leng;i++){
        if(arr[i]>96&&123>arr[i]){
            arr[i]=arr[i]-32;
        }
        printf("%c",arr[i]);
    }
    printf("\n");

};


void asciitosmall(char (*arr)){
    printf("TO Small : ");
    int leng=strlen(arr);
    for(int i=0;i<leng;i++){
        if(arr[i]>64&&91>arr[i]){
            arr[i]=arr[i]+32;
        }
        printf("%c",arr[i]);
    }
    printf("\n");

};

void calculateascii(char (*arr)){
    printf("Sum by Ascii : %d\n",arr[0]+arr[2]);
}


void changeascii(int (*arr), char(*arr1), int length){
    for(int i=0;i<length;i++){
        int a=arr[i];
        char s[2];
        sprintf(s, "%c", a);
        arr1[i]=s[0];
    }
};


void countab(char *arr,int *a,int *b,int *c){
    int leng=strlen(arr);
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    for(int i=0;i<leng;i++){
        if(arr[i]=='a'){
            cnt1+=1;
        }
        else if(arr[i]=='b'){
            cnt2+=1;
        }
        else{
            cnt3+=1;
        }
    }


    *a=cnt1;
    *b=cnt2;
    *c=cnt3;
};


int mincount(char *arr){
    int leng1=strlen(arr);
    int a[40]={0};
    int leng2=sizeof(a);
    for(int i=0;i<leng1;i++){
        for(int j=65;j<105;j++){
            if(arr[i]==j){
                a[j-65]+=1;
            }
        }
    }

    int count=0;
    int min=0;

    for(int i=0;i<leng2/4-1;i++){
        if(a[min]>a[i+1]){
            min=i+1;
        }
    }

    printf("min count character : %c\n",min+65);

    return min+65;
};



int maxcount(char *arr){
    int a[40]={0};
    int leng1=strlen(arr);
    int leng2=sizeof(a);

    for(int i=0;i<leng1;i++){
        for(int j=65;j<105;j++){
            if(arr[i]==j){
                a[j-65]+=1;
            }
        }
    }

    int count=0;
    int max=0;

    for(int i=0;i<leng2/4-1;i++){
        if(a[max]<a[i+1]){
            max=i+1;
        }
    }

    printf("max count character : %c\n",max+65);
    return max+65;
};


void summinmax(char *arr){
    int max=maxcount(arr);
    int min=mincount(arr);

    printf("Max+Min %d(function call)\n",max+min);
};


void bubblesort(char *arr,int a){

    int leng=strlen(arr);

    for (int j = 0; j<leng-1; j++) {
        for (int i=a; i<leng-j-1; i++) {
            if (arr[i]>arr[i+1]) {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
        }
    }
  }

  printf("sorted part array : ");
    for(int i=a;i<leng;i+=2){
        printf("%c",arr[i]);
        printf("%c",arr[i+1]);
    }

    printf("\n");
};


void functioncall(int (*arr),char (*arr2)){
    for(int i=0;i<3;i++){
        randlist(arr);
        changeascii(arr,arr2,39999);
        arr2[39999]='\0';
        summinmax(arr2);
        bubblesort(arr2,39500);
    }
};