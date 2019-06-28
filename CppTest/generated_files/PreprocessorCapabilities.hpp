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
	struct PreprocessorCapabilities;
	struct PreprocessorCapabilities {
		void Write(IXmlSerializerWriter&s);
		bool Read(IXmlSerializerReader& s);
		std::optional<bool> Labelling {false};
		std::optional<bool> DeferredLabelling {false};
		PreprocessorCapabilities() {}
		~PreprocessorCapabilities() {}
	};
}
void Materialise::PreprocessorCapabilities::Write(IXmlSerializerWriter& s) {
	IXmlSerializerWriter::Scope scope(s, "PreprocessorCapabilities");
	s.Write("Labelling", Labelling.value());
	s.Write("DeferredLabelling", DeferredLabelling.value());
}
bool Materialise::PreprocessorCapabilities::Read(IXmlSerializerReader& s) {
	IXmlSerializerReader::Scope scope(s, "PreprocessorCapabilities");
	if (scope.exist() == false)
		return false;
	s.ReadBool("Labelling", Labelling.value());
	s.ReadBool("DeferredLabelling", DeferredLabelling.value());
	return true;
}
