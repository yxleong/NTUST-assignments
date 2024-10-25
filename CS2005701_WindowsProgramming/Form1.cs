using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace B11015016
{
    public partial class Form1 : Form
    {
        private const int StuNum = 5;
        private const int SubNum = 3;

        private readonly string[] names = { "Alice", "Bob", "Charlie", "Dave", "Eve" };
        private readonly int[,] scores =
        {
           { 98, 80, 50, 76, 69 },  // math
           { 85, 90, 78, 54, 67 },  // chinese
           { 75, 88, 62, 49, 81 }   // english
        };

        private const int MATH = 0;
        private const int CN = 1;
        private const int ENG = 2;

        public Form1()
        {
            InitializeComponent();
        }

        private string GenerateHeader()
        {
            return "Name\tMath\tChinese\tEnglish";
        }

        private string GenerateSeparator(int newColNum)
        {
            var sep = new string('=', 5) + "\t" + new string('=', 5) + "\t" 
                + new string('=', 6) + "\t" + new string('=', 6);

            for (int i = 0; i < newColNum; i++) 
            {
                sep += "\t" + new string('=', 5);
            }
            return sep;
        }

        private void LoadData(object sender, EventArgs e)
        {
            var result = new StringBuilder();
            result.AppendLine(GenerateHeader());
            result.AppendLine(GenerateSeparator(0));

            for (int stu = 0; stu < StuNum; stu++)
            {
                result.AppendLine($"{names[stu]}\t{scores[MATH, stu]}\t{scores[CN, stu]}\t{scores[ENG, stu]}");
            }

            result.AppendLine(GenerateSeparator(0));
            txtOutput.Text = result.ToString();
        }

        private void btnCalc_Click(object sender, EventArgs e)
        {
            int newColCounter = 0;
            var result = new StringBuilder();

            result.Append(GenerateHeader());
            if (chkAvg.Checked)
            {
                result.Append("\tAverage");
                newColCounter++;
            }
            if (chkFailNum.Checked)
            {
                result.Append("\tFail"); 
                newColCounter++;
            }
            if (chkRank.Checked)
            {
                result.Append("\tRank");
                newColCounter++;
            }
            if (chkWeightAvg.Checked)
            {
                result.Append("\tWAVG");
                newColCounter++;
            }
            if (chkFailCredit.Checked)
            {
                result.Append("\tFail Cr.");
                newColCounter++;
            }
            result.AppendLine();
            result.AppendLine(GenerateSeparator(newColCounter));

            double[] avgs = new double[StuNum];
            int[] failCounter = new int[StuNum];
            int[] ranks = new int[StuNum];

            for (int stu = 0; stu < StuNum; stu++)
            {
                int stuTotal = scores[MATH, stu] + scores[CN, stu] + scores[ENG, stu];

                if (chkAvg.Checked)
                {
                    avgs[stu] = stuTotal / (double)SubNum;
                }

                if (chkFailNum.Checked)
                {
                    failCounter[stu] = (scores[MATH, stu] < 60 ? 1 : 0) + (scores[CN, stu] < 60 ? 1 : 0) + (scores[ENG, stu] < 60 ? 1 : 0);
                }

                if (chkRank.Checked)
                {
                    ranks[stu] = 1;
                    for (int i = 0; i < StuNum; i++)
                    {
                        if (scores[MATH, i] + scores[CN, i] + scores[ENG, i] > stuTotal)
                        {
                            ranks[stu]++;
                        }
                    }
                }

                result.Append($"{names[stu]}\t{scores[MATH, stu]}\t{scores[CN, stu]}\t{scores[ENG, stu]}");

                if (chkAvg.Checked) result.Append($"\t{avgs[stu]:F2}");
                if (chkFailNum.Checked) result.Append($"\t{failCounter[stu]}");
                if (chkRank.Checked) result.Append($"\t{ranks[stu]:F2}");

                result.AppendLine();
            }

            result.AppendLine(GenerateSeparator(newColCounter));

            if (chkCourseAvg.Checked)
            {
                result.Append("Average\t");
                for(int sub = 0; sub < SubNum; sub++)
                {
                    int total = 0;
                    for(int stu = 0; stu < StuNum; stu++)
                    {
                        total += scores[sub, stu];
                    }
                    result.Append($"{(total / (double)StuNum):F2}\t");
                }
                result.AppendLine();
            }

            txtOutput.Text = result.ToString();
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            int index = Array.IndexOf(names, name);

            if(index >= 0)
            {
                txtOutput.Text = $"Name: {names[index]}\r\nMath: {scores[MATH, index]}\r\nChinese: {scores[CN, index]}\r\nEnglish: {scores[ENG, index]}\r\n";
            }
            else
            {
                txtOutput.Text = $"??? The data for student '{name}' does not exist ???\r\n";
            }
        }
    }
}
