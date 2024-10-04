using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace POSOrder
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            textBox1.KeyPress += TextBox_KeyPress;
            textBox2.KeyPress += TextBox_KeyPress;
            textBox3.KeyPress += TextBox_KeyPress;
            textBox4.KeyPress += TextBox_KeyPress;
            textBox5.KeyPress += TextBox_KeyPress;
            textBox6.KeyPress += TextBox_KeyPress;
            textBox7.KeyPress += TextBox_KeyPress;
            textBox8.KeyPress += TextBox_KeyPress;
            textBox9.KeyPress += TextBox_KeyPress;

            chkLaksa.CheckedChanged += CheckBox_CheckedChanged;
            chkRice.CheckedChanged += CheckBox_CheckedChanged;
            chkTeow.CheckedChanged += CheckBox_CheckedChanged;
            chkCurry.CheckedChanged += CheckBox_CheckedChanged;
            chkSide.CheckedChanged += CheckBox_CheckedChanged;
            chkDrink.CheckedChanged += CheckBox_CheckedChanged;

            rdbEgg.CheckedChanged += RadioButton_CheckedChanged;
            rdbSoup.CheckedChanged += RadioButton_CheckedChanged;
            rdbTea.CheckedChanged += RadioButton_CheckedChanged;
            rdbMilo.CheckedChanged += RadioButton_CheckedChanged;
            rdb100.CheckedChanged += RadioButton_CheckedChanged;

            UpdateRadioButtonState(null);
            UpdateTextBoxState();
        }

        private void UpdateButtonState()
        {
            btnOrder.Enabled = chkLaksa.Checked || chkRice.Checked || chkTeow.Checked || chkCurry.Checked;
        }

        private int GetTextValue(int price, TextBox textBox)
        {
            return (price * Int32.Parse(textBox.Text));
        }

        private void btnOrder_Click(object sender, EventArgs e)
        {
            int totalAmount = 0;

            if (chkLaksa.Checked) totalAmount += GetTextValue(185, textBox1);
            if (chkRice.Checked) totalAmount += GetTextValue(155, textBox2);
            if (chkTeow.Checked) totalAmount += GetTextValue(175, textBox3);
            if (chkCurry.Checked) totalAmount += GetTextValue(205, textBox4);

            if (chkSide.Checked)
            {
                if (rdbEgg.Checked) totalAmount += GetTextValue(35, textBox5);
                else if (rdbSoup.Checked) totalAmount += GetTextValue(15, textBox6);
            }

            if (chkDrink.Checked)
            {
                if (rdbTea.Checked) totalAmount += GetTextValue(60, textBox7);
                else if (rdbMilo.Checked) totalAmount += GetTextValue(60, textBox8);
                else if (rdb100.Checked) totalAmount += GetTextValue(50, textBox9);
            }

            lblOutput.Text = "NT $ " + totalAmount;
        }

        private void TextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true; // Ignore the key press
            }
        }

        private void UpdateRadioButtonState(CheckBox changedCheckBox)
        {
            bool isSideDish = chkSide.Checked;
            bool isDrink = chkDrink.Checked;

            rdbEgg.Enabled = isSideDish;
            rdbSoup.Enabled = isSideDish;

            rdbTea.Enabled = isDrink;
            rdbMilo.Enabled = isDrink;
            rdb100.Enabled = isDrink;

            if (!isSideDish)
            {
                rdbEgg.Checked = false;
                rdbSoup.Checked = false;
            }

            if (!isDrink)
            {
                rdbTea.Checked = false;
                rdbMilo.Checked = false;
                rdb100.Checked = false;
            }
        }

        private void UpdateTextBoxStateForControl(TextBox textBox, CheckBox checkBox, RadioButton radioButton = null)
        {
            bool isChecked = checkBox.Checked;
            bool isRadioChecked = radioButton?.Checked ?? true; // if radioButton is null, then true

            if (isChecked && isRadioChecked)
            {
                textBox.Enabled = true;
                textBox.Focus();
            }
            else
            {
                textBox.Enabled = false;
                textBox.Clear();
            }
        }

        private void UpdateTextBoxState()
        {
            UpdateTextBoxStateForControl(textBox1, chkLaksa); 
            UpdateTextBoxStateForControl(textBox2, chkRice); 
            UpdateTextBoxStateForControl(textBox3, chkTeow); 
            UpdateTextBoxStateForControl(textBox4, chkCurry); 

            UpdateTextBoxStateForControl(textBox5, chkSide, rdbEgg);
            UpdateTextBoxStateForControl(textBox6, chkSide, rdbSoup);
            UpdateTextBoxStateForControl(textBox7, chkDrink, rdbTea);
            UpdateTextBoxStateForControl(textBox8, chkDrink, rdbMilo);
            UpdateTextBoxStateForControl(textBox9, chkDrink, rdb100);

            UpdateButtonState();
        }

        private void CheckBox_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox changedCheckBox = sender as CheckBox;
            UpdateRadioButtonState(changedCheckBox);

            UpdateTextBoxState();
        }

        private void RadioButton_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTextBoxState();
        }
    }
}
