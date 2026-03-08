<HTML>
<HEAD>
<TITLE>Rob & Coronel - ColdFusion Examples</TITLE>
<!--- inserting record in table --->
<CFINSERT DATASOURCE="RobCor" TABLENAME="DEPARTMENT">
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Insert Query: Result Confirmation</B></CENTER></H1>
You have added the following record:
<CFOUTPUT>
<PRE>
	DEPT_ID  : #DEPT_ID#
	DEPT_DESC: #DEPT_DESC#
	USR_ID   : #USR_ID#
</PRE>
</CFOUTPUT>
<FORM ACTION="rc-0.cfm" METHOD="post">
	<INPUT TYPE="submit" VALUE="Main Menu ">
</FORM>
</BODY>
</HTML>

