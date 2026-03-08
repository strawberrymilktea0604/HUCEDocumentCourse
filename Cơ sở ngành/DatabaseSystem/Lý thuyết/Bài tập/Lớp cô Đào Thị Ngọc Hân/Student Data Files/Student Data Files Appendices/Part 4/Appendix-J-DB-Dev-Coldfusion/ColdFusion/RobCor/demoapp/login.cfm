<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
	<title>Login Page</title>
</head>
<body topmargin=0>
<!--- header --->
<cfset session.curoption = "Login">
<cfinclude template = "header.cfm">

<!--- Page code starts here --->
<H1>Please login</h1>
<cfform action="login2.cfm" method="POST" enablecab="Yes">
<table>
<tr>
	<td Align=Right>Login :</td>
	<td><cfinput type="Text"
       name="wloginname"
       value="guest"
       message="Valid Login name is required"
       required="Yes"
       size="12"
       maxlength="12"></td>
</tr>
<tr>
	<td><input type="Submit" name="action" value="Login" align="TOP"></td>
	<td><input type="Reset"></td>
</tr>
<tr>
<td>

</td></tr>
</table>
</cfform>
<br>
<p>[Note the main header of this page shows the current application framework]</p>
<br>
<center><a href="../rc-0.cfm">Return to Menu</a></center>
</body>
</html>




