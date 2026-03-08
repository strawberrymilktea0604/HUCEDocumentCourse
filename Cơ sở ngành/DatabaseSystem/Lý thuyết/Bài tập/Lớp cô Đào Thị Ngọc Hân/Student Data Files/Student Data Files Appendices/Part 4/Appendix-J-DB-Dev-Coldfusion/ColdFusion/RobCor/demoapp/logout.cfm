<html>
<head>
<title>Logout Page</title>
<meta http-equiv="REFRESH" content="2; url=login.cfm">
</head>
<body title="Logout Page" topmargin=0>
<!--- header --->
<cfset session.curoption = "Logout">
<cfinclude template="header.cfm">

<!--- Logout procedure resets session variables --->
<!--- Set the session variables to blank to force login page--->
<cfset session.validuser = "">
<cfset session.curoption = "">

<!--- Page starts here --->
<H1 align="center">
<FONT color="#0000ff">You will be sent to the login page in a few seconds<BR></FONT>
</H1>
<HR>
</BODY>
</HTML>









