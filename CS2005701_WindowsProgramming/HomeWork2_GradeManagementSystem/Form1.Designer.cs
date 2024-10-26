namespace B11015016
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            txtOutput = new TextBox();
            grpReport = new GroupBox();
            chkSort = new CheckBox();
            chkFailCredit = new CheckBox();
            chkWeightAvg = new CheckBox();
            chkCourseAvg = new CheckBox();
            chkRank = new CheckBox();
            chkFailNum = new CheckBox();
            chkAvg = new CheckBox();
            btnCalc = new Button();
            label1 = new Label();
            txtName = new TextBox();
            btnSearch = new Button();
            grpReport.SuspendLayout();
            SuspendLayout();
            // 
            // txtOutput
            // 
            txtOutput.Location = new Point(25, 12);
            txtOutput.Multiline = true;
            txtOutput.Name = "txtOutput";
            txtOutput.ReadOnly = true;
            txtOutput.ScrollBars = ScrollBars.Both;
            txtOutput.Size = new Size(719, 328);
            txtOutput.TabIndex = 10;
            txtOutput.TabStop = false;
            // 
            // grpReport
            // 
            grpReport.Controls.Add(chkSort);
            grpReport.Controls.Add(chkFailCredit);
            grpReport.Controls.Add(chkWeightAvg);
            grpReport.Controls.Add(chkCourseAvg);
            grpReport.Controls.Add(chkRank);
            grpReport.Controls.Add(chkFailNum);
            grpReport.Controls.Add(chkAvg);
            grpReport.Font = new Font("Times New Roman", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            grpReport.Location = new Point(750, 12);
            grpReport.Name = "grpReport";
            grpReport.Size = new Size(216, 262);
            grpReport.TabIndex = 1;
            grpReport.TabStop = false;
            grpReport.Text = "Student Report";
            // 
            // chkSort
            // 
            chkSort.AutoSize = true;
            chkSort.Location = new Point(6, 229);
            chkSort.Name = "chkSort";
            chkSort.Size = new Size(156, 23);
            chkSort.TabIndex = 9;
            chkSort.Text = "Sort Names by Rank";
            chkSort.UseVisualStyleBackColor = true;
            // 
            // chkFailCredit
            // 
            chkFailCredit.AutoSize = true;
            chkFailCredit.Location = new Point(7, 196);
            chkFailCredit.Name = "chkFailCredit";
            chkFailCredit.Size = new Size(163, 23);
            chkFailCredit.TabIndex = 8;
            chkFailCredit.Text = "Failed Subject Credits";
            chkFailCredit.UseVisualStyleBackColor = true;
            // 
            // chkWeightAvg
            // 
            chkWeightAvg.AutoSize = true;
            chkWeightAvg.Location = new Point(7, 163);
            chkWeightAvg.Name = "chkWeightAvg";
            chkWeightAvg.Size = new Size(178, 23);
            chkWeightAvg.TabIndex = 7;
            chkWeightAvg.Text = "Weighted Average Score";
            chkWeightAvg.UseVisualStyleBackColor = true;
            // 
            // chkCourseAvg
            // 
            chkCourseAvg.AutoSize = true;
            chkCourseAvg.Location = new Point(7, 130);
            chkCourseAvg.Name = "chkCourseAvg";
            chkCourseAvg.Size = new Size(201, 23);
            chkCourseAvg.TabIndex = 6;
            chkCourseAvg.Text = "Each Subject Average Score";
            chkCourseAvg.UseVisualStyleBackColor = true;
            // 
            // chkRank
            // 
            chkRank.AutoSize = true;
            chkRank.Location = new Point(7, 97);
            chkRank.Name = "chkRank";
            chkRank.Size = new Size(77, 23);
            chkRank.TabIndex = 5;
            chkRank.Text = "Ranking";
            chkRank.UseVisualStyleBackColor = true;
            // 
            // chkFailNum
            // 
            chkFailNum.AutoSize = true;
            chkFailNum.Location = new Point(7, 64);
            chkFailNum.Name = "chkFailNum";
            chkFailNum.Size = new Size(121, 23);
            chkFailNum.TabIndex = 4;
            chkFailNum.Text = "Failed Subjects";
            chkFailNum.UseVisualStyleBackColor = true;
            // 
            // chkAvg
            // 
            chkAvg.AutoSize = true;
            chkAvg.Location = new Point(7, 31);
            chkAvg.Name = "chkAvg";
            chkAvg.Size = new Size(118, 23);
            chkAvg.TabIndex = 3;
            chkAvg.Text = "Average Score";
            chkAvg.UseVisualStyleBackColor = true;
            // 
            // btnCalc
            // 
            btnCalc.Font = new Font("Times New Roman", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnCalc.Location = new Point(747, 280);
            btnCalc.Name = "btnCalc";
            btnCalc.Size = new Size(219, 51);
            btnCalc.TabIndex = 0;
            btnCalc.Text = "Compute Grades";
            btnCalc.UseVisualStyleBackColor = true;
            btnCalc.Click += btnCalc_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Times New Roman", 14F);
            label1.Location = new Point(164, 365);
            label1.Name = "label1";
            label1.Size = new Size(57, 21);
            label1.TabIndex = 3;
            label1.Text = "Name:";
            // 
            // txtName
            // 
            txtName.Location = new Point(227, 362);
            txtName.Name = "txtName";
            txtName.Size = new Size(189, 26);
            txtName.TabIndex = 1;
            // 
            // btnSearch
            // 
            btnSearch.Font = new Font("Times New Roman", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            btnSearch.Location = new Point(422, 356);
            btnSearch.Name = "btnSearch";
            btnSearch.Size = new Size(115, 38);
            btnSearch.TabIndex = 2;
            btnSearch.Text = "View Scores";
            btnSearch.UseVisualStyleBackColor = true;
            btnSearch.Click += btnSearch_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(9F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(993, 406);
            Controls.Add(btnSearch);
            Controls.Add(txtName);
            Controls.Add(label1);
            Controls.Add(btnCalc);
            Controls.Add(grpReport);
            Controls.Add(txtOutput);
            Font = new Font("Microsoft Sans Serif", 12F);
            Margin = new Padding(4);
            Name = "Form1";
            Text = "四資工四_B11015016_梁婭瑄";
            grpReport.ResumeLayout(false);
            grpReport.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
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