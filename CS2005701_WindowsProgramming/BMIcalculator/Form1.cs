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
        private void InitResultBox(Label resultbox)
        {
            resultbox.Text = "[ BMI Categories ]\n" +
                "Underweight: BMI < 18.5\n" +
                "Normal Range: 18.5 ≤ BMI < 24\n" +
                "Overweight: 24 ≤ BMI < 27\n" +
                "Mild Obesity: 27 ≤ BMI < 30\n" +
                "Moderate Obesity: 30 ≤ BMI < 35\n" +
                "Severe Obesity: BMI ≥ 35"; ;
            resultbox.ForeColor = SystemColors.ActiveCaption;
            resultbox.Font = new Font(resultbox.Font.FontFamily, 9);
        }

        private void InitTextBox(TextBox inputbox, string text)
        {
            if (inputbox.Text == "")
            {
                inputbox.Text = text;
                inputbox.ForeColor = SystemColors.InactiveCaption;
            }
        }

        private void SetTextBox(TextBox inputbox)
        {
            inputbox.Clear();
            inputbox.ForeColor = Color.Black;
        }

        private void SetWarningMsg(String text)
        {
            MessageBox.Show(text, "Input Required", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }

        public Form1()
        {
            InitializeComponent();
            InitResultBox(resultbox);
        }

        private void gender_Enter(object sender, EventArgs e)
        {
            SetTextBox(gender);
        }

        private void height_Enter(object sender, EventArgs e)
        {
            SetTextBox(height);
            InitResultBox(resultbox);
        }

        private void weight_Enter(object sender, EventArgs e)
        {
            SetTextBox(weight);
            InitResultBox(resultbox);
        }

        private void gender_Leave(object sender, EventArgs e)
        {
            InitTextBox(gender, "M / F");
        }

        private void height_Leave(object sender, EventArgs e)
        {
            InitTextBox(height, "m");
        }

        private void weight_Leave(object sender, EventArgs e)
        {
            InitTextBox(weight, "kg");
        }

        private void calBtn_Click(object sender, EventArgs e)
        {
            double w = 0, h = 0;
            string result = "";

            if (string.IsNullOrWhiteSpace(weight.Text) && string.IsNullOrWhiteSpace(height.Text))
            {
                SetWarningMsg("Please enter both your weight and height to calculate your BMI.");
            }else if (string.IsNullOrWhiteSpace(weight.Text))
            {
                SetWarningMsg("Please enter your weight to calculate your BMI.");
            }
            else if (string.IsNullOrWhiteSpace(height.Text))
            {
                SetWarningMsg("Please enter your height to calculate your BMI.");
            }
            else
            {
                if (!double.TryParse(weight.Text, out w) || !double.TryParse(height.Text, out h))
                {
                    MessageBox.Show("Please enter valid numerical values for weight and height.", "Invalid Input", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    w = Convert.ToDouble(weight.Text);
                    h = Convert.ToDouble(height.Text);

                    double bmi = w / h / h;

                    if (bmi < 18.5)
                    {
                        result = bmi.ToString("F2") + " = Underweight";
                    }
                    else if (bmi < 24.9)
                    {
                        result = bmi.ToString("F2") + " = Normal weight";
                    }
                    else if (bmi < 29.9)
                    {
                        result = bmi.ToString("F2") + " = Overweight";
                    }
                    else
                    {
                        result = bmi.ToString("F2") + " = Obesity";
                    }

                    resultbox.Text = result;
                    resultbox.ForeColor = Color.Black;
                    resultbox.Font = new Font(resultbox.Font.FontFamily, 33);
                }
            }        
           
        }
    }
}
