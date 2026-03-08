<html>
<head>
<title>Orders for Current Week</title>

<!--- This sample report list all orders within the "current" week --->
<!--- The week for this report goes from the most recent Monday to the next Monday --->
<!--- This example demonstrates the use of :    --->
<!---    CFSET   to define variables --->
<!---    NOW() function to get the date --->
<!---    DayOfWeek() function to get the number of the day of the week from a date --->
<!---    Date arithmetic to add and substract days to a date field --->
<!---    CreateODBCDate() function to create ODBC complaint dates used in SQL statements --->

<!-- the webbot tag is used if using FrontPage98 -->
<!-- webbot bot="HTMLMarkup" StartSpan -->

<!--- CFSET tag will define and give a value to a new variable --->
<!--- Now() function returns today's date --->
<CFSET QBegDate = Now()>

<!--- DayOfWeek(datefield) function returns the day of the week as a number --->
<!-- Sunday is 1 -->
<CFSET DOW = DayOfWeek(#QBegDate#)>

<!--- Data arithmetic. You can add or substract days to a date field --->
<cfif #DOW# IS 1>
	    <CFSET QBegDate = (Now() - 6)>
<cfelseif #DOW# IS 3>
		<CFSET QBegDate = (Now() - 1)>
<cfelseif #DOW# IS 4>
		<CFSET QBegDate = (Now() - 2)>
<cfelseif #DOW# IS 5>
		<CFSET QBegDate = (Now() - 3)>
<cfelseif #DOW# IS 6>
		<CFSET QBegDate = (Now() - 4)>
<cfelseif #DOW# IS 7>
		<CFSET QBegDate = (Now() - 5)>
</cfif>
<CFSET QEndDate = #QBegDate# + 7>

<!--- CreateODBCDate(datefield) returns a ODBC complaint date to be used in SQL queries --->
<CFSET D1 = CreateODBCDate(DateFormat(#QBegDate#, 'yyyy-mm-dd'))>
<CFSET D2 = CreateODBCDate(DateFormat(#QEndDate#, 'yyyy-mm-dd'))>

<!--- Mulitple join query with date ranges --->
<!--- Requires you to name each field if there are two tables with a common field name --->
<!--- For example in this query: VEN_CODE, ORD_ID and TY_GROUP are repeated field names --->
<CFQUERY NAME="ORDERSToday" DATASOURCE="RobCor">
SELECT  ORDERS.ORD_ID,ORD_DATE,VENDOR.VEN_CODE,USR_LNAME,ORD_DESCRIP,ORD_SHIP_COST,ORD_TOT_COST
FROM    ORDERS, ORDER_LINE, VENDOR, USER, INVTYPE
WHERE   ORDERS.ORD_DATE >= #D1# AND ORDERS.ORD_DATE <= #D2# AND
		ORDERS.ORD_ID = ORDER_LINE.ORD_ID AND
        ORDER_LINE.TY_GROUP = INVTYPE.TY_GROUP AND
        ORDERS.USER_ID = USER.USR_ID AND
        ORDERS.VEN_CODE = VENDOR.VEN_CODE
ORDER BY ORDERS.ORD_DATE, ORDERS.VEN_CODE
</CFQUERY>
<!--webbot BOT="HTMLMarkup" endspan --> 
</head>


<body bgcolor="#FFFFFF" text="#000000" link="#0000FF" vlink="#006699" alink="#000000">

<h1>
<!--mstheme-->
<font face="times new roman, times" color="#006666">
<strong>Report Of Orders For This Week</strong> 
<!--mstheme-->
</font>
</h1>

<!--msthemeseparator-->
<hr>
<p>
<!--webbot bot="HTMLMarkup" StartSpan -->

<cfif #ORDERSToday.Recordcount# IS 0 >
	<cfoutput>
	There are no Orders from #DateFormat(QBegDate, 'ddd, mmmm dd, yyyy')# to #DateFormat(QEndDate, 'ddd, mmmm dd, yyyy')# 
	</cfoutput>
<cfelse>
	<cfoutput>
	There are #ORDERSToday.RecordCount# orders for #DateFormat(QBegDate, 'ddd, mmmm dd, yyyy')# to #DateFormat(QEndDate, 'ddd, mmmm dd, yyyy')#  
	<!--Font face="courier"><font size=1-->	
	</cfoutput>
	<cftable query="ORDERSToday" colspacing="1" colheaders headerlines="1" htmltable border>
	<cfcol text="<small>#ORD_ID#</small>" header="ID" align="LEFT">
	<cfcol text="<small>#DateFormat('#ORD_DATE#','ddd, mmmm dd, yyyy')#</small>" header="Date" align="LEFT">
	<cfcol text="<small>#VEN_CODE#</small>" header="Vendor"align="LEFT">
	<cfcol text="<small>#USR_LNAME#</small>" header="User"align="LEFT">
	<cfcol text="<small>#ORD_DESCRIP#</small>" header="Description"align="LEFT">
	<cfcol text="<small>#DollarFormat(ORD_SHIP_COST)#</small>" header="Ship Cost"  align="RIGHT">
   	<cfcol text="<small>#DollarFormat(ORD_TOT_COST)#</small>" header="Total Cost" align="RIGHT">
	</cftable>
	<!--/font-->
</cfif>
<!--webbot BOT="HTMLMarkup" endspan -->
</p>
<!--mstheme-->
</font>
<center><a href="rc-0.cfm">Return to Menu</a></center>
</body>
</html>
