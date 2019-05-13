# -*- coding: utf-8 -*-
def print_matrix(matrix, title):
    if not(title is None):
        print(title)
    
    n = len(matrix[0])
    for i in range(n):
        m = len(matrix[i])
        for j in range(m):
            print(matrix[i][j], end = ' ')
        print()

def lu(matriz):
    n = len(matriz[0])
    lower = [[float(0)] * n] * n
    upper = [[float(0)] * n] * n
    
    print_matrix(matriz, 'Matriz A')
    
    for j in range(n):
        lower[j][j] = float(1)
        for i in range(j + 1):
            soma = float(0)
            for k in range(i):
                soma += upper[k][j] * lower[i][k]
            upper[i][j] = matriz[i][j] - soma
        
        for i in range(j, n):
            soma = float(0)
            for k in range(i):
                soma += upper[k][j] * lower[i][k]
            lower[i][j] = (matriz[i][j] - soma) / upper[j][j]

    print_matrix(lower, 'Matriz L')
    print_matrix(upper, 'Matriz U')

matriz = [[8.0, -4.0, -2.0], [-4.0, 10.0, -2.0], [-2.0, -2.0, 10.0]]
lu(matriz)