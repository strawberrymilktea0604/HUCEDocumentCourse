<!--- header.cfm   Header for all Applications --->
<div align="LEFT" >
<CFOUTPUT>
<table border=1 width="80%" bgcolor="Silver" valign="TOP" cellpadding=0 cellspacing=0>

<!--- if using hex color codes, you need to use double '#' symbols 
so coldfusion does not attempt to parse code to a field, variable or function name --->
<tr bordercolor="##0000FF">
	<td valign="TOP" style="font-size: xx-small; font-family: sans-serif; font-weight: normal; text-decoration: none; color: Maroon;">
	#session.apptitle#
	</td>
	<td valign="TOP" style="font-size: xx-small; font-family: sans-serif; font-weight: normal; text-decoration: none; color: Maroon;">
	#session.auname#
	</td>
	<td valign="TOP" style="font-size: xx-small; font-family: sans-serif; font-weight: normal; text-decoration: none; color: Maroon;">
    #session.curoption#
	</td>
	<td align="RIGHT" valign="TOP" width="10%" style="font-size: xx-small; font-family: sans-serif; font-weight: normal; text-decoration: none; color: Maroon;">
	#DateFormat(Now(),('dd/mm/yy'))#
	</td>
</tr>
</table>
</CFOUTPUT>
</div>







