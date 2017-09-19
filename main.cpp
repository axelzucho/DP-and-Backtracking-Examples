Límite de entrega: 25 sept. 23:59
Tarea No. 3. Disen~o de algoritmos


Vicente Cubells Nonell
7:00
Añadir un comentario de la clase
Ver orientaciones en el documento anexo.

Tarea No. 3. Disen~o de algoritmos
Documentos de Google
Tu trabajo
ENTREGA ANULADA
Tu profesor puede ver y editar los archivos que añadas o crees

main.cpp
C++
AÑADIR
CREAR
ENTREGAR

Añade un comentario privado…

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int row[10000], a, b, lineCounter;
bool solution[1000][1000];

bool place(int r, int c){
    for(int prev = 0; prev < c; ++prev)
        if(row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) return false;
    return true;
}

bool backtrack(int c, int n, int m){
    if(n > m) {
        cout << "Can't place this number of queens!\n";
        return false;
    }
    if(c == n){
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
                if(solution[i][j]) cout << "Queen number " << i+1 << " in row: " << i+1 << " and column: " << j+1 << "\n";
        return true;
    }
    for(int r = 0; r < n; ++r)
        if(place(r,c)) {
            solution[r][c] = true;
            row[c] = r;
            if(backtrack(c+1, n, m)) return true;
        }
    for(int i = c-1; i < n; ++i){
        for(int j = 0; j < n; ++j){
            solution[j][i] = false;
        }
    }
    return false;
}

bool pairCompare(pair<int,int>& firstElem, pair<int,int>& secondElem) {
    return firstElem.first < secondElem.first;

}

float Mochila(vector<int> arr, int max, int * solution){
    sort(arr.begin(), arr.end());
    float peso = 0;
    int i = 0;
    while((peso < max) && i < arr.size()){
        if((arr[i] + peso) <= max) solution[i] = 1;
        else solution[i] = 0;
        peso = peso + solution[i]*arr[i];
        ++i;
    }
    return peso;
}

int fontaneroDiligente(vector<pair<int,int>> arr){
    sort(arr.begin(), arr.end(), pairCompare);
    int insatisfaccion = 0;
    for(int i = 0; i < arr.size(); ++i){
        insatisfaccion += insatisfaccion + arr[i].first;
        cout << "Elemento agregado: " << arr[i].second <<"\n";
    }
    return insatisfaccion;
}


int main() {
    int n, m;
    cin >> n >> m;
    memset(row,0,sizeof(row));
    memset(solution,false,sizeof(solution));
    backtrack(0, n, m);
}