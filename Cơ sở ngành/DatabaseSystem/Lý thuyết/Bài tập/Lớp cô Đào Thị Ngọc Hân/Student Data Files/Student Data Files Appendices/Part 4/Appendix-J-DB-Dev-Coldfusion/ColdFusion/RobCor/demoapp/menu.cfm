<HTML>
<HEAD>
<TITLE>Main Menu</TITLE>
</HEAD>
<BODY topmargin="0">
<!--- header --->
<cfset session.curoption = "Main Menu">
<cfinclude template="header.cfm">

<!--- Page starts here --->
<H1 align="center"><FONT color="#0000ff">Welcome to this Menu<BR></FONT></H1>
<HR>
<DIV align="center">
<TABLE border="0" cellpadding="0" cellspacing="0" width="90%" align="center">
    <TR>
	    <TD><a href="option1.cfm"><H4>Option 1</H4></a></TD>
	</TR>
	<TR>
        <TD><a href="logout.cfm"><H4>Logout</H4></a></TD>
    </TR>
</TABLE>
</DIV>
</BODY>
</HTML>





