<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
<CFQUERY NAME="DeptData" DATASOURCE="RobCor">
	SELECT * FROM DEPARTMENT WHERE (DEPARTMENT.DEPT_ID='#form.DEPT_ID#')
</CFQUERY>
<CFQUERY NAME="USRLIST" DATASOURCE="RobCor">
   SELECT USR_ID, USR_LNAME, USR_FNAME, USR_MNAME
      FROM USER
	  WHERE USR_ID NOT IN (SELECT USR_ID FROM DEPARTMENT 
	  						WHERE USR_ID > 0 AND DEPT_ID <> '#form.DEPT_ID#') 
	  ORDER BY USR_LNAME, USR_FNAME, USR_MNAME
</CFQUERY>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Update Query: Edit Record Screen</B></CENTER>
</H1>
<FORM ACTION="rc-6c.cfm" METHOD="post">
<TABLE ALIGN="CENTER" BGCOLOR="Silver" BORDERCOLOR="Blue">
<TR>
<TD>
<CFOUTPUT QUERY="DeptData">
<PRE>
<INPUT TYPE="hidden" NAME="DEPT_ID" VALUE="#DEPTDATA.DEPT_ID#">
Department ID: <B>#DEPT_ID#</B><BR>
Description  : <INPUT TYPE="text" NAME="DEPT_DESC" VALUE="#DEPT_DESC#"SIZE=35 MAXLENGTH=35><BR>
Manager      : <SELECT NAME="USR_ID" SIZE=1><!--- select user from list --->
               <OPTION <CFIF #DEPTDATA.USR_ID# EQ "">SELECTED</CFIF> VALUE="">----------
</CFOUTPUT>
<CFOUTPUT QUERY="USRLIST">
               <OPTION <CFIF #DEPTDATA.USR_ID# EQ #USRLIST.USR_ID#>SELECTED</CFIF> VALUE="#UsrList.USR_ID#">
               [#USR_ID#] #USR_LNAME#, #USR_FNAME#, #USR_MNAME#
</CFOUTPUT>
                </SELECT>
</PRE>
</TD>
<TD VALIGN="TOP">
<INPUT TYPE="submit" VALUE=" Update ">
</FORM>
<FORM ACTION="rc-0.cfm" METHOD="post">
	<INPUT TYPE="submit" VALUE="Main Menu">
</FORM>
</TD>
</TR>
</TABLE>
</BODY>
</HTML>


