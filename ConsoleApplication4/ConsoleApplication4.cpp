#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;   

vector<vector<int>> setSizeOfTable(int n, int m) {
    vector<vector<int>> table;
    //fukcja ustawia wartości i rozmiar tabeli początkowej a potem zwraca tabelę
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
    return table;
}

void showTable(int n, int m, vector<vector<int>> table) {
    //ta metoda pokazuje aktualny wygląd tablicy
    //używane są tutaj kody ascii, żeby tabela lepiej wyglądała
    for (int i = 0; i < m; i++) {
        cout << char(179);
        for (int j = 0; j < n; j++) {
            
            cout << table[i][j] << char(179);
        }
        cout << endl;
        cout << char(195);
        for (int j = 0; j < n-1; j++) {
            cout << char(196) << char(197);
        }
        cout << char(196) << char(180);
        cout << endl;
    }
}

void changePlaceOfToken(int n, int m, vector<vector<int>> table) {
    //funkcja dla każdego żetonu generuje liczbę pseudo losową wygenerowaną na podstawie czasu procesora i zamienia miejscami kązdy żeton z odpowiednim indeksem, którego numer stanowi liczba losowa
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //funkcja rand losuje liczbe od 0 do liczby, która jest szerokością tablicy, ponieważ tabice w c++ są numerowane od zera
            int random = rand() % n;
            int bufor = table[i][j];
            table[i][j] = table[i][random];
            table[i][random] = bufor;
            cout << endl;
            showTable(n, m, table);
            //zmienna do liczenia jedynek w polowie kolumn po prawej stronie
            int maxI = 0;
            //zliczanie jedynek w polowie kolumn po prawej stronie
            for (int y = 0; y < m; y++) {
                for (int x = ceil(double(n) / 2); x < n; x++) {
                    if (table[y][x] == 1) {
                        maxI++; 
                    } 
                }
            }
            cout << "Liczba 1 stanowi " << double((double(maxI) / (n * m)) * 100) << "% " << "wszystkich liczba w polowie kolumn po prawej stronie" << endl;
        }
    }
}
int main(){   
    int n;
    int m;
    
    cout << "Podaj szerokosc: ";
    cin >> n;
    cout << "Podaj wysokosc: ";
    cin >> m;
    vector < vector <int>> table = setSizeOfTable(n, m);
    cout << "Tablica poczatkowa:" << endl;
    cout << endl;
 
    showTable(n, m, table);
    changePlaceOfToken(n, m, table);
    system("PAUSE");
}

