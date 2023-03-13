using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


using System.IO;
using System.IO.Ports;  //시리얼통신을 위해 추가해줘야 함

namespace firstAccessment
{
    public partial class Form1 : Form
    {
        SerialPort mySerial = new SerialPort("COM3",9600);

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e) // 로드 됐을 때
        {

            mySerial.Open();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            mySerial.Write("1on");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            mySerial.Write("2on");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            mySerial.Write("1off");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            mySerial.Write("2off");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            mySerial.Write("3left");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            mySerial.Write("3right");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            mySerial.Close();
        }
    }
}
