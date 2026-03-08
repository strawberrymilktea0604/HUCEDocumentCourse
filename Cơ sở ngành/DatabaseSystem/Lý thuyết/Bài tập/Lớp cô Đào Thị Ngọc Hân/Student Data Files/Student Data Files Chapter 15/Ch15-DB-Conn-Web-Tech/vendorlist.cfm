<HTML>
<HEAD>
<TITLE>Coronel & Morris -  ColdFusion Examples</TITLE>
<CFQUERY NAME="venlist" DATASOURCE="RobCor">
    SELECT * FROM VENDOR ORDER BY VEN_CODE
</CFQUERY>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Simple Query using CFQUERY and CFOUTPUT</B></CENTER>
<CENTER><B>(Vertical Output)</B></CENTER>
</H1>
<BR>
<HR>
<CFOUTPUT>
	Your query returned #venlist.RecordCount# records
</CFOUTPUT>
<CFOUTPUT QUERY="venlist">
<PRE><B>
 VENDOR CODE:       #VEN_CODE#
 VENDOR NAME:       #VEN_NAME#
 CONTACT PERSON:    #VEN_CONTACT_NAME#
 ADDRESS:           #VEN_ADDRESS#
 CITY:              #VEN_CITY#
 STATE:             #VEN_STATE#
 ZIP:               #VEN_ZIP# 
 PHONE:             #VEN_PH# 
 FAX:               #VEN_FAX#
 E-MAIL:            #VEN_EMAIL#
 CUSTOMER ID:       #VEN_CUS_ID#
 SUPPORT ID:        #VEN_SUPPORT_ID#
 SUPPORT PHONE:     #VEN_SUPPORT_PH#
 VENDOR WEB PAGE:   #VEN_WEB_PAGE#
<HR></B></PRE>
</CFOUTPUT>
</FORM>
</BODY>
</HTML>


