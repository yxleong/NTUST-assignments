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
            Console.WriteLine("Boolean: {0} and {1}", true, false);

            Console.WriteLine("Char: {0}, {1}, and {2}", 'A', '\u0041', '\u0042');  // Unicode Character
            Console.WriteLine("65 is " + (char) 65);
            Console.WriteLine("A is " + (int) 'A');

            Console.WriteLine("String: {0}, {1}", "Hello", "C#");
        }
    }
}