<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
<CFQUERY NAME="USRLIST" DATASOURCE="RobCor">
SELECT USR_ID, USR_LNAME, USR_FNAME, USR_MNAME
      FROM USER
	  WHERE USR_ID NOT IN (SELECT USR_ID FROM DEPARTMENT WHERE USR_ID > 0)
	  ORDER BY USR_LNAME, USR_FNAME, USR_MNAME
</CFQUERY>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Insert Query: Data Entry Screen</B></CENTER></H1>
<FORM ACTION="rc-5b.cfm" METHOD="post">
<CENTER><H1>Department Data</H1></CENTER><!--- the following code defines required fields --->
	<INPUT TYPE="hidden" NAME="DEPT_ID_required" VALUE="You must enter a DEPT_ID">
	<INPUT TYPE="hidden" NAME="DEPT_DESC_required" VALUE="You must enter a description">
	<TABLE ALIGN="CENTER" BGCOLOR="Silver">
		<TR>
			<TD>
			<PRE>
 Department ID:
				<INPUT TYPE="text" NAME="DEPT_ID" SIZE="10" MAXLENGTH="10"><BR>Description:
				<INPUT TYPE="text" NAME="DEPT_DESC" SIZE="35" MAXLENGTH="35"><BR>Manager    :
				<SELECT NAME="USR_ID" SIZE="1"><!--- select user from list --->
					<OPTION VALUE="">----------
					<CFOUTPUT QUERY="USRLIST">
						<OPTION VALUE="#UsrList.USR_ID#">[#USR_ID#] #USR_LNAME#, #USR_FNAME#, #USR_MNAME#
					</CFOUTPUT>
				</SELECT></PRE>
			</TD>
			<TD>
				<INPUT TYPE="submit" VALUE="Add Record">
</FORM>
<FORM ACTION="rc-0.cfm" METHOD="post">
	<INPUT TYPE="submit" VALUE=" Main Menu ">
</FORM>
</TD>
</TR>
</TABLE>
</BODY>
</HTML>

