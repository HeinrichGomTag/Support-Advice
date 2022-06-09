
package Queues;
import ADTsException.ADTsException;

/** CircularArrayQueue represents an array implementation of a queue in 
  * which the indexes for the front and rear of the queue circle back to 0
  * when they reach the end of the array.
  */
public class CircularArrayQueue<T> implements QueueADT<T> {
    private final static int DEFAULT_CAPACITY = 100;
    private int front, rear, count;
    private T[] queue; 
  
    /** Creates an empty queue using the specified capacity.
     */
    public CircularArrayQueue(int initialCapacity) {
        front = rear = count = 0;
        queue = ( (T[])(new Object[initialCapacity]) );
    }
  
    /** Creates an empty queue using the default capacity.
     */
    public CircularArrayQueue() {
        this(DEFAULT_CAPACITY);
    }
  
    /** Adds the specified element to the rear of this queue, expanding
     * the capacity of the queue array if necessary.
     */
    public void enqueue(T element) {
    if ( element == null )
            throw new ADTsException("(enqueue) element null.\n");
    
        if (count == queue.length)
            expandCapacity();   //Cola llena.

        queue[rear]= element;
        rear= (rear+1)%queue.length;
        count++;
    }
  
    /** Removes the element at the front of this queue and returns a
     * reference to it. Throws an EmptyCollectionException if the
     * queue is empty.
     */
    public T dequeue() throws ADTsException {
        T result=null;

        if ( isEmpty() )
            throw new ADTsException("Q-VACIA-dequeue.\n");

        result= queue[front];
        queue[front]= null;
        front= (front+1) % queue.length;
        count--;

        return result;
    }
  
    /** Returns a reference to the element at the front of this queue.
     * The element is not removed from the queue.  Throws an
     * EmptyCollectionException if the queue is empty.
     */
    public T first() {
        if ( this.isEmpty() )
            throw new ADTsException("Q-VACIA-first().\n");

        return queue[front];
    }
  
    /** Returns true if this queue is empty and false otherwise.
     */
    public boolean isEmpty() {
        return (count == 0);
    }

  
    /**  Returns a string representation of this queue.
     *   ONLY TO DO PRINT's, NO OTHER OPERATIONS.
     */
    public String toString() {
        String cade = "{ ";
        int f, s;
        
        if( !isEmpty() ) {
            s= count;
            f= front;
            while( s > 0 ) {
                cade= cade + queue[f] + " ";
                f= (f+1) % queue.length;
                s--;
            }
        }
        cade = cade + "}";
        
        return cade;
    }

    /** Creates a new array to store the contents of this queue with
     * twice the capacity of the old one.
     */
    private void expandCapacity() {
        T[] larger = (T[])(new Object[queue.length *2]);
    
        for(int scan=0; scan < count; scan++) {
            larger[scan] = queue[front];
            front = (front+1) % queue.length;
        }
    
        front = 0;
        rear = count;
        queue = larger;
    }



}






















