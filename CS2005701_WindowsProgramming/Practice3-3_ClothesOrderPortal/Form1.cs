using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClothesOrderPortal
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void cal_button_Click(object sender, EventArgs e)
        {
            const int COAT = 3490;
            const int SKIRT = 1290;
            const int WARMER = 990;

            result.Text = "";
            int sum = 0;
            sum += COAT * Convert.ToInt32(coat_qty.Text);
            sum += SKIRT * Convert.ToInt32(skirt_qty.Text);
            sum += WARMER * Convert.ToInt32(warmer_qty.Text);

            result.Text = sum.ToString();
        }
    }
}
