using System;
using System.Linq;

namespace Naomi_CS_Algoritmos_Estructuras
{
    internal struct Proyecto
    {
        public string nombre;
        public string tipo;
        public int duracion;
        public double costo;
        public double total_pagado;
    }

    internal class Program
    {
        private static void Main(string[] args)
        {
            var cantidadProyectos = 0;
            Console.Write("Ingrese la cantidad de proyectos que desea ingresar: ");
            cantidadProyectos = int.Parse(Console.ReadLine() ?? string.Empty);
            var lista = new Proyecto[cantidadProyectos];
            for (var i = 0; i < cantidadProyectos; i++)
            {
                Console.WriteLine();
                Console.Write("Ingrese el nombre del proyecto: ");
                lista[i].nombre = Console.ReadLine();

                var tipo = "";

                do
                {
                    Console.Write("Ingrese el tipo de proyecto: ");
                    tipo = Console.ReadLine();
                    if (tipo != "residencial" && tipo != "comercial" && tipo != "industrial")
                        Console.WriteLine("El tipo de proyecto ingresado no es valido. ");
                } while (tipo != "residencial" && tipo != "comercial" && tipo != "industrial");

                lista[i].tipo = tipo;

                var duracion = 0;
                do
                {
                    Console.Write("Ingrese la duracion del proyecto: ");
                    duracion = int.Parse(Console.ReadLine() ?? string.Empty);
                    if (duracion <= 0) Console.WriteLine("La duración debe ser más de 0");
                } while (duracion <= 0);

                lista[i].duracion = duracion;

                var costo = 0.0;
                do
                {
                    Console.Write("Ingrese el costo del proyecto: ");
                    costo = double.Parse(Console.ReadLine() ?? string.Empty);
                    if (costo <= 0) Console.WriteLine("El costo debe ser más de 0");
                } while (costo <= 0);

                lista[i].costo = costo;

                var total_pagado = 0.0;

                Console.Write("Ingrese el número de pagos: ");
                var numero_pagos = int.Parse(Console.ReadLine() ?? string.Empty);
                for (var j = 0; j < numero_pagos; j++)
                {
                    Console.Write("Ingrese el monto de pago {0}: ", j + 1);
                    total_pagado += double.Parse(Console.ReadLine() ?? string.Empty);
                }

                lista[i].total_pagado = total_pagado;
                Console.WriteLine("Total pagado del proyecto: " + lista[i].total_pagado);
                if (lista[i].total_pagado == lista[i].costo)
                    Console.WriteLine("El proyecto " + lista[i].nombre + " está pagado por completo");
            }

            var buscar = true;
            while (buscar)
            {
                Console.WriteLine("\n\n\n");
                Console.Write("Nombre del proyecto a buscar: ");
                var nombreProyecto = Console.ReadLine() ?? throw new ArgumentNullException("Console.ReadLine()");
                var encontrado = false;
                for (var i = 0; i < cantidadProyectos; i++)
                    if (lista[i].nombre == nombreProyecto)
                    {
                        encontrado = true;
                        Console.WriteLine("Proyecto encontrado");
                        Console.WriteLine("Nombre: " + lista[i].nombre);
                        Console.WriteLine("Tipo: " + lista[i].tipo);
                        Console.WriteLine("Duración: " + lista[i].duracion);
                        Console.WriteLine("Costo: " + lista[i].costo);
                        Console.WriteLine("Total pagado: " + lista[i].total_pagado);
                    }

                if (!encontrado) Console.WriteLine("No se encontró el proyecto");

                Console.Write("\n");
                Console.Write("¿Desea buscar otro proyecto? (s para continuar buscando): ");
                var opcion = Console.ReadLine();
                buscar = opcion == "s";
            }

            Console.WriteLine("\n");
            // Crear un arreglo con los costos de cada proyecto
            var costos = new double[cantidadProyectos];

            // Barrido por cada proyecto y asignar su costo a una posición del arreglo
            for (var i = 0; i < cantidadProyectos; i++) costos[i] = lista[i].costo;

            // Sacar el máximo costo del arreglo usando  Max de System.Linq
            var max = costos.Max();
            Console.WriteLine("El máximo costo es: " + max);

            // Barrido por cada uno de los proyectos y buscar el proyecto que coincida
            for (var i = 0; i < cantidadProyectos; i++)
                if (max == lista[i].costo)
                    Console.WriteLine("El proyecto con el máximo costo es: " + lista[i].nombre);
        }
    }
}