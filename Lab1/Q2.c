#include<stdio.h>
int main(){
    printf("enter number of integers");
    int num;
    scanf("%d",&num);
    int x;
    int sum=0;
    for(int i=0;i<num;i++){
        scanf("%d",&x);
        sum+=x;
    }
    double avg=sum/num;
    printf("%f",avg);
    return 0;
}
