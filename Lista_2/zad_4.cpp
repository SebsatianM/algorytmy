#include <iostream>
#include <string>



int findMaxIter(int t[],int n)
{
    int arraySize = sizeof(int)*n;
    int comparison = 0;
    int size = 0;
    int x=t[--n];
    
    while(n--){
        comparison++;
        if(t[n]>x){
            x=t[n];
        }
    }

    size = sizeof(x)+arraySize+sizeof(n);    
    std::cout << "Funkcja wykonała: " << comparison << " porownań\noraz wykorzystała: " << size <<" bajtow\n";

    return x;
}

int findMaxRecB(const int t[], int size, int largest) {

    //sprawdzamy czy tablica jest jedno elementowa jeśli tak to zwracamy wartość tego elementu
    static int comparisonCounter = 0;
    static int callCounter = 0;
    callCounter++;
    std::cout << "B) Liczba porownań: " << comparisonCounter << " Liczba wywołań: " <<  callCounter << "\n"; 
    
    comparisonCounter++;
    if( size > 0 ){

        comparisonCounter++;
        if( t[size-1] > largest){
            largest = t[size-1];
        }
        return ( largest = findMaxRecB(t,size-1,largest)); 

    }
    else{
        comparisonCounter++;
        return largest > t[size] ? largest: t[size];
    }
    
   
}

int findMaxRecC(const int t[], int first, int length) {

    //sprawdzamy czy tablica jest jedno elementowa jeśli tak to zwracamy wartość tego elementu
    static int comparisonCounter = 0;
    static int callCounter = 0;
    callCounter++;

    comparisonCounter++;
    if (first+1 == length) {
        std::cout << "C) Liczba porownań: " << comparisonCounter << " Liczba wywołań: " <<  callCounter << "\n";       
        return t[first];
    }
    
    //dzielenie tablicy na dwie części 
    int mid = first + (length - first) / 2;

    int leftMax = findMaxRecC(t, first, mid);
    int rightMax = findMaxRecC(t, mid, length);

    comparisonCounter++;
    if (leftMax > rightMax){
        return leftMax;
    }else{
        return rightMax;
    }
   
}

int main()
{

    const int arrLenght = 21;
    const int arrLenght2 = 2;
    int array[arrLenght] = {4440,13,4,4,1,2,4,20,400,20,3001,3000,13,423,1,76,34,13,63,120,12000};
    int array2[arrLenght] = {0,13};
    std::cout<<findMaxIter(array, arrLenght)<<"\n";
    std::cout<<findMaxRecB(array, arrLenght-1 ,array[arrLenght-1])<<"\n";
    std::cout<<findMaxRecC(array, 0,arrLenght)<<"\n";

}