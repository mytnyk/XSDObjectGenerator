// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <pugixml.hpp>

enum class OpenMode : int {
	Write = 0,
	Read = 1,
	Undefined = 2
};

class IXmlSerializer
{
public:
	virtual ~IXmlSerializer() = default;

	virtual void Write(int32_t value) = 0;
	virtual void Write(double value) = 0;
	virtual void Write(bool value) = 0;
	virtual void Write(const char* value) = 0;
	virtual void WriteAttr(const char* name, bool value) = 0;
	virtual void WriteAttr(const char* name, const char* value) = 0;
	virtual void WriteAttr(const char* name, int32_t value) = 0;
	virtual void WriteAttr(const char* name, double value) = 0;
	virtual int32_t ReadInt() = 0;
	virtual double ReadDouble() = 0;
	virtual bool ReadBool() = 0;
	virtual const char* ReadStr() = 0;
	virtual std::vector<int32_t>	 ReadVectorInt(const char* name) = 0;
	virtual std::vector<double>		 ReadVectorDouble(const char* name) = 0;
	virtual std::vector<bool>		 ReadVectorBool(const char* name) = 0;
	virtual std::vector<std::string> ReadVectorStr(const char* name) = 0;
	virtual bool		ReadAttrBool(const char* name) = 0;
	virtual const char* ReadAttrStr(const char* name) = 0;
	virtual double		ReadAttrDouble(const char* name) = 0;
	virtual int32_t		ReadAttrInt(const char* name) = 0;
	virtual bool NextChild(const char* name) = 0;
	virtual void BackChild() = 0;
private:
	virtual void AddChild(const char* name) = 0;
	virtual bool InChild(const char* name) = 0;
	virtual void LeaveChild() = 0;
protected:
	OpenMode mode = OpenMode::Write;
public:
	class Scope
	{
	public: bool is_successfull;
	private: IXmlSerializer& _s;
	public: Scope(IXmlSerializer& s, const char* name) : _s(s) {
		if (_s.mode == OpenMode::Write)
			_s.AddChild(name);
		else {
			is_successfull = _s.InChild(name);
		}
	}
			~Scope() {
				if (is_successfull) {
					if (_s.mode == OpenMode::Write)
						_s.LeaveChild();
					else
						_s.BackChild();
				}
			}
	};
};

class PugiXmlSerializer : public IXmlSerializer
{
private:
	pugi::xml_document _doc;
	pugi::xml_node _cursor;
public:
	PugiXmlSerializer() { _cursor = _doc; }

	void AddChild(const char* name) override { _cursor = _cursor.append_child(name); }
	bool InChild(const char* name) override {
		pugi::xml_node _cursor_backup = _cursor;
		_cursor = _cursor.child(name);
		if (_cursor == NULL) {
			_cursor = _cursor_backup;
			return false;
		}
		else
			return true;
	}
	bool NextChild(const char* name) override {
		pugi::xml_node _cursor_back = _cursor;
		_cursor = _cursor.next_sibling(name);
		if (_cursor == NULL) {
			_cursor = _cursor_back;
			return false;
		}
		else
			return true;
	}
	void LeaveChild() override { _cursor = _cursor.parent(); }
	void BackChild() override {
		_cursor = _cursor.parent();
	}

	void Write(int32_t value) override {
		_cursor.text().set(value);
	}

	int32_t ReadInt() override {
		return atoi(_cursor.child_value());
	}

	void Write(double value) override {
		_cursor.text().set(value);
	}

	double ReadDouble() override {
		return atof(_cursor.child_value());
	}

	void Write(bool value) override {
		_cursor.text().set(value);
	}

	bool ReadBool() override {
		return _cursor.child_value() == "true" ? true : false ;
	}

	void Write(const char* value) override {
		_cursor.text().set(value);
	}

	const char* ReadStr() override {
		return _cursor.child_value();
	}

