<HTML>
<HEAD>
	<TITLE>Coronel & Morris - Microsoft ASP Examples</TITLE>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
	<H1>
		<CENTER><B>Simple Query using ASP - RecordSet and Response.Write</B></CENTER>
		<CENTER><B>(Vertical Output)</B></CENTER>
	</H1>
	<BR>
	<%
		dim connOrderDB
		dim strDatabasePath
		strDatabasePath="C:\MyProjects\GradProject\"
		set connOrderDB = Server.CreateObject("ADODB.Connection")
		connOrderDB.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" _
			& strDatabasePath & "orderdb.mdb"
		connOrderDB.Open
		Response.Write "<HR>"
		set VenCount= Server.CreateObject("ADODB.RecordSet")
		VenCount.Open "SELECT COUNT(VEN_CODE) AS VEN_COUNT FROM VENDOR", connORDERDB 
		Response.Write " Your query returned " & VenCount("VEN_COUNT") & " records" & "<br>"
		set VenList= Server.CreateObject("ADODB.RecordSet")
		VenList.Open "SELECT * FROM VENDOR ORDER BY VEN_CODE" , connORDERDB 
		Do while Not VenList.EOF
			Response.Write "<br><br><B>"
			Response.Write " VENDOR CODE    : " & "&nbsp;&nbsp;" & VenList("VEN_CODE") & "<br>"
			Response.Write " VENDOR NAME    : " & "&nbsp;&nbsp;" & VenList("VEN_NAME") & "<br>"
			Response.Write " CONTACT PERSON : " & "&nbsp;&nbsp;" & VenList("VEN_CONTACT_NAME") & "<br>"
			Response.Write " ADDRESS        : " & "&nbsp;&nbsp;" & VenList("VEN_ADDRESS") & "<br>"
			Response.Write " CITY           : " & "&nbsp;&nbsp;" & VenList("VEN_CITY") & "<br>"
			Response.Write " STATE          : " & "&nbsp;&nbsp;" & VenList("VEN_STATE") & "<br>"
			Response.Write " ZIP            : " & "&nbsp;&nbsp;" & VenList("VEN_ZIP") & "<br>"
			Response.Write " PHONE          : " & "&nbsp;&nbsp;" & VenList("VEN_PH") & "<br>"
			Response.Write " FAX            : " & "&nbsp;&nbsp;" & VenList("VEN_FAX") & "<br>"
			Response.Write " E-MAIL         : " & "&nbsp;&nbsp;" & VenList("VEN_EMAIL") & "<br>"
			Response.Write " CUSTOMER ID    : " & "&nbsp;&nbsp;" & VenList("VEN_CUS_ID") & "<br>"
			Response.Write " SUPPORT ID     : " & "&nbsp;&nbsp;" & VenList("VEN_SUPPORT_ID") & "<br>"
			Response.Write " SUPPORT PHONE  : " & "&nbsp;&nbsp;" & VenList("VEN_SUPPORT_PH")	& "<br>"
			Response.Write " VENDOR WEB PAGE: " & "&nbsp;&nbsp;" & VenList("VEN_WEB_PAGE") & "<br></B><HR>"
			VenList.MoveNext
		Loop
		connOrderDB.Close
	%>
</BODY>
</HTML>