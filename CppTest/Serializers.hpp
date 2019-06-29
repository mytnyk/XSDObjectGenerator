#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <pugixml.hpp>
#include <stack>
#include <set>

class IXmlSerializerWriter
{
public:
	virtual ~IXmlSerializerWriter() = default;
	virtual void Write(const char* name, int32_t value) = 0;
	virtual void Write(const char* name, double value) = 0;
	virtual void Write(const char* name, float value) = 0;
	virtual void Write(const char* name, bool value) = 0;
	virtual void Write(const char* name, const char* value) = 0;
	virtual void Write(const char* name, signed char value) = 0;
	virtual void Write(const char* name, unsigned int value) = 0;
	virtual void Write(const char* name, unsigned short int value) = 0;
	virtual void Write(const char* name, short int value) = 0;
	virtual void Write(const char* name, long value) = 0;
	virtual void Write(const char* name, unsigned long value) = 0;
	virtual void Write(const char* name, char value) = 0;
	virtual void WriteAttr(const char* name, bool value) = 0;
	virtual void WriteAttr(const char* name, const char* value) = 0;
	virtual void WriteAttr(const char* name, int32_t value) = 0;
	virtual void WriteAttr(const char* name, double value) = 0;
private:
	virtual void LeaveChild() = 0;
	virtual void AddChild(const char* name) = 0;
public:
	class Scope
	{
	private: IXmlSerializerWriter& _s;
	public: Scope(IXmlSerializerWriter& s, std::string name) : _s(s) {
		_s.AddChild(name.c_str());
	}
			~Scope() {
				_s.LeaveChild();
			}
	};
};

class IXmlSerializerReader
{
public:
	virtual ~IXmlSerializerReader() = default;

	virtual bool ReadInt(const char* name, int32_t& value) = 0;
	virtual bool ReadDouble(const char* name, double& value) = 0;
	virtual bool ReadBool(const char* name, bool& value) = 0;
	virtual bool ReadStr(const char* name, std::string& value) = 0;
	virtual bool ReadUnsignedInt(const char* name, unsigned int& value) = 0;
	virtual bool ReadUnsignedShortInt(const char* name, unsigned short int& value) = 0;
	virtual bool ReadShortInt(const char* name, short int& value) = 0;
	virtual bool ReadLong(const char* name, long& value) = 0;
	virtual bool ReadUnsignedLong(const char* name, unsigned long& value) = 0;
	virtual bool ReadFloat(const char* name, float& value) = 0;
	virtual bool ReadChar(const char* name, char& value) = 0;
	virtual bool ReadSignedChar(const char* name, signed char& value) = 0;
	virtual std::vector<int32_t>	 ReadVectorInt(const char* name) = 0;
	virtual std::vector<double>		 ReadVectorDouble(const char* name) = 0;
	virtual std::vector<bool>		 ReadVectorBool(const char* name) = 0;
	virtual std::vector<std::string> ReadVectorStr(const char* name) = 0;
	virtual bool ReadAttrBool(const char* name, bool& value) = 0;
	virtual bool ReadAttrStr(const char* name, std::string& value) = 0;
	virtual bool ReadAttrDouble(const char* name, double& value) = 0;
	virtual bool ReadAttrInt(const char* name, int& value) = 0;
	virtual std::string getParentName() = 0;
private:
	virtual void LeaveChild(const char* name) = 0;
	virtual bool EnterChild(const char* name) = 0;
public:
	class Scope
	{
	public: bool exist() {
		return is_successfull;
	}
	private: IXmlSerializerReader& _s;
			 const char* _name;
			 bool is_successfull;
	public:
		Scope(IXmlSerializerReader& s, std::string name) : _s(s), _name(name.c_str()) {
			is_successfull = _s.EnterChild(name.c_str());
		}
		~Scope() {
			if (is_successfull) {
				_s.LeaveChild(_s.getParentName().c_str());
			}
		}
	};
};

class PugiXmlSerializerWriter : public IXmlSerializerWriter {
private:
	pugi::xml_document _doc;
	pugi::xml_node _cursor;
public:
	PugiXmlSerializerWriter() { _cursor = _doc; }

	void AddChild(const char* name) override { _cursor = _cursor.append_child(name); }
	void LeaveChild() override { _cursor = _cursor.parent(); }

	void Write(const char* name, int32_t value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, double value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, float value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, bool value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, const char* value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, signed char value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, char value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, long value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, unsigned long value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, unsigned int value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, unsigned short int value) override {
		_cursor.append_child(name).text().set(value);
	}

	void Write(const char* name, short int value) override {
		_cursor.append_child(name).text().set(value);
	}

