/* Aluno: Matheus Silva Moura, RA: 5152442
 * Atividade 07 - Projetos Integrados - 02/04/22
 */

using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            int count = 0;
            Console.WriteLine("Contando numeros informados até ser informado 10. Informe um numero: ");
            int n = 0;
            do {
                n = Int32.Parse(Console.ReadLine());
                count++;
            } while (n != 10) ;
            Console.WriteLine($"Voçe inseriu {count} numero(s)!");
        }
    }
}