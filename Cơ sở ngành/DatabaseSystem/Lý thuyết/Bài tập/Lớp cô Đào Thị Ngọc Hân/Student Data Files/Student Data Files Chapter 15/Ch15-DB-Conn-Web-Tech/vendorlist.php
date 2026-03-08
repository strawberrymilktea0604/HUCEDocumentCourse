<HTML>
<HEAD>
<TITLE>Coronel & Morris -  PHP Example</TITLE>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1><CENTER><B>Simple Query using PHP and ODBC functions</B></CENTER>
<CENTER><B>(Vertical Output)</B></CENTER></H1>
<BR>
<HR>
<?php
$dbc = odbc_connect("RobCor","","");
$sql = "SELECT * FROM VENDOR ORDER BY VEN_CODE";
$rs  = odbc_exec( $dbc, $sql );

while (odbc_fetch_row( $rs ))
{
$VEN_CODE         = odbc_result($rs,"VEN_CODE");
$VEN_NAME         = odbc_result($rs,"VEN_NAME");
$VEN_CONTACT_NAME = odbc_result($rs,"VEN_CONTACT_NAME");
$VEN_ADDRESS      = odbc_result($rs,"VEN_ADDRESS");
$VEN_CITY         = odbc_result($rs,"VEN_CITY");
$VEN_STATE        = odbc_result($rs,"VEN_STATE");
$VEN_ZIP          = odbc_result($rs,"VEN_ZIP"); 
$VEN_PH           = odbc_result($rs,"VEN_PH"); 
$VEN_FAX          = odbc_result($rs,"VEN_FAX");
$VEN_EMAIL        = odbc_result($rs,"VEN_EMAIL");
$VEN_CUS_ID       = odbc_result($rs,"VEN_CUS_ID");
$VEN_SUPPORT_ID   = odbc_result($rs,"VEN_SUPPORT_ID");
$VEN_SUPPORT_PH   = odbc_result($rs,"VEN_SUPPORT_PH");
$VEN_WEB_PAGE     = odbc_result($rs,"VEN_WEB_PAGE");
 
echo "<BR>";
echo "VENDOR CODE:    ". $VEN_CODE . "<BR>";
echo "VENDOR NAME:    ". $VEN_NAME . "<BR>";
echo "CONTACT PERSON: ". $VEN_CONTACT_NAME . "<BR>";
echo "ADDRESS:        ". $VEN_ADDRESS . "<BR>";
echo "CITY:           ". $VEN_CITY . "<BR>";
echo "STATE:          ". $VEN_STATE . "<BR>";
echo "ZIP:            ". $VEN_ZIP . "<BR>"; 
echo "PHONE:          ". $VEN_PH . "<BR>"; 
echo "FAX:            ". $VEN_FAX . "<BR>";
echo "E-MAIL:         ". $VEN_EMAIL . "<BR>";
echo "CUSTOMER ID:    ". $VEN_CUS_ID . "<BR>";
echo "SUPPORT ID:     ". $VEN_SUPPORT_ID . "<BR>";
echo "SUPPORT PHONE:  ". $VEN_SUPPORT_PH . "<BR>";
echo "VENDOR WEB PAGE:". $VEN_WEB_PAGE . "<BR>";
echo "<HR>";
}
odbc_close($dbc);
?>
</BODY>
</HTML>