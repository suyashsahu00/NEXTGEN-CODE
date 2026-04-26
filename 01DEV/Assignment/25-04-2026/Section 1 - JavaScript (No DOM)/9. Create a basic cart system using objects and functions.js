let cart = [];

let addItem = (name, price, quantity) => {
  return {
    name: name,
    price: price,
    quantity: quantity,
  };
};

cart.push(addItem("Book", 200, 2));
cart.push(addItem("Bottle", 150, 1));
cart.push(addItem("Shoes", 1200, 1));
cart.push(addItem("Bag", 800, 1));

console.log(cart);
