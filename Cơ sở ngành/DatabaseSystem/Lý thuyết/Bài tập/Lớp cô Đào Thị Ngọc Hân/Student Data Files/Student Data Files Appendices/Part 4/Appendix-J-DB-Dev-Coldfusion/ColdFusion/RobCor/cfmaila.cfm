<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1><CENTER><B>CFMAIL example</B></CENTER></H1>
<BR>
<HR>
<p>
This page will generate an email to the address indicated.<BR>
Requirements: Cold Fusion Server Email settings must be defined.
</p>

<form action="cfmailb.cfm" method="POST">
<table>
<tr>
	<td>Please enter your email:</td>
	<td><input type="Text" name="wemail"></td>
</tr>
<tr>
	<td><input type="Submit" name="action" value="Send"></td>
	<td><input type="Reset"></td>
</tr>
</table>
</form>
<p><center><a href="rc-0.cfm">Return to Menu</a></center></P>
</body>
</html>


