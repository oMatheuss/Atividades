using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JogoDaVelha
{
    public partial class JogoDaVelha : Form
    {
        private Dictionary<int, Button> matriz { get; set;  }
        private int jogador { get; set; }
        private int vitoriasJog1 { get; set; }
        private int vitoriasJog2 { get; set; }

        public JogoDaVelha()
        {
            jogador = 1;
            InitializeComponent();
            matriz = new Dictionary<int, Button>();
            matriz.Add(0, button1);
            matriz.Add(1, button2);
            matriz.Add(2, button3);
            matriz.Add(3, button4);
            matriz.Add(4, button5);
            matriz.Add(5, button6);
            matriz.Add(6, button7);
            matriz.Add(7, button8);
            matriz.Add(8, button9);

            for (int i = 0; i < 9; i++)
            {
                matriz.GetValueOrDefault(i).Text = "";
            }
            /*
            for (int i = 0; i < 9; i++)
            {
                matriz.GetValueOrDefault(i).SetBounds(i * 100, (int)i/3 * 100, 100, 100);
            }
            */
            this.label1.Text = "Jogador X tem " + (vitoriasJog1 = 0) + " vitorias.";
            this.label2.Text = "Jogador O tem " + (vitoriasJog2 = 0) + " vitorias.";
            this.button10.Text = "Reset";
        }

        public bool testeVitoria(string element)
        {
            int count = 0;
            for (int i = 0; i < 9; i += 3)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (matriz.GetValueOrDefault(i + j).Text.Equals(element))
                    {
                        count++;
                    }
                }
                if (count == 3)
                {
                    return true;
                }
                count = 0;
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 9; j += 3)
                {
                    if (matriz.GetValueOrDefault(i + j).Text.Equals(element))
                    {
                        count++;
                    }
                }
                if (count == 3)
                {
                    return true;
                }
                count = 0;
            }

            for (int i = 0; i < 9; i += 4)
            {
                if (matriz.GetValueOrDefault(i).Text.Equals(element))
                {
                    count++;
                }
            }
            if (count == 3)
            {
                return true;
            }
            count = 0;
            for (int i = 2; i < 7; i += 2)
            {
                if (matriz.GetValueOrDefault(i).Text.Equals(element))
                {
                    count++;
                }
            }
            if (count == 3)
            {
                return true;
            }

            return false;
        }

        public void vitoria()
        {
            this.button10.Focus();

            if (testeVitoria("X"))
            {
                MessageBox.Show("Jogador X ganhour!");
                vitoriasJog1++;
                reset();
            }
            if (testeVitoria("O"))
            {
                MessageBox.Show("Jogador O ganhour!");
                vitoriasJog2++;
                reset();
            }

            int count = 0;
            for (int i = 0; i < 9; i++)
            {
                if (matriz.GetValueOrDefault(i).Enabled == false)
                {
                    count++;
                }
            }
            if (count == 9)
            {
                reset();
            }
        }

        public void reset()
        {
            for (int i = 0; i < 9; i++)
            {
                matriz.GetValueOrDefault(i).Text = "";
                matriz.GetValueOrDefault(i).Enabled = true;
            }
            this.label1.Text = "Jogador X tem " + (vitoriasJog1) + " vitorias.";
            this.label2.Text = "Jogador O tem " + (vitoriasJog2) + " vitorias.";
            this.label1.Refresh();
            this.label2.Refresh();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(0).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(0).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(0).Text = "O";
                jogador = 1;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(1).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(1).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(1).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(2).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(2).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(2).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(3).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(3).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(3).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(4).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(4).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(4).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(5).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(5).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(5).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(6).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(6).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(6).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(7).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(7).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(7).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            matriz.GetValueOrDefault(8).Enabled = false;
            if (jogador == 1)
            {
                matriz.GetValueOrDefault(8).Text = "X";
                jogador = 2;
            }
            else
            {
                matriz.GetValueOrDefault(8).Text = "O";
                jogador = 1;
            }
            vitoria();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            vitoriasJog1 = 0;
            vitoriasJog2 = 0;
            reset();
        }
    }
}
