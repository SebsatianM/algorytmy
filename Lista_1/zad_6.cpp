#include <iostream>
#include <fstream>
int main(int argc, char **argv)
{
    int ile[256]={0};                                                                //inicjalizuje tablicę licznikow
    
    if(argc < 2) {
        std:: cout << "Nie podano argumentow program nie zadziała!\n";               //sprawdzanie czy podano jakiś argument do programu
        return 0;
    }

    std::ifstream is(argv[1]);
    if(!is) {
        std::cout << "Wystąpił błąd nie da się odczytać pliku\n";                    //sprawdzanie czy argument ktory podano to nazwa pliku ktory mozna otworzyć
    }

    char c;                                                                          //inicjalizuje zmienna na znak

    while (is.get(c)){                                                               //pętla po całym plku z krokiem co jeden znak 

        ile[int(c)]++;                                                               //do tablicy o indeksie odpowiadającym odczytanemu znakowi (w intach) dodaje 1

    }

    is.close();                                                                      //zamykanie pliku

    std::cout << "Liczba wystąpień: \n";

    for (int i = 0; i <256; i++){
        std::cout << "Wartość w int: " << i << " [ " << char(i) << " ] : " <<  ile[i] << " razy\n";     //wyświetlanie wartości znaku w int'ach czyli w ASCII znaku jak wygląda oraz liczba wystąpień
                                                                                                        //wiem, ze niektore zanki (takie jak NULL, start of heading) nie sa wyswietlane ale celowo zostawiłem program takaby wyświetlał wszystko co moze w zakresie od [0 do 255)
    }

  return 0;


}