namespace CarRental;

using static CarRentalSource;

public static class Program
{
    public static void Main()
    {
        int opc;

        var cars = new List<Car>();

        do
        {
            Console.WriteLine("\nMAIN MENU");
            Console.WriteLine("1. Add car");
            Console.WriteLine("2. Show car");
            Console.WriteLine("3. Edit car");
            Console.WriteLine("4. Rent car");
            Console.WriteLine("5. Return car");
            Console.WriteLine("6. Show rented cars");
            Console.WriteLine("7. Available cars");
            Console.WriteLine("8. FINISH");

            Console.Write("Enter choice: ");
            opc = int.Parse(Console.ReadLine() ?? string.Empty);

            switch (opc)
            {
                case 1:
                    AddCar(ref cars);
                    break;
                case 2:
                    SeeCar(cars);
                    break;
                case 3:
                    EditCar(ref cars);
                    break;
                case 4:
                    RentCar(ref cars);
                    break;
                case 5:
                    ReturnCar(ref cars);
                    break;
                case 6:
                    RentedCars(cars);
                    break;
                case 7:
                    AvailableCars(cars);
                    break;
                case 8:
                    Console.WriteLine("FINISHED");
                    break;
            }
        } while (opc != 8);
    }
}