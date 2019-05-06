#include <bits/stdc++.h>

using namespace std;

int main() {
    std::setlocale(LC_ALL, NULL);

    cout << "RESOLUÇÃO DE SISTEMAS LINEARES (Ax = b) POR DECOMPOSIÇÃO LU\n\n";

    int n;
    cout << "1. Entre com a dimensão do sistema linear: ";
    cin >> n;

    cout << "2. ENTRADA DE DADOS";
    int x;
    vector<vector<int>> matriz;
    for (int i = 0; i < n; i++) {
        matriz.push_back(vector<int>(n));
        cout << "Equação " << (i + 1) << ":\n";
        for (int j = 0; j < n; j++) {
            int a;
            cout << "Valor do coeficiente " << (j + 1) << ": ";
            cin >> a;
            matriz[i][j] = a;
            cout << endl;
        }
    }
    
    return 0;
}