	void WriteAttr(const char* name, bool value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	void WriteAttr(const char* name, const char* value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	void WriteAttr(const char* name, int32_t value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	void WriteAttr(const char* name, double value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	void SaveToFile(const char* file_name) {
		_doc.save_file(file_name);
	}
};

class PugiXmlSerializerReader : public IXmlSerializerReader
{
private:
	pugi::xml_document _doc;
	pugi::xml_node _cursor;
	std::stack<std::pair<bool, std::string>> names;
	std::set<size_t> used_hashes;
public:
	PugiXmlSerializerReader() { _cursor = _doc; }

	bool EnterChild(const char* name) override {
		pugi::xml_node new_cursor;
		bool was_visited = false;
		if (names.size() > 0 && names.top().second == name && names.top().first == true) {
			new_cursor = _cursor.next_sibling(name);
			used_hashes.insert(new_cursor.hash_value());
			names.top().first = false;
		}
		else {
			names.push(std::make_pair(false, name));
			new_cursor = _cursor.child(name);
			if (new_cursor != NULL && used_hashes.find(new_cursor.hash_value()) != used_hashes.end()) {
				was_visited = true;
			}
			else {
				used_hashes.insert(new_cursor.hash_value());
			}
		}
		if (new_cursor == NULL || was_visited) {
			names.pop();
			return false;
		}
		else {
			_cursor = new_cursor;
			return true;
		}
	}

	void LeaveChild(const char* cname) override {
		if (names.size() > 0)
			names.top().first = true;
		else
			return;
		if (_cursor.next_sibling(cname) == NULL) {
			_cursor = _cursor.parent();
			names.pop();
		} 
	}

	std::string getParentName() override {
		return _cursor.name();
	}

	bool hasMember(const char* name) {
		auto p = _cursor.child(name);
		return p != NULL;
	}

	bool hasAttribute(const char* name) {
		auto p = _cursor.attribute(name);
		return p != NULL;
	}


	bool ReadInt(const char* name, int32_t& value) override {
		if (!hasMember(name))
			return false;
		value = atoi(_cursor.child(name).child_value());
		return true;
	}

	bool ReadDouble(const char* name, double& value) override {
		if (!hasMember(name))
			return false;
		value = atof(_cursor.child(name).child_value());
		return true;
	}

	bool ReadFloat(const char* name, float& value) override {
		if (!hasMember(name))
			return false;
		value = atof(_cursor.child(name).child_value());
		return true;
	}

	bool ReadUnsignedInt(const char* name, unsigned int& value) override {
		if (!hasMember(name))
			return false;
		value = atol(_cursor.child(name).child_value());
		return true;
	}

	bool ReadUnsignedShortInt(const char* name, unsigned short int& value) override {
		if (!hasMember(name))
			return false;
		value = atoi(_cursor.child(name).child_value());
		return true;
	}

	bool ReadShortInt(const char* name, short int& value) override {
		if (!hasMember(name))
			return false;
		value = atoi(_cursor.child(name).child_value());
		return true;
	}

	bool ReadLong(const char* name, long& value) override {
		if (!hasMember(name))
			return false;
		value = atol(_cursor.child(name).child_value());
		return true;
	}

	bool ReadUnsignedLong(const char* name, unsigned long& value) override {
		if (!hasMember(name))
			return false;
		value = atoll(_cursor.child(name).child_value());
		return true;
	}

	bool ReadBool(const char* name, bool& value) override {
		if (!hasMember(name))
			return false;
		value = _cursor.child(name).child_value() == "true" ? true : false;
		return true;
	}

	bool ReadStr(const char* name, std::string& value) override {
		if (!hasMember(name))
			return false;
		value = _cursor.child(name).child_value();
		return true;
	}

	bool ReadChar(const char* name, char& value) override {
		if (!hasMember(name))
			return false;
		value = _cursor.child(name).child_value()[0];
		return true;
	}

	bool ReadSignedChar(const char* name, signed char& value) override {
		if (!hasMember(name))
			return false;
		value = _cursor.child(name).child_value()[0];
		return true;
	}

	bool ReadAttrBool(const char* name, bool& value) override {
		if (!hasAttribute(name))
			return false;
		value = _cursor.attribute(name).as_bool();
		return true;
	}

	bool ReadAttrStr(const char* name, std::string& value) override {
		if (!hasAttribute(name))
			return false;
		value = _cursor.attribute(name).as_string();
		return true;
	}

	std::vector<int32_t> ReadVectorInt(const char* name) override {
		std::vector<int32_t> r;
		for (pugi::xml_node tool = _cursor.child(name); tool; tool = tool.next_sibling(name))
		{
			r.push_back(tool.text().as_int());
		}
		return r;
	}

	std::vector<double> ReadVectorDouble(const char* name) override {
		std::vector<double> r;
		for (pugi::xml_node tool = _cursor.child(name); tool; tool = tool.next_sibling(name))
		{
			r.push_back(tool.text().as_double());
		}
		return r;
	}

	std::vector<std::string> ReadVectorStr(const char* name) override {
		std::vector<std::string> r;
		for (pugi::xml_node tool = _cursor.child(name); tool; tool = tool.next_sibling(name))
		{
			r.push_back(tool.text().as_string());
		}
		return r;
	}

	std::vector<bool> ReadVectorBool(const char* name) override {
		std::vector<bool> r;
		for (pugi::xml_node tool = _cursor.child(name); tool; tool = tool.next_sibling(name))
		{
			r.push_back(tool.text().as_bool());
		}
		return r;
	}

	bool ReadAttrInt(const char* name, int& value) override {
		if (!hasAttribute(name))
			return false;
		value = _cursor.attribute(name).as_int();
		return true;
	}

	bool ReadAttrDouble(const char* name, double& value) override {
		if (!hasAttribute(name))
			return false;
		value = _cursor.attribute(name).as_double();
		return true;
	}

	void Load(const char* file_name) {
		_doc.load_file(file_name);
	}
};
