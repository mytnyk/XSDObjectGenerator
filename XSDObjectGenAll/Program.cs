using CommandLine.Text;
using CommandLine;
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
        public class Options
        {
            [Option('o', "output", Required = false, HelpText = "Output directory")]
            public string Output { get; set; }
            [Option('i', "input", Required = true, HelpText = "Input directory")]
            public string Input { get; set; }
            [Option('n', "namespace", Required = true, HelpText = "Namespace")]
            public string Namespace { get; set; }
            [Option('s', "shell_execute", Required = false, HelpText = "Shell execute")]
            public bool Shell_execute { get; set; }
            [Option('c', "clear_directory", Required = false, HelpText = "Clear directory")]
            public bool Clear_directory { get; set; }
            [Option('w', "wait_for_exit", Required = false, HelpText = "Wait for exit")]
            public bool Wait_for_exit { get; set; }
        }

        static void Main(string[] args)
        {
            Parser.Default.ParseArguments<Options>(args)
                   .WithParsed<Options>(o =>
                   {
                       if (o.Clear_directory && o.Output != null)
                       {
                           DirectoryInfo di = new DirectoryInfo($"{Environment.CurrentDirectory}\\{o.Output}");
                           if (di.Exists)
                           {
                               foreach (FileInfo file in di.GetFiles())
                               {
                                   file.Delete();
                               }
                               foreach (DirectoryInfo dir in di.GetDirectories())
                               {
                                   dir.Delete(true);
                               }
                           }
                       }

                       var currentDir = Path.GetDirectoryName(typeof(Program).Assembly.Location);
                       var filePathToStart = Path.Combine(currentDir, "XSDObjectGen.exe");
                       string[] filePaths = Directory.GetFiles(o.Input);
                       foreach (var path in filePaths)
                       {
                           Console.WriteLine($"---------- Processing {path}");
                           System.Diagnostics.Process pProcess = new System.Diagnostics.Process();
                           pProcess.StartInfo.FileName = filePathToStart;

                           if (o.Output != null)
                           {
                               pProcess.StartInfo.Arguments = $"{path} /n:{o.Namespace} /f:{o.Output}\\{Path.GetFileNameWithoutExtension(path)}";
                               var dir = Path.Combine(Environment.CurrentDirectory, o.Output);
                               if (!Directory.Exists(dir))
                               {
                                   Directory.CreateDirectory(dir);
                               }
                           }
                           else
                           {
                               pProcess.StartInfo.Arguments = $"{path} /n:{o.Namespace} /f:{Path.GetFileNameWithoutExtension(path)}";
                           }
                           pProcess.StartInfo.RedirectStandardOutput = true;
                           pProcess.StartInfo.RedirectStandardError = true;
                           //if (o.Shell_execute)
                           //    pProcess.StartInfo.UseShellExecute = true;
                           //else
                               pProcess.StartInfo.UseShellExecute = false;
                           pProcess.Start();
                           //if (o.Wait_for_exit)
                           //    pProcess.WaitForExit();
                           var output = pProcess.StandardOutput.ReadToEnd();
                           if (!string.IsNullOrWhiteSpace(output))
                           {
                               Console.WriteLine(output);
                           }
                           var error = pProcess.StandardError.ReadToEnd();
                           if (!string.IsNullOrWhiteSpace(error))
                           {
                               Console.WriteLine(error);
                           }
                           pProcess.WaitForExit();
                           var code = pProcess.ExitCode;
                           pProcess.Close();
                       }
                   });
        }
    }
}
