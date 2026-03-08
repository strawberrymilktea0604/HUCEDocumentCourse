<HTML>
<HEAD>
<TITLE>Orders For A Given Year</TITLE>

<!--webbot bot="HTMLMarkup" StartSpan -->
<CFQUERY NAME="yearlist" DATASOURCE="RobCor" DBTYPE="ODBC">
    SELECT DISTINCT YEAR(ORD_DATE) AS WYEAR FROM ORDERS
</CFQUERY>
<!--webbot BOT="HTMLMarkup" endspan --> 

</HEAD>
<BODY BGCOLOR="#FFFFFF" TEXT="#000000" LINK="#0000FF" VLINK="#006699" ALINK="#000000">
<H1>
<!--mstheme-->
<FONT FACE="times new roman, times" COLOR="#006666">
<STRONG>Orders For A Given Year</STRONG> 
<!--mstheme-->
</FONT>
</H1>

<!--msthemeseparator-->
<HR>
<P>
<!--webbot bot="HTMLMarkup" StartSpan -->
<CFFORM ACTION="cf-ordyear2.cfm" METHOD="POST" ENABLECAB="Yes">
<table nowrap bgcolor="#008080">
<tr>
    <TD><B><U>Year: </U></B>
    <CFINPUT TYPE="Text"
        NAME="year"
        VALUE="#Year(Now())#"
        MESSAGE="Enter Year"
        VALIDATE="integer"
        REQUIRED="No"
        SIZE="4"
        MAXLENGTH="4">
        <INPUT TYPE="Submit" VALUE="Search">
        <INPUT TYPE="reset">
    </TD>
</TR>
</TABLE>
</CFFORM>

<!--- Second form uses a select box to pick the year --->
<BR><HR><BR>
<CFFORM ACTION="cf-ordyear2.cfm" METHOD="POST" ENABLECAB="Yes">
<table nowrap bgcolor="#008080">
<TR>
    <TD><B><U>Year: </U></B>
    <select name="year" size="1">
        <option vallue="">----
    <cfoutput query="yearlist">
        <option>#wyear#
    </cfoutput>
    </select>
    <INPUT TYPE="Submit" VALUE="Search">
    <INPUT TYPE="reset">
    </TD>
</TR>
</TABLE>
</CFFORM>
<!--webbot BOT="HTMLMarkup" endspan -->
<br><hr><br>
Displaying data about the query "yearlist":<BR>
<b><CFOUTPUT>
    Recordcount: #yearlist.recordcount#<BR>
    Column list: #yearlist.columnlist#
</CFOUTPUT></b>
</P>
<!--mstheme-->
</BODY>
</HTML>

