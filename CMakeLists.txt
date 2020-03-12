cmake_minimum_required(VERSION 3.13.0)
project(scintilla VERSION 4.3.3 LANGUAGES C CXX)

file(GLOB lexers_src ${CMAKE_CURRENT_SOURCE_DIR}/lexers/*.cxx)

add_subdirectory(qt)