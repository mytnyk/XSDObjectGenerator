using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XSDObjectGenLib
{
    class GeneratorStream
    {
        public class Struct
        {
            public List<string> write_instructions;
            public List<string> read_instructions;
			public List<string> constructor_instructions;
			public List<string> tile;
			public HashSet<string> classes_used;

            public Struct() {
                write_instructions = new List<string>();
                read_instructions = new List<string>();
				constructor_instructions = new List<string>();
				tile = new List<string>();
				classes_used = new HashSet<string>();
            }
        }

        private Dictionary<string, Struct> structs;
        private List<string> enums;
        private string _namespace;
        private string cur_index;
        private string initString = "#pragma once\n// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk\n// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)\n//--------------------------------------------------------------";
        private string includeString = "#include <iostream>\n#include <string>\n#include <ctime>";

        public GeneratorStream(string name_space)
        {
            structs = new Dictionary<string, Struct>();
            enums = new List<string>();
            _namespace = name_space;
        }

        private string correctNamespace(string name)
        {
            if (name.IndexOf("::") == -1)
                return _namespace + "::" + name;
            else
                return name;
        }

        private bool checkIsPrototype(string type)
        {
            if (type == "int" || type == "bool" || type == "double" || type == "std::string") // prototype means non user defined class, so std::string is here
                return true;
            else
                return false;
        }

        private string getPrefixByType(string type)
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

        public void put_FieldCollectionTemplate(string type, string name, string default_value, bool is_required)
        {
            string correct_type = correctNamespace(type);
            if (checkIsPrototype(type))
                correct_type = type;
            structs[cur_index].tile.Add("\tstd::vector<" + correct_type + "> " + name + ";");
            if (checkIsPrototype(type))
            {
                string prefix = getPrefixByType(type);
                structs[cur_index].write_instructions.Add(string.Format("\tfor(int i = 0;i < {0}.size();i++)\n\t{{\n\t\ts.Write({0}[i]); \n\\t}}", name));
                structs[cur_index].read_instructions.Add(string.Format("{0} = s.ReadVector{1}(\"{0}\")", name, prefix));
            }
            else
            {
				if (is_required)
					structs[cur_index].classes_used.Add(correct_type);
                structs[cur_index].write_instructions.Add(string.Format("\tfor(int i = 0;i < {0}.size();i++)\n\t{{\n\t\t{0}[i].Write(s); \n\t}}", name));
                structs[cur_index].read_instructions.Add(string.Format("\twhile (true) {{ \n\t\t{1} __t;\n\t\tif (__t.Read(s) == false)\n\t\t\tbreak;\n\t\t{0}.push_back(__t);\n\t}}", name, correctNamespace(type)));
			}
			if (default_value != null)
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = {1};", name, default_value));
		}

        public void put_FieldClassTemplate(string type, string name, string default_value, bool is_required)
        {
            string correct_type = correctNamespace(type);
			if (is_required)
				structs[cur_index].tile.Add("\t" + correct_type + " " + name + ";");
			else
				structs[cur_index].tile.Add("\tstd::optional<std::reference_wrapper<" + correct_type + ">> " + name + ";");
			structs[cur_index].classes_used.Add(correct_type);
			structs[cur_index].write_instructions.Add(string.Format("\t{0}.Write(s);", name));
			//structs[cur_index].read_instructions.Add(string.Format("\t{0} = new {1}();", name, correctNamespace(name)));
			structs[cur_index].read_instructions.Add(string.Format("\t{0}.Read(s);", name));
			if (default_value != null)
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = {1};", name, default_value));
		}

        public void put_ElementObjectTemplate(string type, string name, string default_value, bool is_required)
		{
            if (type.Split('<', '>')[0] == "std::string")
            {
                put_ElementValueTypeTemplate(type, name, default_value, is_required);
                return;
            }
			if (is_required)
				structs[cur_index].tile.Add("\t" + type + " " + name + ";");
			else
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + ";");
			structs[cur_index].write_instructions.Add(string.Format("\t{0}.Write(s);", name));
			//structs[cur_index].read_instructions.Add(string.Format("\t{0} = new {1}();", name, correctNamespace(name)));
			structs[cur_index].read_instructions.Add(string.Format("\t{0}.Read(s);", name));
			if (default_value != null)
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = {1};", name, default_value));
		}

		public void put_ElementValueTypeTemplate(string type, string name, string default_value, bool is_required)
        {
			if (is_required)
				structs[cur_index].tile.Add("\t" + type + " " + name + ";");
			else if (type == "std::string")
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {\"\"};");
			else
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {0};");
			string prefix = getPrefixByType(type);
            structs[cur_index].write_instructions.Add(string.Format("\ts.Write(\"{0}\", {0}{1});", name, type.Split('<', '>')[0] == "std::string" ? ".c_str()" : ""));
            structs[cur_index].read_instructions.Add(string.Format("\ts.Read{1}(\"{0}\", {0});", name, prefix));
			if (default_value != null)
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = {1};", name, default_value));
			else if (type != "std::string")
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = 0;", name, default_value));
		}

		public void put_AttributeObjectTemplate(string type, string name, string default_value, bool is_required)
        {
			if (is_required)
				structs[cur_index].tile.Add("\t" + type + " " + name + ";");
			else
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {\"\"};");
            structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0}.c_str());", name));
            structs[cur_index].read_instructions.Add(string.Format("\t{0} = s.ReadAttrStr(\"{0}\");", name));
			if (default_value != null)
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = {1};", name, default_value));
		}

        public void put_AttributeValueTypeTemplate(string type, string name, string default_value, bool is_required)
        {
			if (is_required)
				structs[cur_index].tile.Add("\t" + type + " " + name + ";");
			else
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {0};");
			string prefix = getPrefixByType(type);
            structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0});", name));
            structs[cur_index].read_instructions.Add(string.Format("\t{0} = s.ReadAttr{1}(\"{0}\");", name, prefix));
			if (default_value != null)
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = {1};", name, default_value));
			else
				structs[cur_index].constructor_instructions.Add(string.Format("{0} = 0;", name, default_value));
		}

        public void begin_class(string name, string is_absctract, string inheritance)
        {
            string correct_name = correctNamespace(name);
            structs.Add(correct_name, null);
            structs[correct_name] = new Struct();
            structs[correct_name].tile.Add(is_absctract + "struct " + name + inheritance + " {");
            structs[correct_name].tile.Add("\tvoid Write(IXmlSerializerWriter&s);");
            structs[correct_name].tile.Add("\tbool Read(IXmlSerializerReader& s);");

            structs[correct_name].write_instructions.Add("void " + correct_name + "::Write(IXmlSerializerWriter& s) {");
            structs[correct_name].write_instructions.Add(string.Format("\tIXmlSerializerWriter::Scope scope(s, \"{0}\");", name));
            structs[correct_name].read_instructions.Add("bool " + correct_name + "::Read(IXmlSerializerReader& s) {");
            structs[correct_name].read_instructions.Add(string.Format("\tIXmlSerializerReader::Scope scope(s, \"{0}\");", name));
			structs[correct_name].read_instructions.Add(string.Format("\tif (scope.exist() == false)\n\t\treturn false;", name));
			cur_index = correct_name;
        }

        public void put_Enum(string code)
        {
            enums.Add(code);
        }

        public void put_Constructor(string name, string inherits)
        {
			string instructions = "";
			for (int i = 0; i < structs[correctNamespace(name)].constructor_instructions.Count; i++)
			{
				instructions += "\t\t" + structs[correctNamespace(name)].constructor_instructions[i] + "\n";
			}
            structs[cur_index].tile.Add(string.Format("\t{0}(){1} {{\n{2}\t\t}}", name, inherits, instructions));
			structs[cur_index].tile.Add(string.Format("\t~{0}(){1} {{}}", name, inherits));
		}

		public void end_class()
        {
            structs[cur_index].tile.Add("};");
            structs[cur_index].write_instructions.Add("}");
            structs[cur_index].read_instructions.Add("\treturn true;\n}");
        }

		public string deleteNamespace(string v)
		{
			var i = v.IndexOf("::");
			if (i != -1)
				return v.Substring(i + 2);
			else
				return v;
		}

		public List<Struct> sortStructs()
		{
			Dictionary<string, Struct> copy_structs = new Dictionary<string, Struct>(structs);
			List<Struct> sorted_structs = new List<Struct>();
			while (sorted_structs.Count < structs.Count - 1)
			{
				foreach (var _struct in copy_structs)
				{
					bool used = false;
					foreach (var _struct2 in copy_structs)
					{
						if (_struct2.Value.classes_used.Contains(_struct.Key))
						{
							used = true;
							break;
						}
					}
					if (!used)
					{
						sorted_structs.Add(_struct.Value);
						copy_structs.Remove(_struct.Key);
					}
					break;
				}
			}
			sorted_structs.Add(copy_structs.Last().Value);
			return sorted_structs;
		}

		public string generateCode()
        {
            List<string> code = new List<string>();
            code.Add(initString);
            code.Add(includeString);
            code.Add("namespace " + _namespace + " {");
			foreach (var st in structs)
			{
				code.Add("\tstruct " + deleteNamespace(st.Key) + ";");
			}
			List<Struct> sorted_structs = sortStructs();
			sorted_structs.Reverse();
			foreach (var st in sorted_structs)
            {
                for (int i = 0;i < st.tile.Count;i++)
                {
                    st.tile[i] = "\t" + st.tile[i];
                }
                code.AddRange(st.tile);
            }
            code.Add("}");
            foreach (var st in structs)
            {
                code.AddRange(st.Value.write_instructions);
                code.AddRange(st.Value.read_instructions);
            }
            string final_code = "";
            foreach (var line in code)
            {
                final_code += line + "\n";
            }
            return final_code;
        }
    }
}
