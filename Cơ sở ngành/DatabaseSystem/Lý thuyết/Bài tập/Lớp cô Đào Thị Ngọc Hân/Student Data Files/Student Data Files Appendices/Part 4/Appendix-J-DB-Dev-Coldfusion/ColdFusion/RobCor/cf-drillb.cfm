<HTML>
<CFQUERY NAME="SearchVendor" DATASOURCE="RobCor">
	SELECT VEN_CODE, VEN_NAME, VEN_CONTACT_NAME
	FROM VENDOR
	WHERE 0=0
    <CFIF #FORM.VEN_CODE# IS NOT "">
		AND VENDOR.VEN_CODE LIKE '%#FORM.VEN_CODE#%'
	</CFIF>	
    <CFIF #FORM.VEN_STATE# IS NOT "ANY">
        AND VENDOR.VEN_STATE LIKE '%#FORM.VEN_STATE#%'
	</CFIF>
    ORDER BY VEN_CODE
</CFQUERY>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Drill Down Vendor Search Results</B></CENTER>
</H1>
<BR>

<table>
<tr>
<td><B>Vendor Code</B></td>
<td><B>Vendor Name</B></td>
<td><B>Contact Name</B></td>
<td><B>Edit</B></td>
</tr>
<CFOUTPUT QUERY="SearchVendor">
<tr> 
<TD>#ven_code#</td>
<TD>#ven_name#</td>
<TD>#ven_contact_name#</td>
<td align="CENTER" valign="BASELINE">
<form action="rc-ve1.cfm" method="POST" enablecab="Yes">
<input type="Hidden" name="VEN_CODE" value="#VEN_CODE#">
<input type="Submit" name="Action" value="Edit">
</form>
</td>
</tr>
</cfoutput>
</table>

<CFIF #SEARCHVENDOR.RECORDCOUNT# IS 0>
  	<H2>No records were found matching your criteria </H2>
<CFELSE>
	<CFOUTPUT>Your seach returned #SearchVendor.RecordCount# record(s).</CFOUTPUT>
</CFIF>
<FORM ACTION="rc-0.cfm" METHOD="post">
	<INPUT TYPE="submit" VALUE="Main Menu ">
</FORM>
</BODY>
</HTML>


