let num1 = 8;
let num2 = 9;

function add() {
    let result = num1 + num2;
    return result;
}
function subtract() {
    let result = num1 - num2;
    return result;
}
function multiply() {
    let result = num1 * num2;
    return result;
}
function divide() {
    let result = num1 / num2;
    return result;
}

console.log("Sum of " + num1 + " and " + num2 + " is: " + add());
console.log("Difference of " + num1 + " and " + num2 + " is: " + subtract());
console.log("Product of " + num1 + " and " + num2 + " is: " + multiply());
console.log("Division of " + num1 + " and " + num2 + " is: " + divide());