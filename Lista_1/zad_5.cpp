#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> read(std::string filename){
    std::ifstream fin(filename);   
    std::vector<int> data;
    
    int element;
    while (fin >> element)
    {
        data.push_back(element);
    };
    return data;
}

void print_pol(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


void mltp(std::vector<int> vec_a, std::vector<int> vec_b){

    std::vector<int> vec_c;

    //stopien iloczynu wielomianu jest rowny sumie stopni

    int deg_a,deg_b,deg_c;
    deg_a = vec_a.front();
    deg_b = vec_b.front();
    deg_c = deg_a + deg_b;

    std::cout << "Degree of polynomial A(x): " << deg_a << "\n";
    std::cout << "Degree of polynomial B(x): " << deg_b << "\n";
    std::cout << "Degree of polynomial C(x) = A(x)B(x): " << deg_c << "\n";

   

}


int main()
{
    mltp(read("a.txt"),read("b.txt"));
}