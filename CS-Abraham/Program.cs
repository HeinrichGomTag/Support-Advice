float num = 0;

num = float.Parse(Console.ReadLine());

num /= 4;

if (num % 1 == 0)
    Console.WriteLine("{0}.00", num);
else
    Console.WriteLine("{0}", num);