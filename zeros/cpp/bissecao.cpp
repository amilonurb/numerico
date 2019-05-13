#include <bits/stdc++.h>

using namespace std;

#define MAX_ITERATIONS 100
#define EPS 1e-5;

void show_max_iterations_error() {
    cout << "Valor não encontrado após " << MAX_ITERATIONS << " iterações :(\n";
}

int max_iterations(double a, double b) {
    return (int)((abs(log(b - a) - log(EPS))) / log(2));
}

double f(double x) {
    // TODO: Função
    return MAX_DOUBLE;
}

void bissecao(double a, double b) {
    int max_it = max_iterations(a, b);
    for (int i = 1; i <= max_it; i++) {

        double x = (a + b) / 2.0;
        double fx = f(x);

        // TODO: ajustar esse erro
        if ((fx < EPS) || (fabs(b - a) < (EPS * max({1., fabs(b)})))) {
            cout << "Raiz encontrada em x ~ " << x << '\n';
            return;
        }

        double fa = f(x);
        double fb = f(b);

        if ((fa * fb) < EPS) {
            b = x;
        } else {
            a = x;
        }
    }
    show_max_iterations_error();
}

int main() {
    return 0;
}