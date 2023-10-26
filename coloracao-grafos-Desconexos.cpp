#include <iostream>
#include <chrono>

using namespace std;

int main() {
    char dom[] = {' ', 'A', 'B', 'C', 'D', 'E'};
    int atual = 1, x = 1;
    int m, n, a, b, c, qtdDom = 0;

    cin >> m ;
    cin >> n;
    int grafo[m+1][m+1] = {0};
    char var[m + 1] = {0};

    for(int i=0; i < n; i++){
        cin >> a;
        cin >> b;
        cin >> c;
        grafo[a][b] = c;
        grafo[b][a] = c;
    }
    
    cout<< m << endl;
    cout<< n << endl;
    for (int i = 1; i < m+1 ; i++) {
        for (int j = 1; j < m+1; j++) {
            cout << " " << grafo[i][j]; 
        }
      cout << endl;
    }


     auto start = std::chrono::high_resolution_clock::now();
   while (x != m+1 ) {
        int y = 1;
        bool pass; //variavel para checar se os vizinhos       

        do {
            if(y>qtdDom)
                qtdDom = y;

            var[atual] = dom[y];
            pass = false;  
            for (int i = 1; i < m + 1; i++) { //vare os visinhos
                if (grafo[atual][i]) {
                    if(var[i] == var[atual]){
                        pass = true;
                        break;
                    }                 
                }
            }
            if (pass) {
                y++;  // incrementa o dominio
            }
        } while (pass);
      atual++;
      x++;
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "tempo de execucao: " << duration.count() << endl;

    cout << "quantidade de dominios utilizados: " << qtdDom << endl;
    
    for (int i = 1; i < m +1; i++) {
        cout << "Vertice " << i << ": " << var[i] << endl;
    }

    return 0;
}



