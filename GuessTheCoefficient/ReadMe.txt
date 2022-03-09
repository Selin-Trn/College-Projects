Coefficient Estimation

The goal of this project is to estimate the coefficients of an equation.

There are 250 x and corresponding y coordinates in the file named data.csv. This y data comes from the following equation:
y = ax4 + bx3 + cx2 + dx + e x, y ∈ R; a, b, c, d, e ∈ [1, 2, 3, ..., 9]

We will estimate the coefficients {a, b, c, d, e} that can be between 1 and 9 (1 and 9 included).
To evaluate how good the estimation is an error scale must be used and the Mean Squared Error is used for this.

After running the code, the program will estimate the coefficients using the x and y's from the data.csv file.

(First, the program will try out predetermined values. Afterwards, it will outright guess the coefficients. You will find two separate methods for this in the code).