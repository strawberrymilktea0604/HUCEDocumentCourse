<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
<CFQUERY NAME="Deptlist" DATASOURCE="RobCor">
	SELECT * FROM DEPARTMENT ORDER BY DEPT_ID
</CFQUERY>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Delete Query: Record Selection Screen</B></CENTER>
</H1>
<TABLE ALIGN="CENTER" BGCOLOR="Silver">
<TR VALIGN="TOP">
<TD>
<FORM ACTION="rc-7b.cfm" METHOD="post">
	<SELECT NAME="DEPT_ID" SIZE=1>
	<CFOUTPUT QUERY="Deptlist">
		<OPTION VALUE="#DEPT_ID#">[#DEPT_ID#] - #DEPT_DESC#
	</CFOUTPUT>
	</SELECT>
	<INPUT TYPE=HIDDEN NAME="DEPT_ID_required" VALUE="DEPT_ID is required">
</TD>
<TD>
	<INPUT TYPE="submit" VALUE="Delete">
</FORM>
</TD>
<TD>
<FORM ACTION="rc-0.cfm" METHOD="post">
	<INPUT TYPE="submit" VALUE="Main Menu">
</FORM>
</TD>
</TR>
</TABLE>
</BODY>
</HTML>


