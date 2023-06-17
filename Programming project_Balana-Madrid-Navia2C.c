// MEMBERS:
// Renmar Balana
// Ralph James Madrid
// Joshua Toledo Navia

/*


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXRANGE 1000000			//max range of randomly generated number, with equal distribution
#define MAXSIZE 500000				//max size of an array

//function prototype  declarations
void GenerateRandom(int N, int array[]);
void GenerateSorted(int N, int X, int array[]);

double insertionSort(int array[], int N);

void mergeSort(int array[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);

void heapSort(int array[], int N);
void heapify(int arr[], int n, int i);

void swap(int *a, int *b);
void printArr(int N, int array[]);
void fprintArr(int N, int array[], FILE *fptr);
int median (int a, int b, int c);
void delay(int milli);


int main(void) {										//start of main function
//variable declarations
	clock_t start, end;									
	double cpu_time_used;
	int N, X, i;
	
	double insertionS_time, mergeS_time, quickS_time, heapS_time;
	double insertionS_time2, mergeS_time2, quickS_time2, heapS_time2;
	
	
	int *arrRand = malloc(MAXSIZE*sizeof(int));			//initialize the array on the Heap
	int *arrSort = malloc(MAXSIZE*sizeof(int));		
												//arrRand stores array of random inputs; arrSORT sorted in increasing order		
	
	
	printf("Please enter the value of N (no. of integers as input to Sorting Algorithms): ");		//prompt user input N
	do{										//loop makes sure only positive input
		scanf("%d", &N);					//number of integers as input used in sorting
		if(N < 1)
			printf("Error! enter a POSITIVE integer: ");
	}while(N < 1);		
	GenerateRandom(N, arrRand);
	printf("\n\tGenerated array of random numbers:\n");					//print in screen the generated Random array
		printArr(N, arrRand);
	
	
	printf("Please enter a positive integer X(interval for sorted array): ");						//prompt user input X
	do{										//loop makes sure only positive input
		scanf("%d", &X);					//number to be used as increment for sorted array
		if(X < 1)
			printf("Error! enter a POSITIVE integer: ");
	}while(X < 1);
	GenerateSorted(N, X, arrSort);
	printf("\tGenerated array of already sorted numbers:\n");				//print in screen the generated Sorted array
		printArr(N, arrSort);

	
	printf("\n\nPROGRAM RESULTS:\n");
	
	//make 4 copies of the contents of arrRand, that will be sorted in respective arrays
	int *iSort = malloc(MAXSIZE*sizeof(int));
	int *mSort = malloc(MAXSIZE*sizeof(int));
	int *qSort = malloc(MAXSIZE*sizeof(int));
	int *hSort = malloc(MAXSIZE*sizeof(int));
	for(i=0; i<N; i++){
		iSort[i] = arrRand[i];
		mSort[i] = arrRand[i];
		qSort[i] = arrRand[i];
		hSort[i] = arrRand[i];		
	}
	

	insertionS_time = insertionSort(iSort, N);
	printf("\tTime insertion Sort took for N =%d, Random Input : %02.5lf seconds \n", N, insertionS_time);
	
	
	start = clock();
		mergeSort(mSort, 0, N-1);
	end = clock();
	mergeS_time = ((double)(end-start)) / CLOCKS_PER_SEC;
	printf("\tTime merge Sort took for N =%d, Random Input     : %02.5lf seconds \n", N, mergeS_time);

	
	start = clock();
		quickSort(qSort, 0, N-1);
	end = clock();
	quickS_time = ((double)(end-start)) / CLOCKS_PER_SEC;
	printf("\tTime Quick Sort took for N =%d, Random Input     : %02.5lf seconds \n", N, quickS_time);
	
	
	start = clock();
		heapSort(hSort, N);
	end = clock();
	heapS_time = ((double)(end-start)) / CLOCKS_PER_SEC;
	printf("\tTime Heap  Sort took for N =%d, Random Input     : %02.5lf seconds \n", N, heapS_time);
	printf("\n\n");
	
	
	
	//make 4 copies of the contents of arrSort, that will be sorted in respective arrays
	int *iSorted = (int*)malloc(MAXSIZE*sizeof(int));
	int *mSorted = (int*)malloc(MAXSIZE*sizeof(int));
	int *qSorted = (int*)malloc(MAXSIZE*sizeof(int));
	int *hSorted = (int*)malloc(MAXSIZE*sizeof(int));
	for(i=0; i<N; i++){
		iSorted[i] = arrSort[i];
		mSorted[i] = arrSort[i];
		qSorted[i] = arrSort[i];
		hSorted[i] = arrSort[i];		
	}
	//Find running time of array that is already sorted:
	
	insertionS_time2 = insertionSort(iSorted, N);
	printf("\tTime insertion Sort took for N =%d, Sorted Input : %02.5lf seconds \n", N, insertionS_time2);
	

	start = clock();
	mergeSort(mSorted, 0, N-1);
	end = clock();
	mergeS_time2 = ((double)(end-start)) / CLOCKS_PER_SEC;
	printf("\tTime merge Sort took for N =%d, Sorted Input     : %02.5lf seconds \n", N, mergeS_time2);
	
	
	start = clock();
	quickSort(qSorted, 0, N-1);
	end = clock();
	quickS_time2 = ((double)(end-start)) / CLOCKS_PER_SEC;
	printf("\tTime quick Sort took for N =%d, Sorted Input     : %02.5lf seconds \n", N, quickS_time2);
	

	start = clock();
	heapSort(hSorted, N);
	end = clock();
	heapS_time2 = ((double)(end-start)) / CLOCKS_PER_SEC;
	printf("\tTime heap  Sort took for N =%d, Sorted Input     : %02.5lf seconds \n", N, heapS_time2);

	
	
	//FILE PRINTING
	FILE *fptr;
	fptr = fopen("Array_Values+Processor_Time.txt","w");
	if(fptr == NULL){
		printf("ERROR! no output File was produced.");
		return 1;
	}
	fprintf(fptr, "Time Insertion Sort took for N = %6d, Random Input :\t%3.5lf seconds \n", N, insertionS_time);
	fprintf(fptr, "Time Merge Sort took for N = %6d, Random Input    :\t%3.5lf seconds \n", N, mergeS_time);
	fprintf(fptr, "Time Quick Sort took for N = %6d, Random Input    :\t%3.5lf seconds \n", N, quickS_time);
	fprintf(fptr, "Time Heap  Sort took for N = %6d, Random Input    :\t%3.5lf seconds \n", N, heapS_time);
	fprintf(fptr,"\n\n");
	fprintf(fptr, "Time Insertion Sort took for N = %6d, Sorted Input :\t%3.5lf seconds \n", N, insertionS_time2);
	fprintf(fptr, "Time Merge Sort took for N = %6d, Sorted Input :\t%3.5lf seconds \n", N, mergeS_time2);
	fprintf(fptr, "Time Quick Sort took for N = %6d, Sorted Input :\t%3.5lf seconds \n", N, quickS_time2);
	fprintf(fptr, "Time Heap  Sort took for N = %6d, Sorted Input :\t%3.5lf seconds \n", N, heapS_time2);

	fprintf(fptr,"\n\nOriginal Array with randomly generated values:\n");
	fprintArr(N,arrRand,fptr);
	fprintf(fptr,"Array with randomly generated values, After Sorting:\n");
	fprintArr(N,iSort,fptr);
	fprintf(fptr,"\n\nSorted Array with increasing values based on X:\n");
	fprintArr(N,arrSort,fptr);
	fclose(fptr);
	
				//!!!---TEST CASE---!!!		
				//remove the enclosing comments to check if the respective arrays are actually sorted.
	 /*			
	fptr = fopen("Insertion_Sort_Result.txt","w");
	if(fptr == NULL){
		printf("ERROR! the output File __ was NOT produced.");
		return 1;
	}
	fprintf(fptr,"INSERTION SORT RESULT\n");
	fprintf(fptr,"\n\nRandomly generated Array after Sorted by Insertion Sort:\n");
	fprintArr(N,iSort,fptr);
	fclose(fptr);
	
	fptr = fopen("Merge_Sort_Result.txt","w");
	if(fptr == NULL){
		printf("ERROR! the output File __ was NOT produced.");
		return 1;
	}
	fprintf(fptr,"MERGE SORT RESULT\n");
	fprintf(fptr,"\n\nRandomly generated Array after Sorted by Merge Sort:\n");
	fprintArr(N,mSort,fptr);
	fclose(fptr);
	
	fptr = fopen("Quick_Sort_Result.txt","w");
	if(fptr == NULL){
		printf("ERROR! the output File __ was NOT produced.");
		return 1;
	}
	fprintf(fptr,"QUICK SORT RESULT\n");
	fprintf(fptr,"\n\nRandomly generated Array after Sorted by Quick Sort:\n");
	fprintArr(N,qSort,fptr);
	fclose(fptr);
	
	fptr = fopen("Heap_Sort_Result.txt","w");
	if(fptr == NULL){
		printf("ERROR! the output File __ was NOT produced.");
		return 1;
	}
	fprintf(fptr,"HEAP SORT RESULT\n");
	fprintf(fptr,"\n\nRandomly generated Array after Sorted by Heap Sort:\n");
	fprintArr(N,hSort,fptr);
	fclose(fptr);
	
	 */
	
	//free all the allocated memory used earlier
	free(arrRand);
	free(iSort);free(mSort);free(qSort);free(hSort);
	free(arrSort);
	free(iSorted);free(mSorted);free(qSorted);free(hSorted);
	
	return 0;
}	//end of main



