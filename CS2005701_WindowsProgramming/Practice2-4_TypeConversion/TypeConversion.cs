using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TypeConversion
{
    class Program
    {
        static void Main(string[] args)
        {
            // inplicit conversion
            int k = 30000;
            long l = k;
            Console.WriteLine("int k = " + k + ", long l = " + l);

            short s = 32767;
            Console.WriteLine("short s = " + s);
            // s = 40000
                // wrong: 40,000 > (short)32,767
            // s = k
                //wrong: (k)int > (s)short

            // explicit conversion
            s = (short)k;
            Console.WriteLine("int k = " + k + ", short s = " + s);
            k = 40000;
            s = (short)k; // will become negative
            Console.WriteLine("int k = " + k + ", short s = " + s);

            // int i = 1.23f;
                // wrong: float > int
            //int i = 1.23f;
                // wrong: double > int
            int i = (int)1.23f;
            Console.WriteLine("int i = " + i);

            // type conversion in arithmetic calculation
            int num = 100;
            double d;
            d = num + 123.45f;
            Console.WriteLine("int num = " + num + ", d = " + d);

            // the way to use type conversion
            int a = 17, b = 5;
            float f;
            f = a / b;
            Console.WriteLine("f = " + f);
            f = (float)a / (float)b;
            Console.WriteLine("f = " + f);
        }
    }
}
