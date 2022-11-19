using System;
public class Program
{
    struct suffix
    {
        public string value;
        public int pos;
    }
    static string LeaCadena()
    {
        return Console.ReadLine();
    }
    static int[] LeeQuery()
    {
        string[] line = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.None);
        int[] result = new int[line.Length];
        for (int i = 0; i < line.Length; i++)
            result[i] = int.Parse(line[i]);
        return result;
    }
    static suffix[] ConstruirSuffixes(string origen)
    {
        suffix[] suffixes = new suffix[origen.Length];
        for (int i = 0; i < origen.Length; i++)
        {
            suffixes[i].value = origen.Substring(i);
            suffixes[i].pos = i;
        }
        return suffixes;
    }
    static void OrdenaSuffixes(suffix[] suffixes)
    {
        suffix aux;
        for (int i = 0; i < suffixes.Length - 1; i++)
            for (int j = 0; j < suffixes.Length - 1; j++)
                if (String.CompareOrdinal(suffixes[j].value, suffixes[j + 1].value) > 0)
                {
                    aux = suffixes[j];
                    suffixes[j] = suffixes[j + 1];
                    suffixes[j + 1] = aux;
                }
    }
    static void QuerySuffixes(suffix[] suffixes, int[] queries)
    {
        for (int i = 1; i < queries.Length; i++)
        {
            if (i != 1) Console.Write(" ");
            Console.Write(suffixes[queries[i]].pos);
        }
        Console.WriteLine();
        Console.WriteLine("*************");

    }
    static void Main()
    {
        int count = 0;
        string origen = "";
        while ((origen = LeaCadena()) != null && count < 10)
        {
            int[] queries = LeeQuery();
            suffix[] suffixes = ConstruirSuffixes(origen);
            OrdenaSuffixes(suffixes);
            QuerySuffixes(suffixes, queries);
            count++;
        }
    }
}