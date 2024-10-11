using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ch3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void cal_button_Click(object sender, EventArgs e)
        {
            double amt = Convert.ToDouble(textBox1.Text); // principal investment amount -> P
            double percent = Convert.ToDouble(textBox2.Text);   // annual interest rate -> r
            double num = Convert.ToDouble(textBox3.Text);    // number of years -> t
            double compound = amt;  // compound amount -> A
            // n = the number of times that interest is compounded per year

            result.Text = "";   // clear previous result for the second time input
            for (int i = 1; i <= num; i++)
            {
                // formula: A = P * ( 1 + r/n ) ^ (n*t)
                compound *= (1 + percent / 100); // r in decimal
                result.Text += $"Year{i}: Compound amount is {compound:C}\n";   // compund amount in currency format
            }
        }
    }
}
