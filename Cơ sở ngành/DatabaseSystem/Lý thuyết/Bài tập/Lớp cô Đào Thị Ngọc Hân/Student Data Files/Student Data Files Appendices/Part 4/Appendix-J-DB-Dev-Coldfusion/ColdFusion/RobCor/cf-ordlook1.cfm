<html>
<head>
<title>Orders Between Dates</title>

<!--webbot bot="HTMLMarkup" StartSpan -->
<!-- Sunday is 1 -->
<CFSET BeginDate = Now()-(365*7)>
<CFSET EndDate = Now()+30>

<!--webbot BOT="HTMLMarkup" endspan --> 
</head>


<body bgcolor="#FFFFFF" text="#000000" link="#0000FF" vlink="#006699" alink="#000000">

<h1>
<!--mstheme-->
<font face="times new roman, times" color="#006666">
<strong>Orders Between Dates</strong> 
<!--mstheme-->
</font>
</h1>

<!--msthemeseparator-->
<hr>
<p>
<!--webbot bot="HTMLMarkup" StartSpan -->
<cfform action="cf-ordlook2.cfm" method="POST" enablecab="No">

<table bgcolor="tan">
<TR>
<td nowrap>
<b><u>Date of Orders</u></b>&nbsp;&nbsp;&nbsp;&nbsp
</TD>
<td nowrap>
<b>From:</b><cfinput type="Text"
       name="BeginDate"
       value="#DateFormat(BeginDate, 'mm/dd/yyy')#"
       align="LEFT"
       message="Enter Begin Date"
       validate="date"
       required="No"
       size="14"
       maxlength="14">
</td>
<td nowrap>
<b>To:</b><cfinput type="Text"
       name="EndDate"
	   value="#DateFormat(EndDate, 'mm/dd/yyy')#"
       align="LEFT"
       message="Enter End Date"
       validate="date"
       required="No"
       size="14"
       maxlength="14">
</td>
</tr>
</TABLE>
<input type="Submit" name="Search" value="Search">
<input type="reset">
</cfform>

<!--webbot BOT="HTMLMarkup" endspan -->
</p>

<!--mstheme-->

</body>
</html>

