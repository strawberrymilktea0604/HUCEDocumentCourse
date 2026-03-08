<html>



<head>

<title>Common CF Errors</title>

</head>



<body bgcolor="lightblue">



<h1 align="center">Common ColdFusion Errors</h1>



<p>These are some of the most common errors when creating and coding HTML and ColdFusion

pages.Use these tips to check for errors in your pages when testing your pages. 



<ol>

  <li>Check that the <font color="#FF0000">page names are properly spelled</font> in your

    code. A misspelled page name in the FORM ACTION tag will generate a page or object not

    found error.</li>

  <li>Check that the <font color="#FF0000">form variable names are properly spelled</font> in

    your code. Remember that ColdFusion database tags will use the primary key value you

    passed from the calling program to do updates and inserts. Make sure you include the

    affected table key field within the calling form. Remember that all INPUT, SELECT and

    BUTTON form fields will be passed to the page called by the ACTION form parameter.</li>

  <li>Check that you refer to the <font color="#FF0000">proper query name</font>. Use unique

    query names. </li>

  <li>Check that the <font color="#FF0000">query (table) field names are properly spelled</font>.Use

    prefixes when two fields have the same name, so ColdFusion can know if you are reffering

    to the form, query or table field. For example: USER.USR_ID = FORM.USR_ID</li>

  <li>Check for <font color="#FF0000">data type mismatches</font> in fields comparison or

    assignments. Make sure you compare text with text, numeric with numeric, etc. </li>

  <li>Check the WHERE clause of SQL statements to make sure you do <font color="#FF0000">proper

    primary key searches</font>. </li>

  <li>Check the <font color="#FF0000">use of the '#' signs</font> when referring to the query

    field or form field values. </li>

  <li>Check the <font color="#FF0000">use of single and double quotes</font>. Use single

    quotes inside double quotes in the SQL expressions or inside the CFCOL TEXT parameter.</li>

  <li>Check the <font color="#FF0000">placement of the &quot;#&quot; signs when using Cold

    Fusion functions</font>. When using functions, the # signs are used outside the function.

    For example: #DateFormat (ORD_DATE)#</li>

  <li>Follow <font color="#FF0000">proper database, field, page naming conventions.</font></li>

</ol>



<p><center><a href="default.cfm">Return to Main Menu</a></center></p>

</body>

</html>