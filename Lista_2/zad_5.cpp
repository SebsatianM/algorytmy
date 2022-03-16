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

void reverse(lnode *&L)
{

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

void destroy(lnode *&L)
{
    L = nullptr;
}

int main()
{

    lnode *L = nullptr;

    for (int i = 1; i < 11; i++)
    {
        insert(L, i);
    }

    std::cout << "\n";
    wypisz(L);

    reverse(L);

    std::cout << "\n";
    wypisz(L);
}