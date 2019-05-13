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

void gauss(vvd &a, vvd &b) {
    
}

int main() {
    int n, i, j;
    cin >> n;

    cout << "Matrix Dimension: " << n << " x " << n << '\n';

    vvd a;
    loop(i, 0, n) {
        a.push_back(vector<double>(n));
        loop(j, 0, n) {
            double x;
            cin >> x;
            a[i][j] = x;
        }
    }

    vector<double> b;
    loop(i, 0, n) {
        double x;
        cin >> x;
        b.push_back(x);
    }

    gauss(a, b);
    return 0;
}