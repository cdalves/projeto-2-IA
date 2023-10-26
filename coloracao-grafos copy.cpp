#include <iostream>
#include <queue>

using namespace std;

int main() {
    char dom[] = {' ', 'A', 'B', 'C', 'D', 'E'};
    int atual = 1, x = 1;
    int m, n, a, b;
    queue<int> avisitar;

    cin >> m;
    cin >> n;

    int grafo[m + 1][m + 1] = {0};
    char var[m + 1] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        grafo[a][b] = 1;
        grafo[b][a] = 1;
    }

    while (x != m + 1) {
        int y = 1;
        bool pass;

        do {
            var[atual] = dom[y];
            pass = false;

            for (int i = 1; i < m + 1; i++) {
                if (grafo[atual][i] && var[i] != var[atual]) {
                    pass = false;
                    y++;
                    break;
                } else if (!var[i]) {
                    pass = true;
                    
                }
            }
        } while (pass);

        atual = avisitar.front();
        avisitar.pop();
        x++;

    }

    for (int i = 1; i < m + 1; i++) {
        cout << "Vertice " << i << ": " << var[i] << endl;
    }

    return 0;
}