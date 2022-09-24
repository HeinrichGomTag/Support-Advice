using System;

namespace Linear_Algebra_Calculator
{
    internal class Program
    {
        //*************************  Matrix Operations  *************************
        // --> Function to the main
        private static void matrix(string name)
        {
            int op;
            string resp;
            do
            {
                Console.Clear();
                Console.WriteLine("Are you ready " + name + "?");
                Console.WriteLine(
                    "---------------------------------------------------------------------------------------------------");
                Console.WriteLine("What is a matrix?");
                Console.WriteLine("A matrix is a rectangular array of numbers (or other mathematical objects)");
                Console.WriteLine("We can do 7 operations with matrices");
                Console.WriteLine("1. Matrix Addition");
                Console.WriteLine("2. Scalar Product");
                Console.WriteLine("3. Matrix Product");
                Console.WriteLine("4. Transpose");
                Console.WriteLine("5. Adjugate");
                Console.WriteLine("6. Determinants");
                Console.WriteLine("7. Inverse");
                Console.WriteLine("Choose the operation you want to do:");
                op = int.Parse(Console.ReadLine());
                switch (op)
                {
                    case 1:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Matrix addition");
                        matrixAdition();
                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    case 2:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Scalar Product");
                        scalarProduct();
                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    case 3:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Matrix Product");
                        matrixProduct();
                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    case 4:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Transposed Matrix");
                        transposedMatrix();
                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    case 5:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Adjugate of a Matrix");
                        adjugateMatrix();
                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    case 6:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Determinant of a Matrix");
                        determinantMatrix();

                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    case 7:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Inverse of a matrix");

                        Console.WriteLine("Do you want to return to the Matrix menu?");
                        resp = Console.ReadLine();
                        break;
                    default:
                        Console.Clear();
                        Console.WriteLine("Sorry, " + name + ".");
                        Console.WriteLine("Error, this option is not disponible");
                        Console.WriteLine("Do you want to try again?");
                        resp = Console.ReadLine();
                        break;
                }
            } while ((resp == "Yes") | (resp == "yes") | (resp == "YES"));
        }

        private static void matrixAdition()
        {
            int i, numRow, numColumn, numMat, numRowCheck, numcolumnCheck;
            string resp, resp2;
            do
            {
                Console.Clear();
                Console.WriteLine("-------------------- Matrix addition --------------------");
                Console.WriteLine("Matrix addition is the operation of adding two ");
                Console.WriteLine("matrices by adding the corresponding positions.");
                Console.WriteLine("--------------------                 --------------------");
                Console.WriteLine("How many matrices do you want to summ?");
                Console.WriteLine("(If you are here again, you put matrices of different sizes)");
                numMat = int.Parse(Console.ReadLine());
                resp2 = "0";
                var matrixSize = new size[numMat + 1];
                for (i = 1; i <= numMat; i++)
                {
                    Console.WriteLine("Matrix #" + i);
                    Console.WriteLine("Number of rows");
                    matrixSize[i].numRows = int.Parse(Console.ReadLine());
                    Console.WriteLine("Number of columns");
                    matrixSize[i].numColumns = int.Parse(Console.ReadLine());
                }

                Console.WriteLine("We have to check if the operation can be done");
                numRow = matrixSize[1].numRows;
                numColumn = matrixSize[1].numColumns;
                numRowCheck = matrixSize[2].numRows;
                numcolumnCheck = matrixSize[2].numColumns;
                for (i = 1; i <= numMat; i++)
                    if (numRow <= matrixSize[i].numRows && numRow >= matrixSize[i].numRows &&
                        numColumn <= matrixSize[i].numColumns && numColumn >= matrixSize[i].numColumns &&
                        numRowCheck >= matrixSize[i].numRows && numRowCheck <= matrixSize[i].numRows &&
                        numcolumnCheck <= matrixSize[i].numColumns && numcolumnCheck >= matrixSize[i].numColumns)
                    {
                        numRowCheck = matrixSize[i].numRows;
                        numcolumnCheck = matrixSize[i].numColumns;
                        resp2 = "no";
                    }
                    else
                    {
                        resp2 = "yes";
                    }

                resp = resp2;
            } while ((resp == "Yes") | (resp == "yes") | (resp == "YES"));

            //-------------------------- Summ & Formulation of matrices ----------------------
            Console.Clear();
            int y, n, m;
            var matrix = new int[numMat + 1, numRow + 1, numColumn + 1];
            var matrixTot = new int[2, numRow + 1, numColumn + 1];
            Console.WriteLine("We can do the operation. All the entries are the same");
            Console.WriteLine("Enter the entries");
            Console.WriteLine("Click anything to enter the entries");
            for (y = 1; y <= numMat; y++)
            {
                Console.Clear();
                Console.WriteLine("Matrix #" + y);
                for (m = 1; m <= numColumn; m++)
                for (n = 1; n <= numRow; n++)
                {
                    Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                    Console.WriteLine("a" + n + "," + m);
                    Console.SetCursorPosition(3 + 5 * m, 2 + 2 * n);
                    matrix[y, n, m] = int.Parse(Console.ReadLine());
                    matrixTot[1, n, m] = matrixTot[1, n, m] + matrix[y, n, m];
                }
            }

            Console.Clear();
            Console.WriteLine("Congratulations!!! The resultant Matrix is:");
            for (m = 1; m <= numColumn; m++)
            for (n = 1; n <= numRow; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * n);
                Console.WriteLine(matrixTot[1, n, m]);
            }
        }

