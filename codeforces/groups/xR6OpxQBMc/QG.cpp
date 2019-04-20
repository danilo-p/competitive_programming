#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> pratos;
    vector<bool> pratos_usados;
    vector<int> paginas;
    int n, m, i, j, k, c;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> c;
        pratos.push_back(c);
        pratos_usados.push_back(false);
    }
    for (i = 0; i < m; i++) {
        cin >> c;
        paginas.push_back(-c);
    }

    sort(pratos.begin(), pratos.end());
    sort(paginas.begin(), paginas.end());

    j = n - 1;
    k = 0;
    for (i = 0; i < m; i++) {
        paginas[i] = -paginas[i];

        // Encaixa os maiores
        while (j >= 0 && paginas[i] > 0) {
            if (pratos_usados[j] || paginas[i] - pratos[j] < 0) {
                j--;
                continue;
            }

            paginas[i] -= pratos[j];
            pratos_usados[j] = true;
            j--;
        }

        // Encaixa os menores
        while (k < n && paginas[i] > 0) {
            if (pratos_usados[k] || paginas[i] - pratos[k] < 0) {
                k++;
                continue;
            }

            paginas[i] -= pratos[k];
            pratos_usados[k] = true;
            k++;
        }
    }

    bool todos_usados = true;
    for (i = 0; i < n; i++) {
        if (!pratos_usados[i]) {
            todos_usados = false;
            break;
        }
    }

    if (todos_usados) cout << "sim" << endl;
    else  cout << "nao" << endl;

    return 0;
}