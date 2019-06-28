using System;
using System.Collections;
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
            public List<string> pre_write_instructions;
            public List<string> post_write_instructions;
            public List<string> read_instructions;
            public List<string> pre_read_instructions;
            public List<string> post_read_instructions;

            public List<string> tile;
            public List<string> pre_tile;
            public List<string> post_tile;
            public HashSet<string> classes_used;
            public string inheritance = String.Empty;
            public string name;

            public Struct(string name) {
                write_instructions = new List<string>();
                pre_write_instructions = new List<string>();
                post_write_instructions = new List<string>();
                read_instructions = new List<string>();
                pre_read_instructions = new List<string>();
                post_read_instructions = new List<string>();
				tile = new List<string>();
                pre_tile = new List<string>();
                post_tile = new List<string>();
				classes_used = new HashSet<string>();
                this.name = name;
            }
        }

        private Dictionary<string, Struct> structs;
        private List<string> enums;
		private List<string> enums_instructions;
        private Dictionary<string, string> prototypes = new Dictionary<string, string>
        {
            ["std::string"] = "Str",
            ["int"] = "Int",
            ["bool"] = "Bool",
            ["char"] = "Char",
            ["double"] = "Double",
            ["float"] = "Float",
            ["unsigned int"] = "UnsignedInt",
            ["unsigned short int"] = "UnsignedShortInt",
            ["short int"] = "ShortInt",
            ["long int"] = "LongInt",
            ["unsigned long int"] = "UnsignedLongInt",
            ["signed char"] = "SignedChar"
        };
        private string _namespace;
        private string cur_index;
        private string initString = "#pragma once\n// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk\n// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)\n//--------------------------------------------------------------";
        private string includeString = "#include <iostream>\n#include <string>\n#include <ctime>\n#include \"Serializers.hpp\"\n#include <optional>";

        public GeneratorStream(string name_space)
        {
            structs = new Dictionary<string, Struct>();
            enums = new List<string>();
			enums_instructions = new List<string>();
			_namespace = name_space;
        }

		private string removeNamespace(string name)
		{
            if (name.IndexOf("::") == -1)
                return name;
			return name.Substring(name.IndexOf("::") + 2);
		}

        private string correctNamespace(string name)
        {
            if (name.IndexOf("::") == -1)
                return _namespace + "::" + name;
            else
                return name;
        }

        private string editName(string name)
        {
            if (structs[cur_index].name == name)
                return $"__{name}";
            return name;
        }

        private bool checkIsPrototype(string type)
        {
            if (prototypes.ContainsKey(type))
                return true;
            return false;
        }

        private string getPrefixByType(string type)
        {
            return prototypes[type];
        }

        public void put_FieldCollectionTemplate(string type, string name, string default_value, bool is_required)
        {
            name = editName(name);
            string correct_type = correctNamespace(type);
            if (checkIsPrototype(type))
                correct_type = type;
            structs[cur_index].tile.Add("\tstd::vector<" + correct_type + "> " + name + ";");
            if (checkIsPrototype(type))
            {
                string prefix = getPrefixByType(type);
                structs[cur_index].write_instructions.Add(string.Format("\tfor(int i = 0;i < {0}.size();i++)\n\t{{\n\t\ts.Write(\"{0}\", {0}[i]{1}); \n\t}}", name, type == "std::string" ? ".c_str()" : ""));
                structs[cur_index].read_instructions.Add(string.Format("{0} = s.ReadVector{1}(\"{0}\");", name, prefix));
            }
            else
            {
                structs[cur_index].write_instructions.Add(string.Format("\tfor(int i = 0;i < {0}.size();i++)\n\t{{\n\t\t{0}[i].Write(s); \n\t}}", name));
                structs[cur_index].read_instructions.Add(string.Format("\twhile (true) {{ \n\t\t{1} __t;\n\t\tif (__t.Read(s) == false)\n\t\t\tbreak;\n\t\t{0}.push_back(__t);\n\t}}", name, correctNamespace(type)));
			}
            if (is_required)
                structs[cur_index].classes_used.Add(correct_type);
        }

        public void put_FieldClassTemplate(string type, string name, string default_value, bool is_required)
        {
            name = editName(name);
            string correct_type = correctNamespace(type);
			if (is_required)
				structs[cur_index].tile.Add("\t" + correct_type + " " + name + ";");
			else
				structs[cur_index].tile.Add("\tstd::optional<std::reference_wrapper<" + correct_type + ">> " + name + ";");
            if (is_required)
                structs[cur_index].classes_used.Add(correct_type);

            if (is_required)
            {
                structs[cur_index].write_instructions.Add(string.Format("\t{0}.Write(s);", name));
                structs[cur_index].read_instructions.Add(string.Format("\t{0}.Read(s);", name));
            }
            else
            {
                structs[cur_index].write_instructions.Add(string.Format("\t{0}.value().get().Write(s);", name));
                structs[cur_index].read_instructions.Add(string.Format("\t{1}* __{0} = new {1}();", name, correct_type));
                structs[cur_index].read_instructions.Add(string.Format("\t__{0}->Read(s);", name));
                structs[cur_index].read_instructions.Add(string.Format("\t{0} = std::optional<std::reference_wrapper<{1}>> {{ *__{0} }};", name, correct_type));
            }
		}

        public void put_ElementObjectTemplate(string type, string name, string default_value, bool is_required)
        {
            name = editName(name);
            if (type.Split('<', '>')[0] == "std::string")
            {
                put_ElementValueTypeTemplate(type, name, default_value, is_required);
                return;
            }
            if (is_required)
            {
                structs[cur_index].tile.Add("\t" + type + " " + name + ";");
                structs[cur_index].write_instructions.Add(string.Format("\t{0}.Write(s);", name));
                structs[cur_index].read_instructions.Add(string.Format("\t{0}.Read(s);", name));
            }
            else
            {
                structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + ";");
                structs[cur_index].write_instructions.Add(string.Format("\t{0}.value().get().Write(s);", name));
                structs[cur_index].read_instructions.Add(string.Format("\t{0}.value().get().Read(s);", name));
            }
        }

		public void put_ElementValueTypeTemplate(string type, string name, string default_value, bool is_required)
        {
            name = editName(name);
            if (is_required)
				structs[cur_index].tile.Add("\t" + type + " " + name + ";");
			else if (type == "std::string")
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {\"" + (default_value ?? "") +"\"};");
			else
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {" + (default_value ?? "0") + "};");
            if (checkIsPrototype(type))
            {
                string prefix = getPrefixByType(type);
                structs[cur_index].write_instructions.Add(string.Format("\ts.Write(\"{0}\", {0}{2}{1});", name, type.Split('<', '>')[0] == "std::string" ? ".c_str()" : "", is_required ? "" : ".value()"));
                structs[cur_index].read_instructions.Add(string.Format("\ts.Read{1}(\"{0}\", {0}{2});", name, prefix, is_required ? "" : ".value()"));
            } else
            {
                structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {2}::Convert{1}ToString({0}{3}).c_str());", name, removeNamespace(type), _namespace, (is_required) ? "" : ".value()"));
                structs[cur_index].read_instructions.Add(string.Format("\t{0} = {2}::ConvertStringTo{1}(s.ReadAttrStr(\"{0}\"));", name, removeNamespace(type), _namespace));
            }
        }

		public void put_AttributeObjectTemplate(string type, string name, string default_value, bool is_required)
        {
            name = editName(name);
            if (is_required)
            {
                structs[cur_index].tile.Add("\t" + type + " " + name + ";");
                structs[cur_index].read_instructions.Add(string.Format("\t{0} = s.ReadAttrStr(\"{0}\");", name));
                structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0}.c_str());", name));
            }
            else
            {
                structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + " {\"" + (default_value ?? "") + "\"};");
                structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0}.value().c_str());", name));
                structs[cur_index].read_instructions.Add(string.Format("\t{0} = s.ReadAttrStr(\"{0}\");", name));
            }
            
		}

        public void put_AttributeValueTypeTemplate(string type, string name, string default_value, bool is_required)
        {
            name = editName(name);
            if (is_required)
				structs[cur_index].tile.Add("\t" + type + " " + name + ";");
			else
				structs[cur_index].tile.Add("\tstd::optional<" + type + "> " + name + ";");
			if (checkIsPrototype(type))
			{
				string prefix = getPrefixByType(type);
				structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {0}{1});", name, is_required ? "" : ".value()"));
				structs[cur_index].read_instructions.Add(string.Format("\t{0} = s.ReadAttr{1}(\"{0}\");", name, prefix));
			} else
			{
				structs[cur_index].write_instructions.Add(string.Format("\ts.WriteAttr(\"{0}\", {2}::Convert{1}ToString({0}{3}).c_str());", name, removeNamespace(type), _namespace, (is_required) ? "" : ".value()"));
				structs[cur_index].read_instructions.Add(string.Format("\t{0} = {2}::ConvertStringTo{1}(s.ReadAttrStr(\"{0}\"));", name, removeNamespace(type), _namespace));
			}
		}

        public void begin_class(string name, string is_absctract, string inheritance)
        {
            string correct_name = correctNamespace(name);
            structs.Add(correct_name, null);
            structs[correct_name] = new Struct(name);
            if (inheritance != String.Empty)
            {
                structs[correct_name].inheritance = inheritance;
                structs[correct_name].classes_used.Add(correctNamespace(inheritance));
            }
            structs[correct_name].pre_tile.Add(is_absctract + "struct " + name + " {");
            structs[correct_name].pre_tile.Add("\tvoid Write(IXmlSerializerWriter&s);");
            structs[correct_name].pre_tile.Add("\tbool Read(IXmlSerializerReader& s);");

            structs[correct_name].pre_write_instructions.Add("void " + correct_name + "::Write(IXmlSerializerWriter& s) {");
            structs[correct_name].pre_write_instructions.Add(string.Format("\tIXmlSerializerWriter::Scope scope(s, \"{0}\");", name));
            structs[correct_name].pre_read_instructions.Add("bool " + correct_name + "::Read(IXmlSerializerReader& s) {");
            structs[correct_name].pre_read_instructions.Add(string.Format("\tIXmlSerializerReader::Scope scope(s, \"{0}\");", name));
            structs[correct_name].pre_read_instructions.Add(string.Format("\tif (scope.exist() == false)\n\t\treturn false;", name));
            cur_index = correct_name;
        }

        public void put_Enum(string name, ArrayList list, Func<string, bool, string> CheckForKeywords)
        {
			string code = "";
			code += "\tenum class " + name + " {\n";
			string instructions_code_to_enum = "";
			string instructions_code_from_enum = "";
			instructions_code_to_enum += "\t" + name + " ConvertStringTo" + name + "(std::string str) {\n";
			instructions_code_from_enum += "\tstd::string Convert" + name + "ToString(" + name + " e) {\n";
			foreach (string[] item_2 in list)
			{
				string item = CheckForKeywords(item_2[0], true);
                code += $"\t\t{item},\n";
                instructions_code_to_enum += "\t\tif (str == \"" + item_2[0] + "\") return " + name + "::" + item + ";\n";
				instructions_code_from_enum += "\t\tif (e == " + name + "::" + item + ") return \"" + item_2[0] + "\";\n";
			}

            instructions_code_to_enum += "\t\tthrow std::exception(\"Can't convert string to enum value\");\n\t}\n";
            //instructions_code_to_enum += "\t\treturn (" + name + ")0;\n\t}\n";
            instructions_code_from_enum += "\t\tthrow std::exception(\"Can't convert enum value to string\");\n\t}\n";
            code += "\t};\n";
            enums.Add(code);
			enums_instructions.Add(instructions_code_to_enum);
			enums_instructions.Add(instructions_code_from_enum);
		}

        public void put_Constructor(string name, string inherits)
        {
            structs[cur_index].post_tile.Add(string.Format("\t{0}(){1} {{}}", name, inherits));
			structs[cur_index].post_tile.Add(string.Format("\t~{0}(){1} {{}}", name, inherits));
		}

		public void end_class()
        {
            structs[cur_index].post_tile.Add("};");
            structs[cur_index].post_write_instructions.Add("}");
            structs[cur_index].post_read_instructions.Add("\treturn true;\n}");
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
						if (!_struct2.Key.Equals(_struct.Key) && _struct2.Value.classes_used.Contains(_struct.Key))
						{
							used = true;
							break;
						}
					}
					if (!used)
					{
						sorted_structs.Add(_struct.Value);
						copy_structs.Remove(_struct.Key);
						break;
					}
				}
			}
			sorted_structs.Add(copy_structs.Last().Value);
			return sorted_structs;
		}

		public string generateCode()
        {
            List<string> code = new List<string>();
            if (structs.Count == 0)
                return "// No content, because there aren't any structs";
            code.Add(initString);
            code.Add(includeString);
            code.Add("namespace " + _namespace + " {");
			foreach (var en in enums)
			{
				code.Add(en);
			}
			foreach (var en_i in enums_instructions)
			{
				code.Add(en_i);
			}
			foreach (var st in structs)
			{
				code.Add("\tstruct " + deleteNamespace(st.Key) + ";");
			}
			List<Struct> sorted_structs = sortStructs();
			sorted_structs.Reverse();

            foreach (var st in sorted_structs)
            {
                if (st.inheritance != String.Empty) {
                    st.write_instructions.AddRange(structs[st.inheritance].write_instructions);
                    st.read_instructions.AddRange(structs[st.inheritance].read_instructions);
                    st.tile.AddRange(structs[st.inheritance].tile);
                }
            }

			foreach (var st in sorted_structs)
            {
                for (int i = 0;i < st.tile.Count;i++)
                {
                    st.tile[i] = "\t" + st.tile[i];
                }
                for (int i = 0; i < st.pre_tile.Count; i++)
                {
                    st.pre_tile[i] = "\t" + st.pre_tile[i];
                }
                for (int i = 0; i < st.post_tile.Count; i++)
                {
                    st.post_tile[i] = "\t" + st.post_tile[i];
                }
                code.AddRange(st.pre_tile);
                code.AddRange(st.tile);
                code.AddRange(st.post_tile);
            }
            code.Add("}");
            foreach (var st in structs)
            {
                code.AddRange(st.Value.pre_write_instructions);
                code.AddRange(st.Value.write_instructions);
                code.AddRange(st.Value.post_write_instructions);
                code.AddRange(st.Value.pre_read_instructions);
                code.AddRange(st.Value.read_instructions);
                code.AddRange(st.Value.post_read_instructions);
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
