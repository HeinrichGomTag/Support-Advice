import Queues.*;
import LinkedStructures.*;

public class P2 {

    public static void main(String[] args) {
        CircularArrayQueue<Integer> q1 = new CircularArrayQueue();
        // q1 = { -17 3 18 }
        q1.enqueue(-17);
        q1.enqueue(3);
        q1.enqueue(18);
        System.out.println("q1 = " + q1.toString());
        System.out.println("Size = " + queueSize(q1));

        CircularArrayQueue<Double> q2 = new CircularArrayQueue();
        // {q2 = 0.5 7.0 0.0 -3.14 }
        q2.enqueue(0.5);
        q2.enqueue(7.0);
        q2.enqueue(0.0);
        q2.enqueue(-3.14);
        System.out.println("q2 = " + q2.toString());
        System.out.println("Size = " + queueSize(q2));

        CircularArrayQueue<String> q3 = new CircularArrayQueue();
        System.out.println("q3 = " + q3.toString());
        System.out.println("Size = " + queueSize(q3));

        LinkedStruct<Object> s1 = new LinkedStruct();
        s1.add(q1, 3);
        s1.add(q2, 2);
        s1.add(q3, 1);
        System.out.println("s1 = " + s1.toString());

        LinkedStruct<Object> s2 = new LinkedStruct();
        System.out.println("s2: " + s2.toString());

        LinkedStruct<Object> s3 = new LinkedStruct();
        // e3= {} -0.1, 3.1, 7, -3, }
        System.out.println("s3: " + s3.toString());

        intercambiaColasEnLS(s1);
        System.out.println("modified s1 = " + s1.toString());

        intercambiaColasEnLS(s2);
        System.out.println("modified s2 = " + s2.toString());

        System.out.println("s3 = " + s2.toString());
        System.out.println("Added s3 = " + s3.suma());

    }

    // Metodos del examen
    public static <T> int queueSize(CircularArrayQueue<T> cola) {
        int n = 0;
        CircularArrayQueue<T> aux = new CircularArrayQueue();
        while (!cola.isEmpty()) {
            aux.enqueue(cola.dequeue());
            n++;
        }
        while (!aux.isEmpty()) {
            cola.enqueue(aux.dequeue());
        }
        return n;
    }

    public static void intercambiaColasEnLS(LinkedStruct<Object> ls) {
        CircularArrayQueue<Object> a1 = new CircularArrayQueue();
        CircularArrayQueue<Object> a2 = new CircularArrayQueue();
        int j = 1;
        Object tempQ;

        if (ls != null && !ls.isEmpty()) {

            while (!ls.isEmpty()) {
                tempQ = ls.remove(1);
                a1.enqueue(tempQ);
            }

            while (!a1.isEmpty()) {
                tempQ = a1.dequeue();

                if (!a1.isEmpty())
                    a2.enqueue(a1.dequeue());
                a2.enqueue(tempQ);
            }

            while (!a2.isEmpty()) {
                ls.add(a2.dequeue(), j);
            }

        }
    }

}
