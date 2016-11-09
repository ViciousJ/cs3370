IMPORTANT SETUP INSTRUCTIONS

Before you can use "setport" as a Linux command with the portsetter program, or run the setport test (see below), then you must first do the following:

1) Create the following folder filepath in your Cloud9 system: ~/workspace/portsetter

2) Copy all the provided files into the "portsetter" folder.

3) If you do not have a bin file in your home directory then create one using the following command:
   mkdir ~/bin

4) Update the PATH variable using the following command:
   export PATH=$PATH:$HOME/bin

5) Copy the file named "setport" into the bin folder by using the following command:
   mv ~/workspace/portsetter/setport ~/bin

6) Type the following command to give the setport script executable permissions: 
   chmod +x ~/bin/setport
   
7) Because this program uses regEx code, IT WILL NOT WORK IN Cloud9 UNLESS IT IS COMPILED WITH THE INCLUDED MAKEFILE.
   Do the following steps now to compile the code:
   A) Enter the portsetter folder by typing the following command:
      cd ~/workspace/portsetter
   B) Now simply type "make" (without the quotes) in the command line and press Enter.

8) Success! You can now use the setport command. For more information, type the following in your command line:
   setport -h


HOW TO RUN THE SETPORT TEST

1) Make sure the program has been set up correctly as described above. You will know everything is set up correctly if you can use the Linux "setport" command without any problems.

2) In the "test_files" folder, open "testsetport.cpp"

3) Press the "Run" button with the green arrow to compile and run the test program. (You do not need to use a Makefile to compile the test program.)

EDITS

Line 56, 83, 107 with comment /*----Part of code for CO5----*/
I added several test cases to the testing program (formatted like the others) but had to comment them out as
the testing program couldn't handle them. It did handle one however that isn't commented out. They have to be run
manually.
   