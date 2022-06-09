
package LinkedStructures;

import java.util.Iterator;
import ADTsException.ADTsException;

public class LinkedStruct<T> {
    private int count;
    private LinearNode<T> front;

    public LinkedStruct() {
        count = 0;
        front = null;
    }

    public void add(T element, int pos) {
        LinearNode<T> node = new LinearNode<T>(element);
        LinearNode<T> current;
        int i;

        if (this.isEmpty()) {
            front = node;
        } else {
            if (pos <= 1) {
                node.setNext(front);
                front = node;
            } else {
                i = 1;
                current = front;
                while (i < (pos - 1) && current.getNext() != null) {
                    i++;
                    current = current.getNext();
                }
                node.setNext(current.getNext());
                current.setNext(node);
            }
        }
        count++;
    }

    public T remove(int pos) {
        LinearNode<T> current, previous = null;
        T result = null;
        int i;

        if (pos < 1 || pos > count) {
            throw new ADTsException(
                    "remove(): Not Found, posicion fuera de limites o vacio.");
        }

        if (pos == 1) {
            result = front.getElement();
            front = front.getNext();
        } else {
            i = 1;
            current = front;
            while (i < pos) {
                previous = current;
                current = current.getNext();
                i++;
            }
            result = current.getElement();
            previous.setNext(current.getNext());
        }
        count--;
        return result;
    }

    public T get(int pos) {
        LinearNode<T> current;

        if (pos < 1 || pos > count) {
            throw new ADTsException(
                    "get(): Not Found, posicion fuera de limites o vacio.");
        }

        current = front;
        for (int i = 1; i < pos; i++) {
            current = current.getNext();
        }

        return current.getElement();
    }

    public void set(T element, int pos) {
        LinearNode<T> current;

        if (pos < 1 || pos > count) {
            throw new ADTsException(
                    "set(): Not Found, posicion fuera de limites o vacio.");
        }

        current = front;
        for (int i = 1; i < pos; i++) {
            current = current.getNext();
        }

        current.setElement(element);
    }

    public boolean isEmpty() {
        return (count == 0);
    }

    public Iterator<T> iterator() {
        return (new LinkedStructIter<T>(front));
    }

    @Override
    public String toString() {
        String result = "";
        LinearNode<T> current;

        if (isEmpty()) {
            result = "LinkedStruct: empty";
        } else {
            current = front;
            result = "LinkedStruct: ";
            for (int i = 1; i <= count; i++) {
                result += current.getElement() + " ";
                current = current.getNext();
            }
        }
        return result;
    }

    public double suma() {
        double suma = 0;
        LinearNode<T> current = front;

        while (current != null) {
            if (current.getElement() instanceof Integer) {
                suma += (Integer) current.getElement();
            } else if (current.getElement() instanceof Double) {
                suma += (Double) current.getElement();
            } else {
                throw new ADTsException("No es un valor numerico");
            }
            current = current.getNext();
        }
        return suma;
    }

    public String toString(LinkedStruct<T> ls) {
        String result = "";
        LinearNode<T> current = ls.front;

        while (current != null) {
            result += current.getElement() + " ";
            current = current.getNext();
        }

        return result;
    }

}
