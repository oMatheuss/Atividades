/* Aluno: Matheus Silva Moura, RA: 5152442
 * Atividade 06 - Projetos Integrados - 02/04/22
 */

using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Exponenciação. Informe a base: ");
            int b = Int32.Parse(Console.ReadLine());
            int c = b;
            Console.WriteLine("Exponenciação. Informe o expoente: ");
            int e = Int32.Parse(Console.ReadLine());
            int i = 0;
            do
            {
                b *= c;
                i++;
            } while (i < e-1);

            Console.WriteLine($"{c}^{e} = {b}");
        }
    }
}