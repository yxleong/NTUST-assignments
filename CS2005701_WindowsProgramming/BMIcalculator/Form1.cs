using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BMIcalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void gender_Enter(object sender, EventArgs e)
        {
            gender.Clear();
            gender.ForeColor = Color.Black;
        }

        private void height_Enter(object sender, EventArgs e)
        {
            height.Clear();
            height.ForeColor = Color.Black;
        }

        private void weight_Enter(object sender, EventArgs e)
        {
            weight.Clear();
            weight.ForeColor = Color.Black;
        }

        private void calBtn_Click(object sender, EventArgs e)
        {
            double w = Convert.ToDouble(weight.Text);
            double h = Convert.ToDouble(height.Text);
            double bmi = w / h;
            string result = "";

            if(bmi < 18.5)
            {
                result = "Underweight";
            }
            else if (bmi < 24.9)
            {
                result = "Normal weight";
            }
            else if (bmi < 29.9)
            {
                result = "Overweight";
            }
            else
            {
                result = "Obesity";
            }
        }
    }
}
