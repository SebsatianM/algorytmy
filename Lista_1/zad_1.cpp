#include <iostream>

int power_recurrence(int x, int n){
    if(n == 0 ){
        return 1;
    }else if(n ==1){
        return x;
    }else if (n%2==0){
        return power_recurrence(x*x,n/2);
    }else{
        return x * power_recurrence(x,n-1);
    }
}

int power(int x, int n){
    int result = 1;
    
    while (n > 0){
        if (n % 2 == 0){
            x = x * x;
            n = n / 2;
        }else{
            result = result * x;
            n = n - 1;
        }
    }
    return result;
}
int main()
{
    int n_1,n_2;
    float x;
    x=2;
    n_1 = 10;
    n_2 = 11;
    std::cout << "Podpunkt a)rekurencja:\n1)Parzyste: "<<x<<"^"<<n_1<<"="<<power_recurrence(x,n_1)<<"\n2)Nieparzyste: "<<x<<"^"<<n_2<<"="<<power_recurrence(x,n_2)<<"\n";
    std::cout<<"\n";
    std::cout << "Podpunkt b)bez rekurencji:\n1)Parzyste: "<<x<<"^"<<n_1<<"="<<power(x,n_1)<<"\n2)Nieparzyste: "<<x<<"^"<<n_2<<"="<<power(x,n_2)<<"\n";


}