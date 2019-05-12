#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> vvd;

void lu(const vvd &matriz) {
    
    int n = matriz[0].size();

    vvd lower = vvd(n, vector<double>(n));
    vvd upper = vvd(n, vector<double>(n));

    int i, j, k;

    cout << "Matriz A\n";
    for (i = 0; i < matriz[0].size(); i++) {
        for (j = 0; j < matriz.size(); j++) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }

    for (j = 0; j < n; j++) {
        lower[j][j] = 1;
        for (i = 0; i <= j; i++) {
            double sum = 0.0;
            for (k = 0; k < i; k++) {
                sum += upper[k][j] * lower[i][k];
            }
            upper[i][j] = matriz[i][j] - sum;
        }

        for (i = j; i < n; i++) {
            double sum = 0.0;
            for (k = 0; k < i; k++) {
                sum += upper[k][j] * lower[i][k];
            }
            lower[i][j] = (matriz[i][j] - sum) / upper[j][j];
        }
    }

    cout << "\nMatriz L\n";
    for (i = 0; i < lower[0].size(); i++) {
        for (j = 0; j < lower.size(); j++) {
            cout << lower[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "\nMatriz U\n";
    for (i = 0; i < upper[0].size(); i++) {
        for (j = 0; j < upper.size(); j++) {
            cout << upper[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    std::setlocale(LC_ALL, "Portuguese");

    cout << "RESOLUÇÃO DE SISTEMAS LINEARES (Ax = b) POR DECOMPOSIÇÃO LU\n\n";

    int n;
    cout << "1. Entre com a dimensão do sistema linear: ";
    cin >> n;

    cout << "2. ENTRADA DE DADOS\n";
    vvd matriz;
    for (int i = 0; i < n; i++) {
        matriz.push_back(vector<double>(n));
        cout << "Equação " << (i + 1) << ":\n";
        for (int j = 0; j < n; j++) {
            double a;
            cout << "Valor do coeficiente " << (j + 1) << ": ";
            cin >> a;
            matriz[i][j] = a;
            cout << endl;
        }
    }

    //vvd m1 = { { 2, -1, -2 }, { -4, 6, 3 }, { -4, -2, 8 } };
    // vvd m2 = { { 8, -4, -2 }, { -4, 10, -2 }, { -2, -2, 10 } };

    lu(matriz);
    // lu(m2);
    
    return 0;
}
