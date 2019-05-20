public class EliminacaoGaussiana {
    
    public static void solveGauss(double a[][], double b[]) {
        
        System.out.println("Matriz A Não Triangularizada");
        for (int i = 0; i < a[0].length; i++) {
            for (int j = 0; j < a.length; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
        
        System.out.println();
        
        System.out.println("Vetor B Não Ajustado");
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i] + "\t");
        }
        
        System.out.println();
        System.out.println();
        
        int n = b.length;
        
        /**
         * Processo de Triangulação
         */
        for (int k = 0; k < n - 1; k++) {
            
            for (int i = k + 1; i < n; i++) {
                
                double m = a[i][k] / a[k][k];
                
                for (int j = k; j < n; j++) {
                    
                    a[i][j] = a[i][j] - m * a[k][j];
                    
                }
                
                b[i] = b[i] - m * b[k];
            }
            
        }
        
        System.out.println("Matriz A Triangularizada");
        for (int i = 0; i < a[0].length; i++) {
            for (int j = 0; j < a.length; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
        
        System.out.println();
        
        System.out.println("Vetor B");
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i] + "\t");
        }
        
        System.out.println();
        System.out.println();
        solveLinerSystem(a, b);
    }
    
    private static void solveLinerSystem(double a[][], double b[]) {
        int n = b.length;
        double x[] = new double[n];
        x[n - 1] = b[n - 1] / a[n - 1][n - 1];
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0.0;
            for (int j = i + 1; j < n; j++) {
                sum += a[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / a[i][i];
        }
        
        System.out.println("Solução do sistema");
        for (int i = 0; i < x.length; i++) {
            System.out.print("X[" + (i + 1) + "] = " + x[i] + "\t");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        double a[][] = new double[][] {
            {2.0, 3.0, -1.0},
            {4.0, 4.0, -3.0},
            {2.0, -3.0, 1.0}
        };
        
        double b[] = {5.0, 3.0, -1.0};
        
        solveGauss(a, b);
    }
}