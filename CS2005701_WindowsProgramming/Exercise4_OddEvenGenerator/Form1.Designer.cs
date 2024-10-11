
namespace OddEven
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
            this.num = new System.Windows.Forms.TextBox();
            this.oddResult = new System.Windows.Forms.Label();
            this.evenResult = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.OKbtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 14F);
            this.label1.Location = new System.Drawing.Point(69, 64);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(127, 21);
            this.label1.TabIndex = 0;
            this.label1.Text = "Enter a number:";
            // 
            // num
            // 
            this.num.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.num.Location = new System.Drawing.Point(202, 63);
            this.num.Name = "num";
            this.num.Size = new System.Drawing.Size(100, 26);
            this.num.TabIndex = 1;
            // 
            // oddResult
            // 
            this.oddResult.BackColor = System.Drawing.SystemColors.Control;
            this.oddResult.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.oddResult.Font = new System.Drawing.Font("Times New Roman", 12F);
            this.oddResult.Location = new System.Drawing.Point(60, 144);
            this.oddResult.Name = "oddResult";
            this.oddResult.Size = new System.Drawing.Size(309, 90);
            this.oddResult.TabIndex = 2;
            // 
            // evenResult
            // 
            this.evenResult.BackColor = System.Drawing.SystemColors.Control;
            this.evenResult.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.evenResult.Font = new System.Drawing.Font("Times New Roman", 12F);
            this.evenResult.Location = new System.Drawing.Point(60, 289);
            this.evenResult.Name = "evenResult";
            this.evenResult.Size = new System.Drawing.Size(309, 90);
            this.evenResult.TabIndex = 3;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Times New Roman", 14F);
            this.label4.Location = new System.Drawing.Point(56, 123);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(109, 21);
            this.label4.TabIndex = 4;
            this.label4.Text = "Odd number:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Times New Roman", 14F);
            this.label5.Location = new System.Drawing.Point(56, 268);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(112, 21);
            this.label5.TabIndex = 5;
            this.label5.Text = "Even number:";
            // 
            // OKbtn
            // 
            this.OKbtn.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OKbtn.Location = new System.Drawing.Point(317, 53);
            this.OKbtn.Name = "OKbtn";
            this.OKbtn.Size = new System.Drawing.Size(52, 45);
            this.OKbtn.TabIndex = 6;
            this.OKbtn.Text = "OK";
            this.OKbtn.UseVisualStyleBackColor = true;
            this.OKbtn.Click += new System.EventHandler(this.OKbtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(441, 450);
            this.Controls.Add(this.OKbtn);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.evenResult);
            this.Controls.Add(this.oddResult);
            this.Controls.Add(this.num);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Odd Even Generator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox num;
        private System.Windows.Forms.Label oddResult;
        private System.Windows.Forms.Label evenResult;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button OKbtn;
    }
}

