using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CelsiusFahrenheitConverter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            celsiusValue.Enter += celsiusValue_Enter;
            fahrenheitValue.Enter += fahrenheitValue_Enter;
        }
        private void celsiusValue_Enter(object sender, EventArgs e)
        {
            fahrenheitValue.Clear();
        }

        private void fahrenheitValue_Enter(object sender, EventArgs e)
        {
            celsiusValue.Clear();
        }

        private void convertButton_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(celsiusValue.Text))
            {
                double c = Convert.ToDouble(celsiusValue.Text);
                double f = c * 9 / 5 + 32;
                fahrenheitValue.Text = f.ToString("F2");
            } else if (!string.IsNullOrWhiteSpace(fahrenheitValue.Text))
            {
                double f = Convert.ToDouble(fahrenheitValue.Text);
                double c = (f - 32) / 9 * 5;
                celsiusValue.Text = c.ToString("F2");
            } else
            {
                MessageBox.Show("Please enter a value in either Celsius or Fahrenheit.");
            }
        }
    }
}
