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

// void insertion_sort(lnode *&L)
// {
    
    // if( L == nullptr || L->next == nullptr ) return;                                                    //zabezpieczenie czy lista nie jest pusta lub 1 elementowa
    // lnode* sorted = nullptr;                                                                            //do trzymania posortowanej listy 
    // lnode* not_sorted = L;                                                                              //pomocnicza do przechodzenia przez listę zeby nie modyfikować pierowtnej listy w pętli

//     while (not_sorted!=nullptr)
//         {    
//             lnode* current = not_sorted;                                                                //pobieramy obecną wartość z listy
//             if (sorted == nullptr || current->key >= sorted->key)                                       //sprawdzamy czy nasza posortowana lista nie jest pusta lub obecna wartość jest większa lub rowna wartości w posortowanej liście
//             {
//                 current->next = sorted;                                                                 //wskazujemy kolejny element obecnej "wartości" na dotychczasową posortowaną listę
//                 sorted = current;                                                                       //zapisujemy posortowaną listę ze wstawionym elementem na przodzie listy 
//             }else
//             {
//                 lnode* curSorted = sorted;                                                              //kolejna pomocniczna zmienna, dla pamieci porownywania liczb, tutaj rosnie wielkosc listy
//                 while (curSorted!= nullptr)                                                            
//                 {
//                     if (!curSorted->next || current->key >= curSorted->next->key)                        //jesli nastepny klucz obecnej zmiennej nie jest null albo liczba z current jest mniejsza od nastepnego currenta
//                     {
//                         current->next = curSorted->next;                                                //przypisanie do nastepnego current obecnego sorta
//                         curSorted->next = current;                                                      //prawie to samo, zamiana miejsc
//                         break;                                                                          //by mi sie nie zapetlilo 
//                     }
//                     curSorted = curSorted->next;                                                        //wklepujemy curenta na nastepne miejsce
//                 }
//             }
//             not_sorted = not_sorted->next;                                                              //przechodzimy do kolejnego elementu w nieposrtowanej tablicy
//         }

//         L = sorted;                                                                                     //nadpisanie listy nowa
//         reverse(L);                                                                                     //odwracanie listy
    
// }
void insertion_sort(lnode *&L)
{

    if( L == nullptr || L->next == nullptr ) return;                                                    //zabezpieczenie czy lista nie jest pusta lub 1 elementowa
    lnode* sorted = nullptr;                                                                            //do trzymania posortowanej listy 
    lnode* not_sorted = L;                                                                              //pomocnicza do przechodzenia przez listę zeby nie modyfikować pierowtnej listy w pętli

    while (not_sorted != nullptr) 
    {
        lnode* current = not_sorted;                                                                    //pobieramy obecną wartość z listy
        not_sorted = not_sorted->next;                                                                  //przechodzimy do kolejnego elementu w nieposrtowanej tablicy
        if (sorted == nullptr || current->key >= sorted->key)                                           //sprawdzamy czy nasza posortowana lista nie jest pusta lub obecna wartość jest większa lub rowna wartości w posortowanej liście
        {
            current->next = sorted;                                                                     //wskazujemy kolejny element obecnej "wartości" na dotychczasową posortowaną listę
            sorted = current;                                                                           //zapisujemy posortowaną listę ze wstawionym elementem na przodzie listy
        } else
        {
        lnode* current_sorted = sorted;
           while (current_sorted != nullptr)
                {
                    if (current_sorted->next == nullptr || current->key > current_sorted->next->key)    //praktycznie tak samo jak w if'ie wyzej 
                    {
                        current->next = current_sorted->next;
                        current_sorted->next = current;
                    }
                    current_sorted = current_sorted->next;                                              
                }
        }
                                                        
    }

    L = sorted;                                                                                         //nadpisujemy liste nowa juz posortowaną
    reverse(L);                                                                                         //odwracamy liste
}
int main()
{
    lnode* L = nullptr;
    insert(L, 7);
    insert(L, 13);
    insert(L, -3);
    insert(L, 2);
    insert(L, -9);
    insert(L, 4);
    
    std::cout << "Nie osortowana lista: ";
    wypisz(L);
    std::cout << "\nPosortowana lista: ";
    insertion_sort(L);
    wypisz(L);
}