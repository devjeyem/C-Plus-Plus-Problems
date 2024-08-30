import java.util.Scanner;

public class NumberCounter 
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int l = 16;
        int[] arr = new int[l];
        int[] count = new int[300];
        int offset = 200;

        System.out.println("Enter 16 numbers [duplicates allowed].");
        for (int i = 0; i < l; i++) 
        {
            arr[i] = s.nextInt();
            count[arr[i] + offset]++;
        }
        System.out.println();

        System.out.println("\tN      Count");
        for (int i = count.length - 1; i >= 0; i--)
         {
            if (count[i] > 0)
            {
                System.out.println( "\t" + (i - offset) + "       " + count[i]);
            }
        }
    }
}