	void WriteAttr(const char* name, bool value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	bool ReadAttrBool(const char* name) override {
		return _cursor.attribute(name).as_bool();
	}

	void WriteAttr(const char* name, const char* value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	const char* ReadAttrStr(const char* name) override {
		return _cursor.attribute(name).as_string();
	}

	void WriteAttr(const char* name, int32_t value) override {
		_cursor.append_attribute(name).set_value(value);
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

	int32_t ReadAttrInt(const char* name) override {
		return _cursor.attribute(name).as_int();
	}

	void WriteAttr(const char* name, double value) override {
		_cursor.append_attribute(name).set_value(value);
	}

	double ReadAttrDouble(const char* name) override {
		return _cursor.attribute(name).as_double();
	}

	void Load(const char* file_name) {
		_doc.load_file(file_name);
		mode = OpenMode::Read;
	}

	void SaveToFile(const char* file_name) {
		_doc.save_file(file_name);
	}
};



//------------------- Generated code begin--------------//

namespace Test
{
	struct Declarations
	{
		const std::string SchemaVersion = "";
	};
	struct item
	{
		//ELEMENT_STD
		std::string title;
		//ELEMENT_STD
		std::string note;
		//ELEMENT_STD
		std::string quantity;
		//ELEMENT_PROTO
		int price;
		item()
		{
		}
		void Write(IXmlSerializer& s);
		void Read(IXmlSerializer& s, bool = true);
	};
	struct shipto
	{
		//ELEMENT_STD
		std::string name;
		//ELEMENT_STD
		std::string address;
		//ELEMENT_STD
		std::string city;
		//ELEMENT_STD
		std::string country;
		shipto()
		{
		}
		void Write(IXmlSerializer& s);
		void Read(IXmlSerializer& s, bool = true);
	};
	struct shiporder
	{
		//ATTRIBUTE_STD
		std::string orderid;
		//ELEMENT_STD
		std::string orderperson;
		//ELEMENT_CLASS
		shipto shipto;
		//LIST
		std::vector<item> item;
		shiporder()
		{
		}
		void Write(IXmlSerializer& s);
		void Read(IXmlSerializer& s, bool = true);
	};
}
void Test::shiporder::Write(IXmlSerializer& s)
{
	IXmlSerializer::Scope scope(s, "shiporder");
	s.WriteAttr("orderid", orderid.c_str());
	{
		IXmlSerializer::Scope scope(s, "orderperson");
		s.Write(orderperson.c_str());
	}
	shipto.Write(s);
	for (int i = 0; i < item.size(); i++)
	{
		item[i].Write(s);
	}
}

void Test::shiporder::Read(IXmlSerializer& s, bool init)
{
	if (init) {
		IXmlSerializer::Scope scope(s, "shiporder");
		orderid = s.ReadAttrStr("orderid");
		{
			IXmlSerializer::Scope scope(s, "orderperson");
			orderperson = s.ReadStr();
		}
		shipto.Read(s);
		{
			IXmlSerializer::Scope scope2(s, "item");
			if (scope2.is_successfull) {
				do {
					Test::item __t;
					__t.Read(s, false);
					item.push_back(__t);
				} while (s.NextChild("item"));
			}
		}
	}
	else {
		orderid = s.ReadAttrStr("orderid");
		{
			IXmlSerializer::Scope scope(s, "orderperson");
			orderperson = s.ReadStr();
		}
		shipto.Read(s);
		{
			IXmlSerializer::Scope scope2(s, "item");
			if (scope2.is_successfull) {
				do {
					Test::item __t;
					__t.Read(s, false);
					item.push_back(__t);
				} while (s.NextChild("item"));
			}
		}
	}
}

void Test::shipto::Write(IXmlSerializer& s)
{
	IXmlSerializer::Scope scope(s, "shipto");
	{
		IXmlSerializer::Scope scope(s, "name");
		s.Write(name.c_str());
	}
	{
		IXmlSerializer::Scope scope(s, "address");
		s.Write(address.c_str());
	}
	{
		IXmlSerializer::Scope scope(s, "city");
		s.Write(city.c_str());
	}
	{
		IXmlSerializer::Scope scope(s, "country");
		s.Write(country.c_str());
	}
}

void Test::shipto::Read(IXmlSerializer& s, bool init)
{
	if (init) {
		IXmlSerializer::Scope scope(s, "shipto");
		{
			IXmlSerializer::Scope scope(s, "name");
			name = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "address");
			address = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "city");
			city = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "country");
			country = s.ReadStr();
		}
	}
	else {
		{
			IXmlSerializer::Scope scope(s, "name");
			name = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "address");
			address = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "city");
			city = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "country");
			country = s.ReadStr();
		}
	}
}

void Test::item::Write(IXmlSerializer& s)
{
	IXmlSerializer::Scope scope(s, "item");
	{
		IXmlSerializer::Scope scope(s, "title");
		s.Write(title.c_str());
	}
	{
		IXmlSerializer::Scope scope(s, "note");
		s.Write(note.c_str());
	}
	{
		IXmlSerializer::Scope scope(s, "quantity");
		s.Write(quantity.c_str());
	}
	{
		IXmlSerializer::Scope scope(s, "price");
		s.Write(price);
	}
}

void Test::item::Read(IXmlSerializer& s, bool init)
{
	if (init) {
		IXmlSerializer::Scope scope(s, "item");
		{
			IXmlSerializer::Scope scope(s, "title");
			title = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "note");
			note = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "quantity");
			quantity = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "price");
			price = s.ReadInt();
		}
	}
	else {
		{
			IXmlSerializer::Scope scope(s, "title");
			title = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "note");
			note = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "quantity");
			quantity = s.ReadStr();
		}
		{
			IXmlSerializer::Scope scope(s, "price");
			price = s.ReadInt();
		}
	}
}

//------------------- Generated code end--------------//

int main()
{
	PugiXmlSerializer s;
	s.Load("text.xml");
	Test::shiporder c;
	c.Read(s);
	std::cout << c.shipto.country;
	int a;
	std::cin >> a;
	/*Test::shiporder c;
	c.orderid = "falshjje";
	c.orderperson = "Alex";
	c.shipto.address = "asd";
	c.shipto.country = "Ukraine";
	c.shipto.name = "asdaaa";
	Test::item i;
	i.price = 200;
	i.note = "asd";
	c.item.push_back(i);
	c.Write(s);*/

	//s.SaveToFile("text.xml");

	return 0;
}
