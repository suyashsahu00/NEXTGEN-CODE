const num1 = [10, 38, 12, 87, 98, 74];

function largestElement(arr) {
  let largestNum = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > largestNum) {
      largestNum = arr[i];
    }
  }
  return largestNum;
}

const result = largestElement(num1);
console.log("The largest element is : " + result);
