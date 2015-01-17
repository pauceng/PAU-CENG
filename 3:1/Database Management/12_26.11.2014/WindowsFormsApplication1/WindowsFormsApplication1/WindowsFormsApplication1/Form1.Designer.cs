namespace WindowsFormsApplication1
{
    partial class Form1
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
            System.Windows.Forms.Label urunAdiLabel;
            System.Windows.Forms.Label urunFiyatiLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            System.Windows.Forms.Label urunAdiLabel1;
            System.Windows.Forms.Label urunIDLabel;
            this.btnara = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.denemeDataSet = new WindowsFormsApplication1.DenemeDataSet();
            this.denemeDataSetBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tblUrunlerBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tblUrunlerTableAdapter = new WindowsFormsApplication1.DenemeDataSetTableAdapters.tblUrunlerTableAdapter();
            this.urunIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.urunAdiDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.urunFiyatiDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tblUrunlerBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.tableAdapterManager = new WindowsFormsApplication1.DenemeDataSetTableAdapters.TableAdapterManager();
            this.urunAdiTextBox = new System.Windows.Forms.TextBox();
            this.urunFiyatiTextBox = new System.Windows.Forms.TextBox();
            this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
            this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
            this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigator1 = new System.Windows.Forms.BindingNavigator(this.components);
            this.urunAdiComboBox = new System.Windows.Forms.ComboBox();
            this.urunIDTextBox = new System.Windows.Forms.TextBox();
            urunAdiLabel = new System.Windows.Forms.Label();
            urunFiyatiLabel = new System.Windows.Forms.Label();
            urunAdiLabel1 = new System.Windows.Forms.Label();
            urunIDLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.denemeDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.denemeDataSetBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tblUrunlerBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tblUrunlerBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingNavigator1)).BeginInit();
            this.bindingNavigator1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnara
            // 
            this.btnara.Location = new System.Drawing.Point(432, 60);
            this.btnara.Name = "btnara";
            this.btnara.Size = new System.Drawing.Size(75, 23);
            this.btnara.TabIndex = 3;
            this.btnara.Text = "tıkla bana";
            this.btnara.UseVisualStyleBackColor = true;
            this.btnara.Click += new System.EventHandler(this.btnara_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.urunIDDataGridViewTextBoxColumn,
            this.urunAdiDataGridViewTextBoxColumn,
            this.urunFiyatiDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.tblUrunlerBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(12, 100);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(495, 161);
            this.dataGridView1.TabIndex = 4;
            // 
            // denemeDataSet
            // 
            this.denemeDataSet.DataSetName = "DenemeDataSet";
            this.denemeDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // denemeDataSetBindingSource
            // 
            this.denemeDataSetBindingSource.DataSource = this.denemeDataSet;
            this.denemeDataSetBindingSource.Position = 0;
            // 
            // tblUrunlerBindingSource
            // 
            this.tblUrunlerBindingSource.DataMember = "tblUrunler";
            this.tblUrunlerBindingSource.DataSource = this.denemeDataSetBindingSource;
            // 
            // tblUrunlerTableAdapter
            // 
            this.tblUrunlerTableAdapter.ClearBeforeFill = true;
            // 
            // urunIDDataGridViewTextBoxColumn
            // 
            this.urunIDDataGridViewTextBoxColumn.DataPropertyName = "urunID";
            this.urunIDDataGridViewTextBoxColumn.HeaderText = "urunID";
            this.urunIDDataGridViewTextBoxColumn.Name = "urunIDDataGridViewTextBoxColumn";
            this.urunIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // urunAdiDataGridViewTextBoxColumn
            // 
            this.urunAdiDataGridViewTextBoxColumn.DataPropertyName = "urunAdi";
            this.urunAdiDataGridViewTextBoxColumn.HeaderText = "urunAdi";
            this.urunAdiDataGridViewTextBoxColumn.Name = "urunAdiDataGridViewTextBoxColumn";
            this.urunAdiDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // urunFiyatiDataGridViewTextBoxColumn
            // 
            this.urunFiyatiDataGridViewTextBoxColumn.DataPropertyName = "urunFiyati";
            this.urunFiyatiDataGridViewTextBoxColumn.HeaderText = "urunFiyati";
            this.urunFiyatiDataGridViewTextBoxColumn.Name = "urunFiyatiDataGridViewTextBoxColumn";
            this.urunFiyatiDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // tblUrunlerBindingSource1
            // 
            this.tblUrunlerBindingSource1.DataMember = "tblUrunler";
            this.tblUrunlerBindingSource1.DataSource = this.denemeDataSet;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.tblUrunlerTableAdapter = this.tblUrunlerTableAdapter;
            this.tableAdapterManager.UpdateOrder = WindowsFormsApplication1.DenemeDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // urunAdiLabel
            // 
            urunAdiLabel.AutoSize = true;
            urunAdiLabel.Location = new System.Drawing.Point(17, 34);
            urunAdiLabel.Name = "urunAdiLabel";
            urunAdiLabel.Size = new System.Drawing.Size(49, 13);
            urunAdiLabel.TabIndex = 5;
            urunAdiLabel.Text = "urun Adi:";
            // 
            // urunAdiTextBox
            // 
            this.urunAdiTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tblUrunlerBindingSource1, "urunAdi", true));
            this.urunAdiTextBox.Location = new System.Drawing.Point(72, 31);
            this.urunAdiTextBox.Name = "urunAdiTextBox";
            this.urunAdiTextBox.Size = new System.Drawing.Size(100, 20);
            this.urunAdiTextBox.TabIndex = 6;
            // 
            // urunFiyatiLabel
            // 
            urunFiyatiLabel.AutoSize = true;
            urunFiyatiLabel.Location = new System.Drawing.Point(8, 60);
            urunFiyatiLabel.Name = "urunFiyatiLabel";
            urunFiyatiLabel.Size = new System.Drawing.Size(58, 13);
            urunFiyatiLabel.TabIndex = 6;
            urunFiyatiLabel.Text = "urun Fiyati:";
            // 
            // urunFiyatiTextBox
            // 
            this.urunFiyatiTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tblUrunlerBindingSource1, "urunFiyati", true));
            this.urunFiyatiTextBox.Location = new System.Drawing.Point(72, 57);
            this.urunFiyatiTextBox.Name = "urunFiyatiTextBox";
            this.urunFiyatiTextBox.Size = new System.Drawing.Size(100, 20);
            this.urunFiyatiTextBox.TabIndex = 7;
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
            this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
            this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveFirstItem.Text = "Move first";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
            this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
            this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMovePreviousItem.Text = "Move previous";
            // 
            // bindingNavigatorSeparator
            // 
            this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorPositionItem
            // 
            this.bindingNavigatorPositionItem.AccessibleName = "Position";
            this.bindingNavigatorPositionItem.AutoSize = false;
            this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
            this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 23);
            this.bindingNavigatorPositionItem.Text = "0";
            this.bindingNavigatorPositionItem.ToolTipText = "Current position";
            // 
            // bindingNavigatorCountItem
            // 
            this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
            this.bindingNavigatorCountItem.Size = new System.Drawing.Size(35, 22);
            this.bindingNavigatorCountItem.Text = "of {0}";
            this.bindingNavigatorCountItem.ToolTipText = "Total number of items";
            // 
            // bindingNavigatorSeparator1
            // 
            this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
            this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
            this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
            this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveNextItem.Text = "Move next";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
            this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
            this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveLastItem.Text = "Move last";
            // 
            // bindingNavigatorSeparator2
            // 
            this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
            this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigator1
            // 
            this.bindingNavigator1.AddNewItem = null;
            this.bindingNavigator1.BindingSource = this.tblUrunlerBindingSource;
            this.bindingNavigator1.CountItem = this.bindingNavigatorCountItem;
            this.bindingNavigator1.DeleteItem = null;
            this.bindingNavigator1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2});
            this.bindingNavigator1.Location = new System.Drawing.Point(0, 0);
            this.bindingNavigator1.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.bindingNavigator1.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.bindingNavigator1.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.bindingNavigator1.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.bindingNavigator1.Name = "bindingNavigator1";
            this.bindingNavigator1.PositionItem = this.bindingNavigatorPositionItem;
            this.bindingNavigator1.Size = new System.Drawing.Size(527, 25);
            this.bindingNavigator1.TabIndex = 5;
            this.bindingNavigator1.Text = "bindingNavigator1";
            // 
            // urunAdiLabel1
            // 
            urunAdiLabel1.AutoSize = true;
            urunAdiLabel1.Location = new System.Drawing.Point(188, 29);
            urunAdiLabel1.Name = "urunAdiLabel1";
            urunAdiLabel1.Size = new System.Drawing.Size(49, 13);
            urunAdiLabel1.TabIndex = 7;
            urunAdiLabel1.Text = "urun Adi:";
            // 
            // urunAdiComboBox
            // 
            this.urunAdiComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tblUrunlerBindingSource1, "urunAdi", true));
            this.urunAdiComboBox.DataSource = this.tblUrunlerBindingSource;
            this.urunAdiComboBox.DisplayMember = "urunAdi";
            this.urunAdiComboBox.FormattingEnabled = true;
            this.urunAdiComboBox.Location = new System.Drawing.Point(243, 26);
            this.urunAdiComboBox.Name = "urunAdiComboBox";
            this.urunAdiComboBox.Size = new System.Drawing.Size(121, 21);
            this.urunAdiComboBox.TabIndex = 8;
            // 
            // urunIDLabel
            // 
            urunIDLabel.AutoSize = true;
            urunIDLabel.Location = new System.Drawing.Point(192, 63);
            urunIDLabel.Name = "urunIDLabel";
            urunIDLabel.Size = new System.Drawing.Size(45, 13);
            urunIDLabel.TabIndex = 9;
            urunIDLabel.Text = "urun ID:";
            // 
            // urunIDTextBox
            // 
            this.urunIDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.tblUrunlerBindingSource1, "urunID", true));
            this.urunIDTextBox.Location = new System.Drawing.Point(243, 60);
            this.urunIDTextBox.Name = "urunIDTextBox";
            this.urunIDTextBox.Size = new System.Drawing.Size(100, 20);
            this.urunIDTextBox.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(527, 281);
            this.Controls.Add(urunIDLabel);
            this.Controls.Add(this.urunIDTextBox);
            this.Controls.Add(urunAdiLabel1);
            this.Controls.Add(this.urunAdiComboBox);
            this.Controls.Add(urunFiyatiLabel);
            this.Controls.Add(this.urunFiyatiTextBox);
            this.Controls.Add(urunAdiLabel);
            this.Controls.Add(this.urunAdiTextBox);
            this.Controls.Add(this.bindingNavigator1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.btnara);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form1";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.denemeDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.denemeDataSetBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tblUrunlerBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tblUrunlerBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingNavigator1)).EndInit();
            this.bindingNavigator1.ResumeLayout(false);
            this.bindingNavigator1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnara;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.BindingSource denemeDataSetBindingSource;
        private DenemeDataSet denemeDataSet;
        private System.Windows.Forms.BindingSource tblUrunlerBindingSource;
        private DenemeDataSetTableAdapters.tblUrunlerTableAdapter tblUrunlerTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn urunIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn urunAdiDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn urunFiyatiDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource tblUrunlerBindingSource1;
        private DenemeDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.TextBox urunAdiTextBox;
        private System.Windows.Forms.TextBox urunFiyatiTextBox;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
        private System.Windows.Forms.BindingNavigator bindingNavigator1;
        private System.Windows.Forms.ComboBox urunAdiComboBox;
        private System.Windows.Forms.TextBox urunIDTextBox;

    }
}

