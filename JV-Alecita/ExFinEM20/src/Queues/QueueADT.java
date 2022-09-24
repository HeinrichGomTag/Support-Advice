package Queues;
/**
 * QueueADT<T> defines the interface to a queue collection.
 */
public interface QueueADT<T> {

    /**  Adds one element to the rear of this queue.
     */
    public void enqueue (T element);

    /**  Removes and returns the element at the front of this queue.
     */
    public T dequeue();

    /**  Returns without removing the element at the front of this queue.
     */
    public T first();

    /**  Returns true if this queue contains no elements.
     */
    public boolean isEmpty();

    /**  Returns a string representation of this queue.
     *   ONLY TO DO PRINT's, NO OTHER OPERATIONS.
     */
    public String toString();

    //++++++++++++++++++++++++++++++++++++++++++++++++

}
