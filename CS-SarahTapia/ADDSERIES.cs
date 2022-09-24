using System;

namespace SumaSerie
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //     // EJEMPLO DE LA SERIE
            //     // 1/1 + 1/1+2 + 1/1+2+3 + 1/1+2+3+4 + 1/1+2+3+4+5
            //     // 1/1 + 1/3 + 1/6 + 1/10 + 1/15
            //     int numero, denominador = 0;
            //     double fraccion, suma = 0;
            //     Console.Write("Ingrese el numero de terminos de la serie: ");
            //     numero = int.Parse(Console.ReadLine());
            //     for (int i = 1; i <= numero; i++)
            //     {
            //         denominador += i;
            //         // Console.WriteLine("Denominador {0} = {1}", i, denominador);
            //         fraccion = 1.0 / denominador;
            //         // Console.WriteLine("Fraccion {0} = {1}", i, fraccion);
            //         suma += fraccion;
            //         // Console.WriteLine("Suma {0} = {1}", i, suma);
            //     }
            //     Console.WriteLine("La suma de la serie es: {0}", suma);

            // ------------------------------------------------------------------
            // USING 2 FOR CICLES
            int numero, denominador = 0;
            double fraccion, suma = 0;
            Console.Write("Ingrese el numero de terminos de la serie: ");
            numero = int.Parse(Console.ReadLine());
            for (int i = 1; i <= numero; i++)
            {
                denominador = 0;
                for (int j = 1; j <= i; j++)
                {
                    denominador += j;
                }
                // Console.WriteLine("Denominador {0} = {1}", i, denominador);
                fraccion = 1.0 / denominador;
                // Console.WriteLine("Fraccion {0} = {1}", i, fraccion);
                suma += fraccion;
                // Console.WriteLine("Suma {0} = {1}", i, suma);
            }
            Console.WriteLine("La suma de la serie es: {0}", suma);
        }
    }
}
