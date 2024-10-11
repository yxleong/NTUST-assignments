
namespace ClothesOrderPortal
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
            this.coat_qty = new System.Windows.Forms.TextBox();
            this.skirt_qty = new System.Windows.Forms.TextBox();
            this.warmer_qty = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cal_button = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.result = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(75, 92);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(264, 19);
            this.label1.TabIndex = 0;
            this.label1.Text = "PUFFERTECH Quilted Coat   NT$3,490";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(75, 141);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(263, 19);
            this.label2.TabIndex = 1;
            this.label2.Text = "Pleated Long Skirt                   NT$1,290";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(75, 190);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(260, 19);
            this.label3.TabIndex = 2;
            this.label3.Text = "Nylon Hooded Neck Warmer    NT$990";
            // 
            // coat_qty
            // 
            this.coat_qty.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.coat_qty.Location = new System.Drawing.Point(376, 92);
            this.coat_qty.Name = "coat_qty";
            this.coat_qty.Size = new System.Drawing.Size(74, 26);
            this.coat_qty.TabIndex = 1;
            // 
            // skirt_qty
            // 
            this.skirt_qty.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.skirt_qty.Location = new System.Drawing.Point(376, 141);
            this.skirt_qty.Name = "skirt_qty";
            this.skirt_qty.Size = new System.Drawing.Size(74, 26);
            this.skirt_qty.TabIndex = 2;
            // 
            // warmer_qty
            // 
            this.warmer_qty.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.warmer_qty.Location = new System.Drawing.Point(376, 187);
            this.warmer_qty.Name = "warmer_qty";
            this.warmer_qty.Size = new System.Drawing.Size(74, 26);
            this.warmer_qty.TabIndex = 3;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(390, 61);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 19);
            this.label4.TabIndex = 6;
            this.label4.Text = "QTY";
            // 
            // cal_button
            // 
            this.cal_button.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cal_button.Location = new System.Drawing.Point(247, 242);
            this.cal_button.Name = "cal_button";
            this.cal_button.Size = new System.Drawing.Size(203, 54);
            this.cal_button.TabIndex = 4;
            this.cal_button.Text = "Estimate Total Price";
            this.cal_button.UseVisualStyleBackColor = true;
            this.cal_button.Click += new System.EventHandler(this.cal_button_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(232, 336);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(83, 19);
            this.label5.TabIndex = 8;
            this.label5.Text = "Order Total:";
            // 
            // result
            // 
            this.result.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.result.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.result.Location = new System.Drawing.Point(321, 319);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(129, 48);
            this.result.TabIndex = 5;
            this.result.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(564, 450);
            this.Controls.Add(this.result);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.cal_button);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.warmer_qty);
            this.Controls.Add(this.skirt_qty);
            this.Controls.Add(this.coat_qty);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = " UNIQLO : C Autumn/Winter 2024 collection";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox coat_qty;
        private System.Windows.Forms.TextBox skirt_qty;
        private System.Windows.Forms.TextBox warmer_qty;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button cal_button;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label result;
    }
}

