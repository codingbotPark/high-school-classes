using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Net;
using System.Net.Sockets;

namespace secondAssesment
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[1024];

            UdpClient client = new UdpClient("192.168.153.130", 10007);

            data = Encoding.UTF8.GetBytes("haha");
            client.Send(data, data.Length);

            client.Close();
            Console.WriteLine("Stopping clinet");
        }
    }
}
