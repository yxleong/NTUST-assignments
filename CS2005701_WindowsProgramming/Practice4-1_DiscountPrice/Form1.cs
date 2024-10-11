using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DiscountPrice
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            price.Enter += price_Enter;
        }
        private void checkBtn_Click(object sender, EventArgs e)
        {
            double amt = Convert.ToDouble(price.Text);
            double result = 0;
            if(amt > 200)
            {
                result = amt * 0.9;
            }
            else
            {
                result = amt;
            }
            discount.Text = result.ToString();
        }

        private void price_Enter(object sender, EventArgs e)
        {
            discount.Clear();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
