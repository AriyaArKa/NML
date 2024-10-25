#include <bits/stdc++.h>
using namespace std;

int maxIteration = 1000;
double tolerance = 1e-6;

// Jacobi Method Function
vector<double> jacobiMethod(const vector<vector<double>>& A, const vector<double>& b, const vector<double>& initialGuess = {}) {
    int n = b.size();
    vector<double> xOld(n, 0.0);
    if (!initialGuess.empty()) {
        xOld = initialGuess;
    }
    vector<double> xNew(n, 0.0);
    vector<double> errors(n, 0.0);

    for (int iter = 0; iter < maxIteration; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * xOld[j];
                }
            }
            if (fabs(A[i][i]) < 1e-12) {
                cerr << "Zero diagonal element encountered at row " << i + 1 << endl;
                return {};
            }
            xNew[i] = (b[i] - sigma) / A[i][i];
            errors[i] = fabs(xNew[i] - xOld[i]);
        }

        // Check for convergence
        double maxError = *max_element(errors.begin(), errors.end());
        if (maxError < tolerance) {
            cout << "Jacobi method converged in " << iter + 1 << " iterations." << endl;
            return xNew;
        }
        xOld = xNew;
    }

    cout << "Jacobi method did not converge within the maximum number of iterations." << endl;
    return xNew;
}

/*

4 1 -1 3
1 5 1 7
2 1 6 10

Jacobi Method Solution:
x[1] = 0.809917
x[2] = 0.991735
x[3] = 1.231405

*/

// Testing the Jacobi Method

void takeInputforLinear() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));

    // Display augmented matrix format
    cout << "\nThe augmented matrix format is as follows (each row has " << n + 1 << " coefficients):" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "|";
        for (int j = 1; j <= n; ++j) {
            cout << " a" << i << j;
        }
        cout << " | b" << i << " |" << endl;
    }
    cout << "\nEnter the augmented matrix coefficients:" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cin >> augmentedMatrix[i][j];
        }
    }

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = augmentedMatrix[i][j];
        }
        b[i] = augmentedMatrix[i][n];
    }

    vector<double> initialGuess(n, 0.0);
    vector<double> jacobiSolution = jacobiMethod(A, b, initialGuess);
    cout << "\nJacobi Method Solution:" << endl;
    for (size_t i = 0; i < jacobiSolution.size(); ++i) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << jacobiSolution[i] << endl;
    }
}

