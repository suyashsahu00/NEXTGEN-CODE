function isPalidrome(str) {
  let rev = "";
  for (let i = str.length - 1; i >= 0; i--) {
    rev += str[i];
  }
  if (rev == str) {
    return true;
  } else {
    return false;
  }
}

let str1 = "racecar";
let str2 = "nitin";
let str3 = "Rama";

console.log(isPalidrome(str1));
console.log(isPalidrome(str2));
console.log(isPalidrome(str3));
