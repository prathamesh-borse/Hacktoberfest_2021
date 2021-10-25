/*
 Java implementation of heap sort
 Input format: 
 	Enter number of elements in the array: 5
	Enter 5 elements 
	5 4 7 3 1
	
 Output: 
	Elements in array:
	5 4 7 3 1 
	Elements after sorting:
	1 3 4 5 7 
 */
import java.util.Scanner;
public class HeapSort {

  public static void heapify(int a[], int i, int n) {

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int temp, largest;

    if (l < n && a[l] > a[i])
      largest = l;
    else
      largest = i;

    if (r < n && a[r] > a[largest])
      largest = r;

    if (largest != i) {
      temp = a[largest];
      a[largest] = a[i];
      a[i] = temp;

      heapify(a, largest, n);
    }

  }

  public static void bheap(int a[]) {

    for (int i = (a.length / 2) - 1; i >= 0; i--) {

      heapify(a, i, a.length);

    }

  }

  public static void Sort(int a[]) {
    int temp, j, i;

    bheap(a);

    for (i = (a.length) - 1; i > 0;) {
      temp = a[0];
      a[0] = a[i];
      a[i] = temp;
      heapify(a, 0, i--);

    }

  }

  public static void printarray(int a[]) {
    for (int i = 0; i < a.length; i++) {

      System.out.print(a[i] + " ");
    }

  }
  public static void main(String[] args) {
    int n, res, i;
    Scanner s = new Scanner(System.in);
    System.out.print("Enter number of elements in the array: ");
    n = s.nextInt();
    int a[] = new int[n];
    System.out.println("Enter " + n + " elements ");
    for (i = 0; i < n; i++) {
      a[i] = s.nextInt();
    }

    System.out.println("Elements in array: ");
    printarray(a);
    Sort(a);
    System.out.println("\nElements after sorting:");
    printarray(a);

  }

}
