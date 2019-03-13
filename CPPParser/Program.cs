using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CPPParser
{
    class Program
    {
        static bool isStructUsed(string struct_name, List<string> lines)
        {
            foreach (var line in lines)
            {
                string[] pv = line.Split(' ', '\t');
                foreach (var v in pv)
                {
                    if (v == struct_name)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        static List<string> getPositions(Dictionary<string, List<string>> pairs)
        {
            List<string> result = new List<string>();
            while (pairs.Count > 1)
            {
                string[] keys = pairs.Keys.ToArray();
                foreach (var key in keys)
                {
                    bool is_struct_used = false;
                    foreach (var pair in pairs)
                    {
                        if (pair.Key == key)
                            continue;
                        if (isStructUsed(key, pair.Value))
                        {
                            is_struct_used = true;
                            break;
                        }
                    }
                    if (!is_struct_used)
                    {
                        result.Add(key);
                        pairs.Remove(key);
                        break;
                    }
                }
            }
            result.Add(pairs.Keys.ToArray()[0]);
            return result;
        }

        static string correctNamespace(string name, string _namespace) {
            if (name.IndexOf("::") == -1)
                return _namespace + "::" + name;
            else
                return name;
        }

        static string getPrefixByType(string type)
        {
            if (type == "int")
                return "Int";
            else if (type == "bool")
                return "Bool";
            else if (type == "double")
                return "Double";
            else if (type == "std::string")
                return "Str";
            else
                return "Undefined";
        }

        static string input_file_name = "test.hpp";
        static string out_file_name = "test_full.hpp";

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(input_file_name);
            string code = sr.ReadToEnd();
            sr.Close();
            string[] lines = code.Split('\r', '\n'); // \r \n for Windows
            bool is_serialize_begin = false;
            List<string> new_lines = new List<string>();
            List<string> write_instructions = new List<string>();
            List<string> read_instructions = new List<string>();
            List<string> read_instructions2 = new List<string>();
            List<string> post_lines = new List<string>();
            Dictionary<string, List<string>> pairs = new Dictionary<string, List<string>>();
            string cur_struct = "";
            string cur_namespace = "";
            bool is_in_struct = false;
            for (int i = 0; i < lines.Length; i++)
            {
                if (lines[i] == "")
                    continue;
                if (lines[i].StartsWith("\t//BEGIN_CPP2SERIALIZE"))
                {
                    is_serialize_begin = true;
                }
                if (lines[i].StartsWith("namespace"))
                    cur_namespace = lines[i].Split(' ')[1];
                if (is_serialize_begin)
                {
                    if (lines[i].StartsWith("\tstruct"))
                    {
                        string name = lines[i].Split(' ')[1];
                        cur_struct = name;
                        is_in_struct = true;
                        pairs.Add(cur_struct, new List<string>());
                        write_instructions.Add(string.Format("\tIXmlSerializer::Scope scope(s, \"{0}\");", name));
                        read_instructions.Add("\tif (init) {");
                        read_instructions.Add(string.Format("\tIXmlSerializer::Scope scope(s, \"{0}\");", name));
                    }
                    
                    if (lines[i] == "\t\t//ATTRIBUTE_STD")
                    {
                        string name = lines[i + 1].Split(' ')[1].Substring(0, lines[i + 1].Split(' ')[1].Length - 1);
                        write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0}.c_str());", name));
                        read_instructions2.Add(string.Format("\t{0} = s.ReadAttrStr(\"{0}\");", name));
                    }
                    if (lines[i] == "\t\t//ATTRIBUTE_PROTO")
                    {
                        string name = lines[i + 1].Split(' ')[1].Substring(0, lines[i + 1].Split(' ')[1].Length - 1);
                        write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0});", name));
                        string ff = lines[i + 1].Split(' ')[0].Substring(2);
                        string prefix = getPrefixByType(ff);
                        read_instructions2.Add(string.Format("\t{0} = s.ReadAttr{1}(\"{0}\");", name, prefix));
                    }
                    if (lines[i] == "\t\t//ELEMENT_STD")
                    {
                        string v = lines[i + 1].Split(' ')[1].Substring(0, lines[i + 1].Split(' ')[1].Length - 1);
                        write_instructions.Add(string.Format("\t{{\n\t\tIXmlSerializer::Scope scope(s, \"{0}\");\n \t\ts.Write({0}.c_str());\n\t}}", v));
                        read_instructions2.Add(string.Format("\t{{\n\t\tIXmlSerializer::Scope scope(s, \"{0}\");\n \t\t{0} = s.ReadStr();\n\t}}", v));
                    }
                    if (lines[i] == "\t\t//ELEMENT_PROTO")
                    {
                        string name = lines[i + 1].Split(' ')[1].Substring(0, lines[i + 1].Split(' ')[1].Length - 1);
                        write_instructions.Add(string.Format("\t{{\n\t\tIXmlSerializer::Scope scope(s, \"{0}\");\n \t\ts.Write({0});\n\t}}", name));
                        string type = lines[i + 1].Split(' ')[0].Substring(2);
                        string s = getPrefixByType(type);
                        read_instructions2.Add(string.Format("\t{{\n\t\tIXmlSerializer::Scope scope(s, \"{0}\");\n \t\t{0} = s.Read{1}();\n\t}}", name, s));
                    }
                    if (lines[i] == "\t\t//ELEMENT_CLASS")
                    {
                        string name = lines[i + 1].Split(' ')[1].Substring(0, lines[i + 1].Split(' ')[1].Length - 1);
                        write_instructions.Add(string.Format("\t{0}.Write(s);", name));
                        read_instructions2.Add(string.Format("\t{0}.Read(s);", name));
                    }
                    if (lines[i] == "\t\t//LIST")
                    {
                        string type = lines[i + 1].Split(' ')[0].Split('<', '>')[1];
                        string name = lines[i + 1].Split(' ')[1].Substring(0, lines[i + 1].Split(' ')[1].Length - 1);
                        if (type == "double" || type == "float" || type == "int" || type == "bool" || type == "std::string")
                        {
                            string s = getPrefixByType(type);
                            write_instructions.Add(string.Format("\tfor(int i = 0;i < {0}.size();i++)\n\t{{\n\t\ts.Write({0}[i]); \n\\t}}", name));
                            read_instructions2.Add(string.Format("{0} = s.ReadVector{1}(\"{0}\")", name, s));
                        }
                        else
                        {
                            write_instructions.Add(string.Format("\tfor(int i = 0;i < {0}.size();i++)\n\t{{\n\t\t{0}[i].Write(s); \n\t}}", name));
                            read_instructions2.Add(string.Format("\t{{\n\t\tIXmlSerializer::Scope scope2(s, \"{0}\");\n\t\tif (scope2.is_successfull) {{\n\t\t\tdo {{\n\t\t\t\t{2} __t;\n\t\t\t\t__t.Read(s, false);\n\t\t\t\t{0}.push_back(__t);\n\t\t\t}} while (s.NextChild(\"{0}\"));\n\t\t}}\n\t}}", name, type, correctNamespace(name, cur_namespace)));
                        }
                    }
                    
                    if (is_serialize_begin && lines[i] == "\t};")
                    {
                        
                        pairs[cur_struct].Add("\t\tvoid Write(IXmlSerializer& s);");
                        pairs[cur_struct].Add("\t\tvoid Read(IXmlSerializer& s, bool = true);");
                        post_lines.Add(string.Format("void {1}::{0}::Write(IXmlSerializer& s)\n{{", cur_struct, cur_namespace));
                        foreach (var instruction in write_instructions)
                        {
                            post_lines.Add(instruction);
                        }
                        post_lines.Add("}\n");
                        post_lines.Add(string.Format("void {1}::{0}::Read(IXmlSerializer& s, bool init)\n{{", cur_struct, cur_namespace));

                        foreach (var instruction in read_instructions)
                        {
                            post_lines.Add(instruction);
                        }
                        
                        foreach (var instruction in read_instructions2)
                        {
                            post_lines.Add(instruction);
                        }

                        post_lines.Add("\t}\n\telse {");
                        foreach (var instruction in read_instructions2)
                        {
                            post_lines.Add(instruction);
                        }

                        post_lines.Add("\t}\n}\n");

                        pairs[cur_struct].Add(lines[i]);
                        is_in_struct = false;
                        write_instructions.Clear();
                        read_instructions.Clear();
                        read_instructions2.Clear();
                    }
                    if (is_in_struct)
                        pairs[cur_struct].Add(lines[i]);
                } else
                    new_lines.Add(lines[i]);
            }
            StreamWriter sw = new StreamWriter(out_file_name);
            foreach (var line in new_lines)
            {
                sw.WriteLine(line);
            }
            Dictionary<string, List<string>> pairs_copy = new Dictionary<string, List<string>>();
            foreach (var pair in pairs)
            {
                pairs_copy.Add(pair.Key, pair.Value);
            }
            List<string> pos = getPositions(pairs_copy);
            pos.Reverse();
            foreach (var item in pos)
            {
                foreach (var line in pairs[item])
                {
                    sw.WriteLine(line);
                }
            }
            sw.WriteLine("}");
            foreach (var line in post_lines)
            {
                sw.WriteLine(line);
            }
            sw.Close();
        }
    }
}
