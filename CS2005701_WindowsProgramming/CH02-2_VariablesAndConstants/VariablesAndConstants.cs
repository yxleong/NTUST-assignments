using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VariablesAndConstants
{
    class Program
    {
        static void Main(string[] args)
        {
            char ch = 'A';
            int i = 'A';

            Console.WriteLine("character variable ch is " + ch);
            Console.WriteLine("integer variable i is " + i);

            Console.WriteLine("convert character variable ch to integer is " + (int)ch);
            Console.WriteLine("convert integer variable i to character is " + (char)i);

            string s1 = "Visual C#";
            string s2 = "Visual C#\tprogramming";   // tab
            string s3 = "Visual C#\nprogramming";   // newline
            string s4 = "Microsoft .NET Framework";

            Console.WriteLine(s1);
            Console.WriteLine(s2);
            Console.WriteLine(s3);
            Console.WriteLine(s4 + "\n" + s1);  // combine two string

            const double PI = 3.14159;
            double r = 10;
            Console.WriteLine("radius is " + r);
            Console.WriteLine("circumference is " + 2 * PI * r);
            Console.WriteLine("area is " + PI * r * r);

            //PI = 3.14;
            // will be wrong since already const to fix the value
            Console.WriteLine("circumference is " + (2 * PI * r).ToString("0.00"));
            Console.WriteLine("area is " + (PI * r * r).ToString("F2")); // two decimal place
        }
    }
}