Instructions to run the Web Server: 

1. Install Node.js

2. Install the dependencies. Open a command window, set the directory to your project directory(where there should be a package.json file) and then run "npm install", which should install all packages listed in the package.json file.

3. In the same command window, run "node app.js" to start the server. If you navigate to "http://localhost:3000", you'll see a webpage with a simple header, and if you go back to the command window, a message should have been printed that says "Node.js is listening". This message is sent every time a client connects.

4. After receiving the connection confirmation, applying force to the FSR should result in the console printing out the values, as well as the value on the webpage changing in real-time.
