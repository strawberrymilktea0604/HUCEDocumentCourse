<!--- application.cfm CF Application Framework --->
<!--- Start the Application and Session framework 
session timeout is set to 2 minutes
if user does not request any page in 2 minutes, the session is lost --->
<cfapplication name="DemoAppv2" Sessionmanagement="YES" sessiontimeout=" #CreateTimeSpan(0, 0, 2, 0)# ">
<!--- Set session variables 
session.webhome 
    used to create the home page for the application. 
    each group must add the rest of the path to the 
    frist page of the application (login)
session.dsn
    data source name used for all database access.
    each user must change it to match the dsn used in the 
    project, i.e. lmsv2
session.auname 
    name of user or group who developed application
session.curoption 
    name of the current menu option or process    
    it must be set before including the header.cfm page
session.validuser
    valid user contains the user id of a valid user.
    this variable is ONLY defined in the login pages.
--->

<CFSET session.apptitle     = "DemoApp V2">
<CFSET session.auname       = "Carlos Coronel">
<CFIF NOT (IsDefined("session.curoption"))>
   <CFSET session.curoption = "">
</cfif>
<CFSET session.dsn          = "RobCor">
<CFSET session.hostip       = "#cgi.http_host#">
<CFSET session.webhome      = "http://#cgi.http_host#">

<!--- Set Login Id variables 
If session.validuser is not defined or blank, means nobody has login yet.
user is redirected to login page, unless the user is already in the login process pages
--->

<!--- get name of current page --->
<CFSET wcurfile= #GetFileFromPath(cgi.script_name)#> 

<CFIF NOT (IsDefined("session.validuser"))>
    <cfif NOT ((#wcurfile# EQ "login.cfm") OR (#wcurfile# EQ "login2.cfm"))>
        <cflocation url="login.cfm">
    </cfif>   
<CFELSE>
    <cfif session.validuser EQ "">
        <cfif NOT ((#wcurfile# EQ "login.cfm") OR (#wcurfile# EQ "login2.cfm"))>
            <cflocation url="login.cfm">
        </cfif>   
    </cfif>
</CFIF>

