/* Aluno: Matheus Silva Moura, RA: 5152442
 * Atividade 03 - Projetos Integrados - 02/04/22
 */

using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Informe três números para os três lados de um triangulo: ");
            double a = Int32.Parse(Console.ReadLine());
            double b = Int32.Parse(Console.ReadLine());
            double c = Int32.Parse(Console.ReadLine());
            double maior = a;
            double catA = b, catB = c;
            if (maior < b) { maior = b; catA = a; catB = c; };
            if (maior < c) { maior = c; catA = a; catB = b; };

            if (maior > Math.Abs(catA - catB) && maior < (catA + catB))
            {
                Console.WriteLine("Os números são os lados de um triangulo!");
            } else
            {
                Console.WriteLine("Os números não são os lados de um triangulo!");
            }
            
        }
    }
}