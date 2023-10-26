#include <iostream>
using namespace std;

int main() {
    int m, n, a, b, c;
    cin >> m ;
    cin >> n;
    int grafo[m+1][m+1] = {0};

    for(int i=0; i < m; i++){
        cin >> a;
        cin >> b;
        cin >> c;
        grafo[a][b] = c;
        grafo[b][a] = c;
    }


   // Imprimir a matriz
    cout<< m << endl;
    cout<< n << endl;
    for (int i = 1; i < m+1 ; i++) {
        for (int j = 1; j < m+1; j++) {
            cout << " " << grafo[i][j]; 
        }
      cout << endl;
    }
    return 0;
}
