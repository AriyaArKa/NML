# NML-ASSIGNMENT


<h1>Gaussian and Gauss-Jordan Elimination Methods</h1>
</head>
<body>

 <h1>Runge-Kutta Metho for Solving Differential Equations</h1>

    <h2>Overview</h2>
    <p>This code uses the Runge-Kutta 4th-order method (RK4) to approximate the solution of differential equations <code>dy/dx = f(x, y)</code>. The function allows choosing between polynomial, sine, and cosine functions as input for <code>f(x, y)</code>.</p>

    <h2>Algorithm Explanation</h2>
    <p>The RK4 method estimates the next point in the solution by combining the current point and four calculated increments:</p>
    <ul>
        <li><code>k1</code>: Slope at the beginning of the interval.</li>
        <li><code>k2</code>: Slope at the midpoint using <code>k1</code>.</li>
        <li><code>k3</code>: Slope at the midpoint using <code>k2</code>.</li>
        <li><code>k4</code>: Slope at the end of the interval.</li>
    </ul>

<h1>Gaussian and Gauss-Jordan Elimination</h1>

<p>This project demonstrates the use of Gaussian and Gauss-Jordan elimination methods to solve systems of linear equations. Below is a detailed explanation and pseudocode of the algorithms.</p>

<h2>Overview</h2>
<p>The process involves three main steps:</p>
<ol>
  <li><strong>Gaussian Elimination</strong>: Converts the matrix into an upper triangular form.</li>
  <li><strong>Gauss-Jordan Elimination</strong>: Further reduces the matrix to create a diagonal form.</li>
  <li><strong>Row Echelon Form</strong>: Scales each row so that each pivot element is 1.</li>
</ol>

<h2>Algorithm Pseudocode</h2>

<h3>1. Gaussian Elimination</h3>
<p>This step converts the matrix to an upper triangular form. The pseudocode:</p>
<pre>
for each column j from 1 to n-1:
    for each row i from n down to j+1:
        if element at a[i][j] is 0, skip this row
        compute lcm = lcm(a[j][j], a[i][j])
        set multipliers up and nic based on lcm
        for each column k from 1 to n+1:
            a[i][k] = (up * a[j][k]) - (nic * a[i][k])
</pre>

<p><strong>Explanation:</strong> For each column, this finds and zeroes out elements below the diagonal to form an upper triangular matrix. The least common multiple (LCM) ensures operations are integer-based, preventing fraction results.</p>

<h3>2. Gauss-Jordan Elimination</h3>
<p>This step reduces the matrix to diagonal form by making elements above the diagonal zero. The pseudocode:</p>
<pre>
for each column j from n down to 2:
    for each row i from 1 up to j-1:
        if element at a[i][j] is 0, skip this row
        compute lcm = lcm(a[j][j], a[i][j])
        set multipliers nic and up based on lcm
        for each column k from 1 to n+1:
            a[i][k] = (nic * a[j][k]) - (up * a[i][k])
</pre>

<p><strong>Explanation:</strong> Starting from the last column, it clears entries above each pivot (diagonal) element, forming a diagonal matrix where non-zero elements appear only on the main diagonal.</p>

<h3>3. Row Echelon Form</h3>
<p>After Gauss-Jordan Elimination, this step makes each pivot element equal to 1. The pseudocode:</p>
<pre>
for each row i from 1 to n:
    divide each element in row i by a[i][i]
</pre>

<p><strong>Explanation:</strong> This scales each row so that each diagonal entry (pivot) becomes 1, leaving the matrix in row echelon form.</p>

<h2>Example Usage</h2>
<p>Here is an example input matrix and the expected output form after performing Gaussian and Gauss-Jordan elimination:</p>
<pre>
Input Matrix:
1 2 3 4 | 10
2 3 4 5 | 20
3 4 5 6 | 30
4 5 6 7 | 40

Result (Row Echelon Form):
1 0 0 0 | x1
0 1 0 0 | x2
0 0 1 0 | x3
0 0 0 1 | x4
</pre>

<p>The resulting matrix displays the solved values of each variable in a system of equations.</p>

</body>
</html>