// Function to evaluate polynomial at a given x
double f(const vector<double>& coef, double x) {1

=======
// Function to evaluate polynomial at a given x
double f(const vector<double>& coef, double x) {
>>>>>>> 2a884421707a8c0b4f91fe485fc90629c253efc6
    double sum = 0.0;
    int n = coef.size();
    for (int i = 0; i < n; ++i) {
        sum += coef[i] * pow(x, n - i - 1);
    }
    return sum;
}

// Function to evaluate derivative of polynomial at a given x
double fPrime(const vector<double>& coef, double x) {
    double sum = 0.0;
    int n = coef.size();
    for (int i = 0; i < n - 1; ++i) {
        sum += (n - i - 1) * coef[i] * pow(x, n - i - 2);
    }
    return sum;
}

// Newton-Raphson method
vector<double> newtonRaphson(const vector<double>& coef, double tolerance = 0.0001) {
    int iteration = 0;
    double x = 0.0;
    vector<double> root(1);

    while (true) {
        iteration++;
        double f_x = f(coef, x);
        double f_prime_x = fPrime(coef, x);

        if (fabs(f_prime_x) < 1e-12) {
            cout << "Derivative too small, stopping iteration." << endl;
            return {};
        }

        double xNew = x - f_x / f_prime_x;

        if (fabs(xNew - x) <= tolerance || fabs(f_x) <= tolerance) {
            cout << "[+] Found Root: " << xNew << endl;
            cout << "[+] Iterations Required: " << iteration << endl;
            root[0] = xNew;
            return root;
        }

        x = xNew;
    }
}

// Bisection method
vector<double> biSection(const vector<double>& coef, int maxIter, double tolerance, double a, double b) {
    cout << endl << "Bisection Method:" << endl;
    vector<double> root(1);

    if (f(coef, a) * f(coef, b) >= 0) {
        cout << "Invalid interval [a, b]." << endl;
        return {};
    }

    double c, f_c;
    for (int iter = 0; iter < maxIter; ++iter) {
        c = (a + b) / 2.0;
        f_c = f(coef, c);

        if (fabs(f_c) <= tolerance) {
            cout << "Found Root: " << c << endl;
            root[0] = c;
            return root;
        }

        if (f(coef, a) * f_c < 0) {
            b = c;
        } else {
            a = c;
        }

        cout << "Iteration " << iter + 1 << ": c = " << c << endl;
    }

    cout << "Max iterations reached without convergence." << endl;
    return {};
}

// Gauss Elimination method
vector<double> gaussElimination(vector<vector<double>> matrix) {
    int n = matrix.size();

    // Forward elimination
    for (int j = 0; j < n - 1; ++j) {
        // Partial pivoting
        int maxRow = j;
        for (int i = j + 1; i < n; ++i) {
            if (fabs(matrix[i][j]) > fabs(matrix[maxRow][j])) {
                maxRow = i;
            }
        }
        swap(matrix[j], matrix[maxRow]);

        for (int i = j + 1; i < n; ++i) {
            double factor = matrix[i][j] / matrix[j][j];
            for (int k = j; k <= n; ++k) {
                matrix[i][k] -= factor * matrix[j][k];
            }
        }
    }

    // Back substitution
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    return solution;
}

// Gauss-Jordan Elimination method
vector<double> gaussJordanElimination(vector<vector<double>> matrix) {
    int n = matrix.size();

    for (int j = 0; j < n; ++j) {
        // Partial pivoting
        int maxRow = j;
        for (int i = j + 1; i < n; ++i) {
            if (fabs(matrix[i][j]) > fabs(matrix[maxRow][j])) {
                maxRow = i;
            }
        }
        swap(matrix[j], matrix[maxRow]);

        // Make pivot element 1
        double pivot = matrix[j][j];
        if (fabs(pivot) < 1e-12) {
            cout << "Zero pivot encountered, no unique solution." << endl;
            return {};
        }
        for (int k = j; k <= n; ++k) {
            matrix[j][k] /= pivot;
        }

        // Eliminate other entries in column
        for (int i = 0; i < n; ++i) {
            if (i != j) {
                double factor = matrix[i][j];
                for (int k = j; k <= n; ++k) {
                    matrix[i][k] -= factor * matrix[j][k];
                }
            }
        }
    }

    // Extract solution
    vector<double> solution(n);
    for (int i = 0; i < n; ++i) {
        solution[i] = matrix[i][n];
    }

    return solution;
}

void mainMenu() {
    cout << "******** NUMERICAL METHODS CONSOLE APPLICATION ********\n";
    cout << "Select a category:\n";
    cout << "1. Linear Equations\n";
    cout << "2. Non-linear Equations\n";
    cout << "3. Differential Equations\n";
    cout << "4. Matrix Operations\n";
    cout << "0. Exit\n";  // Press 0 in the main menu to exit the program
    cout << "Enter your choice: ";
}

void linearMenu() {
    cout << "Select a linear equation solving method:\n";
    cout << "1. Jacobi Method\n";
    cout << "2. Gauss-Seidel Method\n";
    cout << "3. Gauss Elimination\n";
    cout << "4. Gauss-Jordan Elimination\n";
    cout << "5. LU Factorization\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void nonlinearMenu() {
    cout << "Select a non-linear equation solving method:\n";
    cout << "1. Bisection Method\n";
    cout << "2. False Position Method\n";
    cout << "3. Secant Method\n";
    cout << "4. Newton-Raphson Method\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void diffEqMenu() {
    cout << "Select a differential equation solving method:\n";
    cout << "1. Runge-Kutta Method (4th Order)\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void matrixMenu() {
    cout << "Select a matrix operation method:\n";
    cout << "1. Matrix Inversion\n";
    cout << "0. Return to Main Menu\n";
    cout << "Enter your choice: ";
}

void solveLinear(int methodChoice) {
    cout << "Solving linear equation using method " << methodChoice << endl;
}

void solveNonlinear(int methodChoice) {
    cout << "Solving non-linear equation using method " << methodChoice << endl;
}

void solveDifferential(int methodChoice) {
    cout << "Solving differential equation using method " << methodChoice << endl;
}

void solveMatrix(int methodChoice) {
    cout << "Performing matrix operation using method " << methodChoice << endl;
}

int main() {
    int mainChoice, methodChoice;

    while (true) {
        mainMenu();
        cin >> mainChoice;

        if (mainChoice == 0) {
            cout << "Exiting the program.\n";
            break;
        }

        switch (mainChoice) {
            case 1:  // Linear Equations
                while (true) {
                    linearMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveLinear(methodChoice);
                }
                break;
            case 2:  // Non-linear Equations
                while (true) {
                    nonlinearMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveNonlinear(methodChoice);
                }
                break;
            case 3:  // Differential Equations
                while (true) {
                    diffEqMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveDifferential(methodChoice);
                }
                break;
            case 4:  // Matrix Operations
                while (true) {
                    matrixMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;
                    solveMatrix(methodChoice);
                }
                break;
            default:
                cout << "Invalid choice! Please select a valid option.\n";
                break;
        }
    }

    return 0;
}
