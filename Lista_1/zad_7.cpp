#include <iostream>
struct lnode
    { 
        int key;
        lnode *next;
        lnode(int key0,lnode* next0=nullptr):key(key0),next(next0){}
    };

//Przykład A
int wypisz(lnode* L){
    while (L != nullptr)
    {
        std::cout << L->key << " ";
        L = L->next;
    }

    return 0;
}

//Przykład B
int suma(lnode* L){
    int sum = 0;
    while (L != nullptr)
    {
        sum += L->key;
        L = L->next;
    }
    return sum;
}

//Przykład C
int nty(int n, lnode *L){
    while (L != nullptr && n != 0)
    {
        L = L->next;
        n--;
    };
    int result = L == nullptr ? 0 : L->key;
    
    return result;

}

//Przykład D
void insert(lnode* &L, int x){
    L = new lnode(x, L);
}

//Przykład I
void reverse(lnode* &L){
     if (L == nullptr || L->next == nullptr)
        return; // zabezpieczenie przed listą mniejszą niz 2 elementy

    lnode *current = L;
    lnode *previous = nullptr;

    L = L->next;
    current->next = previous;

    while (L != nullptr)
    {
        previous = current;
        current = L;
        L = L->next;
        current->next = previous;
    }

    L = current;
}

//Przykład E
void insert_after_smaller(lnode *&L, int x){
    lnode* L_pom = L;
    lnode* temp1 = NULL;

    while (L_pom != nullptr)
    {
        temp1 = new lnode(L_pom->key,temp1);

        if(L_pom->key < x){
            temp1 = new lnode(x,temp1);
        }
        L_pom = L_pom->next;
    }
    L = temp1;
    reverse(L);
}


//Przykład F
void remove(lnode* &L, int x){
    lnode* L_pom = L;
    lnode* temp1 = NULL;

    while (L_pom != nullptr)
    {
        if(L_pom->key != x){
            temp1 = new lnode(L_pom->key,temp1);
        }
        L_pom = L_pom->next;
    }
    L = temp1;
    reverse(L);
}

//Przykład H
void destroy(lnode* &L){
    L = nullptr;
}

int main(){

    lnode* L=NULL;

    //przykład D (wpisywanie)
    for (int i=1; i<11; i++){
        insert(L,i);
    }

    //Przykład A 
    std::cout<< "a) ";
    wypisz(L);

    //Przykład B
    std::cout << "\nb) Suma elementow: " << suma(L)<<"\n";

    //Przykład C        
    //Tutaj w zadaniu nie było sprecyzowane czy liczymy od prawej czy od lewej i czy liczenie zaczynamy od 0 czy od 1 dlatego rozwiązałem 
    //to w ten sposb, ze liczymy od 0 i od lewej strony.
    int n = 3;
    std::cout << "c) Wartość "<< n << "-go elementu: " << nty(n,L)<<"\n";

    //Przykład E
    insert_after_smaller(L,5);
    std::cout<<"e) ";
    wypisz(L);

    //Przykład F
    remove(L,4);

    std::cout<<"\nf) usuwanie 4: ";
    wypisz(L);

    //Przykład F
    reverse(L);

    std::cout<<"\ni) ";
    wypisz(L);
}