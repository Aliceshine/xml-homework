// library.cpp : Defines the entry point for the console application.
//������TinyXML���ٶ�һ�¾��У�����������ѹ��������2��ͷ�ļ���4��cpp�ļ�

#include "stdafx.h"
#include "tinyxml.h"
#include "tinystr.h"
#include <iostream>
#include <string>
 
using namespace std;

void readSchoolXml() {  
    using namespace std;  
    const char * xmlFile = "G:\\xml\\xml-homework\\��ҵ��\\library.xml";  
    TiXmlDocument doc;                                
    if (doc.LoadFile(xmlFile)) {  
        doc.Print();  
    } else {  
        cout << "can not parse school.xml" << endl;  
        return;  
    }  
    TiXmlElement* rootElement = doc.RootElement();  //SchoolԪ��    
    TiXmlElement* classElement = rootElement->FirstChildElement();  // ClassԪ��  
    TiXmlElement* studentElement = classElement->FirstChildElement();  //Students    
    for (; studentElement != NULL; studentElement = studentElement->NextSiblingElement() ) {  
        TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();  //���student��name����    
        for (;attributeOfStudent != NULL; attributeOfStudent = attributeOfStudent->Next() ) {  
            cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;         
        }                                   
   
        TiXmlElement* studentContactElement = studentElement->FirstChildElement();//���student�ĵ�һ����ϵ��ʽ   
        for (; studentContactElement != NULL; studentContactElement = studentContactElement->NextSiblingElement() ) {  
            string contactType = studentContactElement->Value();  
            string contactValue = studentContactElement->GetText();  
            cout << contactType  << " : " << contactValue << std::endl;             
        }     
   
    }   
}  
   


int main(int argc, char* argv[])
{
	readSchoolXml();  
    system("pause");  
    return 1;  
}
