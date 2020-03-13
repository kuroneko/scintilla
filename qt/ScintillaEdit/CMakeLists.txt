add_custom_command(OUTPUT ScintillaEdit.cpp ScintillaEdit.h
        COMMENT "Generating Qt API Sources"
        DEPENDS ScintillaEdit.cpp.template ScintillaEdit.h.template WidgetGen.py
        COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/WidgetGen.py
        )
add_library(ScintillaEdit
        SHARED
        ScintillaDocument.cpp
        ScintillaDocument.h
        ScintillaEdit.cpp
        ScintillaEdit.h
        ../ScintillaEditBase/PlatQt.cpp
        ../ScintillaEditBase/ScintillaQt.cpp
        ../ScintillaEditBase/ScintillaEditBase.cpp
        ../../src/XPM.cxx
        ../../src/ViewStyle.cxx
        ../../src/UniqueString.cxx
        ../../src/UniConversion.cxx
        ../../src/Style.cxx
        ../../src/Selection.cxx
        ../../src/ScintillaBase.cxx
        ../../src/RunStyles.cxx
        ../../src/RESearch.cxx
        ../../src/PositionCache.cxx
        ../../src/PerLine.cxx
        ../../src/MarginView.cxx
        ../../src/LineMarker.cxx
        ../../src/KeyMap.cxx
        ../../src/Indicator.cxx
        ../../src/ExternalLexer.cxx
        ../../src/EditView.cxx
        ../../src/Editor.cxx
        ../../src/EditModel.cxx
        ../../src/Document.cxx
        ../../src/Decoration.cxx
        ../../src/DBCS.cxx
        ../../src/ContractionState.cxx
        ../../src/CharClassify.cxx
        ../../src/CellBuffer.cxx
        ../../src/Catalogue.cxx
        ../../src/CaseFolder.cxx
        ../../src/CaseConvert.cxx
        ../../src/CallTip.cxx
        ../../src/AutoComplete.cxx
        ../../lexlib/WordList.cxx
        ../../lexlib/StyleContext.cxx
        ../../lexlib/PropSetSimple.cxx
        ../../lexlib/LexerSimple.cxx
        ../../lexlib/LexerNoExceptions.cxx
        ../../lexlib/LexerModule.cxx
        ../../lexlib/LexerBase.cxx
        ../../lexlib/DefaultLexer.cxx
        ../../lexlib/CharacterSet.cxx
        ../../lexlib/CharacterCategory.cxx
        ../../lexlib/Accessor.cxx
        ${lexers_src})
target_include_directories(
        ScintillaEdit
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../ScintillaEditBase>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:include/scintilla>
        $<INSTALL_INTERFACE:include/scintilla/Qt>
        PRIVATE
        ../../src
        ../../lexlib
        )
target_compile_definitions(ScintillaEdit PRIVATE
        SCINTILLA_QT=1 MAKING_LIBRARY=1 SCI_LEXER=1)
target_link_libraries(ScintillaEdit
        PUBLIC
        Qt5::Core Qt5::Gui Qt5::Widgets)
set_target_properties(ScintillaEdit PROPERTIES CXX_STANDARD 17)