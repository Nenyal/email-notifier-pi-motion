# C Program to send e-mail when motion detected RaspberryPI
C Program to send e-mail when motion is detected with RaspberryPI PIR sensor.<br/>
[Source for PIR sensor](https://projects.raspberrypi.org/en/projects/physical-computing/11)

## Steps
1- Download and install all libraries except libquickmail.<br/>
2- Extract the tar file of libquickmail. Terminal commands, respectively, to install the libquickmail library: ./configure, make, sudo su, make install, exit.<br/>
3- Copy the project.c script into this folder, where you installed libquickmail. (../../libquickmail-0.1.29)<br/>
4- Changes in the script: enter the addresses to send and receive e-mail, SMTP user information and the wiringPi pin number to which the PIR sensor is connected to the project.c script.<br/>
5- To compile the project file gcc project.c -o project -lwiringPi -llibquickmail<br/>
6- Run project: ./project

## Possible Mistakes and Errors
### 1- Google SMTP
If you are going to use Google SMTP, you will need to get an application password to the sender email address (this is because as of 05/31/2022 Google has irreversibly blocked access to your account from untrusted sources). If you enter this password in the SMTPPASS section, the problem will be solved. [Sign in using app passwords Google Help](https://support.google.com/mail/answer/185833?hl=en-GB)

### 2- Shared Library Error 
In terminal:<br/>
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib<br/>
export LD_LIBRARY_PATH

### 3- Continuous Email Sending
One of the potentiometers on the PIR sensor adjusts the sensitivity and the other the delay. Make sure these potentiometers are in the correct position. In addition, the required delay time can be adjusted by increasing the parameter of the delay() function in the project.c script.

### 4- WiringPi Error
Check the pin number in the script. [Source for WiringPi pins](http://wiringpi.com/pins/)

## Libraries: 
1- [libquickmail](https://sourceforge.net/projects/libquickmail/)<br/>
2- [Wiring Pi](http://wiringpi.com/download-and-install/)<br/>
3- [libcurl](https://curl.se/libcurl/)<br/>
