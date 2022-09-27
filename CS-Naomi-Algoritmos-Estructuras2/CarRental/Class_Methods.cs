namespace CarRental;

public static class CarRentalSource
{
    public static void AddCar(ref List<Car> cars)
    {
        Console.Write("Enter the plate number: ");
        var plate = Console.ReadLine();
        Console.Write("Enter the brand: ");
        var brand = Console.ReadLine();
        Console.Write("Enter the model: ");
        var model = Console.ReadLine();
        Console.Write("Enter the color: ");
        var color = Console.ReadLine();
        Console.Write("Enter the year: ");
        var year = int.Parse(Console.ReadLine() ?? string.Empty);
        Console.Write("Enter the availability: 1) Available 2) Not Available: ");
        var available = int.Parse(Console.ReadLine() ?? string.Empty) == 1;

        var temp = new Car(plate, brand, model, year, color, available);
        cars.Add(temp);
        Console.WriteLine("Car added successfully!");
    }

    public static void SeeCar(List<Car> cars)
    {
        Console.Write("Enter the plate number: ");
        var plate = Console.ReadLine() ?? string.Empty;

        foreach (var car in cars.Where(car => car.Plate == plate))
        {
            Console.WriteLine("Founded");
            Console.WriteLine("Plate: " + car.Plate + " Brand: " + car.Brand + " Model: " + car.Model + " Color: " +
                              car.Color + " Year: " + car.Year + " Availability: " +
                              (car.Available ? "Available" : "Not Available"));
        }
    }

    public static void EditCar(ref List<Car> cars)
    {
        Console.Write("Enter the plate number: ");
        var plate = Console.ReadLine() ?? string.Empty;
        foreach (var car in cars.Where(car => car.Plate == plate))
        {
            Console.Write("Enter the brand: ");
            car.Brand = Console.ReadLine();
            Console.Write("Enter the model: ");
            car.Model = Console.ReadLine();
            Console.Write("Enter the color: ");
            car.Color = Console.ReadLine();
            Console.Write("Enter the year: ");
            car.Year = int.Parse(Console.ReadLine() ?? string.Empty);
            Console.Write("Enter the availability: 1) Available 2) Not Available: ");
            car.Available = int.Parse(Console.ReadLine() ?? string.Empty) == 1;
            Console.WriteLine("Car edited successfully!");
        }
    }

    public static void RentCar(ref List<Car> cars)
    {
        Console.Write("Enter the plate number: ");
        var plate = Console.ReadLine() ?? string.Empty;
        foreach (var car in cars.Where(car => car.Plate == plate))
            if (!car.Available)
            {
                Console.WriteLine("Car is not available!");
                return;
            }
            else
            {
                car.Available = false;
                Console.WriteLine("Car rented successfully!");
            }
    }

    public static void ReturnCar(ref List<Car> cars)
    {
        Console.Write("Enter the plate number: ");
        var plate = Console.ReadLine() ?? string.Empty;
        foreach (var car in cars.Where(car => car.Plate == plate))
            if (car.Available)
            {
                Console.WriteLine("Car is already available!");
            }
            else
            {
                car.Available = true;
                Console.WriteLine("Car returned successfully!");
            }
    }

    public static void RentedCars(List<Car> cars)
    {
        foreach (var car in cars.Where(car => car.Available == false))
            Console.WriteLine("Plate: " + car.Plate, " Brand: " + car.Brand, " Model: " + car.Model,
                " Year: " + car.Year, " Color: " + car.Color,
                " Availability: " + (car.Available ? "Available" : "Not Available"));
    }

    public static void AvailableCars(List<Car> cars)
    {
        foreach (var car in cars.Where(car => car.Available))
            Console.WriteLine("Plate: " + car.Plate, " Brand: " + car.Brand, " Model: " + car.Model,
                " Year: " + car.Year, " Color: " + car.Color,
                " Availability: " + (car.Available ? "Available" : "Not Available"));
    }

    public class Car
    {
        // PLATE
        public readonly string? Plate;

        // AVAILABLE
        public bool Available;

        // BRAND
        public string? Brand;

        // COLOR
        public string? Color;

        // MODEL
        public string? Model;

        // YEAR
        public int Year;

        public Car(string? plate, string? brand, string? model, int year, string? color, bool available)
        {
            Plate = plate;
            Brand = brand;
            Model = model;
            Year = year;
            Color = color;
            Available = available;
        }
    }
}