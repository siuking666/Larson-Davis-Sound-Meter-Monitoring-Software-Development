namespace LarsonDavis.Sdk.TimeHistoryDemo
{
	partial class TimeHistoryDemoForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
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

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			DataGridViewCellStyle dataGridViewCellStyle1 = new DataGridViewCellStyle();
			DataGridViewCellStyle dataGridViewCellStyle2 = new DataGridViewCellStyle();
			DataGridViewCellStyle dataGridViewCellStyle3 = new DataGridViewCellStyle();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TimeHistoryDemoForm));
			menuStrip1 = new MenuStrip();
			fileToolStripMenuItem = new ToolStripMenuItem();
			openToolStripMenuItem = new ToolStripMenuItem();
			exitToolStripMenuItem = new ToolStripMenuItem();
			helpToolStripMenuItem = new ToolStripMenuItem();
			aboutToolStripMenuItem = new ToolStripMenuItem();
			opensFolderToolStripMenuItem = new ToolStripMenuItem();
			lblRecord = new Label();
			Records = new ComboBox();
			lblSummary = new Label();
			Summary = new TextBox();
			groupBox1 = new GroupBox();
			THGrid = new DataGridView();
			openFileDialog1 = new OpenFileDialog();
			menuStrip1.SuspendLayout();
			groupBox1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)THGrid).BeginInit();
			SuspendLayout();
			// 
			// menuStrip1
			// 
			menuStrip1.Items.AddRange(new ToolStripItem[] { fileToolStripMenuItem, helpToolStripMenuItem });
			menuStrip1.Location = new Point(0, 0);
			menuStrip1.Name = "menuStrip1";
			menuStrip1.Size = new Size(800, 24);
			menuStrip1.TabIndex = 0;
			menuStrip1.Text = "menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			fileToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { openToolStripMenuItem, exitToolStripMenuItem });
			fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			fileToolStripMenuItem.Size = new Size(37, 20);
			fileToolStripMenuItem.Text = "&File";
			// 
			// openToolStripMenuItem
			// 
			openToolStripMenuItem.Name = "openToolStripMenuItem";
			openToolStripMenuItem.Size = new Size(180, 22);
			openToolStripMenuItem.Text = "&Open .ldbin file";
			openToolStripMenuItem.ToolTipText = "Open and parse an .ldbin file";
			openToolStripMenuItem.Click += openToolStripMenuItem_Click;
			// 
			// exitToolStripMenuItem
			// 
			exitToolStripMenuItem.Name = "exitToolStripMenuItem";
			exitToolStripMenuItem.Size = new Size(180, 22);
			exitToolStripMenuItem.Text = "E&xit";
			exitToolStripMenuItem.Click += exitToolStripMenuItem_Click;
			// 
			// helpToolStripMenuItem
			// 
			helpToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { aboutToolStripMenuItem });
			helpToolStripMenuItem.Name = "helpToolStripMenuItem";
			helpToolStripMenuItem.Size = new Size(44, 20);
			helpToolStripMenuItem.Text = "&Help";
			// 
			// aboutToolStripMenuItem
			// 
			aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
			aboutToolStripMenuItem.Size = new Size(107, 22);
			aboutToolStripMenuItem.Text = "&About";
			// 
			// opensFolderToolStripMenuItem
			// 
			opensFolderToolStripMenuItem.Name = "opensFolderToolStripMenuItem";
			opensFolderToolStripMenuItem.Size = new Size(180, 22);
			opensFolderToolStripMenuItem.Text = "Convert .s folder";
			opensFolderToolStripMenuItem.ToolTipText = "Converts a .s Folder to an .ldbin file.";
			opensFolderToolStripMenuItem.Click += opensFolderToolStripMenuItem_Click;
			// 
			// lblRecord
			// 
			lblRecord.AutoSize = true;
			lblRecord.Location = new Point(39, 34);
			lblRecord.Name = "lblRecord";
			lblRecord.Size = new Size(44, 15);
			lblRecord.TabIndex = 1;
			lblRecord.Text = "Record";
			// 
			// Records
			// 
			Records.DropDownStyle = ComboBoxStyle.DropDownList;
			Records.DropDownWidth = 151;
			Records.FormattingEnabled = true;
			Records.Location = new Point(101, 31);
			Records.Name = "Records";
			Records.Size = new Size(151, 23);
			Records.TabIndex = 2;
			Records.SelectedIndexChanged += Records_SelectedIndexChanged;
			// 
			// lblSummary
			// 
			lblSummary.AutoSize = true;
			lblSummary.Location = new Point(25, 59);
			lblSummary.Name = "lblSummary";
			lblSummary.Size = new Size(58, 15);
			lblSummary.TabIndex = 3;
			lblSummary.Text = "Summary";
			// 
			// Summary
			// 
			Summary.Location = new Point(101, 59);
			Summary.Name = "Summary";
			Summary.ReadOnly = true;
			Summary.Size = new Size(430, 23);
			Summary.TabIndex = 4;
			// 
			// groupBox1
			// 
			groupBox1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
			groupBox1.Controls.Add(THGrid);
			groupBox1.Location = new Point(0, 88);
			groupBox1.Name = "groupBox1";
			groupBox1.Size = new Size(800, 352);
			groupBox1.TabIndex = 5;
			groupBox1.TabStop = false;
			groupBox1.Text = "Time History";
			// 
			// THGrid
			// 
			THGrid.AllowUserToAddRows = false;
			THGrid.AllowUserToDeleteRows = false;
			THGrid.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
			dataGridViewCellStyle1.Alignment = DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle1.BackColor = SystemColors.Control;
			dataGridViewCellStyle1.Font = new Font("SansSerif", 8.25F, FontStyle.Regular, GraphicsUnit.Point);
			dataGridViewCellStyle1.ForeColor = SystemColors.WindowText;
			dataGridViewCellStyle1.SelectionBackColor = SystemColors.Highlight;
			dataGridViewCellStyle1.SelectionForeColor = SystemColors.HighlightText;
			dataGridViewCellStyle1.WrapMode = DataGridViewTriState.True;
			THGrid.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			THGrid.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			dataGridViewCellStyle2.Alignment = DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle2.BackColor = SystemColors.Window;
			dataGridViewCellStyle2.Font = new Font("SansSerif", 8.25F, FontStyle.Regular, GraphicsUnit.Point);
			dataGridViewCellStyle2.ForeColor = SystemColors.WindowText;
			dataGridViewCellStyle2.SelectionBackColor = SystemColors.Highlight;
			dataGridViewCellStyle2.SelectionForeColor = SystemColors.HighlightText;
			dataGridViewCellStyle2.WrapMode = DataGridViewTriState.False;
			THGrid.DefaultCellStyle = dataGridViewCellStyle2;
			THGrid.Location = new Point(0, 22);
			THGrid.Name = "THGrid";
			THGrid.ReadOnly = true;
			dataGridViewCellStyle3.Alignment = DataGridViewContentAlignment.MiddleLeft;
			dataGridViewCellStyle3.BackColor = SystemColors.Control;
			dataGridViewCellStyle3.Font = new Font("SansSerif", 8.25F, FontStyle.Regular, GraphicsUnit.Point);
			dataGridViewCellStyle3.ForeColor = SystemColors.WindowText;
			dataGridViewCellStyle3.SelectionBackColor = SystemColors.Highlight;
			dataGridViewCellStyle3.SelectionForeColor = SystemColors.HighlightText;
			dataGridViewCellStyle3.WrapMode = DataGridViewTriState.True;
			THGrid.RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			THGrid.RowTemplate.Height = 25;
			THGrid.Size = new Size(800, 330);
			THGrid.TabIndex = 0;
			// 
			// openFileDialog1
			// 
			openFileDialog1.DefaultExt = "ldbin";
			openFileDialog1.Filter = "Larson Davis bin files|*.ldbin|All files|*.*";
			// 
			// TimeHistoryDemoForm
			// 
			AutoScaleDimensions = new SizeF(7F, 15F);
			AutoScaleMode = AutoScaleMode.Font;
			ClientSize = new Size(800, 452);
			Controls.Add(groupBox1);
			Controls.Add(Summary);
			Controls.Add(lblSummary);
			Controls.Add(Records);
			Controls.Add(lblRecord);
			Controls.Add(menuStrip1);
			Icon = (Icon)resources.GetObject("$this.Icon");
			MainMenuStrip = menuStrip1;
			Name = "TimeHistoryDemoForm";
			Text = "TimeHistoryDemo";
			Load += TimeHistoryDemoForm_Load;
			menuStrip1.ResumeLayout(false);
			menuStrip1.PerformLayout();
			groupBox1.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)THGrid).EndInit();
			ResumeLayout(false);
			PerformLayout();
		}

		#endregion

		private MenuStrip menuStrip1;
		private ToolStripMenuItem fileToolStripMenuItem;
		private ToolStripMenuItem openToolStripMenuItem;
		private ToolStripMenuItem opensFolderToolStripMenuItem;
		private ToolStripMenuItem exitToolStripMenuItem;
		private ToolStripMenuItem helpToolStripMenuItem;
		private ToolStripMenuItem aboutToolStripMenuItem;
		private Label lblRecord;
		private ComboBox Records;
		private Label lblSummary;
		private TextBox Summary;
		private GroupBox groupBox1;
		private DataGridView THGrid;
		private OpenFileDialog openFileDialog1;
	}
}