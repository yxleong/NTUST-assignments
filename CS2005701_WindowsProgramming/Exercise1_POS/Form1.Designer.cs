namespace POSOrder
{
    partial class Form1
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置受控資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
        /// 這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.chkCurry = new System.Windows.Forms.CheckBox();
            this.chkTeow = new System.Windows.Forms.CheckBox();
            this.chkRice = new System.Windows.Forms.CheckBox();
            this.chkLaksa = new System.Windows.Forms.CheckBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.rdbSoup = new System.Windows.Forms.RadioButton();
            this.rdbEgg = new System.Windows.Forms.RadioButton();
            this.chkSide = new System.Windows.Forms.CheckBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.rdb100 = new System.Windows.Forms.RadioButton();
            this.rdbMilo = new System.Windows.Forms.RadioButton();
            this.rdbTea = new System.Windows.Forms.RadioButton();
            this.chkDrink = new System.Windows.Forms.CheckBox();
            this.btnOrder = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.lblOutput = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textBox4);
            this.groupBox1.Controls.Add(this.textBox3);
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.chkCurry);
            this.groupBox1.Controls.Add(this.chkTeow);
            this.groupBox1.Controls.Add(this.chkRice);
            this.groupBox1.Controls.Add(this.chkLaksa);
            this.groupBox1.Location = new System.Drawing.Point(76, 92);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(316, 221);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "主食[必點]";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(248, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 16);
            this.label2.TabIndex = 8;
            this.label2.Text = "個數";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(233, 178);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(69, 27);
            this.textBox4.TabIndex = 7;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(233, 132);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(69, 27);
            this.textBox3.TabIndex = 6;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(233, 87);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(69, 27);
            this.textBox2.TabIndex = 5;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(233, 40);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(69, 27);
            this.textBox1.TabIndex = 4;
            // 
            // chkCurry
            // 
            this.chkCurry.AutoSize = true;
            this.chkCurry.Location = new System.Drawing.Point(20, 185);
            this.chkCurry.Name = "chkCurry";
            this.chkCurry.Size = new System.Drawing.Size(211, 20);
            this.chkCurry.TabIndex = 3;
            this.chkCurry.Text = "馬來椰漿飯咖哩雙拼  $205";
            this.chkCurry.UseVisualStyleBackColor = true;
            // 
            // chkTeow
            // 
            this.chkTeow.AutoSize = true;
            this.chkTeow.Location = new System.Drawing.Point(20, 139);
            this.chkTeow.Name = "chkTeow";
            this.chkTeow.Size = new System.Drawing.Size(211, 20);
            this.chkTeow.TabIndex = 2;
            this.chkTeow.Text = "星馬炒粿條                  $175";
            this.chkTeow.UseVisualStyleBackColor = true;
            // 
            // chkRice
            // 
            this.chkRice.AutoSize = true;
            this.chkRice.Location = new System.Drawing.Point(20, 94);
            this.chkRice.Name = "chkRice";
            this.chkRice.Size = new System.Drawing.Size(211, 20);
            this.chkRice.TabIndex = 1;
            this.chkRice.Text = "星馬海南雞飯              $155";
            this.chkRice.UseVisualStyleBackColor = true;
            // 
            // chkLaksa
            // 
            this.chkLaksa.AutoSize = true;
            this.chkLaksa.Location = new System.Drawing.Point(20, 47);
            this.chkLaksa.Name = "chkLaksa";
            this.chkLaksa.Size = new System.Drawing.Size(211, 20);
            this.chkLaksa.TabIndex = 0;
            this.chkLaksa.Text = "星馬招牌叻沙              $185";
            this.chkLaksa.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.textBox6);
            this.groupBox2.Controls.Add(this.textBox5);
            this.groupBox2.Controls.Add(this.rdbSoup);
            this.groupBox2.Controls.Add(this.rdbEgg);
            this.groupBox2.Controls.Add(this.chkSide);
            this.groupBox2.Location = new System.Drawing.Point(420, 43);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(264, 125);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(186, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 16);
            this.label3.TabIndex = 9;
            this.label3.Text = "個數";
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(176, 78);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(69, 27);
            this.textBox6.TabIndex = 9;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(176, 42);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(69, 27);
            this.textBox5.TabIndex = 8;
            // 
            // rdbSoup
            // 
            this.rdbSoup.AutoSize = true;
            this.rdbSoup.Location = new System.Drawing.Point(20, 85);
            this.rdbSoup.Name = "rdbSoup";
            this.rdbSoup.Size = new System.Drawing.Size(150, 20);
            this.rdbSoup.TabIndex = 2;
            this.rdbSoup.TabStop = true;
            this.rdbSoup.Text = "雞清湯             $15";
            this.rdbSoup.UseVisualStyleBackColor = true;
            // 
            // rdbEgg
            // 
            this.rdbEgg.AutoSize = true;
            this.rdbEgg.Location = new System.Drawing.Point(20, 49);
            this.rdbEgg.Name = "rdbEgg";
            this.rdbEgg.Size = new System.Drawing.Size(150, 20);
            this.rdbEgg.TabIndex = 1;
            this.rdbEgg.TabStop = true;
            this.rdbEgg.Text = "參峇蛋             $35";
            this.rdbEgg.UseVisualStyleBackColor = true;
            // 
            // chkSide
            // 
            this.chkSide.AutoSize = true;
            this.chkSide.Location = new System.Drawing.Point(0, 14);
            this.chkSide.Name = "chkSide";
            this.chkSide.Size = new System.Drawing.Size(91, 20);
            this.chkSide.TabIndex = 0;
            this.chkSide.Text = "人氣單點";
            this.chkSide.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.textBox9);
            this.groupBox3.Controls.Add(this.textBox8);
            this.groupBox3.Controls.Add(this.textBox7);
            this.groupBox3.Controls.Add(this.rdb100);
            this.groupBox3.Controls.Add(this.rdbMilo);
            this.groupBox3.Controls.Add(this.rdbTea);
            this.groupBox3.Controls.Add(this.chkDrink);
            this.groupBox3.Location = new System.Drawing.Point(420, 174);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(264, 161);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(186, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 16);
            this.label4.TabIndex = 10;
            this.label4.Text = "個數";
            // 
            // textBox9
            // 
            this.textBox9.Location = new System.Drawing.Point(176, 122);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(69, 27);
            this.textBox9.TabIndex = 12;
            // 
            // textBox8
            // 
            this.textBox8.Location = new System.Drawing.Point(176, 86);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(69, 27);
            this.textBox8.TabIndex = 11;
            // 
            // textBox7
            // 
            this.textBox7.Location = new System.Drawing.Point(176, 48);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(69, 27);
            this.textBox7.TabIndex = 10;
            // 
            // rdb100
            // 
            this.rdb100.AutoSize = true;
            this.rdb100.Location = new System.Drawing.Point(20, 129);
            this.rdb100.Name = "rdb100";
            this.rdb100.Size = new System.Drawing.Size(152, 20);
            this.rdb100.TabIndex = 5;
            this.rdb100.TabStop = true;
            this.rdb100.Text = "100Plus             $50";
            this.rdb100.UseVisualStyleBackColor = true;
            // 
            // rdbMilo
            // 
            this.rdbMilo.AutoSize = true;
            this.rdbMilo.Location = new System.Drawing.Point(20, 93);
            this.rdbMilo.Name = "rdbMilo";
            this.rdbMilo.Size = new System.Drawing.Size(154, 20);
            this.rdbMilo.TabIndex = 4;
            this.rdbMilo.TabStop = true;
            this.rdbMilo.Text = "美祿                  $60";
            this.rdbMilo.UseVisualStyleBackColor = true;
            // 
            // rdbTea
            // 
            this.rdbTea.AutoSize = true;
            this.rdbTea.Location = new System.Drawing.Point(20, 54);
            this.rdbTea.Name = "rdbTea";
            this.rdbTea.Size = new System.Drawing.Size(154, 20);
            this.rdbTea.TabIndex = 3;
            this.rdbTea.TabStop = true;
            this.rdbTea.Text = "印度拉茶          $60";
            this.rdbTea.UseVisualStyleBackColor = true;
            // 
            // chkDrink
            // 
            this.chkDrink.AutoSize = true;
            this.chkDrink.Location = new System.Drawing.Point(0, 11);
            this.chkDrink.Name = "chkDrink";
            this.chkDrink.Size = new System.Drawing.Size(123, 20);
            this.chkDrink.TabIndex = 0;
            this.chkDrink.Text = "南洋風味飲品";
            this.chkDrink.UseVisualStyleBackColor = true;
            // 
            // btnOrder
            // 
            this.btnOrder.Location = new System.Drawing.Point(174, 355);
            this.btnOrder.Name = "btnOrder";
            this.btnOrder.Size = new System.Drawing.Size(97, 49);
            this.btnOrder.TabIndex = 3;
            this.btnOrder.Text = "點餐";
            this.btnOrder.UseVisualStyleBackColor = true;
            this.btnOrder.Click += new System.EventHandler(this.btnOrder_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(447, 371);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 16);
            this.label1.TabIndex = 4;
            this.label1.Text = "總金額 :";
            // 
            // lblOutput
            // 
            this.lblOutput.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblOutput.Location = new System.Drawing.Point(524, 355);
            this.lblOutput.Name = "lblOutput";
            this.lblOutput.Size = new System.Drawing.Size(122, 49);
            this.lblOutput.TabIndex = 5;
            this.lblOutput.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("新細明體", 24F);
            this.label5.Location = new System.Drawing.Point(30, 30);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(334, 32);
            this.label5.TabIndex = 10;
            this.label5.Text = "星馬快餐Sin Ma Express";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(748, 456);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.lblOutput);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnOrder);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("新細明體", 12F);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "POSOrder 四資工四乙_B11015016_梁婭瑄";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox chkRice;
        private System.Windows.Forms.CheckBox chkLaksa;
        private System.Windows.Forms.CheckBox chkCurry;
        private System.Windows.Forms.CheckBox chkTeow;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton rdbSoup;
        private System.Windows.Forms.RadioButton rdbEgg;
        private System.Windows.Forms.CheckBox chkSide;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.RadioButton rdb100;
        private System.Windows.Forms.RadioButton rdbMilo;
        private System.Windows.Forms.RadioButton rdbTea;
        private System.Windows.Forms.CheckBox chkDrink;
        private System.Windows.Forms.Button btnOrder;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblOutput;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.Label label5;
    }
}

