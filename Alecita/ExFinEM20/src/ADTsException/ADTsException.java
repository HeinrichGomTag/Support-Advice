package ADTsException;

/**
 *  Represent wrong situations:
 *     - a parameter error,
 *     - a Null Pointer Reference,
 *     - an Empty Collection,
 *     - an Element Not Found.
 */

public class ADTsException extends RuntimeException {
    /** Sets up this exception with an appropriate message.
     */
    public ADTsException(String collection) {
        super ("> > > ADTsException:  " + collection);
  }
}
