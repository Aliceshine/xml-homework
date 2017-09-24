// library.cpp : Defines the entry point for the console application.
//先下载TinyXML，百度一下就行，下载下来解压，里面有2个头文件和4个cpp文件

#include "stdafx.h"
#include "tinyxml.h"
#include "tinystr.h"
#include <iostream>
#include <string>
 
using namespace std;

void readSchoolXml() {  
    using namespace std;  
    const char * xmlFile = "G:\\xml\\xml-homework\\作业三\\library.xml";  
    TiXmlDocument doc;                                
    if (doc.LoadFile(xmlFile)) {  
        doc.Print();  
    } else {  
        cout << "can not parse school.xml" << endl;  
        return;  
    }  
    TiXmlElement* rootElement = doc.RootElement();  //School元素    
    TiXmlElement* classElement = rootElement->FirstChildElement();  // Class元素  
    TiXmlElement* studentElement = classElement->FirstChildElement();  //Students    
    for (; studentElement != NULL; studentElement = studentElement->NextSiblingElement() ) {  
        TiXmlAttribute* attributeOfStudent = studentElement->FirstAttribute();  //获得student的name属性    
        for (;attributeOfStudent != NULL; attributeOfStudent = attributeOfStudent->Next() ) {  
            cout << attributeOfStudent->Name() << " : " << attributeOfStudent->Value() << std::endl;         
        }                                   
   
        TiXmlElement* studentContactElement = studentElement->FirstChildElement();//获得student的第一个联系方式   
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
