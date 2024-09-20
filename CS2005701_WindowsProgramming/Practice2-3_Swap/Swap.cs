using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Swap
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 5, b = 10;
            Console.WriteLine("before swapping: a = " + a + ", b = " + b);
            int temp = a;
            a = b;
            b = temp;
            Console.WriteLine("after swapping: a = " + a + ", b = " + b);
        }
    }
}