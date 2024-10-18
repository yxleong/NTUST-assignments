
namespace BMIcalculator
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.age = new System.Windows.Forms.TextBox();
            this.gender = new System.Windows.Forms.TextBox();
            this.height = new System.Windows.Forms.TextBox();
            this.weight = new System.Windows.Forms.TextBox();
            this.calBtn = new System.Windows.Forms.Button();
            this.resultbox = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(105, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 21);
            this.label1.TabIndex = 0;
            this.label1.Text = "Age:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(80, 85);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 21);
            this.label2.TabIndex = 1;
            this.label2.Text = "Gender:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(73, 132);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(76, 21);
            this.label3.TabIndex = 2;
            this.label3.Text = "* Height:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(70, 179);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(79, 21);
            this.label4.TabIndex = 3;
            this.label4.Text = "* Weight:";
            // 
            // age
            // 
            this.age.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.age.Location = new System.Drawing.Point(155, 33);
            this.age.Name = "age";
            this.age.Size = new System.Drawing.Size(100, 26);
            this.age.TabIndex = 4;
            this.age.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // gender
            // 
            this.gender.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gender.ForeColor = System.Drawing.SystemColors.InactiveCaption;
            this.gender.Location = new System.Drawing.Point(155, 80);
            this.gender.Name = "gender";
            this.gender.Size = new System.Drawing.Size(100, 26);
            this.gender.TabIndex = 5;
            this.gender.Text = "M / F";
            this.gender.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.gender.Enter += new System.EventHandler(this.gender_Enter);
            this.gender.Leave += new System.EventHandler(this.gender_Leave);
            // 
            // height
            // 
            this.height.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.height.ForeColor = System.Drawing.SystemColors.InactiveCaption;
            this.height.Location = new System.Drawing.Point(155, 127);
            this.height.Name = "height";
            this.height.Size = new System.Drawing.Size(100, 26);
            this.height.TabIndex = 6;
            this.height.Text = "m";
            this.height.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.height.Enter += new System.EventHandler(this.height_Enter);
            this.height.Leave += new System.EventHandler(this.height_Leave);
            // 
            // weight
            // 
            this.weight.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.weight.ForeColor = System.Drawing.SystemColors.InactiveCaption;
            this.weight.Location = new System.Drawing.Point(155, 174);
            this.weight.Name = "weight";
            this.weight.Size = new System.Drawing.Size(100, 26);
            this.weight.TabIndex = 7;
            this.weight.Text = "kg";
            this.weight.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.weight.Enter += new System.EventHandler(this.weight_Enter);
            this.weight.Leave += new System.EventHandler(this.weight_Leave);
            // 
            // calBtn
            // 
            this.calBtn.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.calBtn.Location = new System.Drawing.Point(325, 80);
            this.calBtn.Name = "calBtn";
            this.calBtn.Size = new System.Drawing.Size(100, 73);
            this.calBtn.TabIndex = 8;
            this.calBtn.Text = "Calculate";
            this.calBtn.UseVisualStyleBackColor = true;
            this.calBtn.Click += new System.EventHandler(this.calBtn_Click);
            // 
            // resultbox
            // 
            this.resultbox.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.resultbox.Font = new System.Drawing.Font("Times New Roman", 9F);
            this.resultbox.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.resultbox.Location = new System.Drawing.Point(31, 217);
            this.resultbox.Name = "resultbox";
            this.resultbox.Size = new System.Drawing.Size(447, 122);
            this.resultbox.TabIndex = 9;
            this.resultbox.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(511, 368);
            this.Controls.Add(this.resultbox);
            this.Controls.Add(this.calBtn);
            this.Controls.Add(this.weight);
            this.Controls.Add(this.height);
            this.Controls.Add(this.gender);
            this.Controls.Add(this.age);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "BMI Calculator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox age;
        private System.Windows.Forms.TextBox gender;
        private System.Windows.Forms.TextBox height;
        private System.Windows.Forms.TextBox weight;
        private System.Windows.Forms.Button calBtn;
        private System.Windows.Forms.Label resultbox;
    }
}

