<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</HEAD>
<CFQUERY NAME="DeptData" DATASOURCE="RobCor">
	SELECT * FROM DEPARTMENT WHERE (DEPARTMENT.DEPT_ID='#form.DEPT_ID#')
</CFQUERY>
<CFIF #DEPTDATA.USR_ID# IS NOT "">
	<CFQUERY NAME="Usrdata" DATASOURCE="RobCor">
	    SELECT USR_ID, USR_LNAME, USR_FNAME, USR_MNAME FROM USER
		 WHERE (USER.USR_ID = #deptdata.usr_id#)
	</CFQUERY>
</CFIF>
<CFQUERY NAME="UsrTot" DATASOURCE="RobCor">
	SELECT COUNT(*) AS T1 FROM USER
	  WHERE (USER.DEPT_ID = '#form.DEPT_ID#')
</CFQUERY>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1><CENTER><B>Delete Query: Show Record Screen</B></CENTER></H1>
<FORM ACTION="rc-7c.cfm" METHOD="post">
<CFOUTPUT QUERY="DeptData">
<INPUT TYPE="hidden" NAME="DEPT_ID" VALUE="#deptdata.DEPT_ID#">
<INPUT TYPE="hidden" NAME="DEPT_DESC" VALUE="#deptdata.DEPT_DESC#">
<INPUT TYPE="hidden" NAME="USR_ID" VALUE=#DEPTDATA.USR_ID#>
<TABLE ALIGN="CENTER" BGCOLOR="Silver" BORDERCOLOR="Blue">
<TR>
<TD>
<PRE>
Department ID: #DEPT_ID#<BR>
Description  : #DEPT_DESC#<BR>
Manager      : <CFIF #DEPTDATA.USR_ID# IS NOT "">#Usrdata.USR_LNAME# #Usrdata.USR_FNAME# #Usrdata.USR_MNAME#</CFIF>
</CFOUTPUT>
</PRE>
</TD>
<TD VALIGN="TOP">
<CFIF #USRTOT.T1# EQ 0>
	<INPUT TYPE="submit" VALUE=" Delete ">
<CFELSE>
	<SMALL><B>We cannot delete this record <BR>because there are dependent <BR>users assigned to this department</B></SMALL>
</CFIF>
</FORM>
<FORM ACTION="rc-0.cfm" METHOD="post"><INPUT TYPE="submit" VALUE="Main Menu"></FORM>
</TD>
</TR>
</TABLE>
</BODY>
</HTML>

