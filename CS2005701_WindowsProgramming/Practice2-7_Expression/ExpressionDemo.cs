using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExpressionDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("---increment operator---");
            int x = 10, y = x++;
            Console.WriteLine("x = 10; y = x++; ---> x = " + x + ", y = " + y);
            x = 10; y = ++x;
            Console.WriteLine("x = 10; y = ++x; ---> x = " + x + ", y = " + y);

            Console.WriteLine("---assignment operator---");
            int a = 10; a += 10;
            Console.WriteLine("a = 10; a += 10; ---> a = " + a);
            string s = "2 * 2 = 4;";
            s += " 3 * 3 = 9";
            Console.Write("s = \"2 * 2 = 4;\"; s += \"3 * 3 = 9\";");
            Console.WriteLine(" ---> s = \"" + s + "\"");

            Console.WriteLine("---relational operator---");
            a = 16;
            int b = 13;
            Console.WriteLine("a = 16, b = 13; a == b ---> " + (a == b));
            Console.WriteLine("a = 16, b = 13; a >= b ---> " + (a >= b));
            bool flag = a <= (b + 2);
            Console.WriteLine("bool flag = a <= (b + 2); flag ---> " + (a <= (b + 2)));

            Console.WriteLine("---logical operator---");
            Console.WriteLine("!(20 > 10) ---> " + !(20 > 10));
            Console.WriteLine("20 > 10 && 15 <= 12 ---> " + (20 > 10 && 15 <= 12));
            Console.WriteLine("20 > 10 || 15 <= 12 ---> " + (20 > 10 || 15 <= 12));
        }
    }
}