#include <iostream>
#include <queue>
#include <chrono>

using namespace std;

bool busca(int valor, queue<int> lista) {
    for (int i = 0; i < lista.size(); i++) {

        if (lista.front() == valor) {
            return true;
        }
        lista.pop();
    }
    return false; 
}

int main() {
    char dom[] = {' ', 'A', 'B', 'C', 'D', 'E'};
    int atual, m, n, a, b, c, qtdDom = 0;
    queue<int> avisitar;

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

    // cout<< m << endl;
    // cout<< n << endl;
    // for (int i = 1; i < m+1 ; i++) {
    //     for (int j = 1; j < m+1; j++) {
    //         cout << " " << grafo[i][j]; 
    //     }
    //   cout << endl;
    // }
    
    avisitar.push(1);
   // auto start = chrono::steady_clock::now();

    while (!avisitar.empty()) {
        int y = 1;
        bool pass; //variavel para checar se os vizinhos
        atual = avisitar.front();
        avisitar.pop();

        do {
            var[atual] = dom[y];
            pass = false;  
            if(y>qtdDom)
                qtdDom = y;
                
            for (int i = 1; i < m + 1; i++) { //vare os visinhos
                if (grafo[atual][i]) {
                    if(var[i] == var[atual]){
                        pass = true;
                        break;
                    } else if(!var[i] && !busca(i, avisitar)) {
                        avisitar.push(i);                      
                    }                   
                }
            }
            if (pass) {
                y++;  // incrementa o dominio
            }
        } while (pass);
      
    }

    // auto end = chrono::steady_clock::now();

    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // cout << "tempo de execucao: " << duration << endl;
    cout << "quantidade de dominios utilizados: " << qtdDom << endl;
    for (int i = 1; i < m + 1; i++) {
        cout << "Vertice " << i << ": " << var[i] << endl;
    }

    return 0;
}
