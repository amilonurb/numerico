#ifndef LU_H
#define LU_H
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<double>> vvd;

#define loop(init_var, init_value, range) for (int init_var = (init_value); init_var < (range); init_var++)
#define loop_eq(init_var, init_value, range) for (int init_var = (init_value); init_var <= (range); init_var++)

void print_matrix(const vvd &matriz, const string &title);
#endif

double sum(const vvd &a, const vvd &b, int j, int i);
void lu(const vvd &matriz);