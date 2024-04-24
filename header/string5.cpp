/**
 *
 * \file string5.cpp
*/
// #ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  // #define _CRT_SECURE_NO_WARNINGS
// #endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez
// #include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(char c){
   len=1;
   pData=new char[2];
   pData[0]=c;
   pData[1]='\0';
}

/// Másoló konstruktor: String-ből készít (createString)
String::String(const char* str){
   if(str){
   len=strlen(str);
   pData=new char[len+1];
   strcpy(pData,str);
   }
}

String::String(const String& s0){
   len=s0.len;
   pData=new char[len+1];
   strcpy(pData,s0.pData);
}


/// Destruktor (disposeString)
String::~String(){
   delete[] pData;
}

// Operatokrok
String& String::operator=(const String &s0){
   if(this!=&s0){
      delete[] pData;
      len=s0.len;
      pData=new char[len+1];
      strcpy(pData,s0.pData);
   }
   return *this;
}


String String::operator+ (const String &s0)const{
   String s1; delete[] s1.pData;
   s1.len=len+s0.len;
   s1.pData=new char[s1.len+1];
   strcpy(s1.pData,pData);
   strcat(s1.pData,s0.pData);
   return s1;
}


String String::operator+ (char c)const{
   String s1; delete[] s1.pData;
   s1.len=len+1;
   s1.pData=new char[s1.len+1];
   strcpy(s1.pData,pData);
   s1.pData[s1.len-1]=c;
   s1.pData[s1.len]='\0';
   return s1;
}


String operator+ (char c, String s0){
   String ch(c);
   return String(ch+s0);
}


char& String::operator[] (size_t n)const{
   if (n>=len || n<0)
      throw "OODMXV";
   return pData[n];
}


/// << operator, ami kiír az ostream-re
std::ostream& operator << (std::ostream& os, String const s0){
   os<<s0.c_str();
   return os;
}

