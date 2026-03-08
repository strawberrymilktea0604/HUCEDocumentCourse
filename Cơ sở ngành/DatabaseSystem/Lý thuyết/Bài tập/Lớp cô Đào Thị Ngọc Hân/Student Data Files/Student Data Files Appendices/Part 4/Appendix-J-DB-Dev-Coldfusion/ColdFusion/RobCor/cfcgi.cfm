<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<html>
<head>
	<title>CGI Variables</title>
</head>
<body>
<h1>CGI Variables</h1>
<hr>
<cfoutput>
<table border=1>
<tr>
	<td>SERVER_SOFTWARE</td>
	<td>#SERVER_SOFTWARE#</td>
</tr>
<tr>
    <td>SERVER_NAME</td>
    <td>#SERVER_NAME#</td>
</tr>
<tr>
    <td>GATEWAY_INTERFACE</td>
    <td>#GATEWAY_INTERFACE#</td>
</tr>
<tr>
    <td>SERVER_PROTOCOL</td>
    <td>#SERVER_PROTOCOL#</td>
</tr>
<tr>
    <td>SERVER_PORT</td>
    <td>#SERVER_PORT#</td>
</tr>
<tr>
    <td>REQUEST_METHOD</td>
    <td>#REQUEST_METHOD#</td>
</tr>
 <tr>
    <td>PATH_INFO</td>
    <td>#PATH_INFO#</td>
</tr>
<tr>
    <td>PATH_TRANSLATED</td>
    <td>#PATH_TRANSLATED#</td>
</tr>
<tr>
    <td>SCRIPT_NAME</td>
    <td>#SCRIPT_NAME#</td>
</tr>
<tr>
    <td>QUERY_STRING</td>
    <td>#QUERY_STRING#</td>
</tr>
<tr>
    <td>REMOTE_HOST</td>
    <td>#REMOTE_HOST#</td>
</tr>
<tr>
    <td>REMOTE_ADDR</td>
    <td>#REMOTE_ADDR#</td>
</tr>
 <tr>
    <td>AUTH_TYPE</td>
    <td>#AUTH_TYPE#</td>
</tr>
 <tr>
    <td>REMOTE_USER</td>
    <td>#REMOTE_USER#</td>
</tr>
<tr>
    <td>AUTH_USER</td>
    <td>#AUTH_USER#</td>
</tr>
<!--- tr>
    <td>REMOTE_IDENT</td>
    <td>#REMOTE_IDENT#</td>
</tr --->
<tr>
    <td>CONTENT_TYPE</td>
    <td>#CONTENT_TYPE#</td>
</tr>
<tr>
    <td>CONTENT_LENGTH</td>
    <td>#CONTENT_LENGTH#</td>
</tr>
<tr>
    <td>HTTP_REFERER</td>
    <td>#HTTP_REFERER#</td>
</tr>
<tr>
    <td>HTTP_USER_AGENT </td>
    <td>#HTTP_USER_AGENT#</td>
</tr>
</table>
</cfoutput>
<br>
<center><a href="rc-0.cfm">Return to Menu</a></center>
</body>
</html>


