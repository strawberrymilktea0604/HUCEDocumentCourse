<!--- This is a second page of the add routine that allows 
the user to insert a new user in the database--->

<HTML>
<CFPARAM NAME="USR_FNAME"  DEFAULT = "">
<CFPARAM NAME="USR_LNAME"  DEFAULT = "">
<CFPARAM NAME="USR_SSN"    DEFAULT = "">
<CFPARAM NAME="DEPT_ID"    DEFAULT = "">
<CFPARAM NAME="USR_GENDER" DEFAULT = "">

<CFOUTPUT>Parameters: #USR_FNAME# #USR_LNAME# #USR_SSN# #DEPT_ID# #USR_GENDER# :</cfoutput>
<CFIF USR_FNAME EQ "" OR USR_LNAME EQ "" OR USR_SSN EQ "" OR DEPT_ID EQ "" OR USR_GENDER EQ "">
   <h2>Parameters missing</h2>
   <cfabort>
</cfif>

<HTML>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</HEAD>
<!--- the transaction executes as one single unit of work --->
<!--- no other insert operations can execute until this transaction ends --->
<!-- It's recommended to include multiple fields in the select criteria --->
<CFTRANSACTION>
<cflock timeout="30" throwontimeout="Yes" name="addusr">
<CFINSERT datasource="RobCor" Tablename="USER">
<cfquery name="getID" datasource="RobCor" dbtype="ODBC">
select MAX(USR_ID) as UID from USER 
where USER.USR_FNAME = '#form.usr_fname#' AND USER.USR_LNAME = '#form.usr_lname#' AND
      USER.USR_SSN   = '#form.usr_ssn#'   AND USER.DEPT_ID   = '#form.dept_id#'   AND
      USER.USR_GENDER= '#form.usr_gender#'
</cfquery> 
</cflock>
</cftransaction>

<center>
<h1> Add User Results </H1>

<CFOUTPUT>
        The record was added successfully.
		USER ID = #getid.uid#
</CFOUTPUT>

<FORM ACTION="rc-0.cfm" METHOD=POST>
<INPUT TYPE="Submit" VALUE="User Menu">
</FORM>
</center>
</BODY>
</HTML>





