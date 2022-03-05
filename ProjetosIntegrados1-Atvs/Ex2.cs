/* Aluno: Matheus Silva Moura, RA: 5152442
 * Atividade 02 - Projetos Integrados - 02/04/22
 */

using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Informe N: ");
            int n = Int32.Parse(Console.ReadLine());

            if (!(n % 2 == 0)) { n--; }
            for (int i = n; i >= 0; i -= 2)
            {
                Console.Write($"{i} ");
            }
        }
    }
}