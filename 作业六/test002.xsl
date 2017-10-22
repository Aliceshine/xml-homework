<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="Team">
		<html>
			<head>
				<title>root</title>
			</head>
			<body>
				<xsl:apply-templates/>
			</body>
		</html>
	</xsl:template>
	<xsl:template match="TeamMember">
		<xsl:apply-templates/>
	</xsl:template>
	
</xsl:stylesheet>