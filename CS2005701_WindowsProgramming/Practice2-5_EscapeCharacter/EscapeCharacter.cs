using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EscapeCharacter
{
    class Program
    {
        static void Main(string[] args)
        {
            char ch1 = 'A', ch2 = '\u0041';
            Console.WriteLine("Variable ch1 is character " + ch1);
            Console.WriteLine("Variable ch2 is character " + ch2);

            ch1 = '\''; // sign '
            ch2 = '\\'; // sign \
            Console.WriteLine("Variable ch1 becomes character " + ch1);
            Console.WriteLine("Variable ch2 becomes character " + ch2);

            Console.WriteLine("My \"C#\" program"); // sign ""
            Console.WriteLine("My \u0022C#\u0022 program"); // sign ""
        }
    }
}
