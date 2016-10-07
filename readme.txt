IMPORTANT SETUP INSTRUCTIONS

Before you can use "setport" as a Linux command with the portsetter program, or run the setport test (see below), then you must first do the following:

1) Copy the provided workspace folder with all files inside into your /home/ubuntu directory folder.

2) If you do not have a bin file in your home directory then create one using the following command:
   mkdir ~/bin

3) Update the PATH variable using the following command:
   export PATH=$PATH:$HOME/bin

4) Copy the provided setport file into the bin folder.

5) Type the following command to give the setport script executable permissions: 
   chmod +x ~/bin/setport

6) You can now use the setport command. For more information, type the following in your command line:
   setport -h


HOW TO RUN THE SETPORT TEST

1) Make sure the program has been set up correctly as described above. You will know everything is set up correctly if you can use the Linux "setport" command without any problems.

2) Copy and paste the following into your Linux command line and press Enter:
   ~/workspace/portsetter/testsetport.cpp.o
   