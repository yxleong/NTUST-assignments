using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DivisionDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Num1: ");
            int num1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Num2: ");
            int num2 = Convert.ToInt32(Console.ReadLine());

            double result = (double)num1 / num2;
            Console.WriteLine(num1 + " / " + num2 + " = " + result);

            // ===== precise to 0.01 =====

            // Method 1: {0:0.00}
            Console.WriteLine("{0} / {1} = {2:0.00}", num1, num2, result);

            // Method 2: num.ToString("F2")
            Console.WriteLine(num1 + " / " + num2 + " = " + result.ToString("F2"));

            // Method 3: num.ToString("0.00")
            Console.WriteLine(num1 + " / " + num2 + " = " + result.ToString("0.00"));

            // Method 4: string.Format("{0:0.00}", num)
            Console.WriteLine(num1 + " / " + num2 + " = " + string.Format("{0:0.00}", result));

        }
    }
}