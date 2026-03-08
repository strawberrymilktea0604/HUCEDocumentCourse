<CFPARAM name="year" default="0">
<html>
<head>
<title>Orders For A Given Year</title>

<!--webbot bot="HTMLMarkup" StartSpan -->

<!--- Search Reservations --->
<CFQUERY NAME="ORDQry" DATASOURCE="RobCor">
SELECT  ORDERS.ORD_ID,ORD_DATE,VENDOR.VEN_CODE,USR_LNAME,ORD_DESCRIP,ORD_SHIP_COST,ORD_TOT_COST
FROM    ORDERS, VENDOR, USER
WHERE   ORDERS.USER_ID = USER.USR_ID AND
        ORDERS.VEN_CODE = VENDOR.VEN_CODE
<CFIF #form.year# GT 0>
		AND YEAR(ORD_DATE) = #form.year#
</CFIF>
ORDER BY ORDERS.ORD_DATE, ORDERS.VEN_CODE
</CFQUERY>
<!--webbot BOT="HTMLMarkup" endspan --> 
</head>


<body bgcolor="#FFFFFF" text="#000000" link="#0000FF" vlink="#006699" alink="#000000">

<h1>
<!--mstheme-->
<font face="times new roman, times" color="#006666">
<strong>Orders</strong> 
<!--mstheme-->
</font>
</h1>

<!--msthemeseparator-->
<hr>
<p><!--webbot bot="HTMLMarkup" StartSpan -->


<CFOUTPUT>
<b>Search Criteria:</b><BR>
<b>Order Year:</b>#form.year# &nbsp;&nbsp;&nbsp
</CFOUTPUT>

<cfif #ORDQry.Recordcount# IS 0 >
	<cfoutput>
	There are no Orders that match your criteria <BR>
	</cfoutput>
<cfelse>
	<cfoutput>
	There are #ORDQry.RecordCount# orders that match your criteria
	<!--Font face="courier"><font size=1-->	
	</cfoutput>
	<cftable query="ORDQry" colspacing="1" colheaders headerlines="1" htmltable border>
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
<!--webbot BOT="HTMLMarkup" endspan --> </p>
<!--mstheme-->
</font>
<center><a href="rc-0.cfm">Return to Menu</a></center>
</body>
</html>






