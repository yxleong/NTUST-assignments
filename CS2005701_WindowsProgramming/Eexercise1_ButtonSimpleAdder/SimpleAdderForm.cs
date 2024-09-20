using System;
using System.Windows.Forms;
using System.Drawing;   //  Color

namespace SimpleAdder
{
    public partial class SimpleAdderForm : Form
    {
        public SimpleAdderForm()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("This is my first C# program");
        }
        
        // ------------------------------------------------------------------
        private void SetDefaultPrompt(TextBox textbox, string prompt)
        {
            textbox.Text = prompt;
            textbox.ForeColor = Color.Gray;
        }

        private void ClearTextBox(TextBox textBox, string prompt)
        {
            textBox.Clear();
            SetDefaultPrompt(textBox, prompt);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SetDefaultPrompt(textBox2, "Input the first number");
            SetDefaultPrompt(textBox3, "Input the second number");
        }

        private void textBox_Enter(object sender, EventArgs e)
        {
            TextBox textBox = sender as TextBox;
            if(textBox != null && textBox.ForeColor == Color.Gray)
            {
                textBox.Clear();
                textBox.ForeColor = Color.Black;
                label2.Text = "Sum: ";
            }
        }

        private void textBox_Leave(object sender, EventArgs e)
        {
            TextBox textBox = sender as TextBox;
            if (string.IsNullOrWhiteSpace(textBox.Text))
            {
                SetDefaultPrompt(textBox, textBox == textBox2 ? "Input the first number" : "Input the second number");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double num1, num2;

            if(double.TryParse(textBox2.Text, out num1) && double.TryParse(textBox3.Text, out num2))
            {
                double sum = num1 + num2;
                label2.Text = "Sum: " + sum.ToString();
            }
            else
            {
                MessageBox.Show("Please input a valid number!");
            }

            ClearTextBox(textBox2, "Input the first number");
            ClearTextBox(textBox3, "Input the second number");
        }
    }
}
