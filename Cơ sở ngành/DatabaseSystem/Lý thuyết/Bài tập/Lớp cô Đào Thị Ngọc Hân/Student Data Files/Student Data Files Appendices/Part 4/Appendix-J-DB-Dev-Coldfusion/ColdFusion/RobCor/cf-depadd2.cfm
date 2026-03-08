
<HTML>
<HEAD>
<TITLE>Rob & Coronel - ColdFusion Examples</TITLE>
<!--- parameter checking ---->
<CFPARAM name="form.DEPT_ID" DEFAULT="">
<CFPARAM name="form.DEPT_DESC" DEFAULT="">
<CFPARAM name="form.USR_ID" DEFAULT="">

<!--- data validation --->
<!--- verify record does not exist --->
<cfquery name="dep" datasource="RobCor" dbtype="ODBC">
select * from department where dept_id = '#form.dept_id#'
</cfquery>

<!--- inserting record in table if it is a new record--->
<cfif dep.recordcount EQ 0>
    <CFINSERT DATASOURCE="RobCor" TABLENAME="DEPARTMENT">
</cfif>

<!--- read record after save --->
<cfquery name="depdata" datasource="RobCor" dbtype="ODBC">
select * from department where dept_id = '#form.dept_id#'
</cfquery>

</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Insert Query: Result Confirmation</B></CENTER></H1>
<div align="CENTER" style="text-decoration: none; text-align: center; color: Blue; font-family: sans-serif;">
<cfif NOT dep.recordcount EQ 0>
    <b><font size="+1">
    Record already exist! <BR>
    Please verify your data and try again
    </font></b>
<cfelse>
    You have added the following record:
</cfif>
</div>
<CFOUTPUT>
<PRE>
	DEPT_ID  : #depdata.DEPT_ID#
	DEPT_DESC: #depdata.DEPT_DESC#
	USR_ID   : #depdata.USR_ID#
</PRE>
</CFOUTPUT>
<center><a href="rc-0.cfm">Return to Menu</a></center>
</BODY>
</HTML>