void GenerateRandom(int N, int array[]){				//generates array of random nums
	int i;
	srand(time(NULL));		//sets the seed of rand, by predefined function time (seconds elapsed since Jan. 1, 1970)
	unsigned long x;

	for(i=0; i<N; i++){
		x = rand();				
		x <<= 15; 				//shift by 15 bits, to increase max value
		x ^= rand();			//takes 2 random numbers and performs XOR on every bit. result is 1 if 2 bits are different.
		x %= MAXRANGE+1;		//perform modulo by 1M+1, so number can only be between 0 to 1M.
				
		array[i] = x ;
	}
	
	/*	NOTES	
	rand can give at least 15 bits, and at max the value 32767 on windows
	shift by 15bits, XOR the results, then modulo by 1000000 (+1 to include 1 Mill itself)
	*/
	return;
}
void GenerateSorted(int N, int X, int array[]){			//generates an array already sorted in increasing order
	int i;
	for (i=0; i<N; i++){		
		array[i] = N+(1+i)*X ;
	}
	return;
}

double insertionSort(int array[], int N){				//function for insertion sort
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	int i, j, key;
	for(j=1; j<N; j++){								
		key = array[j];								
		i = j-1;									
		while ((i>=0) && (array[i]>key)){			
			array[i+1] = array[i];					
			i = i-1;								
		}											
		array[i+1] = key;							
	}
	end = clock();
	
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}

