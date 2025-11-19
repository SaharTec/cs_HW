import java.util.LinkedList;
public class BigNum {
    private Link head;
    private Link tail;

    // Constructor to create a BigNum from a string of digits
    // Input: A string of digits representing a large non-negative integer (e.g., "123456789").
    // This method should convert the string into a doubly linked list where each node stores a single digit.
    // The most significant digit will be stored at the head, and the least significant digit will be at the tail.
    public BigNum(String numberStr) {
        int size = numberStr.length();
        for(int i = 0; i < size; i++){
            char current = numberStr.charAt(i);
            int dig = Character.getNumericValue(current);

            Link newLink = new Link(dig);
            if(head == null){
                head = newLink;
                tail = newLink;
            }else{
                tail.next = newLink;
                newLink.prev = tail;
                tail = newLink;
            }
        }
    }

    // Default constructor that creates an empty BigNum with no digits.
    public BigNum() { }

    // Subtracts two BigNum objects and returns the result as a new BigNum
    // Input: Another BigNum object representing a large non-negative integer.
    // It can be assumed that this BigNum is greater than or equal to the other.
    // The subtraction should be done digit by digit, borrowing when needed.
    // Output: A new BigNum object representing the difference between the two numbers.
    public BigNum subtract(BigNum other) {
        BigNum result = new BigNum();
        Link t1 = this.tail;
        Link t2 = other.tail;
        int borrow = 0;

        while (t1 != null) { // Assumption: this >= other, so only need to check t1
            int dig1 = t1.digit;
            int dig2 = (t2 != null) ? t2.digit : 0;

            int diff = dig1 - dig2 - borrow;

            if (diff < 0) {
                diff += 10;
                borrow = 1; // Correction: Set borrow to 1
            } else {
                borrow = 0;
            }

            Link newLink = new Link(diff);

            // Corrected Insertion at HEAD of the result list
            if (result.head == null) {
                result.head = newLink;
                result.tail = newLink;
            } else {
                newLink.next = result.head;
                result.head.prev = newLink;
                result.head = newLink;
            }

            t1 = t1.prev;
            if (t2 != null) t2 = t2.prev;
        }

        // Correction: Remove leading zeros AFTER the loop
        while (result.head != null && result.head.digit == 0 && result.head.next != null) {
            result.head = result.head.next;
            result.head.prev = null;
        }

        return result;
    }


    // Adds two BigNum objects and returns the result as a new BigNum
    // Input: Another BigNum object representing a large non-negative integer.
    // This method should add the current BigNum object with the input BigNum digit by digit.
    // It must handle carry-over when the sum of two digits exceeds 9.
    // Output: A new BigNum object representing the sum of the two numbers.
    public BigNum add(BigNum other) {
        BigNum result = new BigNum();
        Link t1 = this.tail;
        Link t2 = other.tail;
        int carry = 0;

        while (t1 != null || t2 != null || carry > 0){
            int dig1 = (t1 != null) ? t1.digit : 0;
            int dig2 = (t2 != null) ? t2.digit : 0;

            int sum = dig1 + dig2 + carry;
            carry = sum / 10;
            int dig = sum % 10;

            Link newLink = new Link(dig);

            // Corrected Insertion at HEAD of the result list
            if(result.head == null){
                result.head = newLink;
                result.tail = newLink;
            }else{
                newLink.next = result.head;    // New node points to the old head
                result.head.prev = newLink;    // Old head points back to the new node
                result.head = newLink;         // Update the head pointer
            }

            if(t1 != null) t1 = t1.prev;
            if(t2 != null) t2 = t2.prev;
        }
        return result;
    }

    // Multiplies two BigNum objects and returns the result as a new BigNum
    // Input: Another BigNum object representing a large non-negative integer.
    // This method multiplies the current BigNum object with the input BigNum, handling partial products and carries.
    // You need to shift the partial results as required, similar to how manual long multiplication is done.
    // Output: A new BigNum object representing the product of the two numbers.
    public BigNum multiply(BigNum other) {
        BigNum result = new BigNum("0");
        Link t2 = other.tail;
        int position = 0;

        while (t2 != null){
            BigNum partialProduct = new BigNum();
            int carry = 0;
            int otherDigit = t2.digit; // Fetch multiplier digit once

            Link t1 = this.tail;

            while (t1 != null || carry > 0){
                int dig1 = (t1 != null) ? t1.digit : 0;

                // Correction: Use multiplication logic
                int product = dig1 * otherDigit + carry;

                carry = product / 10;
                int dig = product % 10;

                Link newLink = new Link(dig);

                // Corrected Insertion at HEAD of the partialProduct list
                if(partialProduct.head == null){
                    partialProduct.head = newLink;
                    partialProduct.tail = newLink;
                }else{
                    newLink.next = partialProduct.head;
                    partialProduct.head.prev = newLink;
                    partialProduct.head = newLink;
                }

                if(t1 != null) t1 = t1.prev;
            }

            // Shifting (Appending zeros to the tail)
            for(int i = 0; i < position; i++){
                Link zeroLink = new Link(0);
                if(partialProduct.tail != null){
                    partialProduct.tail.next = zeroLink;
                    zeroLink.prev = partialProduct.tail;
                    partialProduct.tail = zeroLink;
                }
            }

            // Add the partial product to the main result
            // NOTE: This relies on the corrected 'add' method working
            result = result.add(partialProduct);

            t2 = t2.prev;
            position++;
        }
        return result;
    }

    // Converts the linked list back to a string representation of the number
    // Output: A string that represents the linked list as a number (e.g., "123456789").
    public String toString() {
        StringBuilder result = new StringBuilder();
        Link current = head;
        while (current != null) {
            result.append(current.digit);
            current = current.next;
        }
        return result.toString();
    }
}
