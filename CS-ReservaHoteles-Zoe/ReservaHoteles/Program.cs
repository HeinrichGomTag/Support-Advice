// Declares a method to capture and calculate payment details for guests.

static void Capture(string?[] names, int[] nights, double[] nightPrice, double[] payments)
{
    for (int i = 0; i < names.Length; i++)
    {
        // Capture each guest's name.
        Console.Write("Name for guest " + (i + 1) + ": ");
        names[i] = Console.ReadLine();

        // Capture and validate the number of nights for the guest.
        do
        {
            Console.Write("Nights for guest " + names[i] + ": ");
            nights[i] = int.Parse(Console.ReadLine() ?? string.Empty);
            if (nights[i] < 1 || nights[i] > 8)
                Console.WriteLine("Invalid number of nights. Please enter a number between 1 and 8.\n");
        } while (nights[i] < 1 || nights[i] > 8);

        // Capture and validate the nightly rate.
        do
        {
            Console.Write("Enter night price for guest " + names[i] + ": ");
            nightPrice[i] = double.Parse(Console.ReadLine() ?? string.Empty);
            if (nightPrice[i] < 1000 || nightPrice[i] > 8000)
                Console.WriteLine("Invalid price. Please enter a price between 1000 and 8000.\n");
        } while (nightPrice[i] < 1000 || nightPrice[i] > 8000);

        // Calculate the total payment for the guest.
        payments[i] = nights[i] * nightPrice[i];
        Console.WriteLine("Payment for guest " + names[i] + ": " + payments[i] + "\n");
    }
}

// Method to find and display the guest with the minimum payment.
static void Min(string?[] name1, double[] payments)
{
    int index = -1;
    double min = 604001;
    for (var i = 0; i < name1.Length; i++)
    {
        if (payments[i] < min)
        {
            min = payments[i];
            index = i;
        }
    }

    Console.WriteLine(
        "Guest with the Minimum payment: " + name1[index] + " with a payment of " + payments[index] + "\n");
}

// Method to calculate and display the average payment.
static void Average(double[] payments)
{
    double sum = payments.Sum();
    double average = sum / payments.Length;
    Console.WriteLine("Average payment: " + average);
}

// Main control flow of the program.
int opc;
int band = 0; // A flag to check if data has been entered before proceeding to results.
Console.Write("Number of guests: ");
var n = int.Parse(Console.ReadLine() ?? string.Empty);
string?[] names = new string?[n];
double[] nightPrice = new double[n];
int[] nights = new int[n];
double[] payments = new double[n];

do
{
    // Main menu for the application.
    Console.WriteLine("MENU\n1.- Capture data\n2.- Results\n3.- Exit\n----------------");
    do
    {
        Console.Write("Option: ");
        opc = int.Parse(Console.ReadLine() ?? string.Empty);
        if (opc < 1 || opc > 3)
            Console.WriteLine("Invalid option. Please enter a number between 1 and 3.\n");
    } while (opc < 1 || opc > 3);

    switch (opc)
    {
        case 1:
            band = 1; // Set the flag when data has been captured.
            Capture(names, nights, nightPrice, payments);
            break;
        case 2:
            if (band == 1) // Ensure data is entered before showing results.
            {
                int opc1;
                do
                {
                    // Submenu for displaying results.
                    Console.WriteLine(
                        "SUBMENU\n1 - Average payment\n2 - Guest with the Minimum payment\n3 - Exit\n----------------");
                    do
                    {
                        Console.Write("Option: ");
                        opc1 = int.Parse(Console.ReadLine() ?? string.Empty);
                        if (opc1 < 1 || opc1 > 3)
                            Console.WriteLine("Invalid option. Please enter a number between 1 and 3.\n");
                    } while (opc1 < 1 || opc1 > 3);

                    switch (opc1)
                    {
                        case 1:
                            Average(payments);
                            break;
                        case 2:
                            Min(names, payments);
                            break;
                        case 3:
                            Console.WriteLine("Returning to main menu.\n");
                            break;
                    }
                } while (opc1 != 3);
            }
            else
            {
                Console.WriteLine("Please enter the data first.\n");
            }

            break;
        case 3:
            Console.WriteLine("Goodbye!"); // Exit the application.
            break;
    }
} while (opc != 3); // Loop until the user chooses to exit.

///////////////////////////////////
/*
 * 1. User Input & output
 * 2. Exception Handling (parse)
 * 3. Control Structures (loops & conditionals)
 * 4. Data Validation (ranges)
 * 5. Arrays
 * 6. Menus
 * 7. Arithmetic Operations & Agregation
 * 8. Methods
 * 9. Control Variables (flags)
 */