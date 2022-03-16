#include <iostream>
struct lnode
{
    int key;
    lnode *next;
    lnode(int key0, lnode *next0 = nullptr) : key(key0), next(next0) {}
};

int wypisz(lnode *L)
{
    while (L != nullptr)
    {
        std::cout << L->key << " ";
        L = L->next;
    }

    return 0;
}

void insert(lnode *&L, int x)
{
    L = new lnode(x, L);
}

void destroy(lnode *&L)
{
    L = nullptr;
}

lnode* merge(lnode* L1, lnode* L2){
    //sprawdzamy czy ktoraś lista nie jest pusta
    if(L1 == nullptr)
        return L2;      
    if(L2 == nullptr)
        return L1;
    
    //inicjalizuje miejsce na liste wynikową
    lnode* result = nullptr;

    //do naszej wynikowej tablicy przypisuje "pojemnik z danymi" gdznie na 1 miejscu jest większa wartość
    //oraz od razu przesuwam jej wsaźnik na kolejny, poniewaz wiemy, ze jest ona największa
    if (L1->key > L2->key){
        result = L1;
        L1 = L1->next;
    }else{
        result = L2;
        L2 = L2->next;
    }

    //last to pojemnik na przechowywanie ostatniej wartości ktora przypisaliśmy do listy wynikowej
    //przypisujemy ja tutaj, poniewaz wiemy, ze jest tam tylko 1 element
    lnode *last = result;

    //pętla do momentu az obie listy się nie "wyzerują"
    while(L1 != nullptr && L2 != nullptr){

        //tworzymy pomocnicze "pudełko" do trzymania ostatniej przypisanej wartości
        lnode * old_last = last;

        //sprawdzamy klucz w z dwoch list jest większy i przypisujemy go do kubełka "last"
        if(L1->key > L2->key){
            last = L1;
            L1 = L1->next;
        }else{
            last = L2;
            L2 = L2->next;
        }
        old_last->next = last;          //tutaj do naszej dopisujemy kolejną wartość do naszej listy
    }

    //upewnienie się, ze obie listy są puste bez tego czasami pomijany był ostatni element listy
    if (L1 != nullptr) last->next = L1;
    if (L2 != nullptr) last->next = L2;

    return result;
}

int main()
{

    lnode *L_1 = nullptr;
    lnode *L_2 = nullptr;
    lnode *merged = nullptr;

    for (int i = 1; i < 18; i++)
    {
        insert(L_1, i);
        insert(L_2, i*2);
    }


    std::cout << "Lista L_1:\n";
    wypisz(L_1);


    std::cout << "\n\nLista L_2:\n";
    wypisz(L_2);
    merged = merge(L_1, L_2);

    std::cout << "\n\nPołączona lista:\n";
    wypisz(merged);
}