#pragma once
// Copyright 2008, Microsoft Corporation and 2019 Alex Mytnyk
// Sample Code - Use restricted to terms of use defined in the accompanying license agreement (EULA.doc)
//--------------------------------------------------------------
#include <iostream>
#include <string>
#include <ctime>
#include "Serializers.hpp"
#include <optional>
namespace Materialise {
	const std::string schema_CppTest_PreprocessorInput_namespace = "http://www.materialise.com/BuildProcessor/2014";
	struct PartInstances;
	struct Instance;
	struct PartLabels;
	struct Label;
	struct PreprocessorInput;
	struct Labelling;
	struct PreliminaryPass;
	struct Parts;
	struct Part;
	struct Part {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Part(const Part&) = delete;
		Part& operator=(Part&&) = delete;
		Part& operator=(Part&) = delete;
		Part(Part&&) noexcept;
		Part() = default;
		~Part() = default;
		std::string id;
		std::optional<std::string> FilePath;
		std::optional<std::unique_ptr<PartInstances>> Instances;
	};
	struct Parts {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Parts(const Parts&) = delete;
		Parts& operator=(Parts&&) = delete;
		Parts& operator=(Parts&) = delete;
		Parts(Parts&&) noexcept;
		Parts() = default;
		~Parts() = default;
		std::vector<Part> Part;
	};
	struct PreliminaryPass {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PreliminaryPass(const PreliminaryPass&) = delete;
		PreliminaryPass& operator=(PreliminaryPass&&) = delete;
		PreliminaryPass& operator=(PreliminaryPass&) = delete;
		PreliminaryPass(PreliminaryPass&&) noexcept;
		PreliminaryPass() = default;
		~PreliminaryPass() = default;
		std::optional<bool> enabled;
	};
	struct Labelling {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Labelling(const Labelling&) = delete;
		Labelling& operator=(Labelling&&) = delete;
		Labelling& operator=(Labelling&) = delete;
		Labelling(Labelling&&) noexcept;
		Labelling() = default;
		~Labelling() = default;
		std::optional<bool> enabled;
	};
	struct PreprocessorInput {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PreprocessorInput(const PreprocessorInput&) = delete;
		PreprocessorInput& operator=(PreprocessorInput&&) = delete;
		PreprocessorInput& operator=(PreprocessorInput&) = delete;
		PreprocessorInput(PreprocessorInput&&) noexcept;
		PreprocessorInput() = default;
		~PreprocessorInput() = default;
		std::optional<std::unique_ptr<Labelling>> Labelling;
		std::optional<std::unique_ptr<PreliminaryPass>> PreliminaryPass;
		std::optional<std::unique_ptr<Parts>> Parts;
	};
	struct Label {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Label(const Label&) = delete;
		Label& operator=(Label&&) = delete;
		Label& operator=(Label&) = delete;
		Label(Label&&) noexcept;
		Label() = default;
		~Label() = default;
		std::string id;
		std::string value;
	};
	struct PartLabels {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PartLabels(const PartLabels&) = delete;
		PartLabels& operator=(PartLabels&&) = delete;
		PartLabels& operator=(PartLabels&) = delete;
		PartLabels(PartLabels&&) noexcept;
		PartLabels() = default;
		~PartLabels() = default;
		std::vector<Label> Label;
	};
	struct Instance {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		Instance(const Instance&) = delete;
		Instance& operator=(Instance&&) = delete;
		Instance& operator=(Instance&) = delete;
		Instance(Instance&&) noexcept;
		Instance() = default;
		~Instance() = default;
		std::string id;
		std::optional<std::unique_ptr<PartLabels>> Labels;
	};
	struct PartInstances {
		void Write(IXmlSerializerWriter& s, const std::string& __name__);
		bool Read(IXmlSerializerReader& s, const std::string& __name__);
		PartInstances(const PartInstances&) = delete;
		PartInstances& operator=(PartInstances&&) = delete;
		PartInstances& operator=(PartInstances&) = delete;
		PartInstances(PartInstances&&) noexcept;
		PartInstances() = default;
		~PartInstances() = default;
		std::vector<Instance> Instance;
	};
}
Materialise::PartInstances::PartInstances(Materialise::PartInstances &&___PartInstances) noexcept
	: Instance(std::move(___PartInstances.Instance))
{ }
void Materialise::PartInstances::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Instance)
	{
		element.Write(s, "Instance"); 
	}
}
bool Materialise::PartInstances::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Instance __t;
		if (!__t.Read(s, "Instance"))
			break;
		Instance.push_back(std::move(__t));
	}
	return true;
}
Materialise::Instance::Instance(Materialise::Instance &&___Instance) noexcept
	: id(std::move(___Instance.id))
	, Labels(std::move(___Instance.Labels))
{ }
void Materialise::Instance::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	if (Labels.has_value())
		Labels.value().get()->Write(s, "Labels");
}
bool Materialise::Instance::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	Materialise::PartLabels* __Labels = new Materialise::PartLabels();
	if (__Labels->Read(s, "Labels"))
		Labels = std::optional<std::unique_ptr<Materialise::PartLabels>> { __Labels };
	return true;
}
Materialise::PartLabels::PartLabels(Materialise::PartLabels &&___PartLabels) noexcept
	: Label(std::move(___PartLabels.Label))
{ }
void Materialise::PartLabels::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Label)
	{
		element.Write(s, "Label"); 
	}
}
bool Materialise::PartLabels::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Label __t;
		if (!__t.Read(s, "Label"))
			break;
		Label.push_back(std::move(__t));
	}
	return true;
}
Materialise::Label::Label(Materialise::Label &&___Label) noexcept
	: id(std::move(___Label.id))
	, value(std::move(___Label.value))
{ }
void Materialise::Label::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	s.WriteAttr("value", value.c_str());
}
bool Materialise::Label::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	s.ReadAttrStr("value", value);
	return true;
}
Materialise::PreprocessorInput::PreprocessorInput(Materialise::PreprocessorInput &&___PreprocessorInput) noexcept
	: Labelling(std::move(___PreprocessorInput.Labelling))
	, PreliminaryPass(std::move(___PreprocessorInput.PreliminaryPass))
	, Parts(std::move(___PreprocessorInput.Parts))
{ }
void Materialise::PreprocessorInput::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (Labelling.has_value())
		Labelling.value().get()->Write(s, "Labelling");
	if (PreliminaryPass.has_value())
		PreliminaryPass.value().get()->Write(s, "PreliminaryPass");
	if (Parts.has_value())
		Parts.value().get()->Write(s, "Parts");
}
bool Materialise::PreprocessorInput::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	Materialise::Labelling* __Labelling = new Materialise::Labelling();
	if (__Labelling->Read(s, "Labelling"))
		Labelling = std::optional<std::unique_ptr<Materialise::Labelling>> { __Labelling };
	Materialise::PreliminaryPass* __PreliminaryPass = new Materialise::PreliminaryPass();
	if (__PreliminaryPass->Read(s, "PreliminaryPass"))
		PreliminaryPass = std::optional<std::unique_ptr<Materialise::PreliminaryPass>> { __PreliminaryPass };
	Materialise::Parts* __Parts = new Materialise::Parts();
	if (__Parts->Read(s, "Parts"))
		Parts = std::optional<std::unique_ptr<Materialise::Parts>> { __Parts };
	return true;
}
Materialise::Labelling::Labelling(Materialise::Labelling &&___Labelling) noexcept
	: enabled(std::move(___Labelling.enabled))
{ }
void Materialise::Labelling::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (enabled.has_value())
		s.WriteAttr("enabled", enabled.value());
}
bool Materialise::Labelling::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	bool __enabled;
	if (s.ReadAttrBool("enabled", __enabled))
		enabled = std::optional<bool> { __enabled };
	return true;
}
Materialise::PreliminaryPass::PreliminaryPass(Materialise::PreliminaryPass &&___PreliminaryPass) noexcept
	: enabled(std::move(___PreliminaryPass.enabled))
{ }
void Materialise::PreliminaryPass::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	if (enabled.has_value())
		s.WriteAttr("enabled", enabled.value());
}
bool Materialise::PreliminaryPass::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	bool __enabled;
	if (s.ReadAttrBool("enabled", __enabled))
		enabled = std::optional<bool> { __enabled };
	return true;
}
Materialise::Parts::Parts(Materialise::Parts &&___Parts) noexcept
	: Part(std::move(___Parts.Part))
{ }
void Materialise::Parts::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	for(auto&& element : Part)
	{
		element.Write(s, "Part"); 
	}
}
bool Materialise::Parts::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	while (true) { 
		Materialise::Part __t;
		if (!__t.Read(s, "Part"))
			break;
		Part.push_back(std::move(__t));
	}
	return true;
}
Materialise::Part::Part(Materialise::Part &&___Part) noexcept
	: id(std::move(___Part.id))
	, FilePath(std::move(___Part.FilePath))
	, Instances(std::move(___Part.Instances))
{ }
void Materialise::Part::Write(IXmlSerializerWriter& s, const std::string& __name__) {
	IXmlSerializerWriter::Scope scope(s, __name__);
	s.WriteAttr("id", id.c_str());
	if (FilePath.has_value())
		s.Write("FilePath", FilePath.value().c_str());
	if (Instances.has_value())
		Instances.value().get()->Write(s, "Instances");
}
bool Materialise::Part::Read(IXmlSerializerReader& s, const std::string& __name__) {
	IXmlSerializerReader::Scope scope(s, __name__);
	if (!scope.exist())
		return false;
	s.ReadAttrStr("id", id);
	s.ReadStr("FilePath", FilePath.value());
	Materialise::PartInstances* __Instances = new Materialise::PartInstances();
	if (__Instances->Read(s, "Instances"))
		Instances = std::optional<std::unique_ptr<Materialise::PartInstances>> { __Instances };
	return true;
}
