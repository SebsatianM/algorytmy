#include <iostream>

struct MinMax{
   int Min,Max;
};

void findMinMax(int array[5], int start, int stop){
    MinMax min_max;
    int idx;
    int comparison = 0;
    int n = stop - start+1;             //liczba elementow ktore będą porownywane
    if(n % 2!= 0){
        min_max.Min = array[start];
        min_max.Max = array[start];
        idx = start+1;
    }else{
        if (array[start] < array[start+1] ){
            comparison+=1;
            min_max.Min = array[start];
            min_max.Max = array[start+1];
        }else{
            min_max.Min = array[start+1];
            min_max.Max = array[start];
        }
        idx = start + 2;
    }

    int curr_min,curr_max;
    for ( int i = idx; i < n-1; i += 2 ){

      if ( array[i] < array[i+1] ){ 
        comparison+=1;
        curr_min = array[i];
        curr_max = array[i+1];
      }
      else{
        curr_min = array[i+1];
        curr_max = array[i];
      }

      if ( min_max.Min > curr_min ){ 
        comparison+=1;
        min_max.Min = curr_min;
      }
      if ( min_max.Max < curr_max ){ 
        comparison+=1;
        min_max.Max = curr_max;
      }
   }
   std::cout << "Najmniejsza liczba w tablicy to: "<<min_max.Min <<"\nNajwiększa liczba w tablicy to: "<<min_max.Max <<"\nWyniki znalezione w: "<<comparison<<" porownaniach 3n/2= "<<(3*n)/2<<"\n";
}

int main()
{
    int array[9] = {0,13,4,4,1,2,4,20,400};

    findMinMax(array, 0, 8);

}