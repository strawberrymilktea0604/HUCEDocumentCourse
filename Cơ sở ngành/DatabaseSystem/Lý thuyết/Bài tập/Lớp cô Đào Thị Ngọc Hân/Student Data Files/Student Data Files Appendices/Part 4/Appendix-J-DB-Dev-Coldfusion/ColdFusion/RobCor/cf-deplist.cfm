
<HTML>
<HEAD>
<TITLE>Department Listing</TITLE>
<CFQUERY NAME="deptlist" DATASOURCE="RobCor">
SELECT DEPARTMENT.DEPT_ID, DEPT_DESC, USR_LNAME + ', ' + USR_FNAME AS UNAME
FROM DEPARTMENT, USER
WHERE DEPARTMENT.USR_ID = USER.USR_ID
ORDER BY DEPARTMENT.DEPT_ID
</CFQUERY>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<CENTER><B>Department Listing</B></CENTER>
<table width="100%" border="1" cellspacing="1" cellpadding="1" align="CENTER" nowrap bordercolor="#0000FF">
<TR><TD><B>Dept ID</b></td><TD><B>Description</b></td><TD><B>Manager</B></td></tr>
<cfoutput query="deptlist">
<TR>
<TD width="20%" align="LEFT">#DEPT_ID#</td>
<TD width="40%" align="LEFT">#DEPT_DESC#</td>
<TD width="40%" align="LEFT">#UNAME#</td>
</tr>
</cfoutput>
</table>
</BODY>
</HTML>








