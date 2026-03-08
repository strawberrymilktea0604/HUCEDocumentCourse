
<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
<CFQUERY NAME="USRLIST" DATASOURCE="RobCor">
SELECT USR_ID, USR_LNAME + ', ' + USR_FNAME + USR_MNAME AS FULLNAME
      FROM USER
	  WHERE USR_ID NOT IN (SELECT USR_ID FROM DEPARTMENT WHERE USR_ID > 0)
	  ORDER BY USR_LNAME 
</CFQUERY>

<SCRIPT ID="clientEventHandlersJS" LANGUAGE="JavaScript">
<!--
function _onclick()
{
window.open('cf-deplist.cfm','ViewDep','width=400,height=300,directories=no,location=no,menubar=no,scrollbars=yes,status=no,toolbar=no,resizable=no,left=100,top=100,screenX=100,screenY=100');
}
-->
</SCRIPT>

</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Insert Query: Data Entry Screen with CFFORM and JavaScript</B></CENTER></H1>
<cfform action="cf-depadd2.cfm" method="POST" enablecab="Yes">
<CENTER><H1>Department Data</H1></CENTER>
<!--- the following code defines required fields 
    good practice if client browser does not support JavaScript--->
	<INPUT TYPE="hidden" NAME="DEPT_ID_required" VALUE="You must enter a DEPT_ID">
	<INPUT TYPE="hidden" NAME="DEPT_DESC_required" VALUE="You must enter a description">
	<TABLE ALIGN="CENTER" BGCOLOR="Silver">
		<TR>
			<TD>
			<PRE>
            Department ID: <cfinput type="Text" name="DEPT_ID" message="Department ID is required" required="Yes" size="10" maxlength="10"><BR>
            Description:   <cfinput type="Text" name="DEPT_DESC" message="Department description is required" required="Yes" size="35" maxlength="35"><BR>
            Manager    :   <select name="USR_ID" size="1">
                            <OPTION VALUE="">--------
                            <cfoutput query="USRLIST">
                            <OPTION VALUE="#USRLIST.USR_ID#">#FULLNAME#
                            </cfoutput>
                           </select>
            </PRE>
			</TD>
			<TD>
            <INPUT TYPE="button" VALUE="View " onClick="_onclick()"><BR><BR>
			<INPUT TYPE="submit" VALUE="Add  "><BR><BR>
			<INPUT TYPE="reset"  VALUE="Reset">
            </TD>
    </TR>
    </TABLE>

</CFFORM>
</TD>
</TR>
</TABLE>
</BODY>
</HTML>







