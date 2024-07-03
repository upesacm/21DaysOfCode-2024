// Define the runTwice function
function runTwice(func) {
    func(); // Call the function the first time
    func(); // Call the function the second time
}

// Example usage: Define a function that logs a name
function printName() {
    console.log('Atrayee');
}

// Call runTwice with the printName function
runTwice(printName);
