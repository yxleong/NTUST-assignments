using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WriteRead
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("My first C# program!");
            Console.WriteLine("no need type System also can");
            Console.Write("Please input any string: ");

            string input;
            input = Console.ReadLine(); // let the inputted string to become a variable 'input'
            Console.WriteLine("Your input is: " + input);
        }
    }
}
