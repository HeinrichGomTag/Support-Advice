using System;

namespace AmandaCartas
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var fig = Menu_figura();
            Console.Clear();
            var n = Aleatorio();
            var n_oculto = Aleatorio();
            Carta_volteada(20, 1);
            Carta(20, 8, n, fig);
            var respuesta = Pregunta();
            Console.Clear();
            Carta(20, 1, n_oculto, fig);
            Carta(20, 8, n, fig);
            Verificar(respuesta, n, n_oculto);
        }

        private static void Carta(int p0, int p1, string p2, string fig)
        {
            throw new NotImplementedException();
        }

        private static void Carta_volteada(int i, int i1)
        {
            throw new NotImplementedException();
        }

        private static void Verificar(string respuesta, string s, string nOculto)
        {
            var num1 = int.Parse(s);
            var num2 = int.Parse(nOculto);
            if (respuesta == "up") Console.WriteLine(num2 > num1 ? "Correcto" : "Incorrecto");
            if (respuesta == "down") Console.WriteLine(num2 < num1 ? "Correcto" : "Incorrecto");
        }

        private static string Pregunta()
        {
            Console.WriteLine("¿Será la carta mayor o menor?");
            var mensaje = "Presiona la tecla hacia arriba para mayor o hacia abajo para menor";
            var respuesta = Tecla_Presionada(mensaje);
            return respuesta;
        }

        private static string Tecla_Presionada(string mensaje)
        {
            Console.WriteLine(mensaje);
            return Console.ReadKey().Key.ToString();
        }

        private static string Aleatorio()
        {
            var rnd = new Random();
            var n = rnd.Next(1, 10);
            return n.ToString();
        }

        private static string Menu_figura()
        {
            string symbol;
            Console.WriteLine("Bienvenido al juego de cartas *¿mayor o menor?*");
            Console.WriteLine("REGLAS:");
            Console.WriteLine("En pantalla apareceran 2 cartas. 1 Boca abierto y otra boca abajo");
            Console.WriteLine("El usuario presionará arriba cuando crea que la carta boca abajo es superior");
            Console.WriteLine("El usuario presionará abajo cuando crea que la carta boca abajo es inferior");
            Console.WriteLine(
                "Seleciona la figura de la baraja que te gustaría usar, indicando el inciso correspondiente: ");
            Console.WriteLine("a) ♥");
            Console.WriteLine("b) ♦");
            Console.WriteLine("c) ♣");
            Console.WriteLine("d) ♠");
            symbol = Console.ReadLine();
            return symbol;
        }
    }
}