void mergeSort(int array[], int low, int high){			//mergesort function
	if (low < high){
		int mid = (low+high)/2;
		
		mergeSort(array, low, mid);
		mergeSort(array, mid+1, high);
		
		merge(array, low, mid, high);		
	}
	return;
}
void merge(int arr[], int low, int mid, int high){		//function to merge subarrays for MergeSort
	
	//find length of temp arrays to be used
	int n1 = mid - low+1;
	int n2 = high - mid;
	
	//create temp array
	int *Left = malloc(n1*sizeof(int));
	int *Right = malloc(n2*sizeof(int));
	
	
	//copy data to temp array
	int i, j, k;
	for(i=0; i<n1; i++)
		Left[i] = arr[low+i];
	for(j=0; j<n2;j++)
		Right[j] = arr[mid+1+j];
		
	//merge the temp arrays (with leftovers)
	i=0, j=0, k=low;
	while((i<n1)&&(j<n2)){
		if (Left[i] <= Right[j]){
			arr[k] = Left[i];
			i++;
		}
		else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	
	//copy the remaining elements 
	while (i<n1){
		arr[k] = Left[i];
		i++; k++;
 	}
 	while (j<n2){
 		arr[k] = Right[j];
 		j++; k++;
	 }
	 
	 
	free(Left);
	free(Right);
}

void quickSort(int array[], int low, int high){			//function for Quicksort
	while (low < high){									//
		int j = partition(array, low, high);			//
		if(j-low < high-j){								//
			quickSort(array, low, j-1);					// case if j, the partitioned element is on the left side of array
			low = j+1;									//		recurse the smaller part = on left side of j
		} else {										//
			quickSort(array, j+1, high);				//case if j, is near the right side of array
			high = j-1; 								//		recurse the smaller part = on right side of j
		}
	}
	return;
}
int partition(int array[], int low, int high){			//function to find partition position for QuickSort
	//select  pivot
	int pivot;
	
//	srand(time(NULL));											//code if pivot is chosen to be random
//	random = rand() % high+1;
//	pivot = array[random];

//	random = median(array[0], array[high/2],array[high]);		//code if pivot is chosen to be median
//	pivot = array[random];
	
	pivot = array[high];										//code if pivot is chosen to be last element
	int j, i = (low-1);
	
	//check every element of the array & compare with pivot
	for(j=low; j<=high-1; j++){
		if (array[j] <= pivot){				//if element smaller than pivot is found, swap with greatest element stored in i
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1], &array[high]);		//swap pivot with greater element
	return(i+1);								//return partition point
}

void heapSort(int array[], int N){						//heapsort function
	int i;								
	for(i=N/2-1; i>=0; i--)				//build maxheap
		heapify(array, N, i);			
	
	//Heap sort
	for(i=N-1; i>=0; i--){
		swap(&array[0], &array[i]);
		heapify(array, i, 0);			//heapify root element to get highest element at root again
	}
	return;
}
void heapify(int arr[], int n, int i){					////heapify function
	//Find largest in root, left and right child
	int largest = i;
	int left = 2*i +1;
	int right = 2*i +2;
	
	if((left<n) && (arr[left] > arr[largest]))
		largest = left;
	if((right<n) && (arr[right] > arr[largest]))
		largest = right;
		
	if(largest != i){								//swap and continue heapifying if root is not largest
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
	return;
}


void swap(int *a, int *b){								//swaps two elements
	int t = *a;
	*a = *b;
	*b = t;
}

void printArr(int N, int array[]){						//Prints the array on screen
	int i, j, k;
	printf("\t\t");
		for(i=0; i<17; i++)
			printf("------");							//prints top border
	int rows = (N-1)/10;

	i=0;
		for(j=0; j<=rows; j++){
			printf("\n\t\t|");
				for (k=0; (k<10)&&(i<N); i++,k++){
					printf(" %8d ",array[i]);
				}
				if (k != 10){							//makes sure proper closing border.
					for(;k<10;k++)
						printf("          ");
				}
			printf("|");
		}
	printf("\n\t\t");
		for(i=0; i<17; i++)
			printf("------");							//prints bottom border
		printf("\n");
	
	return;
}
void fprintArr(int N, int array[], FILE *fptr){			//prints array on a file
	int i, j, k;
	fprintf(fptr,"\t\t");
		for(i=0; i<17; i++)
			fprintf(fptr,"------");							//prints top border
	int rows = (N-1)/10;

	i=0;
		for(j=0; j<=rows; j++){
			fprintf(fptr,"\n\t\t|");
				for (k=0; (k<10)&&(i<N); i++,k++){
					fprintf(fptr," %8d ",array[i]);
				}
				if (k != 10){							//makes sure proper closing border.
					for(;k<10;k++)
						fprintf(fptr,"          ");
				}
			fprintf(fptr,"|");
		}
	fprintf(fptr,"\n\t\t");
		for(i=0; i<17; i++)
			fprintf(fptr,"------");							//prints bottom border
		fprintf(fptr,"\n");
	
	return;	
}

int median (int a, int b, int c){						//this function finds the median between 3 integers
	if ((a<=b) && (b<=c)) return b;
	if ((a<=c) && (c<=b)) return c;
	if ((b<=a) && (a<=c)) return a;
	if ((b<=c) && (c<=a)) return c;
	if ((c<=a) && (a<=b)) return a;
	return b;
}

void delay(int milli){									//delays clock by the entered parameter in milliseconds.
	long pause;											//function for troubleshooting time. making sure it works
	clock_t now, then;
	
	pause = milli*(CLOCKS_PER_SEC/1000);
	now = then = clock();
	while ((now-then) < pause )
		now = clock();
	return;
}
