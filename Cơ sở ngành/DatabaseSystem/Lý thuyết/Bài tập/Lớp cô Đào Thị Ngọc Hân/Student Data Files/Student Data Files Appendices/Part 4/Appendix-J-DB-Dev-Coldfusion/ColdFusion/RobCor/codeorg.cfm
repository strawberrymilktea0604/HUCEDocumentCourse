<html>

<head>
<title>Code Organization</title>
</head>

<body bgcolor="CYAN">

<h1 align="center">Code Organization</h1>

<p>Code organization is critical to write simple to maintain/debug programs.
Here are some of the most common practices to develop good code:
<ul>
  <li>Organize the layout of your pages:<ul>
  <li><b>Header </b> area: use an standard header</li>
  <li><b>Menu</b> Bar (horizontal and left side navigation bars)</li>
  <li><b>Footer</b> area</li>
</ul>
  </li>
  <li>Write code in <b>modules</b>. Identifying pieces of code that can be 
  reused.</li>
  <li><b>Comment</b> your code. Each section of code should have a description.</li>
  <li>Use proper <b>indentation</b> in your code.</li>
  <li>When writing a program divide the program on:
    <ul>
      <li><b>Documentation - </b>Program description</li>
      <li><b>Variable</b> verification, definition and initialization</li>
      <li><b>Query </b> execution</li>
      <li><b>Header  </b>section (call to a template)</li>
      <li><b>Output</b> presentation - generally screen output and user interface</li>
      <li><b>Footer</b> section (call to a template)</li>
    </ul>
  </li>
  <li>Always <b>scope</b> your variables. For example: #form.var1# or #cig.http_referer#.</li>
  <li>Do not use <b>pound signs</b> (#) in: CFSET, CFIF, and ColdFusion 
  functions.</li>
  <li>Use pound signs (#) in CFOUTPUT and CFQUERY.</li>
  <li>Use CFSWITCH instead of CFIF (is faster).</li>
  <li>Restrict your CFQUERY statements return sets whenever possible (use the 
  MAXROWS attribute).</li>
  <li>Use a file <b>naming standard</b>: lowercase, 11 characters long, no
    special characters, no spaces, semantic names.</li>
</ul>
<center><a href="default.cfm">Return to Main Menu</a></center>
</body>
</html>