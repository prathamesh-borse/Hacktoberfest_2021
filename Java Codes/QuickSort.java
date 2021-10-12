package Sorting;

class QuickSort {
  public static void main(String[] args) {
    int[] ar = { 2, 2, 5, 1, 6, 6, 9, 11, 12 };
    quickSort(ar, 0, ar.length - 1);
    for (int i : ar) {
      System.out.print(i + " ");
    }
  }

  static void swap(int[] ar, int i, int j) {
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
  }

  static void quickSort(int[] ar, int l, int h) {
    if (l < h) {
      int p = partition(ar, l, h);
      quickSort(ar, l, p - 1);
      quickSort(ar, p + 1, h);
    }
  }

  public static int partition(int[] ar, int l, int h) {
    int pivot = ar[h];
    int i = l;
    for (int j = l; j <= h; j++) {
      if (ar[j] < pivot) {
        swap(ar, i++, j);
      }
    }
    swap(ar, i, h);
    return i;
  }
}