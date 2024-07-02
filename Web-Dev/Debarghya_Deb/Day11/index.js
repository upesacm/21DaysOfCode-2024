let add =  function save(){
    console.log(2 + 3);
}

add()

function printName(){
    console.log("Debarghya Deb")
}

function runTwice(fun){
    fun();
    fun();
}

runTwice(printName);

var button = document.querySelector(".Finish")

function handleClick(){
    setTimeout(() => {
            button.textContent = "Finished!"
    }, 1000)
}