<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<!--- Login verification page --->
<!--- 
Here is where we would normally read the userid and password from a 
database and compare it to the one entered by the user. If they match we
continue to the menu page, otherwise we go back to the login page.
In this case we go directly to a main menu.
--->
<!---Set session.validuser to the userid of logged user 
    This will later be used to timestamp all database access
--->
<cfset session.validuser = "#form.wloginname# - #cgi.remote_addr#">
<cflocation url="menu.cfm" addtoken="No">





