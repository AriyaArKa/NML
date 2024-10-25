#include <bits/stdc++.h>
using namespace std;

int n;
void gauss_elimination()
{
    for(int j=1;j<n;j++)
    {
        for(int i=n;i>j;i--)
        {
            if(a[i][j]==0) continue;
            int lcm=a[j][j]*a[i][j]/__gcd(a[j][j],a[i][j]);
            int up=lcm/a[j][j], nic=lcm/a[i][j];
            for(int k=1;k<=n+1;k++) a[i][k]=up*a[j][k]-nic*a[i][k];
        }
    }
}
void Jordan_elimination()
{
    for(int j=n;j>1;j--)
    {
        for(int i=1;i<j;i++)
        {
            if(a[i][j]==0) continue;
            int lcm=a[j][j]*a[i][j]/__gcd(a[j][j],a[i][j]);
            int nic=lcm/a[j][j],up=lcm/a[i][j];
            for(int k=1;k<=n+1;k++) a[i][k]=nic*a[j][k]-up*a[i][k];
        }
    }
}
void row_echelon()
{
    for(int i=1;i<=n;i++) a[i][n+1]/=a[i][i], a[i][i]=1;
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
    cout << "0. Return to Main Menu\n";  // Press 0 to return to the main menu
    cout << "Enter your choice: ";
}

void nonlinearMenu() {
    cout << "Select a non-linear equation solving method:\n";
    cout << "1. Bisection Method\n";
    cout << "2. False Position Method\n";
    cout << "3. Secant Method\n";
    cout << "4. Newton-Raphson Method\n";
    cout << "0. Return to Main Menu\n";  // Press 0 to return to the main menu
    cout << "Enter your choice: ";
}

void diffEqMenu() {
    cout << "Select a differential equation solving method:\n";
    cout << "1. Runge-Kutta Method (4th Order)\n";
    cout << "0. Return to Main Menu\n";  // Press 0 to return to the main menu
    cout << "Enter your choice: ";
}

void matrixMenu() {
    cout << "Select a matrix operation method:\n";
    cout << "1. Matrix Inversion\n";
    cout << "0. Return to Main Menu\n";  // Press 0 to return to the main menu
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
            break;  // Exit the program
        }

        switch (mainChoice) {
            case 1:  // Linear Equations
                while (true) {
                    linearMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;  // Return to main menu
                    solveLinear(methodChoice);
                }
                break;
            case 2:  // Non-linear Equations
                while (true) {
                    nonlinearMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;  // Return to main menu
                    solveNonlinear(methodChoice);
                }
                break;
            case 3:  // Differential Equations
                while (true) {
                    diffEqMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;  // Return to main menu
                    solveDifferential(methodChoice);
                }
                break;
            case 4:  // Matrix Operations
                while (true) {
                    matrixMenu();
                    cin >> methodChoice;
                    if (methodChoice == 0) break;  // Return to main menu
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
