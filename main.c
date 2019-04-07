/*This Program is a Modified version of Honey Bee Algorithm**
It has a modified Global search algorithm and Binary search in Local search**
NOTE: THIS PROGRAM MUST ONLY BE APPLIED TO A DATA STRUCTURE WHICH IS SORTED(ASCENDING ORDER)
*/

#include<stdio.h>
#include<stdlib.h>
int globalSearch(int *key, int *input_array,int size);
int localSearch(int left_limit, int right_limit, int *input_array, int *key);
int output(int position);
int waggleDance();
int *input(int size);
int *getKey();


int waggleDance(){
    //change the size below
    int size = 10000;
    int *input_array;
    input_array = input(size);
    //key contains both key and partition size for our array
    int *key;
    key = getKey();
    int i = globalSearch(key, input_array, size);
    int result = localSearch(i * *(key+1), (i+1) * *(key+1), input_array, key);
    output(result);
    return 0;
}



int *input(int size){
    FILE *file = fopen("numbersforArray.txt", "r");
    int n = 0, i = 0;
    int *numbers = malloc(sizeof(int)* size);
    while( fscanf(file, "%d,", &n) > 0 ){
        numbers[++i] = n;
    }
    fclose(file);
    return numbers;
}



int *getKey(){
    int *key = malloc(sizeof(int)*2);
    printf("Enter the search element\t:");
    scanf("%d",&key[0]);
    printf("Enter the partition size\t:");
    scanf("%d",&key[1]);
    return key;
}



int globalSearch(int *key, int *input_array,int size){
    int partitions = size / *(key + 1), j;
    int checkpoint[partitions];
    j = 0;
    for(int i = 0; i < partitions; i++){
        checkpoint[i] = input_array[j];
        j += size / partitions;
    }
    for(int i = 0; i < partitions; i++){
        if(checkpoint[i]<= *(key) && checkpoint[i + 1] >= *(key))
            return i;
    }
return -1;
}



int localSearch(int left_limit, int right_limit, int *input_array, int *key){
    int beginning = left_limit, end = right_limit, middle;
    while(beginning <= end){
        middle = (beginning + end) / 2;
        if(input_array[middle] == *key){
            return middle;
        }
        else if(input_array[middle] > *key)
            end = middle - 1;
        else
            beginning = middle + 1;
    }
    return -1;
}



int output(int position){
    printf("The Element is found at the position:\t%d\n", position);
    return 0;
}



int main(){
    waggleDance();
    return 0;
}
