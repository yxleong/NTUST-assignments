using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculation
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("num1: "); // get input
            string input1 = Console.ReadLine(); // save input as variable
            int num1 = Convert.ToInt32(input1); // str to int

            Console.Write("num2: ");
            //string input2 = Console.ReadLine();
            //int num2 = Convert.ToInt32(input2);
            int num2 = Convert.ToInt32(Console.ReadLine());

            // Choice 1:
            //Console.WriteLine(num1 + num2);

            // Choice 2:
            int result = num1 + num2;
            Console.WriteLine(num1 + " + " + num2 + " = " + result);

            // Choice 3:
            //Console.Write(num1);
            //Console.Write(" + ");
            //Console.Write(num2);
            //Console.Write(" = ");
            //Console.WriteLine(result); // WriteLine: to move to next line

            // Choice 4:
            //Console.WriteLine("{0} + {1} = {2}", num1, num2, result);
        }
    }
}


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataTypes
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Integer: " + 100);
            Console.WriteLine("Float: " + 3.14159);
            Console.WriteLine("Boolean: {0} and {1}" + true, false);

            Console.WriteLine("Char: {0}, {1}, and {2}", 'A', '\u0041', '\u0042');
            Console.WriteLine("65 is: ", + (char)65);
            Console.WriteLine("A is: ", + (int)'A');

            Console.WriteLine("String: {0}, {1}", "Hello", "C#");

        }
    }
}

