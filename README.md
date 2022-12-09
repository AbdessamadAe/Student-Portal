# Student-Portal
You were hired to write a program that manages the student’s portal account 
To enter the portal the student must login
Below is the main menu that should be displayed first to the student with a detailed description of 
what each option does:
1) Log in: 
The student must enter the ID and password. Your program must check if the student exists (you 
will be provided with an input file (“input.txt”) that contains 3 students to start with).A student 
exists if the ID and the password entered match the ones in the file. If by mistake, the student 
mistyped the password by entering the same character twice consecutively, you must ask him the 
secret question which is available in the file and check the answer with the one provided too. 
Also, if the ID entered does not match one of those available in the file, you should direct the 
student to the enrollment menu. 
2)Enroll: 
The student is prompted to enter all the information below: 
First Name 
Last Name 
Email 
Date of Birth 
Gender 
City 
Phone Number 
These information are then stored in a file enroll. 
When entering the information, if the student enters an existing email available in the input.txt 
file, he will be informed that he is already enrolled in the university and will be asked if s-he 
wishes to enter another email or login to his/her account. 
3) Exit: 
When the student decides to exit the program 2 output file are created. One enroll.txt file that 
contains all of the information of the people who decided to enroll. One output.txt file, it is 
similar to the input file except that it contains the updated information (the updated password, 
updated phone number, etc…) and it is alphabetically sorted by ID. 
Once signed in, your program must interact with the student in a loop that allows the student to 
perform the following actions
1) Change student information 
The student will be introduced to a page where s-he can change any information in their profile 
(password, email, phone number, etc), only the ID cannot be changed. the information is then 
updated on the student profile. Before any change to the profile, the student MUST be asked to reauthenticate by reentering the password only. 
Password rules: for safety concerns the password must contain at least 9 characters that must 
include at least each of the following:  2 lowercase letters  2 uppercase letters  3 digits  2 characters 
You must make sure the password does not contain the following special characters: ‘@’, ‘\’, ‘;’ 
2) Pay fess 
The program should deduct an amount of money based on the student’s semester credits and 
housing choice: 
You should ask the student to enter the number of credits s-he is enrolled in then compute the 
total knowing that the price of one credit is 2100 MAD 
The student will then be asked to specify the type of book s-he wishes to reserve: 
1. Double room: 5880 MAD 
2. Single room: 12800 MAD 
3. Triple room: 3570 MAD 
Finally, you should ask the student if s-he benefits from a scholarship by entering the scholarship 
percentage is yes and 0 is no. 
You should then compute the total amount to be paid and decrement that amount from the 
student’s balance then update the balance. 
If the amount is bigger than the amount available in the balance, make sure to display the 
following message to the student: 
“You still need to pay “amount that is negative” before the first day of classes to avoid getting a 
financial hold” 
3) Supply Cash wallet: 
When clicking on this option, the amount that the student currently has in his/her cash wallet will 
be displayed, and then will be given the option to supply it with an amount between 50 and 
10000MAD. 
If the student enters an amount that is less than 50 MAD, the following message should be 
displayed: “The amount that you entered is less than then minimum required amount of money to 
supply your cash wallet, please enter a higher amount”. 
If the student enters an amount that is more than 10000 MAD, the following message should be 
displayed: “The amount that you entered is more than then maximum allowed amount of money 
to supply your cash wallet, please enter a lower amount”. 
4) Logout 
When login out of the student account, the main menu should be displayed: 
1. Log in 
2. Enroll 
3. Exit 
After reading the requirements above, some of you might have questions for a better 
understanding of what is needed. Every team is allowed to send Mr. Slimane El Ouafi ONLY 1 email that contains all the questions they might have. Do not approach him concerning the project 
except for that 1 e-mail. 
Note: 
The file input.txt contains in every row the profile information of a student which includes: ID 
email fname lname password Phone number balance cash wallet secret_question answer 
