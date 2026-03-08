<HTML>
<CFQUERY NAME="STATELIST" DATASOURCE="RobCor">
	Select VEN_STATE from VENDOR Order by VEN_STATE
</CFQUERY>
<HEAD>
<TITLE>Rob & Coronel -  ColdFusion Examples</TITLE>
</HEAD>
<BODY BGCOLOR="LIGHTBLUE">
<H1>
<CENTER><B>Dynamic Search Query: Criteria Entry Form</B></CENTER>
</H1>
<FORM ACTION="rc-4b.cfm" METHOD=POST>
<TABLE ALIGN="CENTER" BGCOLOR="Silver">
	<TR>
	<TD ALIGN="right">VEN_CODE</TD>
	<TD> 
	<INPUT TYPE ="text" NAME="VEN_CODE" SIZE="10" MAXLENGTH="10"></TD>
	</TR>
	<TR>
	<TD ALIGN="right">VEN_STATE</TD>
	<TD><SELECT NAME="VEN_STATE" SIZE=1>
		<OPTION SELECTED VALUE="ANY">ANY
		 <CFOUTPUT QUERY="STATELIST">
	     <OPTION VALUE="#STATELIST.VEN_STATE#">#VEN_STATE#
 		 </CFOUTPUT>
    	 </SELECT>
	</TD>
	</TR>
	<TR>
	<TD ALIGN="right" VALIGN="middle">
		<INPUT TYPE="submit" VALUE="Search">
		</FORM>
	</TD>
	<TD ALIGN="right" VALIGN="middle">
		<FORM ACTION="rc-0.cfm" METHOD="post">
			<INPUT TYPE="submit" VALUE="Main Menu ">
		</FORM>
	</TD>
	</TR>
</TABLE>
</BODY>
</HTML>


