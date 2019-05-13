#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> vvd;

#define loop(init_var, init_value, range) for (init_var = init_value; init_var < range; init_var++)
#define loop_eq(init_var, init_value, range) for (init_var = init_value; init_var <= range; init_var++)

void print_matrix(const vvd &matriz, const string &title) {
    cout << title << '\n';
    int i, j;
    loop(i, 0, matriz[0].size()) {
        loop(j, 0, matriz[i].size()) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }
}

double sum(const vvd &a, const vvd &b, int j, int i) {
    double sum = 0.0;
    int k;
    loop(k, 0, i) {
        sum += a[k][j] * b[i][k];
    }
    return sum;
}

void lu(const vvd &matriz) {
    int n = matriz[0].size(), i, j;

    vvd lower = vvd(n, vector<double>(n));
    vvd upper = vvd(n, vector<double>(n));

    print_matrix(matriz, "Matriz A");

    loop(j, 0, n) {
        lower[j][j] = 1;
        loop_eq(i, 0, j) {
            upper[i][j] = matriz[i][j] - sum(upper, lower, j, i);
        }

        loop(i, j, n) {
            lower[i][j] = (matriz[i][j] - sum(upper, lower, j, i)) / upper[j][j];
        }
    }
    
    cout << '\n';
    print_matrix(lower, "Matriz L");

    cout << '\n';
    print_matrix(upper, "Matriz U");
}

int main() {
    int n, i, j;
    cin >> n;

    cout << "Matrix Dimension: " << n << " x " << n << '\n';

    vvd matriz;
    loop(i, 0, n) {
        matriz.push_back(vector<double>(n));
        loop(j, 0, n) {
            double a;
            cin >> a;
            matriz[i][j] = a;
        }
    }

    lu(matriz);
    
    /*
     * TEST
     */
    // vvd m = { { 8, -4, -2 }, { -4, 10, -2 }, { -2, -2, 10 } };
    // lu(m);
    return 0;
}