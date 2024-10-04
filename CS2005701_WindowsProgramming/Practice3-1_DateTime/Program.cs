using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OBPDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("-----Default-----");
            DateTime dt = new DateTime();
            Console.WriteLine(dt.Year + "/" + dt.Month + "/" + dt.Day);
            Console.WriteLine(dt.ToString());
            
            Console.WriteLine("-------Set-------");
            dt = new DateTime(2021, 9, 2);
            Console.WriteLine(dt.Year + "/" + dt.Month + "/" + dt.Day);

            Console.WriteLine("-------Now-------");
            dt = DateTime.Now;
            Console.WriteLine(dt.Year + "/" + dt.Month + "/" + dt.Day);
            Console.WriteLine(dt.Hour + ":" + dt.Minute + ":" + dt.Second);
            Console.WriteLine(dt.ToString());

            Console.WriteLine("-----Random-----");
            Random rd = new Random();
            int yy = rd.Next(2021, 2026);
            int mm = rd.Next(1, 13);
            int dd = rd.Next(1, 31);
            DateTime dt1 = new DateTime(yy, mm, dd);
            yy = rd.Next(2021, 2026);
            mm = rd.Next(1, 13);
            dd = rd.Next(1, 31);
            DateTime dt2 = new DateTime(yy, mm, dd);
            Console.WriteLine(dt1.Year + "/" + dt1.Month + "/" + dt1.Day);
            Console.WriteLine(dt2.Year + "/" + dt2.Month + "/" + dt2.Day);
        }
    }
}
