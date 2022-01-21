#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;

//klasa będzie obsługiwać wszystkie potrzebne operacje
class random {
private:
    //globalne zmienne które są rozmiarami tabeli
    int globalN;
    int globalM;
    //tablica(wektor) w której będą przechowywane wartości żetonów (tak jak na załączonym obrazku)
    vector < vector <int>> table;

public:
    void setSizeOfTable(int n, int m);
    void showTable();
    void changePlaceOfToken();

};

void random::setSizeOfTable(int n, int m) {
    globalN = n;
    globalM = m;
    //metoda ustawia wartości i rozmiar tabeli początkowej
    //w wypadku gdy szerokość tablicy jest nie parzysta, to krąglana w górę, ale liczba procentowa jedynek jest liczona tylko dla dwóch ostatnich tabel
    for (int i = 0; i < m; i++) {
        table.push_back(vector <int>());
        for (int j = 0; j < ceil(double(n)/2); j++) {
            
            table[i].push_back(1);
        }
        for (int j = ceil(double(n) / 2); j < n; j++) {
            
            table[i].push_back(0);
        }
    }
}

void random::showTable() {
    //ta metoda pokazuje aktualny wygląd tablicy
    //używane są tutaj kody ascii, żeby tabela lepiej wyglądała
    for (int i = 0; i < globalM; i++) {
        cout << char(179);
        for (int j = 0; j < globalN; j++) {
            
            cout << table[i][j] << char(179);
        }
        cout << endl;
        cout << char(195);
        for (int j = 0; j < globalN-1; j++) {
            cout << char(196) << char(197);
        }
        cout << char(196) << char(180);
        cout << endl;
    }
}

void random::changePlaceOfToken() {
    //funkcja dla każdego żetonu generuje liczbę pseudo losową wygenerowaną na podstawie czasu procesora i zamienia miejscami kązdy żeton z odpowiednim indeksem, którego numer stanowi liczba losowa
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < globalM; i++) {
        for (int j = 0; j < globalN; j++) {
            //funkcja rand losuje liczbe od 0 do liczby, która jest szerokością tablicy, ponieważ tabice w c++ są numerowane od zera
            int random = rand() % globalN;
            int bufor = table[i][j];
            table[i][j] = table[i][random];
            table[i][random] = bufor;
            cout << endl;
            showTable();
            //zmienna do liczenia jedynek w polowie kolumn po prawej stronie
            int maxI = 0;
            //zliczanie jedynek w polowie kolumn po prawej stronie
            for (int y = 0; y < globalM; y++) {
                for (int x = ceil(double(globalN) / 2); x < globalN; x++) {
                    if (table[y][x] == 1) {
                        maxI++; 
                    } 
                }
            }
            cout << "Liczba 1 stanowi " << double((double(maxI) / (globalN * globalM)) * 100) << "% " << "wszystkich liczba w polowie kolumn po prawej stronie" << endl;
        }
    }
}
int main(){   
    int n;
    int m;
    //tworzymy instancje klasy
    random r1;
    
    cout << "Podaj szerokosc: ";
    cin >> n;
    cout << "Podaj wysokosc: ";
    cin >> m;
    r1.setSizeOfTable(n, m);
    cout << "Tablica poczatkowa:" << endl;
    cout << endl;
 
    r1.showTable();
    r1.changePlaceOfToken();
    system("PAUSE");
}

