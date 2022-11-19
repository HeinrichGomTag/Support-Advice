namespace proyectoticketmaster;

internal class Program
{
    private static void Main(string[] args)
    {
        var mitienda = new ticketmaster();
        menuprincipal(mitienda);
    }

    private static void limpiar()
    {
        Console.WriteLine("presione enter para continuar ...");
        Console.ReadLine();
        Console.Clear();
    }

    private static void menuprincipal(ticketmaster mitienda)
    {
        int a = new();
        mitienda.usu = new usuario[a];
        mitienda.eve = new evento[a];
        for (var i = 0; i < mitienda.eve.Length; i++)
            foreach (var user in mitienda.eve[i].registro)
                mitienda.eve[i].registro[i] = new usuario();

        var salir = true;
        while (salir)
        {
            Console.WriteLine("Hola ingrese una opcion ");
            Console.WriteLine("1. Crear Usuario  ");
            Console.WriteLine("2. iniciar sesion ");
            Console.WriteLine("3. Salir");
            var opcion = Convert.ToInt32(Console.ReadLine());
            switch (opcion)
            {
                case 1:

                    mitienda.usu = crearusuario(mitienda.usu);
                    limpiar();
                    break;
                case 2:
                    iniciarsesion(mitienda.usu, ref mitienda);

                    limpiar();
                    break;


                case 3:
                    salir = false;

                    break;
                default:
                    Console.WriteLine("opcion no valida...");
                    limpiar();
                    break;
            }
        }
    }

    private static usuario[] crearusuario(usuario[] u)
    {
        var temporal = new usuario[u.Length + 1];

        for (var i = 0; i < temporal.Length; i++)
            if (i < u.Length)
            {
                temporal[i] = u[i];
            }
            else
            {
                temporal[i] = new usuario();
                Console.WriteLine("Hola ingrese su nombre de usuario");
                temporal[i].nombreusuario = Console.ReadLine();
                Console.WriteLine("ingrese su contraseña");
                temporal[i].pass = Console.ReadLine();
                Console.WriteLine("Ingrese su rol \n 1.cliente \n 2.operador");
                temporal[i].rol = Convert.ToInt32(Console.ReadLine());
            }

        return temporal;
    }

    private static void iniciarsesion(usuario[] u, ref ticketmaster mitienda)
    {
        Console.WriteLine("HOLA, bienvenido ingrese su  nombre de usuario");
        var nombreusuario = Console.ReadLine();

        Console.WriteLine(" ingrese su contraseña");
        var contraseña = Console.ReadLine();
        for (var i = 0; i < u.Length; i++)
            if (nombreusuario == u[i].nombreusuario && contraseña == u[i].pass && u[i].rol == 1)
                menucliente(ref mitienda, u[i]);
            else if (nombreusuario == u[i].nombreusuario && contraseña == u[i].pass && u[i].rol == 2)
                menuoperador(ref mitienda);
    }

    private static void menucliente(ref ticketmaster mitienda, usuario u)
    {
        var salir = true;
        while (salir)
        {
            Console.WriteLine("Hola ingrese una opcion ");
            Console.WriteLine("1. registrar a un evento ");
            Console.WriteLine("2. ver mis eventos ");
            Console.WriteLine("3. Salir");
            var opcion = Convert.ToInt32(Console.ReadLine());
            switch (opcion)
            {
                case 1:
                    registrarmeaunevento(ref mitienda.eve, u);
                    limpiar();
                    break;
                case 2:
                    vermiseventos(mitienda.eve, u);
                    limpiar();
                    break;


                case 3:
                    salir = false;

                    break;
                default:
                    Console.WriteLine("opcion no valida...");
                    limpiar();
                    break;
            }
        }
    }

