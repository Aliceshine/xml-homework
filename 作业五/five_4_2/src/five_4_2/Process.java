package five_4_2;

import javax.xml.parsers.*;
import org.w3c.dom.*;
public class Process {
	public static void main(String[] args)
	{
		try
		{
			DocumentBuilderFactory factory=DocumentBuilderFactory.newInstance();
			DocumentBuilder builder=factory.newDocumentBuilder();
			Document doc=builder.parse("Teams.xml");
			doc.normalize();
			
			Element root=doc.getDocumentElement();
			
			if(doc!=null)
			{
				printNode(root);
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	private static void printNode(Element element)
	{
		int k;
		NamedNodeMap attr;
		NodeList children=element.getChildNodes();
		attr=element.getAttributes();
		int r=children.getLength();
		if(attr!=null)
		{
			System.out.print("<"+element.getNodeName());
			for(int j=0;j<attr.getLength();j++)
			{
				System.out.print(" "+attr.item(j).getNodeName()+"="+attr.item(j).getNodeValue());
			}
			System.out.println(">");
		}
		else if(attr==null)
		{
			System.out.print("<"+element.getNodeName()+">");
		}
		if(element.hasChildNodes())
		{
			for(k=0;k<r;k++)
			{
				if(children.item(k).getNodeType()==org.w3c.dom.Node.ELEMENT_NODE)
				{
					printNode((Element) children.item(k));
				}
				else if(children.item(k).getNodeType()==org.w3c.dom.Node.TEXT_NODE)
				{
					System.out.println(children.item(k).getNodeValue());
				}
				
			}
			System.out.println("</"+element.getNodeName()+">");
		}
	}
}
