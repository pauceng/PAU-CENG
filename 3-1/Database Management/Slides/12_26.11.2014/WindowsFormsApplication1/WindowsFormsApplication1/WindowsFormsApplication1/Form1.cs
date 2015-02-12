using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void bindingNavigatorMovePreviousItem_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'denemeDataSet.tblUrunler' table. You can move, or remove it, as needed.
            this.tblUrunlerTableAdapter.Fill(this.denemeDataSet.tblUrunler);

        }

        private void btnara_Click(object sender, EventArgs e)
        {
            int id = int.Parse(urunIDTextBox.Text.ToString());

            //this.tblUrunlerTableAdapter.Fill(
            urunIDTextBox.Text = tableAdapterManager.tblUrunlerTableAdapter.ScalarQuery(id).ToString();
                //);
        }
    }
}
