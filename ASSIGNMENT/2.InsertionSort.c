#include<stdio.h>
int main(){
    int n,a,b,key,shifts=0;
    printf("Enter number of students: ");
    scanf("%d",&n);

    int marks[n];

    printf("Enter %d marks:\n",n);
    for(a=0;a<n;a++)
        scanf("%d",&marks[a]);

    for(a=1;a<n;a++){
        key=marks[a];
        b=a-1;

     while(b>=0&&marks[b]>key){
            marks[b+1]=marks[b];
            shifts++;
            b--;
        }

        marks[b+1]=key;

     printf("After passing %d: ",a);
        for(b=0;b<n;b++)
            printf("%d ",marks[b]);
        printf("\n");
    }

    printf("\nFinal sorted marks of students: ");
    for(a=0;a<n;a++)
        printf("%d ",marks[a]);

    printf("\nTotal number of shifts: %d\n",shifts);

    return 0;
}
