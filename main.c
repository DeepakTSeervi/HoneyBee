#include<stdio.h>

static int input();

static int *get_key();

static int globalSearch(int key, int input_array[],int size);

static int localSearch(int left_limit, int right_limit, int input_array[], int key);

static int output(int element, int position);

static int waggleDance();

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



int waggleDance(){
    int size = 100;
    int key = getKey();
    int i = globalSearch(key, input_array, size);
    int result = i + localSearch(i*10, (i + 1)*10, input_array, key);
    output(key, result);
    return 0;
}



int globalSearch(int key, int input_array[],int size){
    int partition_size = size / 3, j;
    int checkpoint[partition_size];
    for(int i = 0; i < partition_size - 1; i++){
        j = 0;
        checkpoint[i] = input_array[j];
        j += partition_size / 3;
    }
    for(int i = 0; i < partition_size - 1; i++){
        if(checkpoint[i]<= key && checkpoint[i + 1] >= key)
            return i;
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
