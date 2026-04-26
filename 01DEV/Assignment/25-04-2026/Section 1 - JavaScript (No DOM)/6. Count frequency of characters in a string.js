function countFrequency(inputString, targetChar) {
  let count = 0;
  for (let i = 0; i < inputString.length; i++) {
    if (inputString[i] === targetChar) {
      count++;
    }
  }
  return count;
}

const text = "SUYASH!!!";
const charToCount = "S";

console.log(countFrequency(text, charToCount));
