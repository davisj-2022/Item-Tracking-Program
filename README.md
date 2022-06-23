# Item-Tracking-Program
Project 3
<br>
C++ main program that calls Python functions<br>
Import file from Python & C++<br>
Write to a file from Python <br>
Print from Python <br>
Print from C++ using Python function return <br>



<h2>Directions</h2>
<p>One of Python's strengths is its ability to search through text and process large amounts of data, so that programming language will be used to manage internal functions of the program you create. Alternatively, C++ will be used to interface with users who are interested in using the prototype tracking program.</p>
<p><strong>Grocery Tracking Program </strong><br />Begin with a Visual Studio project file that has been set up correctly to work with both C++ and Python, as you have done in a previous module. Remember to be sure you are working in Release mode, rather than Debug mode. Then add the CS210_Starter_CPP_Code and CS210_Starter_PY_Code files, linked in the Supporting Materials section, to their appropriate tabs within the project file so that C++ and Python will be able to effectively communicate with one another. After you have begun to code, you will also wish to access the CS210_Project_Three_Input_File, linked in the Supporting Materials section, to check the functionality and output of your work.</p>
<p>As you work, continue checking your code&rsquo;s syntax to ensure your code will run. Note that when you compile your code, you will be able to tell if this is successful overall because it will produce an error message for any issues regarding syntax. Some common syntax errors are missing a semicolon, calling a function that does not exist, not closing an open bracket, or using double quotes and not closing them in a string, among others.</p>
<ol>
<li>Use C++ to develop a menu display that asks users what they would like to do. Include options for each of the three requirements outlined in the scenario and number them 1, 2, and 3. You should also include an option 4 to exit the program. All of your code needs to effectively validate user input.</li>
</ol>
<ol start="2">
<li><strong>Create code to determine the number of times each individual item appears</strong>. Here you will be addressing the first requirement from the scenario to produce a list of all items purchased in a given day along with the number of times each item was purchased. Note that each grocery item is represented by a word in the input file. Reference the following to help guide how you can break down the coding work.
<ul>
<li>Write C++ code for when a user selects option 1 from the menu. Select and apply a C++ function to call the appropriate Python function, which will display the number of times each item (or word) appears.</li>
<li>Write Python code to calculate the frequency of every word that appears from the input file. It is recommended that you build off the code you have already been given for this work.</li>
<li>Use Python to display the final result of items and their corresponding numeric value on the screen.</li>
</ul>
</li>
</ol>
<ol start="3">
<li><strong>Create code to determine the frequency of a specific item</strong>. Here you will be addressing the second requirement from the scenario to produce a number representing how many times a specific item was purchased in a given day. Remember an item is represented by a word and its frequency is the number of times that word appears in the input file. Reference the following to help guide how you can break down the coding work.
<ol type="a">
<li>Use C++ to validate user input for option 2 in the menu. Prompt a user to input the item, or word, they wish to look for. Write a C++ function to take the user&rsquo;s input and pass it to Python.</li>
<li>Write Python code to return the frequency of a specific word. It will be useful to build off the code you just wrote to address the first requirement. You can use the logic you wrote but modify it to return just one value; this should be a fairly simple change (about one line). Next, instead of displaying the result on the screen from Python, return a numeric value for the frequency of the specific word to C++.</li>
<li>Write a C++ function to display the value returned from Python. Remember, this should be displayed on the screen in C++. We recommend reviewing the C++ functions that have already been provided to you for this work.</li>
</ol>
</li>
</ol>
<ol start="4">
<li><strong>Create code to graphically display a data file as a text-based histogram</strong>. Here you will be addressing the third requirement from the scenario: to produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased. Reference the following to help guide how you can break down the coding work:
<ol type="a">
<li>Use C++ to validate user input for option 3 in the menu. Then have C++ prompt Python to execute its relevant function.</li>
<li>Write a Python function that reads an input file (CS210_Project_Three_Input_File, which is linked in the Supporting Materials section) and then creates a file, which contains the words and their frequencies. The file that you create should be named <em>frequency.dat</em>, which needs to be specified in your C++ code and in your Python code. Note that you may wish to refer to work you completed in a previous assignment where you practiced reading and writing to a file. Some of your code from that work may be useful to reuse or manipulate here. The frequency.dat file should include every item (represented by a word) paired with the number of times that item appears in the input file. For example, the file might read as follows:
<ul style="list-style: none;">
<li>Potatoes 4</li>
<li>Pumpkins 5</li>
<li>Onions 3</li>
</ul>
</li>
<li>Write C++ code to read the frequency.dat file and display a histogram. Loop through the newly created file and read the name and frequency on each row. Then print the name, followed by asterisks or another special character to represent the numeric amount. The number of asterisks should equal the frequency read from the file. For example, if the file includes 4 potatoes, 5 pumpkins, and 3 onions then your text-based histogram may appear as represented below. However, you can alter the appearance or color of the histogram in any way you choose.
<ul style="list-style: none;">
<li>Potatoes ****</li>
<li>Pumpkins *****</li>
<li>Onions ***</li>
</ul>
</li>
</ol>
</li>
</ol>
<ol start="5">
<li><strong>Apply industry standard best practices such as in-line comments and appropriate naming conventions to enhance readability and maintainability</strong>. Remember that you must demonstrate industry standard best practices in all your code to ensure clarity, consistency, and efficiency. This includes the following:
<ol type="a">
<li>Using input validation and error handling to anticipate, detect, and respond to run-time and user errors (for example, make sure you have option 4 on your menu so users can exit the program)</li>
<li>Inserting in-line comments to denote your changes and briefly describe the functionality of the code</li>
<li>Using appropriate variable, parameter, and other naming conventions throughout your code</li>
</ol>
</li>
</ol>
<p><strong>Programming Languages Explanation</strong><br />Consider the coding work you have completed for the grocery-tracking program. You will now take the time to think more deeply regarding how you were able to combine two different programming languages, C++ and Python, to create a complete program. The following should be completed as a written explanation.</p>
<ol>
<li><strong>Explain the benefits and drawbacks of using C++ in a coding project</strong>. Think about the user-focused portion of the grocery-tracking program you completed using C++. What control does this give you over the user interface? How does it allow you to use colors or formatting effectively?</li>
</ol>
<ol start="2">
<li><strong>Explain the benefits and drawbacks of using Python in a coding project</strong>. Think about the analysis portions of the grocery-tracking program you completed using Python. How does Python allow you to deal with regular expressions? How is Python able to work through large amounts of data? What makes it efficient for this process?</li>
</ol>
<ol start="3">
<li><strong>Discuss when two or more coding languages can effectively be combined in a project</strong>. Think about how C++ and Python&rsquo;s different functions were able to support one another in the overall grocery-tracking program. How do the two function well together? What is another scenario where you may wish to use both? Then, consider what would happen if you added in a third language or switched Python or C++ for something else. In past courses, you have worked with Java as a possible example. What could another language add that would be unique or interesting? Could it help you do something more effectively or efficiently in the grocery-tracking program?</li>
</ol>
