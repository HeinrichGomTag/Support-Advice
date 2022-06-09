import Queues.*;

public class P1 {

    public static void main(String[] args) {
        CircularArrayQueue<Object> q1 = new CircularArrayQueue();
        CircularArrayQueue<Integer> q2 = new CircularArrayQueue();
        CircularArrayQueue<Character> q3 = new CircularArrayQueue();

        // q1 = {hola 3 3.1416 -17}
        q1.enqueue("hola");
        q1.enqueue(3);
        q1.enqueue(3.1416);
        q1.enqueue(-17);

        System.out.println("First Q1 ---> " + imprimeCola(q1));
        System.out.println("Deleted ---> " + eliminaSegundo(q1));
        System.out.println("Modified Q1 ---> " + imprimeCola(q1));

        // q2 = { }
        System.out.println("First Q2 ---> " + imprimeCola(q2));
        System.out.println("Deleted ---> " + eliminaSegundo(q2));
        System.out.println("Modified Q2 ---> " + imprimeCola(q2));

        // q3 = { A Z }
        q3.enqueue('A');
        q3.enqueue('Z');
        System.out.println("First Q3 ---> " + imprimeCola(q3));
        System.out.println("Deleted ---> " + eliminaSegundo(q3));
        System.out.println("Modified Q3 ---> " + imprimeCola(q3));
    }

    public static <T> T eliminaSegundo(CircularArrayQueue<T> cola) {

        if (cola == null || cola.isEmpty()) {
            return null;
        }
        cola.enqueue(cola.dequeue());
        return cola.dequeue();
    }

    public static <T> String imprimeCola(CircularArrayQueue<T> cola) {
        if (cola == null || cola.isEmpty()) {
            return "{ }";
        } else {
            String prov = "{";
            if (cola == null || cola.isEmpty()) {
                return "}";
            }
            prov = cola.toString();
            return prov;
        }

    }

}
