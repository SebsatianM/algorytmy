#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>

int findX(int array[],int arrayLength, int x){

// if (array[arrayLength-1]==x){
//     return 1;
    
// }else{
//     for(int i=0;i<arrayLength;i++){   

//         if(array[i] == x)     
//             return i+1;
//         }
//         return 0;
// }

for(int i=0;i<arrayLength;i++){   

    if(array[i] == x)     
        return i+1;
    }
    return 0;

}

int main()

{   
    std::vector<int> comparisonNumber;
    int comparisonCount = 0;
    int probeNumber = 10000;
    int array[100];
    int arrayLength = 100;
    double avarageComparisionNumber = 0.0;
    double sigma = 0.0;

    for(int i=0; i<arrayLength; i++){
        array[i] = i+1;
    }

    for (int i = 0; i < probeNumber; i++)
    {
        int x =  (rand() % arrayLength) + 1;
        std::random_shuffle(std::begin(array), std::end(array));
        comparisonNumber.push_back(findX(array,arrayLength,x));
    }

    for (int i = 0; i < probeNumber; i++){
        comparisonCount+=comparisonNumber[i];
    }
    
    avarageComparisionNumber = (double)comparisonCount/(double)probeNumber;

    for( int i = 0; i < probeNumber; i++ )
    {
        sigma += (comparisonNumber[i] - avarageComparisionNumber) * (comparisonNumber[i] - avarageComparisionNumber);
    }

    sigma = sigma / probeNumber;

    std::cout << "Średnia liczba prownań: "<< avarageComparisionNumber << "\n";
    std::cout << "Wariancja: "<< sqrt(sigma) << "\n";

   
}