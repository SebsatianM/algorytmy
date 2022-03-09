#include <iostream>

int binarySearch(int array[], int left, int right, int x)
{
    while (left <= right) 
    {
        int mid = left + (right - left)/2;
        std::cout <<mid;
        if (array[mid]==x){
            return mid;

        }else if(array[mid]>x){
            right = mid-1;
        }else {

            left = mid +1;
        }
    }
    return -1;
}

int main()
{
    int array[19];

    for(int i=0; i<19; i++){
        array[i] = i+1;
    }
   
    int n = sizeof(array)/sizeof(*array);
    int x = 6;
    int index = binarySearch(array, 0, n - 1, x);

    if (index != -1)
        std::cout << "Index: " << index << "\n";
    else
        std::cout << "x not found";
}