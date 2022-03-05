/* Aluno: Matheus Silva Moura, RA: 5152442
 * Atividade 05 - Projetos Integrados - 02/04/22
 */

using System;

namespace ConsoleApp
{
    class Program
    {
        public static long Fib(int n)
        {
            if (n == 0) return 0;
            else if (n == 1) return 1;
            else return Fib(n - 1) + Fib(n - 2);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Fibonacci na posição N. Informe N: ");
            int n = Int32.Parse(Console.ReadLine());
            Console.WriteLine($"Fib({n:D}) = {Fib(n)}");
        }
    }
}