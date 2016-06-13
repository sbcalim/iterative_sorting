//This code shows how to apply Bubble Sort, Insertion Sort and Selection Sort;
// figure their time elapsed and then test it.
//Array will be created with random number in size of specified by user.

#include <iostream>
#include <ctime>
#include "Sorting.h"

typedef void (*SortingFunction)(int *, int);
void apply_sorting(SortingFunction, char *, int *, int);
using namespace std;

int main()
{
    //Get the size of the array from user and declare it to N
    int N;
    cout<<"Enter the size of the array: ";
    cin>>N;
    cout<<endl;

    //Create an array and copy for each to be fair to all
    //If we were given the same array to all, it would be sorted first
    // and other two would get it sorted.
    int *array = create_array(N);
    int *array2 = new_array(array, N);
    int *array3 = new_array(array, N);

    apply_sorting(BubbleSort, "Bubble Sort", array, N);
    apply_sorting(InsertionSort, "Insertion Sort", array2, N);
    apply_sorting(SelectionSort, "Selection Sort", array3, N);

    return 0;
}

//One function to rule 'em all
void apply_sorting(SortingFunction sortingFunction, char *sortingName, int A[], int N)
{
    clock_t t1 = clock();

    sortingFunction(A, N);

    clock_t t2 = clock();
    int elapsed_time = int((t2-t1)/CLOCKS_PER_SEC);

    printf("%s:\nElapsed Time: %d seconds.\nResult: %d Mistakes.\n\n", sortingName, elapsed_time, test_array(A, N));
}

//Creating a random array as specified size
int *create_array(int N)
{
    int *array;
    array = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        array[i] = rand();
    }//end-of-for
    return array;
}//End of create_array()

//Creating a new array to use for testing each sorting algorithm
int *new_array(int A[], int N)
{
    int *array;
    array = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        array[i] = A[i];
    }//end-of-for
    return array;
}//End of new_array()

//Test the all array and count the number of incorrect results
int test_array(int A[], int N)
{
    int counter = 0;
    for(int i = 0; i<N-1; i++)
    {
        if(A[i]>A[i+1])
        {
            counter++;
        }
    }//end-of-for
    return counter;
}//End of test_array

//All functions below need swap
void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}//End of swap()

//Bubble Sort
void BubbleSort(int A[], int N)
{
    for(int i = N-1; i>=0; i--)//Lock the biggest number at the end and ignore it
    {
        for(int j = 0; j<=i; j++)//Take the biggest number ant take it to the end (just before last locked one)
        {
            if(A[j]>A[j+1]) swap(A[j], A[j+1]);
        }//end-of-for
    }//end-of-for
}//End of BubbleSort()

//Insertion Sort
void InsertionSort(int A[], int N)
{
    for(int i = 1; i<N; i++)
    {
        int j = i;
        while(A[j]<A[j-1])
        {
            swap(A[j], A[j-1]);
            j--;
        }//end-of-for
    }//end-of-for
}//End of InsertionSort


//Selection Sort
void SelectionSort(int A[], int N)
{
    for(int i = 0; i<N; i++)
    {
        int temp = i;
        for(int j = i+1; j<N; j++)
        {
            if(A[j] < A[temp]) temp = j;
        }//end-of-for
        swap(A[temp], A[i]);
    }//end-of-for
}//End of SelectionSort()