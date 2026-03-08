<!--- application.cfm CF Application Framework --->
<!--- Start the Application and Session framework --->
<cfapplication name="ROBCOR" Sessionmanagement="YES">

<!--- Set session variables --->
<CFSET session.apptitle   = "Database Systems: Design, Implementation, and Management">
<CFSET session.appversion = "(R)">
<CFSET session.hostip     = "#cgi.http_host#">
<CFSET session.webhome    = "http://#cgi.http_host#">
<CFSET session.auname     = "Peter Rob & Carlos Coronel">
<CFSET session.puname     = "Course Technology, ITP">

<body topmargin=0 bgcolor="lightblue">
<div align="left" title="main">
<!--- topheader.cfm   Header for all Applications --->
<table border=1 width="98%" bgcolor="cyan" valign="TOP">
<tr>
	<td><small><b>
	<CFOUTPUT>#session.apptitle# #session.appversion#</CFOUTPUT>
	</td></small></b>
	<td><small><b>
	<CFOUTPUT>#session.auname#</CFOUTPUT>
	</td></small></b>
	<td><small><b>
	<CFOUTPUT>#session.puname#</CFOUTPUT>
	</td></small></b>
	<td align="RIGHT"><small><b>
	<CFOUTPUT>#DateFormat(Now(),('ddd, mmm dd'))#</CFOUTPUT>
	</td></small></b>
</tr>
</table>

</div>
</body>


