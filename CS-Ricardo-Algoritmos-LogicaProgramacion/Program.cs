using System;

namespace CS_Ricardo_Algoritmos_LogicaProgramacion
{
    internal class Program
    {
        private static void Main()
        {
            // Arreglo de 5 numeros con un decimal
            var arreglo = new decimal[5];

            // Pide cada uno de los elementos del arreglo
            for (var i = 0; i < arreglo.Length; i++)
            {
                Console.Write("Ingrese el numero {0}: ", i + 1);
                arreglo[i] = Convert.ToDecimal(Console.ReadLine());
            }

            // Invocar al método ordenar
            ordenar(ref arreglo);

            // Preguntar otro numero decimal
            Console.Write("\n\nIngrese otro numero decimal: ");
            var numero = Convert.ToDecimal(Console.ReadLine());

            // Informar si se encuentra en el arreglo y en que posicion está
            var encontrado = false;
            var posicion = 0;
            for (var i = 0; i < arreglo.Length; i++)
                if (arreglo[i] == numero)
                {
                    encontrado = true;
                    posicion = i;
                    Console.WriteLine("\n");
                    Console.WriteLine("El numero {0} se encuentra en la posicion {1}", numero, posicion + 1);
                    break;
                }

            Console.WriteLine("\n");
            if (!encontrado) Console.WriteLine("El numero {0} no se encuentra en el arreglo", numero);

            // Imprime el arreglo
            Console.WriteLine("El arreglo ya ordenado es: ");
            for (var i = 0; i < arreglo.Length; i++) Console.Write("{0}", arreglo[i] + " , ");
        }

        private static void ordenar(ref decimal[] arreglo)
        {
            // Ordenar de menor a mayor con ordenamiento burbuja
            for (var i = 0; i < arreglo.Length; i++)
            for (var j = 0; j < arreglo.Length - 1; j++)
                if (arreglo[j] > arreglo[j + 1])
                {
                    // Con variable auxiliar para intercambiar
                    var aux = arreglo[j];
                    arreglo[j] = arreglo[j + 1];
                    arreglo[j + 1] = aux;

                    // Con Swap
                    //(arreglo[j], arreglo[j + 1]) = (arreglo[j + 1], arreglo[j]);
                }
        }
    }
}