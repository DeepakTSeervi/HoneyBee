#include<stdio.h>

static int *input();

static int *getKey();

static int globalSearch(int key, int input_array[],int size);

static int localSearch(int left_limit, int right_limit, int input_array[], int key);

static int output(int element, int position);

static int waggleDance();

int waggleDance(){
    //change the size below
    int size = 10000;
    int *input_array = input();
    //key contains both key and partition size for our array
    int *key = getKey();
    int i = globalSearch(key, input_array, size);
    int result = i + localSearch(i, (i+1) * *(key+1), input_array, key);
    output(key, result);
    return 0;
}



int input(){
    FILE *file = fopen("numbersforArray.txt", "r");
    int n = 0, i = 0;
    int numbers[10000];
    while( fscanf(file, "%d,", &n) > 0 ){
        numbers[++i] = n;
    }
    fclose(file);
    return numbers;
}



int getKey(){
    int key[2];
    printf("Enter the search element\t:");
    scanf("%d",&key[0]);
    printf("Enter the partition size\t:");
    scanf("%d",&key[1]);
    return key;
}



int globalSearch(int key[], int input_array[],int size){
    int partitions = size / *(key + 1), j;
    int checkpoint[partitions];
    j = 0;
    for(int i = 0; i < partitions; i++){
        checkpoint[i] = input_array[j];
        j += size / partitions;
    }
    for(int i = 0; i < partitions; i++){
        if(checkpoint[i]<= *(key) && checkpoint[i + 1] >= *(key))
            return i * (size / partitions);
    }
return -1;
}



int localSearch(int left_limit, int right_limit, int input_array[], int key){
    int beginning = left_limit, end = right_limit, middle;
    while(beginning <= end){
        middle = (beginning + end) / 2;
        if(input_array[middle] == key){
            return middle;
        }
        else if(input_array[middle] > key)
            end = middle - 1;
        else
            beginning = middle + 1;
    }
    return -1;
}



int output(int element, int position){
    printf("The Element %d is found at the position: %d\n", element, position);
    return 0;
}



int main(){
    waggleDance();
    return 0;
}
