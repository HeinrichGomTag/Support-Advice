// PROGRAM THAT RECEIVES A FLOAT NUMBER BETWEEN 1 AND 10⁵, DIVIDES IT IN 4, AND PRINTS RESULT

// EXAMPLE: 
// INPUT: 16, OUTPUT: 4.00  (TWO DECIMAL PLACES)
// INPUT: 99, OUTPUT: 24.75 

///// FIRST SOLUTION ///////

using System.Globalization;

float number = float.Parse(Console.ReadLine());
float result = number / 4;
Console.WriteLine("{0:0.00}", result);

/////// SECOND SOLUTION ///////
long number2 = long.Parse(Console.ReadLine());
double result2 = number2 / 4.00;
Console.WriteLine("{0:0.00}", result2);

/////// THIRD SOLUTION ///////
decimal number3 = decimal.Parse(Console.ReadLine());
decimal result3 = number3 / 4;
Console.WriteLine("{0:0.00}", result3);

/////// FOURTH SOLUTION ///////
double number4 = double.Parse(Console.ReadLine());
double result4 = number4 / 4;
if (result4 % 1 == 0)
{
    string result4String = result4.ToString("#.00", CultureInfo.InvariantCulture);
    Console.WriteLine(result4String);
}
else
{
    Console.WriteLine(result4);
}

/////// FIFTH SOLUTION ///////
decimal number5 = decimal.Parse(Console.ReadLine());
decimal result5 = number5 / 4.00m;
Console.WriteLine("{0:0.00}", result5);