        private static void scalarProduct()
        {
            int numRow, numColumn, scalar;
            Console.Clear();
            Console.WriteLine("-------------------- Scalar Product --------------------");
            Console.WriteLine("A real number that is the product of the lengths of two vectors");
            Console.WriteLine("and the cosine of the angle between them.");
            Console.WriteLine("--------------------                --------------------");
            Console.WriteLine("Matrix: ");
            Console.WriteLine("Number of rows");
            numRow = int.Parse(Console.ReadLine());
            Console.WriteLine("Number of columns");
            numColumn = int.Parse(Console.ReadLine());
            //-------------------------- Product & Formulation of the matrix ----------------------
            Console.Clear();
            int n, m;
            var matrix = new int[numRow + 1, numColumn + 1];
            var matrixTot = new int[numRow + 1, numColumn + 1];
            Console.WriteLine("Enter the scalar number to make the product:");
            scalar = int.Parse(Console.ReadLine());
            for (m = 1; m <= numColumn; m++)
            for (n = 1; n <= numRow; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * n);
                matrix[n, m] = int.Parse(Console.ReadLine());
                matrixTot[n, m] = matrix[n, m] * scalar;
            }

            Console.Clear();
            Console.WriteLine("Congratulations!!! The resultant Matrix is:");

            for (m = 1; m <= numColumn; m++)
            for (n = 1; n <= numRow; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 9 + 2 * n);
                Console.WriteLine(matrixTot[n, m]);
            }
        }

        private static void matrixProduct()
        {
            int numRow, numColumn, numRow2, numColumn2, nrfm, ncfm;
            string resp, resp2;
            do
            {
                Console.Clear();
                resp2 = "0";
                nrfm = 0;
                ncfm = 0;
                Console.WriteLine("-------------------- Matrix Product --------------------");
                Console.WriteLine(
                    "In mathematics, the multiplication or product of matrices is the composition operation carried ");
                Console.WriteLine("out between two matrices, or the multiplication between a matrix and a");
                Console.WriteLine("scalar according to certain rules.");
                Console.WriteLine("--------------------                --------------------");
                Console.WriteLine("(If you are here again, the columns of M1 and the rows of M2 are not equal)");
                Console.WriteLine("Matrix #1");
                Console.WriteLine("Number of rows");
                numRow = int.Parse(Console.ReadLine());
                Console.WriteLine("Number of columns");
                numColumn = int.Parse(Console.ReadLine());
                Console.WriteLine("Matrix #2");
                Console.WriteLine("Number of rows");
                numRow2 = int.Parse(Console.ReadLine());
                Console.WriteLine("Number of columns");
                numColumn2 = int.Parse(Console.ReadLine());
                if (numColumn >= numRow2 && numColumn <= numRow2)
                {
                    nrfm = numRow;
                    ncfm = numColumn2;
                    Console.WriteLine("The size of the matrix is: " + nrfm + " X " + ncfm);
                    Console.WriteLine("Do you want to enter other values?");
                    resp2 = Console.ReadLine();
                }
                else
                {
                    resp2 = "yes";
                }

                resp = resp2;
            } while ((resp == "Yes") | (resp == "yes") | (resp == "YES"));

            //-------------------------- Product & Formulation of the matrix ----------------------
            Console.Clear();
            int n, m, o;
            double summ;
            var matrix1 = new double[numRow + 1, numColumn + 1];
            var matrix2 = new double[numRow2 + 1, numColumn2 + 1];
            var matrixTot = new double[nrfm + 1, ncfm + 1];
            Console.WriteLine("Matrix #1");
            for (m = 1; m <= numColumn; m++)
            for (n = 1; n <= numRow; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * n);
                matrix1[n, m] = int.Parse(Console.ReadLine());
            }

            Console.Clear();
            Console.WriteLine("Matrix #2");
            for (m = 1; m <= numColumn2; m++)
            for (n = 1; n <= numRow2; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * n);
                matrix2[n, m] = double.Parse(Console.ReadLine());
            }

            nrfm = numRow;
            ncfm = numColumn2;

            //----------------------- Operation -----------------------
            Console.Clear();
            var summi = new double[numColumn + 1];
            for (m = 1; m <= ncfm; m++)
            for (n = 1; n <= nrfm; n++)
            {
                summ = 0;
                for (o = 1; o <= numColumn; o++)
                {
                    summi[o] = summi[o - 1] + matrix1[n, o] * matrix2[o, m];
                    summ = summi[o];
                }

                matrixTot[n, m] = summ;
            }

            //---------------------------------------------------------

            Console.Clear();
            Console.WriteLine("Congratulations!!! The resultant Matrix is:");

            for (m = 1; m <= ncfm; m++)
            for (n = 1; n <= nrfm; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 9 + 2 * n);
                Console.WriteLine(matrixTot[n, m]);
            }
        }

        private static void transposedMatrix()
        {
            int numRow, numColumn, n, m;
            string resp, resp2;
            resp2 = "0";
            do
            {
                Console.WriteLine("-------------------- Transpose of the matrix --------------------");
                Console.WriteLine(" The transpose of a matrix is an operator which flips a matrix over its diagonal ");
                Console.WriteLine("--------------------                         --------------------");
                Console.WriteLine("Enter the size of the Matrix: ");
                Console.WriteLine("Number of rows");
                numRow = int.Parse(Console.ReadLine());
                Console.WriteLine("Number of columns");
                numColumn = int.Parse(Console.ReadLine());
                if (numRow >= numColumn && numRow <= numColumn)
                    resp2 = "no";
                else
                    resp2 = "no";
                resp = resp2;
            } while ((resp == "Yes") | (resp == "yes") | (resp == "YES"));

            var matrix1 = new double[numRow + 1, numColumn + 1];
            var matrixTot = new double[numColumn + 1, numRow + 1];
            Console.Clear();
            Console.WriteLine("Enter the entries of the Matrix: ");
            for (m = 1; m <= numColumn; m++)
            for (n = 1; n <= numRow; n++)
            {
                Console.SetCursorPosition(3 + 5 * m, 1 + 2 * n);
                Console.WriteLine("a" + n + "," + m);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * n);
                matrix1[n, m] = int.Parse(Console.ReadLine());
                matrixTot[m, n] = matrix1[n, m];
            }

            Console.Clear();
            Console.WriteLine("The transpose is size: " + numColumn + " X " + numRow);
            for (m = 1; m <= numColumn; m++)
            for (n = 1; n <= numRow; n++)
            {
                Console.SetCursorPosition(3 + 5 * n, 1 + 2 * m);
                Console.WriteLine("a" + m + "," + n);
                Console.SetCursorPosition(3 + 5 * n, 9 + 2 * m);
                Console.WriteLine(matrixTot[m, n]);
            }
        }

        private static void adjugateMatrix()
        {
            int numRow, numColumn, n, m;
            string resp, resp2;
            resp2 = "0";
            do
            {
                Console.Clear();
                Console.WriteLine("-------------------- Adjugate of the matrix --------------------");
                Console.WriteLine(
                    " The adjugate or classical adjoint of a square matrix is the transpose of its cofactor matrix.");
                Console.WriteLine("--------------------                        --------------------");
                Console.WriteLine("If you are here again, remember that we only have adjugate of square matrix");
                Console.WriteLine("Enter the size of the Matrix: ");
                Console.WriteLine("Number of rows");
                numRow = int.Parse(Console.ReadLine());
                Console.WriteLine("Number of columns");
                numColumn = int.Parse(Console.ReadLine());
                if (numRow >= numColumn && numRow <= numColumn)
                    resp2 = "no";
                else
                    resp2 = "yes";
                resp = resp2;
            } while ((resp == "Yes") | (resp == "yes") | (resp == "YES"));

            var matrix = new double[numColumn + 1, numRow + 1];
            var matrixTot = new double[numColumn + 1, numRow + 1];
            Console.Clear();
            for (n = 1; n <= numRow; n++)
            for (m = 1; m <= numColumn; m++)
            {
                Console.SetCursorPosition(3 + 5 * n, 1 + 2 * m);
                Console.WriteLine("a" + m + "," + n);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * m);
                matrix[m, n] = int.Parse(Console.ReadLine());
            }

            //-------------------- Cofactors & Adjugate --------------------
            var submatrix = new double[numColumn, numRow];
            for (n = 1; n <= numRow; n++)
            for (m = 1; m <= numColumn; m++)
            {
            }
        }

        private static double determinantMatrix()
        {
            int numRow, numColumn, n, m;
            Console.WriteLine("Enter the size of the Matrix: ");
            Console.WriteLine("Number of rows");
            numRow = int.Parse(Console.ReadLine());
            Console.WriteLine("Number of columns");
            numColumn = int.Parse(Console.ReadLine());

            var matrix = new double[numColumn + 1, numRow + 1];
            Console.Clear();
            for (n = 1; n <= numRow; n++)
            for (m = 1; m <= numColumn; m++)
            {
                Console.SetCursorPosition(3 + 5 * n, 1 + 2 * m);
                Console.WriteLine("a" + m + "," + n);
                Console.SetCursorPosition(3 + 5 * m, 2 + 2 * m);
                matrix[m, n] = int.Parse(Console.ReadLine());
            }

            int i, j, k;
            double det = 0;
            for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n + 1; j++)
            {
                det = matrix[j, i] / matrix[i, i];
                for (k = i; k < n; k++)
                    matrix[j, k] = matrix[j, k] - det * matrix[i, k]; // Here's exception
            }

            det = 1;
            for (i = 0; i < n; i++)
                det = det * matrix[i, i];
            return det;
        }

        private static void inverseMatrix()
        {
            // Creating a Matrix structure.
            matrix myMatrix = new matrix(5, 10, 15, 20, 25, 30);

            // Checking if myMatrix is invertible.
            if (myMatrix.HasInverse)
            {

                // Invert myMatrix. myMatrix is now 
                // equal to (-0.4, 0.2 , 0.3, -0.1, 1, -2) 
                myMatrix.Invert();

                // Return the inverted matrix.
                return myMatrix;
            }
            else
            {
                throw new InvalidOperationException("The matrix is not invertible.");
            }
        }

        //*************************      Main      ********************************
        private static void Main(string[] args)
        {
            int op;
            string name, resp;
            Console.WriteLine("Insert your name:");
            name = Console.ReadLine();
            do
            {
                Console.Clear();
                Console.WriteLine("Hey, " + name + "!");
                Console.WriteLine("Welcome to the: Linear Algebra Calculator");
                Console.WriteLine(
                    "---------------------------------------------------------------------------------------------------");
                Console.WriteLine("Linear Algebra:");
                Console.WriteLine(
                    "branch of mathematics that is concerned with mathematical structures closed under the operations");
                Console.WriteLine(
                    "of addition and scalar multiplication and that includes the theory of systems of linear equations,");
                Console.WriteLine(" matrices, determinants, vector spaces, and linear transformations");
                Console.WriteLine(
                    "---------------------------------------------------------------------------------------------------");
                Console.WriteLine("Disponible Options:");
                Console.WriteLine("1. Matrix Operations");
                Console.WriteLine("Insert the number of your selection:");
                op = int.Parse(Console.ReadLine());
                switch (op)
                {
                    case 1:
                        Console.Clear();
                        Console.WriteLine("Hey, " + name + "!");
                        Console.WriteLine("You chose: Matrix operations");
                        matrix(name);
                        Console.WriteLine("Do you want to return to the menu?");
                        resp = Console.ReadLine();
                        break;
                    default:
                        Console.Clear();
                        Console.WriteLine("Sorry, " + name + ".");
                        Console.WriteLine("Error, this option is not disponible");
                        Console.WriteLine("Do you want to try again?");
                        resp = Console.ReadLine();
                        break;
                }
            } while ((resp == "Yes") | (resp == "yes") | (resp == "YES"));
        }

        // --> Sub-Operations
        private struct size
        {
            internal int numRows;
            internal int numColumns;
        }
    }
}

