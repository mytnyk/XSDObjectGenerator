using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace XSDObjectGenAll
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args == null || (args.Length != 5 && args.Length != 6))
            {
                Console.WriteLine("Please run program with args: [path to schemas] [namespace] [use shell execute(y for yes, n for no)] [clear directory(y for yes, n for no)][wait for exit(y for yes, n for no)] [save folder]. If save folder is empty uses exe folder.");
                Console.ReadKey();
                return;
            }


            if (args[3].ToLower() == "y" || args[3].ToLower() == "yes")
            {
                DirectoryInfo di = new DirectoryInfo($"{Environment.CurrentDirectory}\\{args[5]}");
                foreach (FileInfo file in di.GetFiles())
                {
                    file.Delete();
                }
                foreach (DirectoryInfo dir in di.GetDirectories())
                {
                    dir.Delete(true);
                }
            }

            string[] filePaths = Directory.GetFiles(args[0]);
            foreach (var path in filePaths)
            {
                System.Diagnostics.Process pProcess = new System.Diagnostics.Process();
                pProcess.StartInfo.FileName = "XSDObjectGen.exe";
                if (args.Length == 6)
                {
                    pProcess.StartInfo.Arguments = $"{path} /n:{args[1]} /f:{args[5]}\\{Path.GetFileNameWithoutExtension(path)}";
                    if (!Directory.Exists($"{Environment.CurrentDirectory}\\{args[5]}"))
                    {
                        Directory.CreateDirectory($"{Environment.CurrentDirectory}\\{args[5]}");
                    }
                }
                else
                {
                    pProcess.StartInfo.Arguments = $"{path} /n:{args[1]} /f:{Path.GetFileNameWithoutExtension(path)}";
                }
                
                if (args[2].ToLower() == "y" || args[2].ToLower() == "yes")
                    pProcess.StartInfo.UseShellExecute = true;
                else
                    pProcess.StartInfo.UseShellExecute = false;
                pProcess.Start();
                if (args[4].ToLower() == "y" || args[4].ToLower() == "yes")
                    pProcess.WaitForExit();
                pProcess.Close();
            }
        }
    }
}
