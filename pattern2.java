// Update the code below to solve the problem.
import java.util.Scanner;


class Codechef
{
	public static void main (String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        // Update the code below this line.
        if(N <= 0)
        {
            return;
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N - 1; j++)
            {
                System.out.println(" ");
            }
            for(int k = 1; k <= 2 * i - 1; k++)
            {
                System.out.println("*");
            }
            System.out.println();
        }

	}
}
