<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<html>
<head>
	<title>Rob & Coronel -  Cold Fusion Problems</title>
    
<CFUPDATE datasource="RobCor" Tablename="VENDOR">    
</head>

<body>
<center>
<H1>Edit Vendor Results</H1>
</center>
<CFOUTPUT>
<TABLE><TD><B><BIG>Vendor Information</BIG></B></TD></tr>
<TR>    <TD><B>Vendor Code:</B>#VEN_CODE#
        <TD><B>Name:</B>#VEN_NAME#</TD> </tr>
<TR>    <TD><B>Contact Person:</b>#VEN_CONTACT_NAME#</TD> 
        <TD><B>Vendor Address:</B>#VEN_ADDRESS#</TD>
        <TD><B>City:</B>#VEN_CITY#</TD></TR>
<TR>    <TD><B>State:</b>#VEN_STATE#</TD>
        <TD><B>Zip:</b>#VEN_ZIP#</TD>
        <TD><B>Phone:</b>#VEN_PH#</TD></TR>
<TR>    <TD><B>Fax:</b>#VEN_FAX#</TD>
        <TD><B>E-Mail:</b>#VEN_EMAIL#</TD>
        <TD><B>Customer ID:</b>#VEN_CUS_ID#</TD></TR>  
<TR>    <TD><B>Support ID:</b>#VEN_SUPPORT_ID#</TD>
        <TD><B>Phone:</b>#VEN_SUPPORT_PH#</TD>
        <TD><B>Web Page:</b>#VEN_WEB_PAGE#</TD></TR>
</CFOUTPUT>   
<TR><TD>

<!-- FORM ACTION="rc-V0.cfm" method="post">
        <input type="submit" value="Vendor Menu">
</FORM -->
  </td></tr>
  </TABLE></P>
</body>
</html>




