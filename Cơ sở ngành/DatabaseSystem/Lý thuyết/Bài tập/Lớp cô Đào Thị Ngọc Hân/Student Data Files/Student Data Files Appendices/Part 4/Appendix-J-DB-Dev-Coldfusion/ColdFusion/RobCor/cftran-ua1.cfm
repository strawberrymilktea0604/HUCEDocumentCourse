
<CFQUERY NAME="Deptlist" DATASOURCE="RobCor">
SELECT * FROM DEPARTMENT ORDER BY DEPT_ID
</CFQUERY>
<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</HEAD>
<CENTER><H1>Add User</H1>
<FONT SIZE="1">
<FORM ACTION="cftran-ua2.cfm" METHOD="post">
<!--- required fields --->
<INPUT TYPE=hidden NAME="USR_FNAME_required" VALUE = "Name is required">
<INPUT TYPE=hidden NAME="USR_LNAME_required" VALUE = "Name is required">
<INPUT TYPE=hidden NAME="USR_SSN_required" VALUE = "SSN is required">
<INPUT TYPE=hidden NAME="DEPT_ID_required" VALUE = "DEPT_ID is required">
<INPUT TYPE=hidden NAME="USR_GENDER_required" VALUE = "GENDER must be M or F">

<!---display data for input           --->
<TABLE WIDTH="100" ALIGN="CENTER" VALIGN="TOP" NOWRAP BGCOLOR="Silver" BORDERCOLOR="Aqua">
<TR BGCOLOR="yellow" VALIGN="top">
	<TD COLSPAN="6">General Information</TD>
</TR>
<TR>
	<TD ALIGN="right" NOWRAP VALIGN="bottom">First Name:</TD>
	<TD VALIGN="bottom"><INPUT NAME="USR_FNAME" MAXLENGTH="20"></TD>
	<TD ALIGN="right" NOWRAP VALIGN="BOTTOM">Middle Name:</TD>
	<TD VALIGN="bottom"><INPUT NAME="USR_MNAME" SIZE="2" MAXLENGTH="1"></TD>
	<TD ALIGN="right" NOWRAP VALIGN="BOTTOM">Last Name:</TD>
	<TD VALIGN="bottom"><INPUT NAME="USR_LNAME" MAXLENGTH="20"></TD>
</TR>
<TR>
	<TD ALIGN="right" NOWRAP VALIGN="bottom">SSN:</TD>
	<TD><INPUT NAME="USR_SSN" MAXLENGTH="11"></TD>
	<TD ALIGN="right" NOWRAP VALIGN="BOTTOM">Department ID:</TD>
	<TD><SELECT NAME="DEPT_ID" SIZE="1">
			<CFOUTPUT QUERY="Deptlist">
				<OPTION VALUE="#DEPT_ID#">#DEPT_ID#
			</CFOUTPUT>
			</SELECT></TD>
    <TD ALIGN="right" NOWRAP VALIGN="bottom">GENDER:</TD>
	<TD><INPUT NAME="USR_GENDER" SIZE="1" MAXLENGTH="1"></TD>
</TR>
<TR ALIGN="RIGHT">
	<TD WIDTH="100" COLSPAN="2" ALIGN="LEFT" VALIGN="MIDDLE">
	<INPUT TYPE="submit" VALUE=" Add Record ">
</FORM>
	</TD>
</TR>
<TR>
	<TD colspan=6>
    <p title="" align="CENTER">
    This example demonstrate the use of the CFTRANSACTION tag to get the primary key value
    of a MS Access table (USER) after an insert. The primary key column (USR_ID) is defined
    as AutoNumber. The transaction performs two database operations: the first one is a table 
    insert, the second one gets the max value for the primary key column using the following
    statement: SELECT MAX(USR_ID) from USER. 
    Both queries execute as <B>one transaction</b>, this way we are sure of getting the 
    proper primary key value for the just inserted record.
    </p>
	</TD>
</TR>
</TABLE>
</FONT>
<p><center><a href="default.cfm">Return to Main Menu</a></center></p>
</BODY>
</HTML>





