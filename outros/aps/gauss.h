
#ifndef GAUSS_H
#define GAUSS_H
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> vvd;
#define loop(init_var, init_value, range) for (int init_var = (init_value); init_var < (range); init_var++)
#define loop_eq(init_var, init_value, range) for (int init_var = (init_value); init_var <= (range); init_var++)

void print_matrix(const vvd &matriz, const string &title);
#endif

typedef vector<double> vd;

#define each(element, collection) for (auto &element : collection)
#define loop_rv(init_var, init_value, range) for (int init_var = (init_value); init_var >= (range); init_var--)

void print_vector(const vd &vetor, const string &title);
void solveGauss(vvd &a, vd &b);
void solveLinearSystem(const vvd &a, const vd &b);