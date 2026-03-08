<html>
<head>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</head>
<body>

<cfform action="cflocation2.cfm" method="POST" enablecab="Yes">
<table>
<tr>
	<td>Enter a number between 1-3  </td>
	<td><cfinput type="Text"
       name="wnumber"
       value="1"
       range="1,3"
       message="Number must be between 1 and 3"
       validate="integer"
       required="Yes"
       size="1"
       maxlength="1"></td>
</tr>
<tr>
	<td></td>
	<td></td>
</tr>
<tr>
	<td><input type="Submit" name="Action" value="Go"></td>
	<td><input type="Reset"></td>
</tr>
</table>
</cfform>
<p><center><a href="default.cfm">Return to Main Menu</a></center></p>
</body>
</html>



