package xpath;

import javax.xml.parsers.DocumentBuilder;  
import javax.xml.parsers.DocumentBuilderFactory;  
import javax.xml.xpath.XPath;  
import javax.xml.xpath.XPathConstants;  
import javax.xml.xpath.XPathFactory;  

import org.w3c.dom.Document;  
import org.w3c.dom.Node;  
import org.w3c.dom.NodeList;  

public class xp {
	 public static void main(String args[])
	 {  
         try 
         {  
             //解析文档  
             DocumentBuilderFactory domFactory = DocumentBuilderFactory.newInstance();  
             domFactory.setNamespaceAware(true); // never forget this!  
             DocumentBuilder builder = domFactory.newDocumentBuilder();  
             Document doc = builder.parse("city.xml");  
               
              XPathFactory factory = XPathFactory.newInstance(); //创建 XPathFactory  
              XPath xpath = factory.newXPath();//用这个工厂创建 XPath 对象  
               
              NodeList nodes = (NodeList)xpath.evaluate("location/property", doc, XPathConstants.NODESET);  
              String name = "";  
              String value = "";  
              for (int i = 0; i < nodes.getLength(); i++) 
              {  
                   Node node = nodes.item(i);    
                   name = (String) xpath.evaluate("name", node, XPathConstants.STRING);  
                   value = (String) xpath.evaluate("value", node, XPathConstants.STRING);  
                   System.out.println("name="+name+";value="+value);  
              }  
               
               
       } 
       catch (Exception e) 
       {  
           // TODO Auto-generated catch block  
           e.printStackTrace();  
       }  
	 }
}
