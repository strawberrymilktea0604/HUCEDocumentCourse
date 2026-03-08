<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<cfquery name="venlist" datasource="RobCor" maxrows=4 dbtype="ODBC">
select * from vendor
</cfquery>
<cfmail query="venlist" 
to="#form.wemail#" 
from="teacher@mtsu.edu"
subject="Latest list of vendors ">

Here is the latest list of vendors. Please make sure you follow up with them
regarding our new check cashing procedures. 

<cfoutput>
#ljustify(ven_code,10)# #ljustify(ven_name,25)# 
</cfoutput>

Thanks and keep up your good work
</cfmail>

<!--- HTML --->

<html>
<head>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</head>
<body>
<h3>Thanks</h3>
The email has been sent
<br>
<center><a href="rc-0.cfm">Return to Menu</a></center>
</body>
</html>



