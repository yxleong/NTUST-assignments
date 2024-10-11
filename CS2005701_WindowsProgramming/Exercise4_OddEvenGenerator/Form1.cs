using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OddEven
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void OKbtn_Click(object sender, EventArgs e)
        {
            oddResult.Text = string.Empty; // Clear the label
            evenResult.Text = string.Empty;

            string odd_numbers = "";
            string evenNumbers = "";
            int upperLimit;

            if (int.TryParse(num.Text, out upperLimit) && upperLimit > 0)
            {
                for (int i = 1; i <= upperLimit; i++)
                {
                    if (i % 2 != 0)
                    {
                        odd_numbers += i.ToString() + " ";
                    }
                    else
                    {
                        evenNumbers += i.ToString() + " ";
                    }
                }
                oddResult.Text = odd_numbers;
                evenResult.Text = evenNumbers;
            }
            else
            {
                MessageBox.Show("Please enter a valid positive integer greater than 0.");
                num.Clear();
            }
        }
    }
}
