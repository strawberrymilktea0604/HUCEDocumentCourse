<HTML>
<HEAD>
<cfquery name="venlist" datasource="#session.dsn#" maxrows=10 dbtype="ODBC">
select * from vendor
</cfquery>
<TITLE>Option 1</TITLE>
</HEAD>
<BODY topmargin="0">
<!--- header --->
<cfset session.curoption = "Option 1">
<cfinclude template="header.cfm">

<!--- page starts here --->
<H1 align="center"><FONT color="#0000ff">Option 1<BR></FONT></H1>
<HR>
<p>This option performs a query of a database table and lists variable status</p>
<p><h3>Query Output</h3></p>
<cfoutput query="venlist" startrow=1 maxrows=10>
<PRE>
#LJustify(ven_code,10)# #LJustify(ven_name,15)#<BR>
</cfoutput>
<p>Variable Status</p>
</pre>
<CFOUTPUT>
<TABLE border="0" cellpadding="0" cellspacing="0" width="90%" align="center">
<TR>
<TD>session.apptitle</TD>
<td>#session.apptitle#</td>
</TR>
<TR>        
<TD>session.auname</TD>
<td>#session.auname#</td>
</TR>
<TR>        
<TD>session.curoption</TD>
<td>#session.curoption#</td>
</TR>
<TR>        
<TD>session.dsn</TD>
<td>#session.dsn#</td>
</TR>
<TR>        
<TD>session.hostip</TD>
<td>#session.hostip#</td>
</TR>
<TR>        
<TD>session.webhome</TD>
<td>#session.webhome#</td>
</TR>
<TR>        
<TD>session.validuser</TD>
<td>#session.validuser#</td>
</TR>
</TABLE>
</cfoutput>
</BODY>
</HTML>




