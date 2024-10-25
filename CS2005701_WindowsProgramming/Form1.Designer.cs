namespace B11015016
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
            this.txtOutput = new System.Windows.Forms.TextBox();
            this.grpReport = new System.Windows.Forms.GroupBox();
            this.chkSort = new System.Windows.Forms.CheckBox();
            this.chkFailCredit = new System.Windows.Forms.CheckBox();
            this.chkWeightAvg = new System.Windows.Forms.CheckBox();
            this.chkCourseAvg = new System.Windows.Forms.CheckBox();
            this.chkRank = new System.Windows.Forms.CheckBox();
            this.chkFailNum = new System.Windows.Forms.CheckBox();
            this.chkAvg = new System.Windows.Forms.CheckBox();
            this.btnCalc = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.grpReport.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtOutput
            // 
            this.txtOutput.Location = new System.Drawing.Point(25, 12);
            this.txtOutput.Multiline = true;
            this.txtOutput.Name = "txtOutput";
            this.txtOutput.ReadOnly = true;
            this.txtOutput.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.txtOutput.Size = new System.Drawing.Size(653, 328);
            this.txtOutput.TabIndex = 0;
            // 
            // grpReport
            // 
            this.grpReport.Controls.Add(this.chkSort);
            this.grpReport.Controls.Add(this.chkFailCredit);
            this.grpReport.Controls.Add(this.chkWeightAvg);
            this.grpReport.Controls.Add(this.chkCourseAvg);
            this.grpReport.Controls.Add(this.chkRank);
            this.grpReport.Controls.Add(this.chkFailNum);
            this.grpReport.Controls.Add(this.chkAvg);
            this.grpReport.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grpReport.Location = new System.Drawing.Point(693, 12);
            this.grpReport.Name = "grpReport";
            this.grpReport.Size = new System.Drawing.Size(216, 262);
            this.grpReport.TabIndex = 1;
            this.grpReport.TabStop = false;
            this.grpReport.Text = "Student Report";
            // 
            // chkSort
            // 
            this.chkSort.AutoSize = true;
            this.chkSort.Location = new System.Drawing.Point(6, 229);
            this.chkSort.Name = "chkSort";
            this.chkSort.Size = new System.Drawing.Size(156, 23);
            this.chkSort.TabIndex = 6;
            this.chkSort.Text = "Sort Names by Rank";
            this.chkSort.UseVisualStyleBackColor = true;
            // 
            // chkFailCredit
            // 
            this.chkFailCredit.AutoSize = true;
            this.chkFailCredit.Location = new System.Drawing.Point(7, 196);
            this.chkFailCredit.Name = "chkFailCredit";
            this.chkFailCredit.Size = new System.Drawing.Size(163, 23);
            this.chkFailCredit.TabIndex = 5;
            this.chkFailCredit.Text = "Failed Subject Credits";
            this.chkFailCredit.UseVisualStyleBackColor = true;
            // 
            // chkWeightAvg
            // 
            this.chkWeightAvg.AutoSize = true;
            this.chkWeightAvg.Location = new System.Drawing.Point(7, 163);
            this.chkWeightAvg.Name = "chkWeightAvg";
            this.chkWeightAvg.Size = new System.Drawing.Size(178, 23);
            this.chkWeightAvg.TabIndex = 4;
            this.chkWeightAvg.Text = "Weighted Average Score";
            this.chkWeightAvg.UseVisualStyleBackColor = true;
            // 
            // chkCourseAvg
            // 
            this.chkCourseAvg.AutoSize = true;
            this.chkCourseAvg.Location = new System.Drawing.Point(7, 130);
            this.chkCourseAvg.Name = "chkCourseAvg";
            this.chkCourseAvg.Size = new System.Drawing.Size(201, 23);
            this.chkCourseAvg.TabIndex = 3;
            this.chkCourseAvg.Text = "Each Subject Average Score";
            this.chkCourseAvg.UseVisualStyleBackColor = true;
            // 
            // chkRank
            // 
            this.chkRank.AutoSize = true;
            this.chkRank.Location = new System.Drawing.Point(7, 97);
            this.chkRank.Name = "chkRank";
            this.chkRank.Size = new System.Drawing.Size(77, 23);
            this.chkRank.TabIndex = 2;
            this.chkRank.Text = "Ranking";
            this.chkRank.UseVisualStyleBackColor = true;
            // 
            // chkFailNum
            // 
            this.chkFailNum.AutoSize = true;
            this.chkFailNum.Location = new System.Drawing.Point(7, 64);
            this.chkFailNum.Name = "chkFailNum";
            this.chkFailNum.Size = new System.Drawing.Size(121, 23);
            this.chkFailNum.TabIndex = 1;
            this.chkFailNum.Text = "Failed Subjects";
            this.chkFailNum.UseVisualStyleBackColor = true;
            // 
            // chkAvg
            // 
            this.chkAvg.AutoSize = true;
            this.chkAvg.Location = new System.Drawing.Point(7, 31);
            this.chkAvg.Name = "chkAvg";
            this.chkAvg.Size = new System.Drawing.Size(118, 23);
            this.chkAvg.TabIndex = 0;
            this.chkAvg.Text = "Average Score";
            this.chkAvg.UseVisualStyleBackColor = true;
            // 
            // btnCalc
            // 
            this.btnCalc.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCalc.Location = new System.Drawing.Point(690, 280);
            this.btnCalc.Name = "btnCalc";
            this.btnCalc.Size = new System.Drawing.Size(219, 51);
            this.btnCalc.TabIndex = 2;
            this.btnCalc.Text = "Compute Grades";
            this.btnCalc.UseVisualStyleBackColor = true;
            this.btnCalc.Click += new System.EventHandler(this.btnCalc_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 14F);
            this.label1.Location = new System.Drawing.Point(76, 360);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 21);
            this.label1.TabIndex = 3;
            this.label1.Text = "Name:";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(139, 357);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(259, 27);
            this.txtName.TabIndex = 4;
            // 
            // btnSearch
            // 
            this.btnSearch.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSearch.Location = new System.Drawing.Point(418, 357);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(153, 38);
            this.btnSearch.TabIndex = 5;
            this.btnSearch.Text = "View Scores";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(934, 408);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnCalc);
            this.Controls.Add(this.grpReport);
            this.Controls.Add(this.txtOutput);
            this.Font = new System.Drawing.Font("新細明體", 12F);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "四資工四_B11015016_梁婭瑄";
            this.grpReport.ResumeLayout(false);
            this.grpReport.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtOutput;
        private System.Windows.Forms.GroupBox grpReport;
        private System.Windows.Forms.CheckBox chkAvg;
        private System.Windows.Forms.CheckBox chkCourseAvg;
        private System.Windows.Forms.CheckBox chkRank;
        private System.Windows.Forms.CheckBox chkFailNum;
        private System.Windows.Forms.Button btnCalc;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.CheckBox chkFailCredit;
        private System.Windows.Forms.CheckBox chkWeightAvg;
        private System.Windows.Forms.CheckBox chkSort;
    }
}