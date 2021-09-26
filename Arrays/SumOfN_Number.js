'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}
function Sum_Of_N_Numbers(lastNumber) 
{   
    var totalSum = 0;
    for(var i = 1 ; i <= lastNumber ; i++)
        totalSum += i;
    return totalSum;
}

var n = readLine();
console.log(Sum_Of_N_Numbers(parseInt(n)));