    private static void menuoperador(ref ticketmaster mitienda)
    {
        var salir = true;
        while (salir)
        {
            Console.WriteLine("Hola ingrese una opcion ");
            Console.WriteLine("1. agregar evento ");
            Console.WriteLine("2. ver lista de eventos ");
            Console.WriteLine("3. ver lista de participantes por evento");
            Console.WriteLine("4. salir");
            var opcion = Convert.ToInt32(Console.ReadLine());
            switch (opcion)
            {
                case 1:
                    mitienda.eve = agregarevento(mitienda.eve);
                    limpiar();
                    break;
                case 2:
                    verlistadeeventos(mitienda.eve);
                    limpiar();
                    break;
                case 3:
                    participantesporevento(mitienda.eve);
                    limpiar();
                    break;


                case 4:
                    salir = false;

                    break;
                default:
                    Console.WriteLine("opcion no valida...");
                    limpiar();
                    break;
            }
        }
    }

    private static evento[] agregarevento(evento[] e)
    {
        Console.WriteLine("Agregar eventos");

        var eventotemporal = new evento[e.Length + 1];

        for (var i = 0; i < eventotemporal.Length; i++)
            if (i < e.Length)
            {
                eventotemporal[i] = e[i];
            }
            else
            {
                eventotemporal[i] = new evento();

                Console.Write($"Ingrese el nombre del evento  #{i + 1}: ");
                eventotemporal[i].nombre = Console.ReadLine();
            }

        return eventotemporal;
    }

    private static void registrarmeaunevento(ref evento[] eve, usuario u)
    {
        Console.WriteLine("Eventos disponibles");
        for (var i = 0; i < eve.Length; i++) Console.WriteLine($"{i + 1}. {eve[i].nombre}");
        Console.WriteLine("Hola ingrese el nombre del evento al que desea registrarse");
        var nombre = Console.ReadLine();
        for (var i = 0; i < eve.Length; i++)
            if (nombre == eve[i].nombre)
            {
                var temporal = new usuario[eve[i].registro.Length + 1];
                for (var j = 0; j < temporal.Length; j++)
                    if (j < eve[i].registro.Length)
                        temporal[j] = eve[i].registro[j];
                    else
                        temporal[j] = u;
                eve[i].registro = temporal;
            }
    }


    private static void verlistadeeventos(evento[] eve)
    {
        Console.WriteLine("Lista de eventos registrados   ");
        for (var i = 0; i < eve.Length; i++) Console.WriteLine($"{i + 1} - {eve[i].nombre}");
    }

    private static void participantesporevento(evento[] e)
    {
        Console.WriteLine("Lista de eventos registrados   ");
        for (var i = 0; i < e.Length; i++)
        {
            Console.WriteLine($"Evento {i + 1}: {e[i].nombre}");
            if (e[i].registro == null)
                Console.WriteLine("No hay participantes registrados");
            else
                for (var j = 0; j < e[i].registro.Length; j++)
                    Console.WriteLine($"Participante {j + 1}: {e[i].registro[j].nombreusuario}");
        }
    }

    private static void vermiseventos(evento[] e, usuario u)
    {
        Console.WriteLine("Lista de eventos   ");
        if (e.Length > 0)
        {
            for (var i = 0; i < e.Length; i++)
                if (e[i].registro != null)
                    for (var j = 0; j < e[i].registro.Length; j++)
                        if (e[i].registro[j].nombreusuario == u.nombreusuario)
                            Console.WriteLine($"{i + 1} - {e[i].nombre}");
        }
        else
        {
            Console.WriteLine("No hay eventos registrados");
        }
    }

    private struct evento
    {
        public string nombre;
        public double id;
        public int capacidad;
        public usuario[] registro;

        public evento()
        {
            nombre = "";
            id = 0;
            capacidad = 0;
            registro = new usuario[0];
        }
    }

    private struct usuario
    {
        public double idusuario;
        public string nombreusuario;
        public string pass;
        public int rol;
    }

    private struct ticketmaster
    {
        public usuario[] usu;
        public evento[] eve;
    }
}