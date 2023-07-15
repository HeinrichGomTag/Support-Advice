/*
 * For over 600 years, the hourglass has been a well-known timekeeping instrument. An hourglass consists of two glass flasks
 * arranged one above the other which are connected by a narrow channel. Inside the hourglass there is sand which slowly flows
 * from the upper to the lower flask. Hourglasses are typically symmetrical so that the sand always takes the same amount of
 * time to run through, regardless of orientation. For the purposes of this problem, we also assume that the flow rate of the
 * sand is a known constant and does not depend on the amount or distribution of sand in the upper half.
 
 Your friend Helen was bored and has been playing around with her hourglass. At time 0, all the sand was in the lower half. 
 Helen flipped the hourglass over several times and recorded all the moments at which she did so. How many seconds does 
 she need to wait from the current time until all the sand is back in the lower half?
 
 Input: 
 Consists of one line with three integers t,s,n:
 - t(1<=t<=10⁶): time
 - s(1<=s<=10⁶): sand
 - n(1<=n<=1000): times flipped
 
 One line of n integers a_1...q_n(0<a_1<a_n-t) the times at which the hourglass was flipped.
 
 All times are given in seconds. You may assume that the sand flows from the top to the bottom at a constant rate of 1
 gram per second.

Output:
Time in seconds needed for the hourglass to run out starting from time t.

 Sample Input:
 10 7 2
 4 9
 
 Sample Output:
 4
 
 Sample Input:
 2000 333 3
 1000 1250 1500
 
 Sample Output:
 0
 
 Sample Input:
 100 10 5
 15 20 93 96 97
 
 Sample Output:
 5
 
 */

namespace CS_SandAbraham;

static class Program
{
    public static void LeeParametros(ref int t, ref int s, ref int n)
    {
        var parametros = Console.ReadLine().Split(' ');
        t = int.Parse(parametros[0]);
        s = int.Parse(parametros[1]);
        n = int.Parse(parametros[2]);
    }

    public static int[] LeeTiemposVuelta(int n)
    {
        var tiempos = Console.ReadLine().Split(' ');
        var a = new int[n];
        for (var i = 0; i < n; i++)
            a[i] = int.Parse(tiempos[i]);
        return a;
    }

    public static void Main()
    {
        int t = 0, s = 0, n = 0;
        LeeParametros(ref t, ref s, ref n);
        var times = LeeTiemposVuelta(n);
        var timeNeeded = 0;
        var sand = s;
        while (times.Length > 0)
        {
            var time = times[0];
            // times = times.Skip(1).ToArray();
            times = times[1..];
            sand -= time - timeNeeded;
            if (sand <= 0)
            {
                timeNeeded = time;
                break;
            }

            sand = s;
            timeNeeded = time;
        }

        timeNeeded = (sand > 0 ? (t - timeNeeded + sand) / 2 : 0);

        if (timeNeeded > t)
            timeNeeded = t;

        Console.WriteLine(timeNeeded);
    }
}