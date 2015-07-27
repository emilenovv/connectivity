# Connectivity Introductory Project

One server and two client applications that communicate via dedicated shared memory.

Server can perform basic operations:
<li>math operations with 32-bit signed integers<br>
  &nbsp; &nbsp; &nbsp;i.	add 2 numbers<br>
  &nbsp;&nbsp; &nbsp;ii.	subtract 2 numbers<br>
  &nbsp;&nbsp; &nbsp;iii.	multiply 2 numbers<br>
  &nbsp;&nbsp; &nbsp;iv.	divide 2 numbers<br><br>
<li>	string operations (strings with length between 1 and 16 characters)<br>
  &nbsp; &nbsp; &nbsp;&nbsp; &nbsp;i.	concatenate 2 strings<br>
  &nbsp; &nbsp; &nbsp; &nbsp;ii.	search for substring within a string (return the position of the substring)<br>

To simulate delay in the server delay type ```
make all OPT=-DDELAY TIME=-DDELAY_TIME=(number of seconds)```
