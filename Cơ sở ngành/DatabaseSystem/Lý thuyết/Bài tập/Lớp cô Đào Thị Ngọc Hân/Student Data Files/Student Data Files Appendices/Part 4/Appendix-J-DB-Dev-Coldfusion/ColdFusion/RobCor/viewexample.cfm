<CFSET thistag="">
<HTML>
<BODY bgcolor="silver">
<CFFILE ACTION="READ" FILE="#GetDirectoryFromPath(GetTemplatePath())##LCase(tagname)#.cfm" VARIABLE="thistag">
<CFOUTPUT>
<H2>#tagname#.cfm Sample code</h2>
<HR>
#HtmlCodeFormat("#thistag#")#
</BODY>
</CFOUTPUT>
</HTML>
