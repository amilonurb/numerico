package exatos;

import java.math.BigDecimal;

public class DecomposicaoLU {

	public static void lu(double a[][]) {

		double lower[][] = new double[a[0].length][a.length];
		double upper[][] = new double[a[0].length][a.length];

		System.out.println("Matriz A");
		for (int i = 0; i < a[0].length; i++) {
			for (int j = 0; j < a.length; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}

		int n = a[0].length;

		System.out.println("N = " + n);

		for (int j = 0; j < n; j++) {
			lower[j][j] = 1;
			for (int i = 0; i <= j; i++) {
				double sum = BigDecimal.ZERO.doubleValue();
				for (int k = 0; k < i; k++) {
					sum += upper[k][j] * lower[i][k];
				}
				upper[i][j] = a[i][j] - sum;
			}

			for (int i = j; i < n; i++) {
				double sum = BigDecimal.ZERO.doubleValue();
				for (int k = 0; k < i; k++) {
					sum += upper[k][j] * lower[i][k];
				}
				lower[i][j] = (a[i][j] - sum) / upper[j][j];
			}
		}

		System.out.println();
		System.out.println("Matriz L");
		for (int i = 0; i < lower[0].length; i++) {
			for (int j = 0; j < lower.length; j++) {
				System.out.print(lower[i][j] + " ");
			}
			System.out.println();
		}

		System.out.println();
		System.out.println("Matriz U");
		for (int i = 0; i < upper[0].length; i++) {
			for (int j = 0; j < upper.length; j++) {
				System.out.print(upper[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		double a[][] = new double[][] { { 2, -1, -2 }, { -4, 6, 3 }, { -4, -2, 8 } };
		lu(a);
	}

}
