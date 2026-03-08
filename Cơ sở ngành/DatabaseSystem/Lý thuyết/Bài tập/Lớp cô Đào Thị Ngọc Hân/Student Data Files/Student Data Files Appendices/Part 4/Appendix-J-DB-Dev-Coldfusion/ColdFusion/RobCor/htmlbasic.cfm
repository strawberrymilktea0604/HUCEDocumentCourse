<html>

<!-- the tile of this page goes first -->



<head>

<title>Basic HTML</title>

</head>

<!-- The body of the document goes next -->



<body bgcolor="lightblue">



<p><img src="images/Lightbulb.gif" border="0" align="left" alt="lightbulb" WIDTH="106" HEIGHT="121"> <font face="courier"><font color="blue"><big><big><big>Welcome to HTML Basics</big></big></big></p>

</font><!-- A horizontal ruler -->





<hr>

</font><font size="3" face="courier">



<p>HTML tags you should be familiar with:</p>



<p>&nbsp; 



<ul>

  <li>&lt; HTML &gt; and &lt; /HTML &gt; start and end an HTML document</li>

  <li>&lt; HEAD &gt; and &lt; /HEAD &gt; header of your document</li>

  <li>&lt; TITLE &gt; and &lt; /TITLE &gt;&nbsp; defines the title of the page</li>

  <li><p align="left">&lt; BODY BGCOLOR=&quot;color&quot; BACKGROUND=&quot;filename.gif&quot;

    &gt; and &lt; /BODY &gt; <br>

    <br>

    color = blue, gray, white, etc.&nbsp; <br>

    background filename must include the complete path.<br>

    </p>

  </li>

  <li>&lt; FONT FACE=&quot;arial&quot; &gt; </font><font size="3" face="Arial">Arial font</font><font size="3" face="courier"> &lt; /FONT &gt; </li>

  <li>&lt; FONT FACE=&quot;courier&quot; &gt; Courier font &lt; /FONT &gt; </li>

  <li>&lt; SMALL &gt; <small>small <small>smaller </small></small>&lt; /SMALL &gt; </li>

  <li>&lt; b &gt; <b>bold text </b>&lt; /b &gt; </li>

  <li>&lt; u &gt; <u>underline text </u>&lt; /u &gt; </li>

  <li>&lt; i &gt; <i>italicezed text </i>&lt; /i &gt; </li>

  <li>&lt; PRE &gt; Display text as entered, conserving spacing &lt; /PRE &gt; <pre>	This text is indented using the Tab key, also, the letters are spaced

	equally. Notice that the lines are shown exactly as entered. Useful to 

	create columnar outputs, like

		Month	Sales

		Jan	1,000

		Feb	1,200

		Mar	2,200



	 </pre>

  </li>

  <li>Headers : used to display subtitles or section titles <br>

    <h1>&lt; h1 &gt; Header type 1 &lt; /h1 &gt; </h1>

    <h2>&lt; h2 &gt; Header type 2 &lt; /h2 &gt; </h2>

    <h3>&lt; h3 &gt; Header type 3 &lt; /h3 &gt; </h3>

    <h4>&lt; h4 &gt; Header type 4 &lt; /h4 &gt; </h4>

    <h5>&lt; h5 &gt; Header type 5 &lt; /h5 &gt; </h5>

    <h6>&lt; h6 &gt; Header type 6 &lt; /h6 &gt; </h6>

  </li>

  <li>Paragraph: used to create paragraphs that can be aligned. Paragraphs lines are wrapped

    around as needed to fill the margins of the page or display area.Examples:<br>

    <p ALIGN="center">&lt; p align=&quot;center&quot; &gt; This text is centered &lt;/p &gt; </p>

    <p ALIGN="left">&lt; p align=&quot;left&quot; &gt; This text is left aligned &lt;/p &gt; </p>

    <p ALIGN="right">&lt; p align=&quot;right&quot; &gt; This text is right aligned &lt;/p

    &gt; </p>

  </li>

  <li>Hyperlinks to other files (htm, gif, jpg, avi, etc.) Links allow users to click on a

    page text or picture and launch another page. Hyperlinks create the navigational structure

    of the Web. <br>

    Syntax is: &lt; a href=&quot;URL&quot; &gt; Text for link &lt; /a &gt; <br>

    Example: &lt; a href=&quot;http://www.internic.com&quot; &gt; click here to go to Course

    Technology web page &lt; /a &gt; will display as: <br>

    <a href="http://www.course.com">click here to go to Course Technology web page <br>

    </a>You could also link to a ftp site : &lt; a href=&quot;ftp://ftp.microsoft.com&quot;

    &gt; click here to go to Microsoft ftp site &lt; /a &gt; will display as: <br>

    <a href="ftp://ftp.microsoft.com">click here to go to Microsoft ftp site </a><br>

    <br>

  </li>

  <li>&lt; HR &gt; will display an horizontal ruler or line <hr>

  </li>

  <li>&lt; BR &gt; Insert new line or space. <br>

    For example &lt; br &gt; <br>

    <br>

  </li>

  <li>Lists: &lt; ul &gt; and &lt; li &gt; &lt; /ul &gt; for example: <pre>	the following code

	&lt; ul &gt;

		&lt; li &gt;  Item one

		&lt; li &gt;  Item two

		&lt; li &gt;  Item three

	&lt; /ul &gt; 

	



	will list as:

	</pre>

    <ul>

      <li>Item one </li>

      <li>Item two </li>

      <li>Item three </li>

    </ul>

    <p><br>

    </p>

  </li>

  <li>Tables are used to present information in tabular format. The following code:<br>

    <pre>	&lt; table border=&quot;1&quot; cellpadding=&quot;0&quot; cellspacing=&quot;0&quot; width=&quot;100%&quot; &gt;

	&lt; tr &gt;

		&lt; td valign=&quot;top&quot; &gt;

		&lt; p align=center &gt; Row 1, column 1 &lt; /p &gt;

		&lt; /td &gt;

		&lt; td valign=&quot;top&quot; &gt;

		&lt; p align=right &gt; Row 1, column 2 &lt; /p &gt;

		&lt; /td &gt;

	&lt; /tr &gt;

	&lt; tr &gt;

		&lt; td valign=&quot;top&quot; &gt;

		&lt; p &gt; Row 2, column 1 &lt; /p &gt;

		&lt; /td &gt;

		&lt; td valign=&quot;top&quot; &gt;

		&lt; p &gt; Row 2, column 2 &lt; /p &gt;

		&lt; /td &gt;

	&lt; /tr &gt;



	&lt; /table &gt;

	</pre>

    <p><br>

    will display as: </p>

    <table border="1" cellpadding="0" cellspacing="0" width="80%">

      <tr>

        <td valign="top"><p align="center">Row 1, column 1 </td>

        <td valign="middle"><p align="right">Row 1, column 2 </td>

      </tr>

      <tr>

        <td valign="top">Row 2, column 1 </td>

        <td valign="bottom">Row 2, column 2 </td>

      </tr>

    </table>

    <p>&nbsp;</p>

  </li>

</ul>

</font>

<p><center><a href="default.cfm">Return to Main Menu</a></center></p>
</body>

</html>