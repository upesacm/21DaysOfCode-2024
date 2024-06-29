// Ensure the script runs after the DOM is fully loaded
document.addEventListener('DOMContentLoaded', (event) => {
    alert("Hello, I'm Dev!");

    console.log(10 + 5 - 2);

    
    let order_element = document.querySelector(".order_value");

    
    document.body.insertAdjacentHTML('afterbegin', "My Name is Debarghya Deb");

    
    if (order_element) {
        let quantity_soup = 10;
        let burgers = 8;
        let ice_cream = 5;

        let total_value = 1 * quantity_soup + 3 * burgers + 1 * ice_cream;
        order_element.textContent = total_value;
    } else {
        console.error("Element with class 'order_value' not found");
    }
});
