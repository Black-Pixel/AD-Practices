using System;
using System.Collections.Generic;
using System.Diagnostics; //Stopwatch
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortingAlgorithms
{


    class Program
    {
        static Stopwatch sw = new Stopwatch();
        static void Main(string[] args)
        {
            char choice = '0';

            while (choice != 'e')
            {
                int[] a = new int[10] { -5, 13, -32, 7, -3, 17, 23, 12, -35, 19 };
                int size = 10;
                System.Console.WriteLine("1. bubbleSort \n 2. insertionSort \n 3. selectionSort \n 4. quickSort \n 5. Runtime insertionSort \n 6. Runtime quickSort \n 7. insertionSort 2 \n 8. bubbleSort 2 \n 9. selectionSort 2 \n 10. insertionSort recursive \n e. Exit");
                choice = (char)System.Console.Read();
                System.Console.ReadLine(); //consume buffer
                System.Console.WriteLine("Default array: ");
                printArray(a, size);
                if (choice == '1')
                {
                    bubbleSort(a, size);
                }
                else if (choice == '2')
                {
                    insertionSort(a, size);
                }
                else if (choice == '3')
                {
                    selectionSort(a, size);
                }
                else if (choice == '4')
                {
                    quickSort(a, 0, size - 1);
                    printArray(a, size);
                }
                else if (choice == '5')
                {
                    insertionSortRuntime();
                }
                else if (choice == '6')
                {
                    quickSortRuntime();
                }
                else if (choice == '7')
                {
                    insertionSort2(a, size);
                }
                else if (choice == '8')
                {
                    bubbleSort2(a, size);
                }
                else if (choice == '9')
                {
                    selectionSort2(a, size);
                }
                else if (choice == 10)
                {
                    insertionSortRec(0, a, size);
                }

            }
        }

        static void printArray(int[] array, int size)
        {
            System.Console.WriteLine();
            for (int i = 0; i < size; ++i)
            {
                System.Console.Write(array[i] + "  ");
            }
            System.Console.WriteLine();

        }

        static void bubbleSort(int[] array, int size)
        {
            int smaller;
            printArray(array, size);
            int i;
            int j;
            for (i = 0; i < size; ++i)
            {
                for (j = 0; j < size - 1; ++j)
                {
                    if (array[j] > array[j + 1])
                    {
                        smaller = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = smaller;
                        printArray(array, size);
                    }
                }
            }
        }

        static void bubbleSort2(int[] array, int size) // from right to left
        {
            int bigger;
            printArray(array, size);
            int i;
            int j;
            for (i = size - 1; i > 0; --i)
            {
                for (j = size - 1; j > 0; --j)
                {
                    if (array[j] < array[j - 1])
                    {
                        bigger = array[j - 1];
                        array[j - 1] = array[j];
                        array[j] = bigger;
                        printArray(array, size);
                    }
                }
            }
        }

        static void insertionSort(int[] array, int size)
        {
            int i;
            int j;
            int smaller;
            for (i = 1; i < size - 1; ++i)
            {
                j = i;
                if (array[i] > array[i + 1])
                {
                    smaller = array[i + 1];
                    array[i + 1] = array[i];
                    array[i] = smaller;
                    printArray(array, size);
                }
                while (j > 0 && array[j] < array[j - 1])
                {
                    smaller = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = smaller;
                    printArray(array, size);
                    --j;
                }
            }
        }

        static void insertionSort2(int[] array, int size) // from right to left
        {
            int i;
            int j;
            int bigger;
            for (i = size - 1; i > 0; --i)
            {
                j = i;
                if (array[i - 1] > array[i])
                {
                    bigger = array[i - 1];
                    array[i - 1] = array[i];
                    array[i] = bigger;
                    printArray(array, size);
                }
                while (j < size - 1 && array[j] > array[j + 1])
                {
                    bigger = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = bigger;
                    printArray(array, size);
                    ++j;
                }
            }
        }

        static void selectionSort(int[] array, int size)
        {
            int smallest = array[0];
            int sorted = 0;
            int unsorted = size;
            int i;
            while (sorted != size)
            {
                for (i = sorted; i < unsorted; ++i)
                {
                    if (array[sorted] > array[i])
                    {
                        smallest = array[i];
                        array[i] = array[sorted];
                        array[sorted] = smallest;
                        printArray(array, size);
                    }
                }
                ++sorted;
            }
        }

        static void selectionSort2(int[] array, int size) // from right to left
        {
            int biggest = array[size - 1];
            int sorted = 0;
            int unsorted = size - 1;
            int i;
            while (unsorted >= 0)
            {
                for (i = unsorted; i >= sorted; --i)
                {
                    if (array[unsorted] < array[i])
                    {
                        biggest = array[i];
                        array[i] = array[unsorted];
                        array[unsorted] = biggest;
                        printArray(array, size);
                    }
                }
                --unsorted;
            }
        }

        public static void quickSort(int[] elements, int left, int right)
        {
            int i = left, j = right;
            Random random = new Random();
            int pivot = elements[random.Next(left, right)];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0)
                {
                    i++;
                }

                while (elements[j].CompareTo(pivot) > 0)
                {
                    j--;
                }

                if (i <= j)
                {
                    // Swap
                    int tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            // Recursive calls
            if (left < j)
            {
                quickSort(elements, left, j);
            }

            if (i < right)
            {
                quickSort(elements, i, right);
            }
        }

        static void insertionSortRuntime()
        {
            List<int> myList = new List<int>();
            int n = 100;
            TimeSpan ts = new TimeSpan();
            TimeSpan oneMinute = TimeSpan.FromMinutes(1);

            while (ts < oneMinute)
            {
                fillRandom(myList, n);
                sw.Start();
                insertionSortList(myList, n);
                sw.Stop();
                ts = sw.Elapsed;
                sw.Reset();
                System.Console.WriteLine();
                System.Console.WriteLine("n: " + n + "\n time: " + ts);
                n += n;
                System.Threading.Thread.Sleep(2000);
            }

        }

        static void quickSortRuntime()
        {
            List<int> myList = new List<int>();
            int n = 100;
            TimeSpan ts = new TimeSpan();
            TimeSpan oneMinute = TimeSpan.FromMinutes(1);

            while (ts < oneMinute)
            {
                fillRandom(myList, n);
                sw.Start();
                quickSortList(myList, 0, n - 1);
                sw.Stop();
                ts = sw.Elapsed;
                sw.Reset();
                System.Console.WriteLine();
                System.Console.WriteLine("n: " + n + "\n time: " + ts);
                n += n;
                System.Threading.Thread.Sleep(2000);
            }

        }

        static void fillRandom(List<int> list, int n)
        {
            Random random = new Random();
            list.Clear();
            for (int i = 0; i < n; ++i)
            {
                if ((i % 2) == 0)
                {
                    list.Add(random.Next(0, n));
                }
                else
                {
                    list.Add(random.Next(n, n * 2));
                }
            }
        }

        static void insertionSortList(List<int> array, int size)
        {
            int i;
            int j;
            int smaller;
            for (i = 1; i < size - 1; ++i)
            {
                j = i;
                if (array[i] > array[i + 1])
                {
                    smaller = array[i + 1];
                    array[i + 1] = array[i];
                    array[i] = smaller;
                }
                while (j > 0 && array[j] < array[j - 1])
                {
                    smaller = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = smaller;
                    --j;
                }
            }
        }

        public static void quickSortList(List<int> elements, int left, int right)
        {
            int i = left, j = right;
            int pivot = elements[(left + right) / 2];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0)
                {
                    i++;
                }

                while (elements[j].CompareTo(pivot) > 0)
                {
                    j--;
                }

                if (i <= j)
                {
                    // Swap
                    int tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            // Recursive calls
            if (left < j)
            {
                quickSortList(elements, left, j);
            }

            if (i < right)
            {
                quickSortList(elements, i, right);
            }
        }

        public static void insertionSortRec(int i, int[] array, int size)
        {
            if (i < size)
            {
                int j;
                int temp = array[i];

                for (j = i; j > 0 && array[j - 1] > temp; --j)
                {
                    array[j] = array[j - 1];
                }
                array[j] = temp;

                insertionSortRec(++i, array, size);
            }
        }
    }
}


