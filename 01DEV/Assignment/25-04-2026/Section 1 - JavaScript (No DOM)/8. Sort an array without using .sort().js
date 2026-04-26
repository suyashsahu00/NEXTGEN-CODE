function bubbleSort(array) {
  let done = false;
  while (!done) {
    done = true;
    for (let i = 1; i < array.length; i += 1) {
      if (array[i - 1] > array[i]) {
        done = false;
        let tmp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = tmp;
      }
    }
  }
  return array;
}

let numbers = [12, 23, 55, 4, 5, 48, 6, 45];
bubbleSort(numbers);
console.log(numbers);
