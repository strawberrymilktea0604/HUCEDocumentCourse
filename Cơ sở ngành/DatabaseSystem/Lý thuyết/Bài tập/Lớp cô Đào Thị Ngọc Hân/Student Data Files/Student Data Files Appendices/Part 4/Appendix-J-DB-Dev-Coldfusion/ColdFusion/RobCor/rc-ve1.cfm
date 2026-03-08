<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<cfif #form.action#EQ"delete">
<cflocation url="rc-vd1.cfm?ven_code=#form.VEN_CODE#" addtoken="No">
</cfif>
<CFQUERY datasource="RobCor" name="VenEdit">
SELECT * FROM VENDOR WHERE (VENDOR.VEN_CODE='#form.VEN_CODE#')
</CFQUERY>

<html>
<head>
	<title>Rob & Coronel -  Cold Fusion Problems</title>
</head>

<body>
<center><H1>Edit Vendor</h1></center>
<FORM action="rc-ve2.cfm" method="post">
<TABLE ALIGN="CENTER" BGCOLOR="Silver" BORDERCOLOR="Blue">
<cfoutput Query="VenEdit">
  <INPUT type="hidden" name="VEN_CODE" VALUE="#VenEdit.VEN_CODE#">
<TR bgcolor="yellow" valign="top">
   		<TD colspan="6" ><font face="" size="+1" color="Black">Vendor Information</font></td></tr>
<TR>
		<TD align="right" nowrap valign="bottom">Vendor Name:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_NAME" VALUE="#VEN_NAME#" MAXLENGTH=20></TD>
        <TD align="right" nowrap valign="bottom">Contact Person:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_CONTACT_NAME" VALUE="#VEN_CONTACT_NAME#" MAXLENGTH=20></TD>
        <TD align="right" nowrap valign="bottom">Vendor Address:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_ADDRESS" VALUE="#VEN_ADDRESS#" MAXLENGTH=20></TD></TR>
 <TR>   <TD align="right" nowrap valign="bottom">City:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_CITY" VALUE="#VEN_CITY#" MAXLENGTH=20></TD>
        <TD align="right" nowrap valign="bottom">State:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_STATE" VALUE="#VEN_STATE#" MAXLENGTH=2></TD>
        <TD align="right" nowrap valign="bottom">Zip:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_ZIP" VALUE="#VEN_ZIP#" MAXLENGTH=5></TD></TR>
<TR>    <TD align="right" nowrap valign="bottom">Phone:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_PH" VALUE="#VEN_PH#" MAXLENGTH=12></TD>
        <TD align="right" nowrap valign="bottom">Fax:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_FAX" VALUE="#VEN_FAX#" MAXLENGTH=12></TD>
        <TD align="right" nowrap valign="bottom">E-Mail:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_EMAIL" VALUE="#VEN_EMAIL#" MAXLENGTH=25></TD></TR>
 <TR>   <TD align="right" nowrap valign="bottom">Customer ID:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_CUS_ID" VALUE="#VEN_CUS_ID#" MAXLENGTH=20></TD>
        <TD align="right" nowrap valign="bottom">Support ID:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_SUPPORT_ID" VALUE="#VEN_SUPPORT_ID#" MAXLENGTH=20></TD>
        <TD align="right" nowrap valign="bottom">Support Phone:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_SUPPORT_PH" VALUE="#VEN_SUPPORT_PH#" MAXLENGTH=20></TD></TR>
 <TR>  <TD align="right" nowrap valign="bottom">Web Page:</TD>
        <TD valign="bottom"><INPUT TYPE="text" NAME="VEN_WEB_PAGE" VALUE="#VEN_WEB_PAGE#" MAXLENGTH=25></TD></tr></cfoutput>
 <TR>   <TD colspan="2" valingn="bottom">  <INPUT type="submit" value=" Edit "></FORM></td>      
		<TD valing="top"> <!--FORM ACTION="rc-v0.cfm" METHOD="link">
			   <INPUT TYPE="submit" VALUE="Vendor Menu">
			 </form --></td>
		</tr> 
</TABLE>


</body>
</html>





