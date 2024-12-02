namespace LarsonDavis.Sdk.LiveStreamDemo
{
	partial class DataStream
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
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DataStream));
			this.tbConnectionString = new System.Windows.Forms.TextBox();
			this.lbConString = new System.Windows.Forms.Label();
			this.lblValue = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.btnStart = new System.Windows.Forms.Button();
			this.btnStop = new System.Windows.Forms.Button();
			this.btnDisconnect = new System.Windows.Forms.Button();
			this.cmbFlags = new System.Windows.Forms.ComboBox();
			this.cmbRate = new System.Windows.Forms.ComboBox();
			this.sfdOutputFileDlg = new System.Windows.Forms.SaveFileDialog();
			this.tbFileName = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.cbWriteToFile = new System.Windows.Forms.CheckBox();
			this.mToolTip = new System.Windows.Forms.ToolTip(this.components);
			this.label3 = new System.Windows.Forms.Label();
			this.cbStayOpen = new System.Windows.Forms.CheckBox();
			this.cbMoveFile = new System.Windows.Forms.CheckBox();
			this.cbNoConnection = new System.Windows.Forms.CheckBox();
			this.tbLogFile = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.cbJustValue = new System.Windows.Forms.CheckBox();
			this.SuspendLayout();
			// 
			// tbConnectionString
			// 
			this.tbConnectionString.BackColor = System.Drawing.Color.Black;
			this.tbConnectionString.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.tbConnectionString.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.tbConnectionString.ForeColor = System.Drawing.Color.Cyan;
			this.tbConnectionString.Location = new System.Drawing.Point(12, 25);
			this.tbConnectionString.Name = "tbConnectionString";
			this.tbConnectionString.Size = new System.Drawing.Size(195, 21);
			this.tbConnectionString.TabIndex = 0;
			this.tbConnectionString.Text = "USB;0;300";
			this.mToolTip.SetToolTip(this.tbConnectionString, "This value can be for a USB connection and would appear as the following: USB;0;3" +
        "00.  If you are trying to connect to an 831-INT-ET then you would enter the IP A" +
        "ddress.");
			// 
			// lbConString
			// 
			this.lbConString.AutoSize = true;
			this.lbConString.BackColor = System.Drawing.Color.Transparent;
			this.lbConString.Location = new System.Drawing.Point(12, 9);
			this.lbConString.Name = "lbConString";
			this.lbConString.Size = new System.Drawing.Size(94, 13);
			this.lbConString.TabIndex = 1;
			this.lbConString.Text = "Connection String:";
			// 
			// lblValue
			// 
			this.lblValue.BackColor = System.Drawing.Color.Transparent;
			this.lblValue.Font = new System.Drawing.Font("Lucida Sans", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblValue.Location = new System.Drawing.Point(200, 96);
			this.lblValue.Name = "lblValue";
			this.lblValue.Size = new System.Drawing.Size(102, 77);
			this.lblValue.TabIndex = 2;
			this.lblValue.Text = "0.0";
			this.lblValue.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.BackColor = System.Drawing.Color.Transparent;
			this.label2.Font = new System.Drawing.Font("Lucida Sans", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(233, 177);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(29, 18);
			this.label2.TabIndex = 3;
			this.label2.Text = "dB";
			// 
			// btnStart
			// 
			this.btnStart.BackColor = System.Drawing.Color.Transparent;
			this.btnStart.FlatAppearance.BorderSize = 0;
			this.btnStart.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
			this.btnStart.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
			this.btnStart.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnStart.Font = new System.Drawing.Font("Lucida Sans", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnStart.ForeColor = System.Drawing.Color.Cyan;
			this.btnStart.Image = ((System.Drawing.Image)(resources.GetObject("btnStart.Image")));
			this.btnStart.Location = new System.Drawing.Point(364, 185);
			this.btnStart.Name = "btnStart";
			this.btnStart.Size = new System.Drawing.Size(125, 27);
			this.btnStart.TabIndex = 4;
			this.btnStart.Text = "Start";
			this.btnStart.UseVisualStyleBackColor = false;
			this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
			this.btnStart.MouseEnter += new System.EventHandler(this.buttonEnter);
			this.btnStart.MouseLeave += new System.EventHandler(this.buttonLeave);
			// 
			// btnStop
			// 
			this.btnStop.BackColor = System.Drawing.Color.Transparent;
			this.btnStop.FlatAppearance.BorderSize = 0;
			this.btnStop.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
			this.btnStop.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
			this.btnStop.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnStop.Font = new System.Drawing.Font("Lucida Sans", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnStop.ForeColor = System.Drawing.Color.Cyan;
			this.btnStop.Image = ((System.Drawing.Image)(resources.GetObject("btnStop.Image")));
			this.btnStop.Location = new System.Drawing.Point(363, 217);
			this.btnStop.Name = "btnStop";
			this.btnStop.Size = new System.Drawing.Size(128, 28);
			this.btnStop.TabIndex = 4;
			this.btnStop.Text = "Stop";
			this.btnStop.UseVisualStyleBackColor = false;
			this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
			this.btnStop.MouseEnter += new System.EventHandler(this.buttonEnter);
			this.btnStop.MouseLeave += new System.EventHandler(this.buttonLeave);
			// 
			// btnDisconnect
			// 
			this.btnDisconnect.BackColor = System.Drawing.Color.Transparent;
			this.btnDisconnect.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btnDisconnect.FlatAppearance.BorderSize = 0;
			this.btnDisconnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnDisconnect.Image = ((System.Drawing.Image)(resources.GetObject("btnDisconnect.Image")));
			this.btnDisconnect.Location = new System.Drawing.Point(12, 219);
			this.btnDisconnect.Name = "btnDisconnect";
			this.btnDisconnect.Size = new System.Drawing.Size(133, 24);
			this.btnDisconnect.TabIndex = 5;
			this.btnDisconnect.Text = "Disconnect";
			this.mToolTip.SetToolTip(this.btnDisconnect, "This will disconnect from the meter.");
			this.btnDisconnect.UseVisualStyleBackColor = false;
			this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
			this.btnDisconnect.MouseEnter += new System.EventHandler(this.buttonEnter);
			this.btnDisconnect.MouseLeave += new System.EventHandler(this.buttonLeave);
			// 
			// cmbFlags
			// 
			this.cmbFlags.FormattingEnabled = true;
			this.cmbFlags.Location = new System.Drawing.Point(364, 25);
			this.cmbFlags.Name = "cmbFlags";
			this.cmbFlags.Size = new System.Drawing.Size(121, 21);
			this.cmbFlags.TabIndex = 6;
			this.mToolTip.SetToolTip(this.cmbFlags, "Set the value you wish to stream.");
			// 
			// cmbRate
			// 
			this.cmbRate.FormattingEnabled = true;
			this.cmbRate.Location = new System.Drawing.Point(364, 53);
			this.cmbRate.Name = "cmbRate";
			this.cmbRate.Size = new System.Drawing.Size(121, 21);
			this.cmbRate.TabIndex = 7;
			this.mToolTip.SetToolTip(this.cmbRate, "Set the rate at which you wish to stream.");
			// 
			// sfdOutputFileDlg
			// 
			this.sfdOutputFileDlg.FileName = "XMLOutput.xml";
			// 
			// tbFileName
			// 
			this.tbFileName.BackColor = System.Drawing.Color.Black;
			this.tbFileName.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.tbFileName.Font = new System.Drawing.Font("Arial Narrow", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.tbFileName.ForeColor = System.Drawing.Color.Cyan;
			this.tbFileName.Location = new System.Drawing.Point(15, 183);
			this.tbFileName.Multiline = true;
			this.tbFileName.Name = "tbFileName";
			this.tbFileName.Size = new System.Drawing.Size(178, 30);
			this.tbFileName.TabIndex = 8;
			this.mToolTip.SetToolTip(this.tbFileName, "Click here to change the location of the file.");
			this.tbFileName.Click += new System.EventHandler(this.tbFileName_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.BackColor = System.Drawing.Color.Transparent;
			this.label1.Location = new System.Drawing.Point(15, 168);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(26, 13);
			this.label1.TabIndex = 9;
			this.label1.Text = "File:";
			// 
			// cbWriteToFile
			// 
			this.cbWriteToFile.AutoSize = true;
			this.cbWriteToFile.BackColor = System.Drawing.Color.Transparent;
			this.cbWriteToFile.Checked = true;
			this.cbWriteToFile.CheckState = System.Windows.Forms.CheckState.Checked;
			this.cbWriteToFile.Location = new System.Drawing.Point(18, 148);
			this.cbWriteToFile.Name = "cbWriteToFile";
			this.cbWriteToFile.Size = new System.Drawing.Size(82, 17);
			this.cbWriteToFile.TabIndex = 10;
			this.cbWriteToFile.Text = "Write to File";
			this.cbWriteToFile.UseVisualStyleBackColor = false;
			// 
			// mToolTip
			// 
			this.mToolTip.ToolTipIcon = System.Windows.Forms.ToolTipIcon.Info;
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.BackColor = System.Drawing.Color.Transparent;
			this.label3.Location = new System.Drawing.Point(274, 232);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(43, 13);
			this.label3.TabIndex = 11;
			this.label3.Text = "v.2.300";
			// 
			// cbStayOpen
			// 
			this.cbStayOpen.AutoSize = true;
			this.cbStayOpen.BackColor = System.Drawing.Color.Transparent;
			this.cbStayOpen.Location = new System.Drawing.Point(374, 132);
			this.cbStayOpen.Name = "cbStayOpen";
			this.cbStayOpen.Size = new System.Drawing.Size(99, 17);
			this.cbStayOpen.TabIndex = 12;
			this.cbStayOpen.Text = "Keep File Open";
			this.cbStayOpen.UseVisualStyleBackColor = false;
			this.cbStayOpen.Click += new System.EventHandler(this.cbStayOpen_CheckedChanged);
			// 
			// cbMoveFile
			// 
			this.cbMoveFile.AutoSize = true;
			this.cbMoveFile.BackColor = System.Drawing.Color.Transparent;
			this.cbMoveFile.Location = new System.Drawing.Point(374, 152);
			this.cbMoveFile.Name = "cbMoveFile";
			this.cbMoveFile.Size = new System.Drawing.Size(72, 17);
			this.cbMoveFile.TabIndex = 12;
			this.cbMoveFile.Text = "Move File";
			this.cbMoveFile.UseVisualStyleBackColor = false;
			this.cbMoveFile.Click += new System.EventHandler(this.cbMoveFile_CheckedChanged);
			// 
			// cbNoConnection
			// 
			this.cbNoConnection.AutoSize = true;
			this.cbNoConnection.BackColor = System.Drawing.Color.Transparent;
			this.cbNoConnection.Location = new System.Drawing.Point(374, 96);
			this.cbNoConnection.Name = "cbNoConnection";
			this.cbNoConnection.Size = new System.Drawing.Size(97, 17);
			this.cbNoConnection.TabIndex = 12;
			this.cbNoConnection.Text = "No Connection";
			this.cbNoConnection.UseVisualStyleBackColor = false;
			this.cbNoConnection.Click += new System.EventHandler(this.cbStayOpen_CheckedChanged);
			// 
			// tbLogFile
			// 
			this.tbLogFile.BackColor = System.Drawing.Color.Black;
			this.tbLogFile.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.tbLogFile.Font = new System.Drawing.Font("Arial Narrow", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.tbLogFile.ForeColor = System.Drawing.Color.Cyan;
			this.tbLogFile.Location = new System.Drawing.Point(12, 81);
			this.tbLogFile.Multiline = true;
			this.tbLogFile.Name = "tbLogFile";
			this.tbLogFile.Size = new System.Drawing.Size(159, 32);
			this.tbLogFile.TabIndex = 8;
			this.tbLogFile.Click += new System.EventHandler(this.tbFileName_Click);
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.BackColor = System.Drawing.Color.Transparent;
			this.label4.Location = new System.Drawing.Point(10, 66);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(44, 13);
			this.label4.TabIndex = 13;
			this.label4.Text = "Log File";
			// 
			// cbJustValue
			// 
			this.cbJustValue.AutoSize = true;
			this.cbJustValue.BackColor = System.Drawing.Color.Transparent;
			this.cbJustValue.Checked = true;
			this.cbJustValue.CheckState = System.Windows.Forms.CheckState.Checked;
			this.cbJustValue.Location = new System.Drawing.Point(18, 125);
			this.cbJustValue.Name = "cbJustValue";
			this.cbJustValue.Size = new System.Drawing.Size(127, 17);
			this.cbJustValue.TabIndex = 10;
			this.cbJustValue.Text = "Output only the value";
			this.mToolTip.SetToolTip(this.cbJustValue, "Checking this will cause the output to only include the value.  No XML will be ou" +
        "tput.");
			this.cbJustValue.UseVisualStyleBackColor = false;
			// 
			// DataStream
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
			this.CancelButton = this.btnDisconnect;
			this.ClientSize = new System.Drawing.Size(503, 254);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.cbMoveFile);
			this.Controls.Add(this.cbNoConnection);
			this.Controls.Add(this.cbStayOpen);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.cbJustValue);
			this.Controls.Add(this.cbWriteToFile);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.tbLogFile);
			this.Controls.Add(this.tbFileName);
			this.Controls.Add(this.cmbRate);
			this.Controls.Add(this.cmbFlags);
			this.Controls.Add(this.btnDisconnect);
			this.Controls.Add(this.btnStop);
			this.Controls.Add(this.btnStart);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.lblValue);
			this.Controls.Add(this.lbConString);
			this.Controls.Add(this.tbConnectionString);
			this.ForeColor = System.Drawing.Color.Cyan;
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "DataStream";
			this.Text = "Live Stream Data v2.300";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox tbConnectionString;
		private System.Windows.Forms.Label lbConString;
		private System.Windows.Forms.Label lblValue;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btnStart;
		private System.Windows.Forms.Button btnStop;
		private System.Windows.Forms.Button btnDisconnect;
		private System.Windows.Forms.ComboBox cmbFlags;
		private System.Windows.Forms.ComboBox cmbRate;
		private System.Windows.Forms.SaveFileDialog sfdOutputFileDlg;
		private System.Windows.Forms.TextBox tbFileName;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.CheckBox cbWriteToFile;
		private System.Windows.Forms.ToolTip mToolTip;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.CheckBox cbStayOpen;
		private System.Windows.Forms.CheckBox cbMoveFile;
		private System.Windows.Forms.CheckBox cbNoConnection;
		private System.Windows.Forms.TextBox tbLogFile;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.CheckBox cbJustValue;
	}
}

