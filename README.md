Rom 2.4b6 with 8bit colors ------<br/>
<br/>
Color codes are defined in color.h not to make an unreadable merc.h file.<br/>
<br/>
Predefined colors are common web colors with names. You can find the<br/>
complete list from:<br/>
https://www.w3schools.com/colors/colors_groups.asp<br/>
<br/>
Colors are defined with RGB codes like (number,number,number).<br/>
Every number has a range from 0 to 255.<br/>
<br/>
RGB(a,b,c) macro convert the RGB code to a string starting with an escape<br/>
character and a value that defined 8bit color code. I didn't prefer<br/>
to defined the colors with a non-readable escape code. RGB codes make it more<br/>
readable and also easy to add new values.<br/>
<br/>
Color is only used in do_who() function in act_info.c file to demonstrate the<br/>
usage.<br/>
<br/>
A sample screenshot of who command output can be find media folder.<br/>
<br/>
![Alt text](/media/who_command_output.png?raw=true "who command output")<br/>
<br/>
The code is compiled on:<br/>
- CentOS 7.8.2003<br/>
- gcc (GCC) 4.8.5 20150623<br/>
<br/>
The client is Mudlet 4.9.1<br/>
https://www.mudlet.org/<br/>
