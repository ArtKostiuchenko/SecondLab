#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void printArray(int *arr);
int MoreThanMean(int *arr,double mean);
int SumElements(int *arr);

int main(){
    srand(time(0));
    int *arr = (int *) malloc(N*sizeof (int ));
    int Sum = 0;
    double mean = 0.0;
    for(int i = 0; i<N;i++){
        arr[i] = rand()%20-10;
        Sum+=arr[i];
    }
    printArray(arr);
    mean = 1.0*Sum/N;
    printf("The mean value is: %.3lf\n",mean);
    printf("Amount of numbers, more than mean: %d\n", MoreThanMean(arr,mean));
    printf("Sum of modules: %d", SumElements(arr));
}

void printArray(int *arr){
    for(int i = 0;i<N;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int MoreThanMean(int *arr,double mean){
    int count = 0;
    for(int i = 0;i<N;i++){
        if(arr[i]*1.0 > mean) count++;
    }
    return count;
}

int SumElements(int *arr){
    int flag = 0;
    int SumModules = 0;
    for (int i = 0; i < N; i++) {
        if(arr[i]<0){
            flag = i;
            break;
        }
    }
    for (int i = flag+1; i < N; ++i) {
        if(arr[i]<0){
            SumModules += -1*arr[i];
        } else{
            SumModules += arr[i];
        }
    }
    return SumModules;
}

