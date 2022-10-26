namespace Examen_NFL;

//Tan on arreglo con N nombres de equipos de la NFL en desorden y en minúsculas y
//    quieres buscar un nombre de equipo en particular y desplegar el lugar donde se
//encuentra.La lista comienza en 1, es decir que, si hay 4 equipos antes del que
//    buscas, tendrías que desplegar el número 5. Si no se encontró el equipo escribir
//"No se encontró el equipo".

//    Además, quieres saber cuál o cuáles son los equipos con mayor ocurrencia de vocales
//    (a, e, o, u) en su nombre y desplegarlos, en caso de existir más de un equipo que
//coincidan con el mayor número de vocales, tienes que desplegarlos todos.

//    Por último, quieres invertir el nombre del equipo que tenga el menor número de
//    caracteres, si existen más de un equipo con esta misma longitud, tienes que
//    mostrar el primero que encuentres.Los espacios intermedios cuentan como caracteres
internal class Program
{
    private static void Main(string[] args)
    {
        Console.Write("¿Cuántos equipos quieres ingresar?: ");
        var n = int.Parse(Console.ReadLine());

        var equipos = new string[n];

        for (var i = 0; i < n; i++)
        {
            Console.Write("Ingresa el nombre del equipo {0}: ", i + 1);
            equipos[i] = Console.ReadLine();
        }

        int opcion;
        do
        {
            Console.WriteLine();
            Console.WriteLine("1. Buscar equipo y mostrar posición");
            Console.WriteLine("2. Equipo con mayor ocurrencia de vocales");
            Console.WriteLine("3. Invertir nombre del equipo con menor número de caracteres");
            Console.WriteLine("4. Salir");
            Console.Write("Opción: ");
            opcion = int.Parse(Console.ReadLine());
            Console.WriteLine();

            switch (opcion)
            {
                case 1:
                    Console.Write("Ingresa el equipo a buscar: ");
                    var equipo = Console.ReadLine();
                    BuscarEquipo(equipos, equipo);
                    break;
                case 2:
                    EquipoMayorOcurrenciaVocales(n, equipos);
                    break;
                case 3:
                    InvertirEquipoMenorCaracteres(n, equipos);
                    break;
                case 4:
                    Console.WriteLine("Saliendo...");
                    break;
                default:
                    Console.WriteLine("Opción inválida");
                    break;
            }
        } while (opcion != 4);
    }

    private static void InvertirEquipoMenorCaracteres(int tam, string[] equipos)
    {
        var menor = equipos[0].Length;
        var indice = 0;
        for (var i = 1; i < tam; i++)
            if (equipos[i].Length < menor)
            {
                menor = equipos[i].Length;
                indice = i;
            }

        var nombre = equipos[indice];
        var nombreInvertido = "";
        for (var i = nombre.Length - 1; i >= 0; i--) nombreInvertido += nombre[i];

        Console.WriteLine("El nombre del equipo con menor número de caracteres es: {0}",
            nombreInvertido);
    }

    private static void EquipoMayorOcurrenciaVocales(int tam, string[] equipos)
    {
        var vocales = new int[tam];
        for (var i = 0; i < tam; i++) vocales[i] = 0;

        for (var i = 0; i < tam; i++)
        for (var j = 0; j < equipos[i].Length; j++)
            if (equipos[i][j] == 'a' || equipos[i][j] == 'e' || equipos[i][j] == 'i' || equipos[i][j] == 'o' ||
                equipos[i][j] == 'u')
                vocales[i]++;

        var mayor = vocales[0];
        for (var i = 1; i < tam; i++)
            if (vocales[i] > mayor)
                mayor = vocales[i];

        Console.WriteLine("El equipo con mayor ocurrencia de vocales es: {0} con {1} vocales", equipos[0], mayor);
        for (var i = 0; i < tam; i++)
            if (vocales[i] == mayor)
                Console.WriteLine(equipos[i]);
    }

    private static void BuscarEquipo(string[] equipos, string equipo)
    {
        var encontrado = false;
        for (var i = 0; i < equipos.Length; i++)
            if (equipos[i] == equipo)
            {
                Console.WriteLine("El equipo {0} se encuentra en la posición {1}", equipo, i + 1);
                encontrado = true;
                break;
            }

        if (!encontrado) Console.WriteLine("No se encontró el equipo");
    }
}
