namespace CarRental;

public static class CarRentalStruct
{
    public static Car AddCar()
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

        var car = new Car(plate, brand, model, year, color, available);
        Console.WriteLine("Car added successfully!");
        return car;
    }

    public static void SeeCar(Car car)
    {
        Console.WriteLine("Plate: " + car.Plate + " Brand: " + car.Brand + " Model: " + car.Model + " Color: " +
                          car.Color + " Year: " + car.Year + " Availability: " +
                          (car.Available ? "Available" : "Not Available"));
    }

    public static Car EditCar(Car car)
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
        return car;
    }

    public static Car RentCar(Car car)
    {
        if (car.Available)
        {
            car.Available = false;
            Console.WriteLine("Car rented successfully!");
        }
        else
        {
            Console.WriteLine("Car already rented!");
        }

        return car;
    }

    public static Car ReturnCar(Car car)
    {
        if (!car.Available)
        {
            car.Available = true;
            Console.WriteLine("Car returned successfully!");
        }
        else
        {
            Console.WriteLine("Car already available!");
        }

        return car;
    }

    public static void RentedCars(Car car)
    {
        if (!car.Available) SeeCar(car);
    }

    public static void AvailableCars(Car car)
    {
        if (car.Available) SeeCar(car);
    }

    public struct Car
    {
        public readonly string? Plate;
        public bool Available;
        public string? Brand;
        public string? Color;
        public string? Model;
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