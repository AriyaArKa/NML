# Numerical Methods Console Application

This is a console-based application written in C++ that implements various numerical methods for solving linear equations, non-linear equations, differential equations, and performing matrix operations. The application provides an interactive menu-driven interface, allowing users to select the type of problem they wish to solve and choose from multiple algorithms available for that problem category.

## Table of Contents

- [Features](#features)
- [Algorithms Implemented](#algorithms-implemented)
  - [Linear Equations Solving Methods](#linear-equations-solving-methods)
    - [Jacobi Method](#jacobi-method)
    - [Gauss-Seidel Method](#gauss-seidel-method)
    - [Gauss Elimination](#gauss-elimination)
    - [Gauss-Jordan Elimination](#gauss-jordan-elimination)
    - [LU Factorization](#lu-factorization)
  - [Non-linear Equations Solving Methods](#non-linear-equations-solving-methods)
    - [Bisection Method](#bisection-method)
    - [False Position Method](#false-position-method)
    - [Secant Method](#secant-method)
    - [Newton-Raphson Method](#newton-raphson-method)
  - [Differential Equations Solving Methods](#differential-equations-solving-methods)
    - [Runge-Kutta Method (Fourth Order)](#runge-kutta-method-fourth-order)
  - [Matrix Operations](#matrix-operations)
    - [Matrix Inversion using Gauss-Jordan Elimination](#matrix-inversion-using-gauss-jordan-elimination)

## Features

- **Linear Equations Solving Methods**: Solve systems of linear equations using various iterative and direct methods.
- **Non-linear Equations Solving Methods**: Find roots of non-linear equations using bracketing and open methods.
- **Differential Equations Solving Methods**: Solve ordinary differential equations using the Runge-Kutta method.
- **Matrix Operations**: Perform matrix inversion using Gauss-Jordan elimination.
- **User-Friendly Interface**: Menu-driven console application with clear prompts and outputs.
- **Reusable Input**: Input data is entered once per session for linear and non-linear equations, allowing users to switch methods without re-entering data until they return to the main menu.

## Algorithms Implemented

### Linear Equations Solving Methods

#### Jacobi Method

The Jacobi method is an iterative algorithm for solving a system of linear equations. It is based on solving each equation for its own variable in terms of the other variables and iteratively updating the values until convergence.

**Algorithm Steps**:

1. Start with an initial guess for the solution vector.
2. For each iteration:
   - Compute the new value for each variable using the previous iteration's values.
   - Calculate the error between the new and old values.
3. Repeat until the maximum error exceeds the specified tolerance or the maximum number of iterations is reached.

**Convergence Criteria**:

- The method converges if the matrix is diagonally dominant or symmetric positive-definite.

#### Gauss-Seidel Method

The Gauss-Seidel method is an improvement over the Jacobi method. It uses the latest updated values within an iteration, which often results in faster convergence.

**Algorithm Steps**:

1. Start with an initial guess for the solution vector.
2. For each iteration:
   - Update each variable sequentially using the most recent values.
   - Compute the error between the new and old values.
3. Repeat until convergence criteria are met.

**Convergence Criteria**:

- Similar to the Jacobi method, convergence is guaranteed if the matrix is diagonally dominant or symmetric positive-definite.

#### Gauss Elimination

Gauss elimination is a direct method that transforms the system of linear equations into an upper triangular matrix, making it straightforward to solve via back substitution.

**Algorithm Steps**:

1. **Forward Elimination**:
   - For each pivot row, eliminate the variables below the pivot element.
   - Use partial pivoting to improve numerical stability.
2. **Back Substitution**:
   - Starting from the last equation, solve for each variable.
   - Substitute the known variables into the equations above to find the remaining variables.

#### Gauss-Jordan Elimination

Gauss-Jordan elimination extends Gauss elimination by transforming the matrix into a reduced row-echelon form (diagonal matrix), eliminating the need for back substitution.

**Algorithm Steps**:

1. **Forward Elimination**:
   - Convert the matrix into an upper triangular matrix.
2. **Backward Elimination**:
   - Convert the matrix into a diagonal matrix.
3. **Normalize Diagonal Elements**:
   - Scale rows to make the diagonal elements equal to one.
4. Extract the solution directly from the augmented matrix.

#### LU Factorization

LU factorization decomposes a matrix into a product of a lower triangular matrix ($L$) and an upper triangular matrix ($U$). This method is efficient for solving multiple systems with the same coefficient matrix but different right-hand sides.

**Algorithm Steps**:

1. **LU Decomposition**:
   - Decompose matrix $A$ into $L$ and $U$ such that $A = LU$.
2. **Forward Substitution**:
   - Solve $Ly = b$ for $y$.
3. **Backward Substitution**:
   - Solve $Ux = y$ for $x$.

**Advantages**:

- Efficient for solving multiple systems with the same matrix.
- LU decomposition can be reused when the right-hand side changes.

### Non-linear Equations Solving Methods

#### Bisection Method

The bisection method is a bracketing method that repeatedly bisects an interval and selects a subinterval in which a root must lie.

**Algorithm Steps**:

1. Choose an initial interval $[a, b]$ where the function changes sign.
2. Compute the midpoint $c = \dfrac{a + b}{2}$.
3. Evaluate the function at $c$.
4. Decide the subinterval $[a, c]$ or $[c, b]$ where the root lies.
5. Repeat until the interval is sufficiently small or the function value at $c$ is within the tolerance.

**Convergence Criteria**:

- The function must be continuous on $[a, b]$ and $f(a)$ and $f(b)$ must have opposite signs.

#### False Position Method

Also known as the Regula Falsi method, it improves upon the bisection method by using a secant line to estimate the root.

**Algorithm Steps**:

1. Choose an initial interval $[a, b]$ where the function changes sign.
2. Compute $c$ using the formula:

   $c = a - \dfrac{f(a)(b - a)}{f(b) - f(a)}$

3. Evaluate the function at $c$.
4. Decide the subinterval $[a, c]$ or $[c, b]$ where the root lies.
5. Repeat until convergence.

#### Secant Method

The secant method is an open method that uses two initial approximations and approximates the derivative by a finite difference.

**Algorithm Steps**:

1. Choose two initial approximations $x_0$ and $x_1$.
2. Compute the next approximation using:

   $x_{n+1} = x_n - f(x_n) \dfrac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$

3. Repeat until the difference between successive approximations is within the tolerance.

**Advantages**:

- Faster convergence compared to bracketing methods.
- Does not require the computation of derivatives.

#### Newton-Raphson Method

The Newton-Raphson method is an open method that uses the function and its derivative to find successively better approximations to the roots.

**Algorithm Steps**:

1. Choose an initial approximation $x_0$.
2. Compute the next approximation using:

   $x_{n+1} = x_n - \dfrac{f(x_n)}{f'(x_n)}$

3. Repeat until convergence criteria are met.

**Advantages**:

- Quadratic convergence near the root.
- Very efficient if the derivative is easily computed.

**Convergence Criteria**:

- The function must be differentiable in the interval.
- The initial guess should be close to the actual root.

### Differential Equations Solving Methods

#### Runge-Kutta Method (Fourth Order)

The Runge-Kutta method is a powerful technique for solving ordinary differential equations (ODEs) numerically.

**Algorithm Steps**:

Given an initial value problem $y' = f(x, y)$, $y(x_0) = y_0$, and step size $h$.

For each step:

1. Compute the slopes:

   - $k_1 = h \cdot f(x_n, y_n)$
   - $k_2 = h \cdot f\left(x_n + \dfrac{h}{2}, y_n + \dfrac{k_1}{2}\right)$
   - $k_3 = h \cdot f\left(x_n + \dfrac{h}{2}, y_n + \dfrac{k_2}{2}\right)$
   - $k_4 = h \cdot f\left(x_n + h, y_n + k_3\right)$

2. Update the solution:

   $y_{n+1} = y_n + \dfrac{1}{6}(k_1 + 2k_2 + 2k_3 + k_4)$

3. Increment:

   $x_{n+1} = x_n + h$

**Advantages**:

- High accuracy with relatively small step sizes.
- Does not require higher-order derivatives.

### Matrix Operations

#### Matrix Inversion using Gauss-Jordan Elimination

This method computes the inverse of a matrix by augmenting it with the identity matrix and applying Gauss-Jordan elimination.

**Algorithm Steps**:

1. Form the augmented matrix $[A | I]$, where $I$ is the identity matrix.
2. Apply Gauss-Jordan elimination to transform $[A | I]$ into $[I | A^{-1}]$.
3. Extract the inverse $A^{-1}$ from the augmented matrix.

**Conditions**:

- The matrix $A$ must be square and non-singular (invertible).
- Zero pivot elements indicate a singular matrix that cannot be inverted.