/*
 * public static double DET(double[,] a, int n)
    {
        int i, j, k;
        double det = 0;
        for (i = 0; i < n - 1; i++)
        {   
            for (j = i + 1; j < n + 1; j++)
            {
                det = a[j, i] / a[i, i];
                for (k = i; k < n; k++)
                    a[j, k] = a[j, k] - det * a[i, k]; // Here's exception
            }
        }
        det = 1;
        for (i = 0; i < n; i++)
            det = det * a[i, i];
            return det;
    }

private Matrix inverseExample()
{
    
    // Creating a Matrix structure.
    Matrix myMatrix = new Matrix(5, 10, 15, 20, 25, 30);
                
    // Checking if myMatrix is invertible.
    if (myMatrix.HasInverse)
    {

        // Invert myMatrix. myMatrix is now 
        // equal to (-0.4, 0.2 , 0.3, -0.1, 1, -2) 
        myMatrix.Invert();
        
        // Return the inverted matrix.
        return myMatrix;
    }
    else
    {
        throw new InvalidOperationException("The matrix is not invertible.");
    }
}

public void AdjointExample()
        {
            //A = [ a, b ]
            //    [ c, d ]
            var matrix = new Matrix(2, 2);
            matrix[0, 0] = 2;
            matrix[0, 1] = 4;
            matrix[1, 0] = 1;
            matrix[1, 1] = 3;

            var a = matrix.Adjoint();

            // Adj(A) = [ d, -b]
            //          [ -c, a]
            Assert.AreEqual(a[0, 0], 3);
            Assert.AreEqual(a[0, 1], -4);
            Assert.AreEqual(a[1, 0], -1);
            Assert.AreEqual(a[1, 1], 2);
        }

private void GJ(ref double[,] matrix, int filas, int columnas)
        {
            for (int fpivot = 0; fpivot < filas; fpivot++)
            {
 
                double nor = matrix[fpivot, fpivot];
 
                for (int i = 0; i < columnas; i++)
                {
                    matrix[fpivot, i] = matrix[fpivot, i] / nor;
                }
 
                int f = fpivot + 1;
                if (f == filas) f = 0;
 
                for (int fila = 0; fila < filas - 1; fila++)
                {                
                    double k = matrix[f, fpivot];
 
                    for (int c = fpivot; c < columnas; c++)
                    {
                        matrix[f, c] = matrix[f, c] - (k * matrix[fpivot, c]);
                    }
                 
                    if (f == filas - 1) f = 0;
                    else f++; 
                }
            }
        }




 */