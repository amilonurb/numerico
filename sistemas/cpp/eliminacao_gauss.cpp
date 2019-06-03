#include <bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

#define loop(init_var, init_value, range) for (int init_var = (init_value); init_var < (range); init_var++)
#define loop_eq(init_var, init_value, range) for (int init_var = (init_value); init_var <= (range); init_var++)
#define loop_rv(init_var, init_value, range) for (int init_var = (init_value); init_var >= (range); init_var--)
#define each(element, collection) for (auto &element : collection)

void print_vetor(vd&, string&);
void print_matriz(vvd&, string&);
void solveGauss(vvd&, vd&);
void solveLinearSystem(vvd&, vd&);

int main() {
    vvd a = {
        {2.0, 3.0, -1.0},
        {4.0, 4.0, -3.0},
        {2.0, -3.0, 1.0}
    };

    vd b = {5.0, 3.0, -1.0};

    solveGauss(a, b);
    return 0;
}

void print_vetor(vd &vetor, const string &title) {
    cout << title << '\n';
    each(v, vetor) {
        cout << v << '\t';
    }
    cout << endl;
}

void print_matriz(vvd &matriz, const string &title) {
    cout << title << '\n';
    loop(i, 0, matriz[0].size()) {
        loop(j, 0, matriz[i].size()) {
            cout << matriz[i][j] << '\t';
        }
        cout << endl;
    }
}

void solveGauss(vvd &a, vd &b) {
    int n = b.size();
    loop(k, 0, n - 1) {
        /**
         * Checa se é preciso realizar troca de linhas.
         * Isso é necessário quando o pivô corrente é nulo.
         * 
         * Caso positivo, tenta-se fazer uma técnica chamada de pivotamento parcial.
         */
        if (a[k][k] == 0.0) {
            /**
             * Pivotamento Parcial
             * 
             * Seja p o menor inteiro, tal que |a[p][n]| =     max |a[j][k]|
             *                                             k <= j <= n
             * e k <= p <= n.
             * 
             * Se a[p][k] = 0, não existe solução única para o sistema linear.
             * 
             * Se p <> k, troca-se as linhas a[k] e a[p].
             */
            int p = k;
            int a_max = fabs(a[p][k]);
            loop(j, k, n) {
                if (fabs(a[j][k]) > a_max) {
                    a_max = fabs(a[j][k]);
                    p = j;
                }
            }
            
            if (a[p][k] == 0.0) {
                cout << "Sistema com muitas solucoes ou nao tem solucao\n";
                return;
            }

            if (p != k) {
                swap(a[p], a[k]);
                swap(b[p], b[k]);
            }            
        }

        loop(i, k + 1, n) {
            double m = a[i][k] / a[k][k];
            loop(j, k, n) {
                a[i][j] = a[i][j] - m * a[k][j];
            }
            b[i] = b[i] - m * b[k];
        }
    }
    solveLinearSystem(a, b);
}

void solveLinearSystem(vvd &a, vd &b) {
    int n = b.size();
    vd x = vd(n);
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    
    if (a[n - 1][n - 1] == 0.0) {
        cout << "\nSistema com muitas solucoes ou nao tem solucao\n";
        return;
    }

    loop_rv(i, n - 1, 0) {
        double sum = 0.0;
        loop(j, i + 1, n) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
        if (a[i][i] == 0.0) {
            cout << "\nSistema com muitas solucoes ou nao tem solucao\n";
            return;
        }
    }

    cout << "\nSolucao do Sistema\n";
    loop(i, 0, x.size()) {
        cout << "X[" << (i + 1) << "] = " << x[i] << '\t';
    }
    cout << endl;
}