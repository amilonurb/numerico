#include <bits/stdc++.h>
#include "lu.h"
#include "gauss.h"

vvd preencher_matriz_quadrada(int n);
vd preencher_vetor(int n);

int main() {
    cout << "Metodos Numericos Computacionais\n";
    cout << "Atividade Pratica Supervisionada - APS\n";
    cout << endl;

    int opcao, n;
    while (true) {
        cout << "Escolha uma das opcoes abaixo";
        cout << "1 - Decomposicao LU\n";
        cout << "2 - Eliminacao de Gauss\n";
        cout << "2 - Sair\n";
        cout << "Opcao:> ";
        cin >> opcao;

        cout << "\n\n";
        system("cls | clear");

        if (opcao == 3) {
            break;
        }

        if (opcao == 1) {
            cout << "Opcao escolhida: LU";
            cout << "Dimensao da matriz: ";
            cin >> n;
            vvd matriz_a = preencher_matriz_quadrada(n);
            lu(matriz_a);
        } else if (opcao == 2) {
            cout << "Dimensao da matriz: ";
            cin >> n;
            vvd matriz_a = preencher_matriz_quadrada(n);
            vd vetor_b = preencher_vetor(n);
            gauss(a, b);
        } else {
            cout << "Opcao Invalida!!!\n";
        }
    }
    return 0;
}

vvd preencher_matriz_quadrada(int n) {
    double x;
    vvd matriz;
    loop(i, 0, n) {
        vvd linha;
        loop(j, 0, n) {
            cin >> x;
            linha.push_back(x);
        }
        matriz.push_back(linha);
    }
    return matriz;
}

vd preencher_vetor(int n) {
    double x;
    vd vetor;
    loop(i, 0, n) {
        cin >> x;
        vetor.push_back(x);
    }
    return vetor;
}