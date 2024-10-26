using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace B11015016
{
    public partial class Form1 : Form
    {
        private const int STU_NUM = 5;
        private const int SBJ_NUM = 3;

        private readonly string[] names = { "Alice", "Bob", "Charlie", "Dave", "Eve" };
        private readonly int[,] scores = new int[SBJ_NUM, STU_NUM];

        private const int CN = 1;
        private const int ENG = 2;
        private const int MATH = 0;

        private const int W_CN = 2;
        private const int W_ENG = 3;
        private const int W_MATH = 4;

        private void GenerateRandomScores()
        {
            Random rand = new Random();
            for (int stu = 0; stu < STU_NUM; stu++)
            {
                scores[MATH, stu] = rand.Next(0, 101);  // math:0~100
                scores[CN, stu] = rand.Next(0, 101);    // chinese
                scores[ENG, stu] = rand.Next(0, 101);   // english
            }
        }

        public Form1()
        {
            InitializeComponent();
            GenerateRandomScores();
        }

        private string GenerateHeader()
        {
            return "Name\tMath\tChinese\tEnglish";
        }

        private string GenerateSeparator(int newColNum)
        {
            var sep = new string('=', 5) + "\t" + new string('=', 4) + "\t"
                + new string('=', 6) + "\t" + new string('=', 6);

            for (int i = 0; i < newColNum; i++)
            {
                sep += "\t" + new string('=', 5);
            }
            return sep;
        }

        double[] avgs = new double[STU_NUM];
        int[] ranks = new int[STU_NUM];
        int[] failCounter = new int[STU_NUM];
        double[] wavgs = new double[STU_NUM];
        int[] failCredits = new int[STU_NUM];
        List<(int index, int wtotal)> stuRankList = new List<(int, int)>();
        int[] wtotal = new int[STU_NUM];

        void LoadData(StringBuilder result, int stu)
        {
            result.Append($"{names[stu]}\t{scores[MATH, stu]}\t{scores[CN, stu]}\t{scores[ENG, stu]}");

            if (chkAvg.Checked) result.Append($"\t{avgs[stu]:F2}");
            if (chkFailNum.Checked) result.Append($"\t{failCounter[stu]}");
            if (chkRank.Checked) result.Append($"\t{ranks[stu]}");
            if (chkWeightAvg.Checked) result.Append($"\t{wavgs[stu]:F2}");
            if (chkFailCredit.Checked) result.Append($"\t{failCredits[stu]}");
        }

        private void btnCalc_Click(object sender, EventArgs e)
        {
            stuRankList.Clear();
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
            if (chkSort.Checked)
            {
                result.Append("\tTotal");
                newColCounter++;
            }
            result.AppendLine();

            result.AppendLine(GenerateSeparator(newColCounter));
            for (int stu = 0; stu < STU_NUM; stu++)
            {
                wtotal[stu] = W_MATH * scores[MATH, stu] + W_CN * scores[CN, stu] + W_ENG * scores[ENG, stu];
                wavgs[stu] = wtotal[stu] / (double)(W_MATH + W_CN + W_ENG);

                if (chkAvg.Checked)
                {
                    int stuTotal = scores[MATH, stu] + scores[CN, stu] + scores[ENG, stu];
                    avgs[stu] = stuTotal / (double)SBJ_NUM;
                }

                if (chkFailNum.Checked)
                {
                    failCounter[stu] = (scores[MATH, stu] < 60 ? 1 : 0) + (scores[CN, stu] < 60 ? 1 : 0) + (scores[ENG, stu] < 60 ? 1 : 0);
                }

                if (chkRank.Checked)
                {
                    ranks[stu] = 1;
                    for (int i = 0; i < STU_NUM; i++)
                    {
                        if (W_MATH * scores[MATH, i] + W_CN * scores[CN, i] + W_ENG * scores[ENG, i] > wtotal[stu])
                        {
                            ranks[stu]++;
                        }
                    }
                }

                if (chkFailCredit.Checked)
                {
                    failCredits[stu] = (scores[MATH, stu] < 60 ? W_MATH : 0) + (scores[CN, stu] < 60 ? W_CN : 0) + (scores[ENG, stu] < 60 ? W_ENG : 0);
                }

                if (chkSort.Checked)
                {
                    stuRankList.Add((stu, wtotal[stu]));
                }
            }

            if (chkSort.Checked)
            {
                stuRankList = stuRankList.OrderByDescending(item => item.wtotal).ToList();

                int rank = 1;
                for (int i = 0; i < STU_NUM; i++)
                {
                    if (i > 0 && stuRankList[i].wtotal == stuRankList[i - 1].wtotal)
                    {
                        ranks[stuRankList[i].index] = ranks[stuRankList[i - 1].index];
                    }
                    else
                    {
                        ranks[stuRankList[i].index] = rank;
                    }
                    rank++;
                }

                foreach (var stu in stuRankList)
                {
                    LoadData(result, stu.index);
                    result.AppendLine($"\t{stu.wtotal}");
                }

            }
            else
            {
                for (int stu = 0; stu < STU_NUM; stu++)
                {
                    LoadData(result, stu);
                    result.AppendLine();
                }
            }

            result.AppendLine(GenerateSeparator(newColCounter));

            if (chkCourseAvg.Checked)
            {
                result.Append("Average\t");
                for (int sub = 0; sub < SBJ_NUM; sub++)
                {
                    int total = 0;
                    for (int stu = 0; stu < STU_NUM; stu++)
                    {
                        total += scores[sub, stu];
                    }
                    result.Append($"{(total / (double)STU_NUM):F2}\t");
                }
                result.AppendLine();
            }

            txtOutput.Text = result.ToString();
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            string name = txtName.Text;
            int index = Array.IndexOf(names, name);

            if (index >= 0)
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