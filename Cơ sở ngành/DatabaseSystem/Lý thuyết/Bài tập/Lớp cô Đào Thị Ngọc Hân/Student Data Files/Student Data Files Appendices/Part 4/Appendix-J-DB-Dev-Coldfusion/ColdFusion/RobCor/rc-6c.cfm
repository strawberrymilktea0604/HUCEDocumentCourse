<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
<CFUPDATE DATASOURCE="RobCor" TABLENAME="Department">
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Update Query: Result Confirmation</B></CENTER>
</H1>
<CFOUTPUT>
You have successfully Updated the following data 
<PRE>
DEPARTMENT ID:	<B>#DEPT_ID#</B>
DESCRIPTION  :	<B>#DEPT_DESC#</B>
MANAGER      :	<B>#USR_ID#</B>
</PRE>
</CFOUTPUT>
<FORM ACTION="rc-0.cfm" METHOD="post">
	<INPUT TYPE="submit" VALUE="Main Menu ">
</FORM>
</BODY>
</HTML>


