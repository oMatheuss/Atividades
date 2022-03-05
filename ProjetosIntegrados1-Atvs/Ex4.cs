/* Aluno: Matheus Silva Moura, RA: 5152442
 * Atividade 04 - Projetos Integrados - 02/04/22
 */

using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Fatorial de N. Informe N: ");
            int n = Int32.Parse(Console.ReadLine());

            if (n == 0) { Console.WriteLine($"Fatorial de {n:D} = 1"); }
            else if (n > 0)
            {
                int r = 1;
                for (int i = n; i > 0; i--) { r *= i; }
                Console.WriteLine($"Fatorial de {n:D} = {r:D}");
            }
            else { Console.WriteLine("Numero fora do limite!"); }
        }
    }
}